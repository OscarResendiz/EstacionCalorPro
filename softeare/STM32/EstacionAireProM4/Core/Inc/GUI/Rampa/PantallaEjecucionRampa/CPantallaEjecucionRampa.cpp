/*
 * CPantallaEjecucionRampa.cpp
 *
 *  Created on: Jan 10, 2025
 *      Author: W10
 */

#include <GUI/Rampa/PantallaEjecucionRampa/CPantallaEjecucionRampa.hpp>
#include "GUI/CPantallaBase.hpp"
#include <RapaTemperatura/CControladorPasosRampa.hpp>
#include <RapaTemperatura/CControladorRampas.hpp>
#include <RapaTemperatura/CRampa.hpp>
#include <RapaTemperatura/CPaso.hpp>
#include <GUI/ManejadorPantallas/CManejadorPantallas.hpp>
#include<string.h>
CPantallaEjecucionRampa::CPantallaEjecucionRampa():
CPantallaBase(1, (char*)"RAMPA")
{
	// TODO Auto-generated constructor stub
	LabelPaso=new CEtiquetaTft( 5, 35, 50, 20, COLOR::BLACK,(char*)"PASO: ", COLOR::WHITE, 3, 0, COLOR::WHITE);
	LabelTemperatura=new CEtiquetaTft( 5, 70, 50, 20, COLOR::BLACK,(char*)"TEMP: ", COLOR::WHITE, 3, 0, COLOR::WHITE);
	LabelAire=new CEtiquetaTft( 5, 105, 105, 20, COLOR::BLACK,(char*)"AIRE: ", COLOR::WHITE, 3, 0, COLOR::WHITE);
	LabelTiempo=new CEtiquetaTft( 5, 140, 50, 20, COLOR::BLACK,(char*)"TIEM: ", COLOR::WHITE, 3, 0, COLOR::WHITE);

	LabelGuardar=new CEtiquetaTft( 10, 200, 130, 30, COLOR::GREEN,(char*)"INICIAR", COLOR::BLACK, 3, 1, COLOR::WHITE);
	LabelCancelar=new CEtiquetaTft( 160, 200, 145, 30, COLOR::RED,(char*)"REGRESAR", COLOR::BLACK, 3, 1, COLOR::WHITE);

}

CPantallaEjecucionRampa::~CPantallaEjecucionRampa()
{
	// TODO Auto-generated destructor stub
}
void CPantallaEjecucionRampa::SetIDRampa(int id_rampa)
{
	ID_Rampa=id_rampa;
	CRampa rampa=	ControladorRampas.DameRampa(ID_Rampa);
	this->SetTituloPantalla(rampa.Nombre);
	LabelGuardar->SetBackColor(COLOR::GREEN);
	LabelCancelar->SetTexto((char*)"REGRESAR");
	LabelGuardar->Show();
	LabelCancelar->Show();
	Ejecutando=false;

}

