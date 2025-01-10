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

CPantallaEjecucionRampa::CPantallaEjecucionRampa():
CPantallaBase(1, (char*)"RAMPA")
{
	// TODO Auto-generated constructor stub
	LabelPaso=new CEtiquetaTft( 5, 35, 50, 20, COLOR::BLACK,(char*)"PASO: ", COLOR::WHITE, 3, 0, COLOR::WHITE);
	LabelTemperatura=new CEtiquetaTft( 5, 70, 50, 20, COLOR::BLACK,(char*)"TEMP: ", COLOR::WHITE, 3, 0, COLOR::WHITE);
	LabelAire=new CEtiquetaTft( 5, 105, 105, 20, COLOR::BLACK,(char*)"AIRE: ", COLOR::WHITE, 3, 0, COLOR::WHITE);
	LabelTiempo=new CEtiquetaTft( 5, 140, 50, 20, COLOR::BLACK,(char*)"SEG: ", COLOR::WHITE, 3, 0, COLOR::WHITE);

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
}

void CPantallaEjecucionRampa::OnBotonUnoClickEvent()
{
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
//	ManejadorPantallas.AsignaPantallaPasosRampa(ID_Rampa);
}
void CPantallaEjecucionRampa::OnBotonTresClickEvent()
{

	 ManejadorPantallas.MuestraPantallaRampa(ID_Rampa);

}
void CPantallaEjecucionRampa::Show()
{
	CPantallaBase::Show();
	LabelPaso->SetTexto((char*)"Paso:%d",Paso.ID_Paso);
	LabelPaso->Show();

	LabelTemperatura->SetTexto((char*)"TEMP:%d",Paso.Temperatura);
	LabelTemperatura->Show();

	LabelAire->SetTexto((char*)"AIRE:%d",Paso.NivelAire);
	LabelAire->Show();

	LabelTiempo->SetTexto((char*)"SEG:%d",Paso.Segundos);
	LabelTiempo->Show();

	LabelGuardar->Show();
	LabelCancelar->Show();

}
