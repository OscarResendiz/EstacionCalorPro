/*
 * CControladorRampas.cpp
 *
 *  Created on: Oct 30, 2024
 *      Author: W10
 */

#include <RapaTemperatura/CControladorRampas.hpp>
#include <EPROM/CEprom.hpp>
#include <RapaTemperatura/CRampa.hpp>
#include <RapaTemperatura/CPaso.hpp>

CControladorRampas::CControladorRampas()
{
	// TODO Auto-generated constructor stub
	int capacidadMemoriaInstalada = Eprom.DameCapacidadMaximaMemoria();
	DireccionInicial = Eprom.DameDireccionInicioRampas();
	DireccionKey = DireccionInicial;
	DireccionUltimoID_Rampa = DireccionKey + 3;
	;
	DireccionUltimoID_Paso = DireccionUltimoID_Rampa + 2;
	DireccionTablaRampas = DireccionUltimoID_Paso + 2;
	BytesRampa = sizeof(CRampa);
	DireccionTablaPasos = DireccionTablaRampas + (BytesRampa * NUMERO_MAXIMO_RAMPAS);
	BytesPaso = sizeof(CPaso);
	NUMERO_MAXIMO_PASOS = (capacidadMemoriaInstalada - DireccionTablaPasos) / BytesPaso;
	UltimoID_Rampa = -1;
}

CControladorRampas::~CControladorRampas()
{
	// TODO Auto-generated destructor stub
}


bool CControladorRampas::MemoriaInicialidada()
{
	Eprom.LeeBytes(DireccionKey, 3, (uint8_t*)&Key);
	char key[] = "KEY";
	for (int i = 0; i < 3; i++)
	{
		if (Key[i] != key[i])
		{
			return false;
		}
	}
	return true;
}

void CControladorRampas::InicializaMemoria()
{
	CRampa rampa;
	CPaso paso;
	int direccionRampa;
	int direccionPaso;
	int progreso = 0;
	int maximo = NUMERO_MAXIMO_RAMPAS + NUMERO_MAXIMO_PASOS;

	if (ControlProgreso != NULL)
		ControlProgreso->OnMensaje((char*) "Iniciando memoria");

	for (int i = 0; i < NUMERO_MAXIMO_RAMPAS; i++)
	{
		if (ControlProgreso != NULL)
		{
			ControlProgreso->OnProgreso(progreso, maximo);
			progreso++;
		}
		direccionRampa = DireccionTablaRampas + (BytesRampa * i);
		Eprom.GuardaBytes(direccionRampa, BytesRampa,(uint8_t*) &rampa);
	}

	for (int i = 0; i < NUMERO_MAXIMO_PASOS; i++)
	{
		if (ControlProgreso != NULL)
		{
			ControlProgreso->OnProgreso(progreso, maximo);
			progreso++;
		}
		direccionPaso = DireccionTablaPasos + (BytesPaso * i);
		Eprom.GuardaBytes(direccionPaso, BytesPaso, (uint8_t*)&paso);
	}
	UltimoID_Rampa = 0;
	Eprom.GuardaBytes(DireccionUltimoID_Rampa, 2, (uint8_t*)&UltimoID_Rampa);
	UltimoID_Paso = 0;
	Eprom.GuardaBytes(DireccionUltimoID_Paso, 2, (uint8_t*)&UltimoID_Paso);
	Key[0]='K';
	Key[1]='E';
	Key[2]='Y';
	Eprom.GuardaBytes(DireccionKey, 3,(uint8_t*) &Key);

	if (ControlProgreso != NULL)
	{
		ControlProgreso->OnFinProgreso();
		progreso++;
	}

}

void CControladorRampas::SetControlProgreso(CControlProgreso *controlProgreso)
{
	ControlProgreso = controlProgreso;
}

int CControladorRampas::DameNumeroRampas()
{
	if (TotalRampas != -1)
		return TotalRampas;
	CRampa rampa;
	TotalRampas = 0;
	//recorro toda la tabla de rampas y cuento las que estan activas
	for (int i = 0; i < NUMERO_MAXIMO_RAMPAS; i++)
	{
		int direccionRampa = DireccionTablaRampas + (BytesRampa * i);
		//me traigo los datos de la rampa de la memoria
		Eprom.LeeBytes(direccionRampa, BytesRampa, (uint8_t*)&rampa);
		if (rampa.Ocupado == true)
			TotalRampas++;
	}
	return TotalRampas;
}

