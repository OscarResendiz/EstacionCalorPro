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
#include<string.h>
#include <RapaTemperatura/CControladorPasosRampa.hpp>

CControladorRampas::CControladorRampas()
{
	// TODO Auto-generated constructor stub
	int capacidadMemoriaInstalada = Eprom.DameCapacidadMaximaMemoria();
	DireccionInicial = Eprom.DameDireccionInicioRampas();
	DireccionKey = DireccionInicial;
	DireccionUltimoID_Rampa = DireccionKey + 3;
	int direccionUltimoID_Paso=DireccionUltimoID_Rampa + 2;
	ControladorPasosRampa.SetDireccionUltimoID_Paso(direccionUltimoID_Paso);
	DireccionTablaRampas = direccionUltimoID_Paso + 2;
	BytesRampa = sizeof(CRampa);
	int direccionTablaPasos= DireccionTablaRampas + (BytesRampa * NUMERO_MAXIMO_RAMPAS);
	ControladorPasosRampa.SetDireccionTablaPasos(direccionTablaPasos);
	int bytesPaso = ControladorPasosRampa.GetBytesXPaso();
	ControladorPasosRampa.SetNumeroMaximoPasos( (capacidadMemoriaInstalada - direccionTablaPasos) / bytesPaso);
	UltimoID_Rampa = -1;
}

CControladorRampas::~CControladorRampas()
{
	// TODO Auto-generated destructor stub
}


bool CControladorRampas::MemoriaInicialidada()
{
	Eprom.LeeBytes(DireccionKey, 3, (uint8_t*)&Key);
	//char key[] = "OSC";
	for (int i = 0; i < 3; i++)
	{
		if (Key[i] != KEY[i])
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
	int numeroMaximoPasos=ControladorPasosRampa.GetNumeroMaximoPasos();
	int direccionTablaPasos=ControladorPasosRampa.GetDireccionTablaPasos();
	int bytesPaso=ControladorPasosRampa.GetBytesXPaso();
	int maximo = NUMERO_MAXIMO_RAMPAS + numeroMaximoPasos;

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
		GuardaRampaMemoria(direccionRampa, &rampa);
	}

	for (int i = 0; i < numeroMaximoPasos; i++)
	{
		if (ControlProgreso != NULL)
		{
			ControlProgreso->OnProgreso(progreso, maximo);
			progreso++;
		}
		direccionPaso = direccionTablaPasos + (bytesPaso * i);
		ControladorPasosRampa.GuardaPasoMemoria(direccionPaso,&paso);
	}
	UltimoID_Rampa = 0;
	Eprom.GuardaBytes(DireccionUltimoID_Rampa, 2, (uint8_t*)&UltimoID_Rampa);
	ControladorPasosRampa.SetUltimoIDPado(0);
	Eprom.GuardaBytes(DireccionKey, 3,(uint8_t*) KEY);

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
	TotalRampas = 0;
	//recorro toda la tabla de rampas y cuento las que estan activas
	for (int i = 0; i < NUMERO_MAXIMO_RAMPAS; i++)
	{
		int direccionRampa = DireccionTablaRampas + (BytesRampa * i);
		//me traigo los datos de la rampa de la memoria
		CRampa rampa=LeeRampaMemoria(direccionRampa);
		if (rampa.Ocupado == true)
			TotalRampas++;
	}
	return TotalRampas;
}