void CPantallaEjecucionRampa::OnBotonUnoClickEvent()
{
	if(Ejecutando==true)
		return;
	//ControladorRampas.EliminaRampa(ID_Rampa);
	NPasos=	ControladorPasosRampa.DameNumeroPasosRampa(ID_Rampa);
	int id_pasActual=0;
	for(int i=0;i<100;i++)
	{
		if(i<NPasos)
		{
			CPaso paso=ControladorPasosRampa.DameSiguientePaso(ID_Rampa, id_pasActual);
			Pasos[i]=paso.ID_Paso;
			id_pasActual=paso.ID_Paso;
		}
		else
		{
			Pasos[i]=0;
		}
	}
	PasoActual=0;
	LabelGuardar->SetBackColor(COLOR::GREY);
	LabelCancelar->SetTexto((char*)"CANCELAR");
	LabelGuardar->Show();
	LabelCancelar->Show();
	Ejecutando=true;
	PasoTerminado();
//	ManejadorPantallas.AsignaPantallaPasosRampa(ID_Rampa);
}
void CPantallaEjecucionRampa::OnBotonTresClickEvent()
{

	 ManejadorPantallas.MuestraPantallaRampa(ID_Rampa);

}
void CPantallaEjecucionRampa::Show()
{
	CPantallaBase::Show();
	MuestraDatos();

	LabelGuardar->Show();
	LabelCancelar->Show();

}
void CPantallaEjecucionRampa::Refresca()
{
	if(Ejecutando==true)
	{
		if(TiempoMilis<=0)
		{
			PasoTerminado();
			return;
		}
		int mili=HAL_GetTick();
		if(mili>UltimoMili)
		{
			TiempoMilis=TiempoMilis-(mili-UltimoMili);
			UltimoMili=mili;
			if((TiempoMilis/1000)!=Segundos)
			{
				Segundos=(TiempoMilis/1000);
				SegundosATexto(Segundos);
				LabelTiempo->SetTexto((char*)"TIEM:%s     ",TextoTiempo);
				LabelTiempo->Show();
				int temperaturaReal=Estacion->GetTemperaturaRealx();
				LabelTemperatura->SetTexto((char*)"TEMP:%d/%d     ",temperaturaReal,Paso.Temperatura);
				LabelTemperatura->Show();
			}
		}
	}
	else
	{
		Estacion->DesactivarCalefactor();

	}
}
void CPantallaEjecucionRampa::FinEjecucion()
{
	Ejecutando=false;
	 ManejadorPantallas.MuestraPantallaRampa(ID_Rampa);
	 Estacion->DesactivarCalefactor();
}
void CPantallaEjecucionRampa::PasoTerminado()
{
	if(PasoActual>=NPasos)
	{
		FinEjecucion();
		return;
	}

	int id_pasActual=Pasos[PasoActual];
	CPaso paso=ControladorPasosRampa.DamePasoRampa( id_pasActual);
	PasoActual++;
	Paso.ID_Paso=paso.ID_Paso;
	Paso.ID_Rampa=paso.ID_Rampa;
	Paso.NivelAire=paso.NivelAire;
	Paso.Ocupado=paso.Ocupado;
	Paso.Minutos=paso.Minutos;
	Segundos=Paso.Minutos*60;
	Paso.Temperatura=paso.Temperatura;
	TiempoMilis=Segundos*1000;
	UltimoMili=HAL_GetTick();
	 ActualizaEstacion();
	MuestraDatos();
}
void CPantallaEjecucionRampa::MuestraDatos()
{
	LabelPaso->SetTexto((char*)"Paso:%d",Paso.ID_Paso);
	LabelPaso->Show();
	LabelTemperatura->SetTexto((char*)"TEMP:%d",Paso.Temperatura);
	LabelTemperatura->Show();
	LabelAire->SetTexto((char*)"AIRE:%d",Paso.NivelAire);
	LabelAire->Show();
	SegundosATexto(Segundos);
	LabelTiempo->SetTexto((char*)"SEG:%s",TextoTiempo);
	LabelTiempo->Show();
}
void CPantallaEjecucionRampa::SegundosATexto(int tiempoSegundos)
{
	int horas;
	int minutos;
	int segundos;
	for(int i=0;i<100;i++)
	{
		TextoTiempo[i]='\0';
	}
	horas=tiempoSegundos/(3600);
	tiempoSegundos=tiempoSegundos-(horas*3600);
	minutos=tiempoSegundos/(60);
	tiempoSegundos=tiempoSegundos-(minutos*60);
	segundos=tiempoSegundos;
	sprintf(TextoTiempo,(char*)"%d:%d:%d",horas,minutos,segundos);
}
void CPantallaEjecucionRampa::ActualizaEstacion()
{
	Estacion->SetTemperatura(Paso.Temperatura);
	Estacion->SetNivelAire(Paso.NivelAire);
	Estacion->ActivarCalefactor();
}
void CPantallaEjecucionRampa::SetEstacion(CEstacionBase *estacion)
{
	CPantallaBase::SetEstacion(estacion);
	Estacion->DesactivarCalefactor();
}