CRampa CControladorRampas::DameRampa(int numero)
{
	CRampa tmpRampa;
	int numeroRampa = 0;
	//recorro toda la tabla de rampas y cuento las que estan activas
	for (int i = 0; i < NUMERO_MAXIMO_RAMPAS; i++)
	{
		int direccionRampa = DireccionTablaRampas + (BytesRampa * i);
		//me traigo los datos de la rampa de la memoria
		Eprom.LeeBytes(direccionRampa, BytesRampa,(uint8_t*) &tmpRampa);
		if (tmpRampa.Ocupado == false)
			continue;
		numeroRampa++;
		if (numeroRampa != numero)
			continue;
		return tmpRampa;
	}
	tmpRampa.ID_RAMPA=0;
	return tmpRampa;
}
CRampa CControladorRampas::AgregaRampa(char *nombre)
{
	//busco la primer ubicacion vacia para almacear la rampa
	CRampa tmpRampa;
	//recorro toda la tabla de rampas y cuento las que estan activas
	for (int i = 0; i < NUMERO_MAXIMO_RAMPAS; i++)
	{
		int direccionRampa = DireccionTablaRampas + (BytesRampa * i);
		//me traigo los datos de la rampa de la memoria
		Eprom.LeeBytes(direccionRampa, BytesRampa, (uint8_t*)&tmpRampa);
		if (tmpRampa.Ocupado == 0)
		{
			tmpRampa.Ocupado = 1;
			tmpRampa.ID_RAMPA = DameSiguienteID_Rampa();
			tmpRampa.SetNombre(nombre);
			TotalRampas++;
			Eprom.GuardaBytes(direccionRampa, BytesRampa, (uint8_t*)&tmpRampa);
			return tmpRampa;
		}
	}
	tmpRampa.ID_RAMPA=0;
	return tmpRampa;
}

bool CControladorRampas::ActualizaRampa(int ID_Rampa, char *nombre)
{
	CRampa tmpRampa;
	//recorro toda la tabla de rampas y cuento las que estan activas
	for (int i = 0; i < NUMERO_MAXIMO_RAMPAS; i++)
	{
		int direccionRampa = DireccionTablaRampas + (BytesRampa * i);
		//me traigo los datos de la rampa de la memoria
		if (Eprom.LeeBytes(direccionRampa, BytesRampa, (uint8_t*)&tmpRampa) == false)
			return false;
		if (tmpRampa.ID_RAMPA == ID_Rampa)
		{
			tmpRampa.Ocupado = 1;
			tmpRampa.SetNombre(nombre);
			return Eprom.GuardaBytes(direccionRampa, BytesRampa,(uint8_t*) &tmpRampa);
		}
	}
	return false;
}

int CControladorRampas::DameSiguienteID_Rampa()
{
	if (UltimoID_Rampa == -1)
	{
		Eprom.LeeBytes(DireccionUltimoID_Rampa, 2,(uint8_t*) &UltimoID_Rampa);
	}
	UltimoID_Rampa++;
	Eprom.GuardaBytes(DireccionUltimoID_Rampa, 2, (uint8_t*)&UltimoID_Rampa);
	return UltimoID_Rampa;
}
bool CControladorRampas::EliminaRampa(int ID_Rampa)
{
	CRampa tmpRampa;
	//recorro toda la tabla de rampas y cuento las que estan activas
	for (int i = 0; i < NUMERO_MAXIMO_RAMPAS; i++)
	{
		int direccionRampa = DireccionTablaRampas + (BytesRampa * i);
		//me traigo los datos de la rampa de la memoria
		if (Eprom.LeeBytes(direccionRampa, BytesRampa, (uint8_t*)&tmpRampa) == false)
			return false;
		if (tmpRampa.ID_RAMPA == ID_Rampa)
		{
			tmpRampa.Ocupado = 0;
			Eprom.GuardaBytes(direccionRampa, BytesRampa,(uint8_t*) &tmpRampa);
			TotalRampas--;
			return EliminaPasosRampa(ID_Rampa);
		}
	}
	return false;
}

bool CControladorRampas::EliminaPasosRampa(int ID_Rampa)
{
	CPaso paso;
	for (int i = 0; i < NUMERO_MAXIMO_PASOS; i++)
	{
		int direccionPaso = DireccionTablaPasos + (BytesPaso * i);
		if (Eprom.LeeBytes(direccionPaso, BytesPaso, (uint8_t*)&paso) == false)
			return false;
		if (paso.Ocupado == 0)
			continue;
		if (paso.ID_Rampa != ID_Rampa)
			continue;
		paso.Ocupado = 0;
		if (Eprom.GuardaBytes(direccionPaso, BytesPaso, (uint8_t*)&paso) == false)
			return false;
	}
	return true;
}
bool CControladorRampas::AgregarPasoRampa(int ID_Rampa, uint16_t Temperatura, uint8_t NivelAire, uint8_t Segundos)
{
	CPaso pasoTmp;
	for (int i = 0; i < NUMERO_MAXIMO_PASOS; i++)
	{
		int direccionPaso = DireccionTablaPasos + (BytesPaso * i);
		if (Eprom.LeeBytes(direccionPaso, BytesPaso, (uint8_t*)&pasoTmp) == false)
			return false;
		if (pasoTmp.Ocupado == 1)
		{
			continue;
		}
		pasoTmp.ID_Rampa = ID_Rampa;
		pasoTmp.ID_Paso = DameSiguienteID_Paso();
		pasoTmp.Ocupado = 1;
		pasoTmp.NivelAire = NivelAire;
		pasoTmp.Segundos = Segundos;
		pasoTmp.Temperatura = Temperatura;
		return Eprom.GuardaBytes(direccionPaso, BytesPaso,(uint8_t*) &pasoTmp);
	}
	return false;
}