CRampa CControladorRampas::DameRampa(int id_Rampa)
{

	int numeroRampa = 0;
	//recorro toda la tabla de rampas y cuento las que estan activas
	for (int i = 0; i < NUMERO_MAXIMO_RAMPAS; i++)
	{
		int direccionRampa = DireccionTablaRampas + (BytesRampa * i);
		//me traigo los datos de la rampa de la memoria
		CRampa tmpRampa=LeeRampaMemoria(direccionRampa);
		if (tmpRampa.Ocupado == false)
			continue;
		numeroRampa++;
		if (tmpRampa.ID_RAMPA != id_Rampa)
			continue;
		return tmpRampa;
	}
	CRampa tmpRampa2;
	return tmpRampa2;
}
CRampa CControladorRampas::DameRampaNumero(int posicion)
{

	int numeroRampa = 0;
	//recorro toda la tabla de rampas y cuento las que estan activas
	for (int i = 0; i < NUMERO_MAXIMO_RAMPAS; i++)
	{
		int direccionRampa = DireccionTablaRampas + (BytesRampa * i);
		//me traigo los datos de la rampa de la memoria
		CRampa tmpRampa=LeeRampaMemoria(direccionRampa);
		if (tmpRampa.Ocupado != true)
			continue;
		numeroRampa++;
		if (numeroRampa-1 != posicion)
			continue;
		return tmpRampa;
	}
	CRampa tmpRampa2;
	return tmpRampa2;
}
CRampa CControladorRampas::LeeRampaMemoria(int direccion)
{
	/*
	 * lee una rampa desde la memoria
	 * el mapa es el siguiente
	 * -----------------------------------------
	 * | direccion | bytes | dato              |
	 * |-----------|-------|-------------------|
	 * | 00        | 1     | Bandera de ocupado|
	 * | 01-02     | 2     | ID_RAMPA          |
	 * | 03-11h    | 15    | Nombre de la rampa|
	 * -----------------------------------------
	 */
	uint8_t ocupado;
	uint16_t id_rampa;
	char nombre[20];
	CRampa rampa;
	//leo la bandera de ocupado
	Eprom.LeeBytes(direccion, 1, &ocupado);
	Eprom.LeeBytes(direccion, 1, &ocupado);
	rampa.Ocupado=ocupado;
	//leo el ID_RAMPA
	Eprom.LeeBytes(direccion+1, 2, (uint8_t*)&id_rampa);
	Eprom.LeeBytes(direccion+1, 2, (uint8_t*)&id_rampa);
	rampa.ID_RAMPA=id_rampa;
	//leo el nombre
	Eprom.LeeBytes(direccion+3, 15, (uint8_t*)nombre);
	Eprom.LeeBytes(direccion+3, 15, (uint8_t*)nombre);
	rampa.SetNombre(nombre);
	return rampa;

}
void CControladorRampas::GuardaRampaMemoria(int direccion, CRampa *rampa)
{
	/*
	 * lee una rampa desde la memoria
	 * el mapa es el siguiente
	 * -----------------------------------------
	 * | direccion | bytes | dato              |
	 * |-----------|-------|-------------------|
	 * | 00        | 1     | Bandera de ocupado|
	 * | 01-02     | 2     | ID_RAMPA          |
	 * | 03-11h    | 15    | Nombre de la rampa|
	 * -----------------------------------------
	 */
	//guardo la bandera de ocupado
	uint8_t ocupado;
	uint16_t id_rampa;
	char nombre[20];
	uint8_t tmp[30];
	ocupado=rampa->Ocupado;
	id_rampa=rampa->ID_RAMPA;
	strcpy(nombre,rampa->Nombre);
	Eprom.GuardaBytes(direccion, 1, &ocupado);
	//guardo el ID_RAMPA
	Eprom.GuardaBytes(direccion+1, 2, (uint8_t*)&id_rampa);
	//guardo el nombre
	Eprom.GuardaBytes(direccion+3, 15, (uint8_t*)nombre);

	id_rampa=-1;
	ocupado=-1;
	for(int i=0;i<15;i++)
		nombre[i]='\0';

	Eprom.LeeBytes(direccion+3, 15, (uint8_t*)nombre);
	Eprom.LeeBytes(direccion+1, 2, (uint8_t*)&id_rampa);
	Eprom.LeeBytes(direccion, 1, &ocupado);
	Eprom.LeeBytes(direccion, 18, tmp);
}
CRampa CControladorRampas::AgregaRampa(char *nombre)
{
	//busco la primer ubicacion vacia para almacear la rampa
	//recorro toda la tabla de rampas y cuento las que estan activas
	for (int i = 0; i < NUMERO_MAXIMO_RAMPAS; i++)
	{
		int direccionRampa = DireccionTablaRampas + (BytesRampa * i);
		//me traigo los datos de la rampa de la memoria
		CRampa tmpRampa=LeeRampaMemoria(direccionRampa);
		if (tmpRampa.Ocupado == 0)
		{
			tmpRampa.Ocupado = 1;
			tmpRampa.ID_RAMPA = DameSiguienteID_Rampa();
			tmpRampa.SetNombre(nombre);
			TotalRampas++;
			GuardaRampaMemoria(direccionRampa,&tmpRampa);
			CRampa rampa2=LeeRampaMemoria(direccionRampa);
			return tmpRampa;
		}
	}
	CRampa tmpRampa2;
	return tmpRampa2;
}

