/*
 * CControladorPasosRampa.cpp
 *
 *  Created on: Jan 8, 2025
 *      Author: W10
 */

#include <RapaTemperatura/CControladorPasosRampa.hpp>
#include <EPROM/CEprom.hpp>
#include <RapaTemperatura/CRampa.hpp>
#include <RapaTemperatura/CPaso.hpp>
#include<string.h>

CControladorPasosRampa::CControladorPasosRampa()
{
	// TODO Auto-generated constructor stub

}

CControladorPasosRampa::~CControladorPasosRampa()
{
	// TODO Auto-generated destructor stub
}

bool CControladorPasosRampa::EliminaPasosRampa(int ID_Rampa)
{
//	CPaso paso;
	for (int i = 0; i < NUMERO_MAXIMO_PASOS; i++)
	{
		int direccionPaso = DireccionTablaPasos + (BytesPaso * i);
		CPaso paso=LeePasoMemoria(direccionPaso);
		//if (Eprom.LeeBytes(direccionPaso, BytesPaso, (uint8_t*)&paso) == false)
		//	return false;
		if (paso.Ocupado == 0)
			continue;
		if (paso.ID_Rampa != ID_Rampa)
			continue;
		paso.Ocupado = 0;
		GuardaPasoMemoria(direccionPaso, &paso);
//		if (Eprom.GuardaBytes(direccionPaso, BytesPaso, (uint8_t*)&paso) == false)
	//		return false;
	}
	return true;
}

int CControladorPasosRampa::DameSiguienteID_Paso()
{
	int id_paso=0;
	for (int i = 0; i < NUMERO_MAXIMO_PASOS; i++)
	{
		int direccionPaso = DireccionTablaPasos + (BytesPaso * i);
		CPaso paso=LeePasoMemoria(direccionPaso);
		if (paso.Ocupado == false)
		{
			continue;
		}
		if(paso.ID_Paso>=id_paso)
			id_paso=paso.ID_Paso;
	}
	id_paso++;
	return id_paso;
}
//void CControladorPasosRampa::OrdenaPasos(int npasos)
//{
//	int tmp;
//	int max;
//	for(int i=0;i<100;i++)
//	{
		//if(tmpPasos[i]==0)
//			break;
		//max++;
//	}
//	for(int i=0;i<npasos;i++)
//	{
//		for(int j=i+1;j<npasos;j++)
//		{
//			if(tmpPasos[i]>tmpPasos[j])
//			{
//				tmp=tmpPasos[i];
//				tmpPasos[i]=tmpPasos[j];
//				tmpPasos[j]=tmp;
//			}
//		}
//	}
//}
void CControladorPasosRampa::GuardaPasoMemoria(int direccion, CPaso *paso)
{
	uint8_t Ocupado=paso->Ocupado;
	uint8_t ID_Rampa=paso->ID_Rampa;
	uint8_t ID_Paso=paso->ID_Paso;
	uint8_t NivelAire=paso->NivelAire;
	uint8_t Segundos=paso->Segundos;
	uint16_t Temperatura=paso->Temperatura;

	Eprom.GuardaBytes(direccion, 1,&Ocupado);
	direccion++;
	Eprom.GuardaBytes(direccion, 1,&ID_Rampa);
	direccion++;
	Eprom.GuardaBytes(direccion,1 ,&ID_Paso);
	direccion++;
	Eprom.GuardaBytes(direccion, 1,&NivelAire);
	direccion++;
	Eprom.GuardaBytes(direccion, 1,&Segundos);
	direccion++;
	Eprom.GuardaBytes(direccion, 2,(uint8_t*) &Temperatura);
}
CPaso CControladorPasosRampa::LeePasoMemoria(int direccion)
{
	uint8_t Ocupado;
	uint8_t ID_Rampa;
	uint8_t ID_Paso;
	uint8_t NivelAire;
	uint8_t Segundos;
	uint16_t Temperatura;

	Eprom.LeeBytes(direccion, 1,&Ocupado);
	direccion++;
	Eprom.LeeBytes(direccion, 1,&ID_Rampa);
	direccion++;
	Eprom.LeeBytes(direccion,1 ,&ID_Paso);
	direccion++;
	Eprom.LeeBytes(direccion, 1,&NivelAire);
	direccion++;
	Eprom.LeeBytes(direccion, 1,&Segundos);
	direccion++;
	Eprom.LeeBytes(direccion, 2,(uint8_t*) &Temperatura);

	CPaso paso;
	paso.Ocupado=Ocupado;
	paso.ID_Rampa=ID_Rampa;
	paso.ID_Paso=ID_Paso;
	paso.NivelAire=NivelAire;
	paso.Segundos=Segundos;
	paso.Temperatura=Temperatura;
	return paso;
}
bool CControladorPasosRampa::ActualizaPasoRampa(int ID_Paso,int ID_Rampa,uint16_t Temperatura,uint8_t NivelAire,uint8_t Segundos)
{
	//CPaso pasoTmp;
	for (int i = 0; i < NUMERO_MAXIMO_PASOS; i++)
	{
		int direccionPaso = DireccionTablaPasos + (BytesPaso * i);
		CPaso pasoTmp=LeePasoMemoria(direccionPaso);
//		if (Eprom.LeeBytes(direccionPaso, BytesPaso,(uint8_t*) &pasoTmp) == false)
	//		return false;
		if (pasoTmp.ID_Paso != ID_Paso)
			continue;
		pasoTmp.ID_Rampa = ID_Rampa;
		pasoTmp.Ocupado = 1;
		pasoTmp.NivelAire = NivelAire;
		pasoTmp.Segundos = Segundos;
		pasoTmp.Temperatura = Temperatura;
		GuardaPasoMemoria(direccionPaso,&pasoTmp);
		//return Eprom.GuardaBytes(direccionPaso, BytesPaso,(uint8_t*) &pasoTmp);
		return true;
	}
	return false;

}
bool CControladorPasosRampa::EliminaPasoRampa(int ID_Paso)
{
//	CPaso pasoTmp;
	for (int i = 0; i < NUMERO_MAXIMO_PASOS; i++)
	{
		int direccionPaso = DireccionTablaPasos + (BytesPaso * i);
		CPaso pasoTmp=LeePasoMemoria(direccionPaso);
	//	if (Eprom.LeeBytes(direccionPaso, BytesPaso,(uint8_t*) &pasoTmp) == false)
		//	return false;
		if (pasoTmp.ID_Paso != ID_Paso)
			continue;
		pasoTmp.Ocupado = 0;
		GuardaPasoMemoria(direccionPaso,&pasoTmp);
		//return Eprom.GuardaBytes(direccionPaso, BytesPaso,(uint8_t*) &pasoTmp);
	}
	return false;

}
void CControladorPasosRampa::SetDireccionUltimoID_Paso(int ultimoID)
{
	DireccionUltimoID_Paso=	ultimoID;
}