int CControladorRampas::DameSiguienteID_Paso()
{
	if (UltimoID_Paso == -1)
	{
		Eprom.LeeBytes(DireccionUltimoID_Paso, 2,(uint8_t*) &UltimoID_Paso);
	}
	UltimoID_Paso++;
	Eprom.GuardaBytes(DireccionUltimoID_Paso, 2,(uint8_t*) &UltimoID_Paso);
	return UltimoID_Paso;
}

void CControladorRampas::ActualizadaRampa(int ID_Rampa,char *nombre)
{
	CRampa tmpRampa;
	//recorro toda la tabla de rampas y cuento las que estan activas
	for (int i = 0; i < NUMERO_MAXIMO_RAMPAS; i++)
	{
		int direccionRampa = DireccionTablaRampas + (BytesRampa * i);
		//me traigo los datos de la rampa de la memoria
		Eprom.LeeBytes(direccionRampa, BytesRampa, (uint8_t*)&tmpRampa);
		if (tmpRampa.ID_RAMPA == ID_Rampa)
		{
			tmpRampa.Ocupado = 1;
			tmpRampa.SetNombre(nombre);
			Eprom.GuardaBytes(direccionRampa, BytesRampa,(uint8_t*) &tmpRampa);
			return;
		}
	}
}
bool CControladorRampas::ActualizaPasoRampa(int ID_Paso,int ID_Rampa,uint16_t Temperatura,uint8_t NivelAire,uint8_t Segundos)
{
	CPaso pasoTmp;
	for (int i = 0; i < NUMERO_MAXIMO_PASOS; i++)
	{
		int direccionPaso = DireccionTablaPasos + (BytesPaso * i);
		if (Eprom.LeeBytes(direccionPaso, BytesPaso,(uint8_t*) &pasoTmp) == false)
			return false;
		if (pasoTmp.ID_Paso != ID_Paso)
			continue;
		pasoTmp.ID_Rampa = ID_Rampa;
		pasoTmp.Ocupado = 1;
		pasoTmp.NivelAire = NivelAire;
		pasoTmp.Segundos = Segundos;
		pasoTmp.Temperatura = Temperatura;
		return Eprom.GuardaBytes(direccionPaso, BytesPaso,(uint8_t*) &pasoTmp);
	}
	return false;

}
bool CControladorRampas::EliminaPasoRampa(int ID_Paso)
{
	CPaso pasoTmp;
	for (int i = 0; i < NUMERO_MAXIMO_PASOS; i++)
	{
		int direccionPaso = DireccionTablaPasos + (BytesPaso * i);
		if (Eprom.LeeBytes(direccionPaso, BytesPaso,(uint8_t*) &pasoTmp) == false)
			return false;
		if (pasoTmp.ID_Paso != ID_Paso)
			continue;
		pasoTmp.Ocupado = 0;
		return Eprom.GuardaBytes(direccionPaso, BytesPaso,(uint8_t*) &pasoTmp);
	}
	return false;

}
CPaso CControladorRampas::DamePasoRampa(int ID_Paso)
{
	CPaso pasoTmp;
	for (int i = 0; i < NUMERO_MAXIMO_PASOS; i++)
	{
		int direccionPaso = DireccionTablaPasos + (BytesPaso * i);
		if (Eprom.LeeBytes(direccionPaso, BytesPaso, (uint8_t*)&pasoTmp) == false)
		{
			pasoTmp.ID_Paso=0;
			return pasoTmp;
		}
		if (pasoTmp.ID_Paso != ID_Paso)
			continue;
		return pasoTmp;
	}
	pasoTmp.ID_Paso=0;
	return pasoTmp;

}
int CControladorRampas::DameNumeroPasosRampa(int ID_Rampa)
{
	CPaso pasoTmp;
	int npasos=0;
	posicionPasoActual=0;
	for(int i=0;i<100;i++)
		tmpPasos[i]=0;
	for (int i = 0; i < NUMERO_MAXIMO_PASOS; i++)
	{
		int direccionPaso = DireccionTablaPasos + (BytesPaso * i);
		if (Eprom.LeeBytes(direccionPaso, BytesPaso,(uint8_t*) &pasoTmp) == false)
			return 0;
		if (pasoTmp.ID_Rampa == ID_Rampa)
		{
			tmpPasos[npasos]=pasoTmp.ID_Paso;
			npasos++;

		}
	}
	OrdenaPasos();
	return npasos;
}
void CControladorRampas::OrdenaPasos()
{
	int tmp;
	int max;
	for(int i=0;i<100;i++)
	{
		if(tmpPasos[i]==0)
			break;
		max++;
	}
	for(int i=0;i<max;i++)
	{
		for(int j=i+1;j<max;j++)
		{
			if(tmpPasos[i]>tmpPasos[j])
			{
				tmp=tmpPasos[i];
				tmpPasos[i]=tmpPasos[j];
				tmpPasos[j]=tmp;
			}
		}
	}
}
CPaso CControladorRampas::DameSiguientePaso()
{
	CPaso paso;
	int ID_Paso=tmpPasos[posicionPasoActual];
	posicionPasoActual++;
	return DamePasoRampa(ID_Paso);
}