bool CControladorRampas::ActualizaRampa(int ID_Rampa, char *nombre)
{
	//recorro toda la tabla de rampas y cuento las que estan activas
	for (int i = 0; i < NUMERO_MAXIMO_RAMPAS; i++)
	{
		int direccionRampa = DireccionTablaRampas + (BytesRampa * i);
		//me traigo los datos de la rampa de la memoria
		CRampa tmpRampa=LeeRampaMemoria(direccionRampa);
		if (tmpRampa.ID_RAMPA == ID_Rampa)
		{
			tmpRampa.Ocupado = 1;
			tmpRampa.SetNombre(nombre);
			GuardaRampaMemoria(direccionRampa,&tmpRampa);
			return true;
		}
	}
	return false;
}

bool CControladorRampas::EliminaRampa(int ID_Rampa)
{
	//recorro toda la tabla de rampas y cuento las que estan activas
	for (int i = 0; i < NUMERO_MAXIMO_RAMPAS; i++)
	{
		int direccionRampa = DireccionTablaRampas + (BytesRampa * i);
		//me traigo los datos de la rampa de la memoria
		CRampa tmpRampa=LeeRampaMemoria(direccionRampa);
		if (tmpRampa.ID_RAMPA == ID_Rampa)
		{
			tmpRampa.Ocupado = 0;
			GuardaRampaMemoria(direccionRampa,&tmpRampa);
			//Eprom.GuardaBytes(direccionRampa, BytesRampa,(uint8_t*) &tmpRampa);
			TotalRampas--;
			return ControladorPasosRampa.EliminaPasosRampa(ID_Rampa);
		}
	}
	return false;
}


void CControladorRampas::ActualizadaRampa(int ID_Rampa,char *nombre)
{
	//recorro toda la tabla de rampas y cuento las que estan activas
	for (int i = 0; i < NUMERO_MAXIMO_RAMPAS; i++)
	{
		int direccionRampa = DireccionTablaRampas + (BytesRampa * i);
		//me traigo los datos de la rampa de la memoria
		CRampa tmpRampa=LeeRampaMemoria(direccionRampa);

		if (tmpRampa.ID_RAMPA == ID_Rampa)
		{
			tmpRampa.Ocupado = 1;
			tmpRampa.SetNombre(nombre);
			GuardaRampaMemoria(direccionRampa,&tmpRampa);
			return;
		}
	}
}
int CControladorRampas::DameSiguienteID_Rampa()
{
	UltimoID_Rampa=0;
	for (int i = 0; i < NUMERO_MAXIMO_RAMPAS; i++)
	{
		int direccionRampa = DireccionTablaRampas + (BytesRampa * i);
		//me traigo los datos de la rampa de la memoria
		CRampa tmpRampa=LeeRampaMemoria(direccionRampa);

		if (tmpRampa.Ocupado == 1)
		{
			if(tmpRampa.ID_RAMPA>=UltimoID_Rampa)
			{
				UltimoID_Rampa=tmpRampa.ID_RAMPA;
			}
		}
	}
	UltimoID_Rampa++;
	return UltimoID_Rampa;
}