void CControladorPasosRampa::SetDireccionTablaPasos(int direccion)
{
	DireccionTablaPasos=direccion;
}
void CControladorPasosRampa::SetNumeroMaximoPasos(int valor)
{
	NUMERO_MAXIMO_PASOS=valor;
}
int CControladorPasosRampa::GetBytesXPaso()
{
	return BytesPaso;
}
int CControladorPasosRampa::GetNumeroMaximoPasos()
{
	return NUMERO_MAXIMO_PASOS;
}
int CControladorPasosRampa::GetDireccionTablaPasos()
{
	return DireccionTablaPasos;
}
void CControladorPasosRampa::SetUltimoIDPado(uint8_t id)
{
	UltimoID_Paso=id;
	Eprom.GuardaBytes(DireccionUltimoID_Paso, 2, (uint8_t*)&UltimoID_Paso);
}
//-------------------------------------------------------------------------------------------------------------------------------
int CControladorPasosRampa::DameNumeroPasosRampa(int ID_Rampa)
{
	int npasos=0;
	for (int i = 0; i < NUMERO_MAXIMO_PASOS; i++)
	{
		int direccionPaso = DireccionTablaPasos + (BytesPaso * i);
		CPaso pasoTmp=LeePasoMemoria(direccionPaso);
		if (pasoTmp.Ocupado != true)
			continue;
		if (pasoTmp.ID_Rampa == ID_Rampa)
		{
			npasos++;
		}
	}
	return npasos;
}
CPaso CControladorPasosRampa::DameSiguientePaso(int id_rampa, int id_pasActual)
{
	int id_paso=0;
	for (int i = 0; i < NUMERO_MAXIMO_PASOS; i++)
	{
		int direccionPaso = DireccionTablaPasos + (BytesPaso * i);
		CPaso pasoTmp=LeePasoMemoria(direccionPaso);
		if (pasoTmp.Ocupado != true)
			continue;
		if (pasoTmp.ID_Rampa != id_rampa)
			continue;
		if(pasoTmp.ID_Paso<=id_pasActual)
			continue;
		if(id_paso==0)
		{
			id_paso=pasoTmp.ID_Paso;
			continue;
		}
		if(id_paso<=pasoTmp.ID_Paso)
			continue;
		id_paso=pasoTmp.ID_Paso;
	}
	return DamePasoRampa(id_paso);
}
CPaso CControladorPasosRampa::DamePasoRampa(int ID_Paso)
{
	for (int i = 0; i < NUMERO_MAXIMO_PASOS; i++)
	{
		int direccionPaso = DireccionTablaPasos + (BytesPaso * i);
		CPaso pasoTmp=LeePasoMemoria(direccionPaso);
		if (pasoTmp.ID_Paso != ID_Paso)
			continue;
		return pasoTmp;
	}
	CPaso pasoTmp2;
	return pasoTmp2;
}
bool CControladorPasosRampa::AgregarPasoRampa(int ID_Rampa, uint16_t Temperatura, uint8_t NivelAire, uint8_t Segundos)
{
	for (int i = 0; i < NUMERO_MAXIMO_PASOS; i++)
	{
		int direccionPaso = DireccionTablaPasos + (BytesPaso * i);
		CPaso pasoTmp=LeePasoMemoria(direccionPaso);
		if (pasoTmp.Ocupado == 1)
		{
			continue;
		}
		pasoTmp.ID_Rampa = ID_Rampa;
		int id_paso=DameSiguienteID_Paso();
		pasoTmp.ID_Paso =id_paso;
		pasoTmp.Ocupado = 1;
		pasoTmp.NivelAire = NivelAire;
		pasoTmp.Segundos = Segundos;
		pasoTmp.Temperatura = Temperatura;
		GuardaPasoMemoria(direccionPaso, &pasoTmp);
		return true;
	}
	return false;
}
