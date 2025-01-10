/*
 * ManejadorPantallas.cpp
 * clase que se encarga de controlar el manejo de las pantallas
 *  Created on: Sep 19, 2024
 *      Author: W10
 */

#include <GUI/ManejadorPantallas/CManejadorPantallas.hpp>
#include "GUI/PantallaManual/CPantallaManual.hpp"
#include <GUI/PantallaMenuPrincipal/CMenuPrincipal.h>
#include <stdio.h>
#include<string.h>
#include <GUI/ConfigurarPantallaMemoria/CConfigurarPantallaMemoria.hpp>
#include <GUI/Rampa/PantallaEditorNombre/CPantallaEditorNombre.hpp>
#include <GUI/Rampa/PantallaEliminarRampa/CPantallaEliminarRampa.hpp>

CManejadorPantallas::CManejadorPantallas()
{
	// TODO Auto-generated constructor stub
}

CManejadorPantallas::~CManejadorPantallas()
{
	// TODO Auto-generated destructor stub
}
void CManejadorPantallas::SetEstacion(CEstacionBase* estacion)
{
	Estacion=estacion;
}
void CManejadorPantallas::MuestraPantallaManual()
{
	if(pantallaManual==NULL)
		pantallaManual=new CPantallaManual();
	AsignaPantallaActual(pantallaManual);
}
void CManejadorPantallas::MuestraMenuPrincipal()
{
	if(menuPrincipal==NULL)
		menuPrincipal=new CMenuPrincipal();
	AsignaPantallaActual(menuPrincipal);
}

void CManejadorPantallas::MuestraMenuRampa()
{
	if(menuRampa==NULL)
		menuRampa=new CPantallaMenuRampa();
	AsignaPantallaActual(menuRampa);
}
void CManejadorPantallas::RefrescaPantalla()
{
	CambiaPantalla();
	PantallaActual->Refresca();
}
void CManejadorPantallas::AsignaPantallaActual(CPantallaBase* pantalla)
{
	PantallaPendinteCambiar=pantalla;
	CambioPantalla=true;
	PantallaPendinteCambiar->Seleccionada();
}
void CManejadorPantallas::CambiaPantalla()
{
	if(	CambioPantalla==false)
		return;
	if(PantallaActual!=NULL)
	{
		PantallaActual->Ocultar();
		PantallaAnterior=PantallaActual;
	}
	PantallaActual=PantallaPendinteCambiar;
	PantallaActual->SetEstacion(Estacion);
	PantallaActual->SetManejadorControles(ManejadorControles);
	PantallaActual->Show();
	CambioPantalla=false;
}

void CManejadorPantallas::SetManejadorControles(CManejadorControles* manejador)
{
	ManejadorControles=manejador;
}

void CManejadorPantallas::MuestraPantallaConfiguracionMemoria(int meoria)
{
	if(ConfigurarPantallaMemoria==NULL)
		ConfigurarPantallaMemoria=new CConfigurarPantallaMemoria();
	ConfigurarPantallaMemoria->SetMemoria(meoria);
	AsignaPantallaActual(ConfigurarPantallaMemoria);
}
void CManejadorPantallas::MuestraPantallaMemoria(int memoria)
{
	if(PantallaMemoria==NULL)
		PantallaMemoria=new CPantallaMemoria();
	PantallaMemoria->SetMemoria(memoria);
	AsignaPantallaActual(PantallaMemoria);

}
void CManejadorPantallas::MuestraPantallaAnterior()
{
	if(PantallaAnterior==NULL)
		return;
	AsignaPantallaActual(PantallaAnterior);
}
void CManejadorPantallas::MuestraCPantallaCalibracion()
{
	if(PantallaCalibracion==NULL)
		PantallaCalibracion=new CPantallaCalibracion();
	AsignaPantallaActual(PantallaCalibracion);
}
void CManejadorPantallas::MuestraPantallaRampa(int nrampa)
{
	if(PantallaRampa==NULL)
		PantallaRampa=new CPantallaRampa();
	PantallaRampa->SetNumeroRampa(nrampa);
	AsignaPantallaActual(PantallaRampa);

}
void CManejadorPantallas::MuestraPantallaInicializaMemoria()
{
	if(PantallaInicializaMemoria==NULL)
		PantallaInicializaMemoria=new CPantallaInicializaMemoria();
	AsignaPantallaActual(PantallaInicializaMemoria);
}
void CManejadorPantallas::MuestraPantallaEditorNombre(int id_Rampa)
{
	if(PantallaEditorNombre==NULL)
		PantallaEditorNombre=new CPantallaEditorNombre(id_Rampa);
	PantallaEditorNombre->AsignaID(id_Rampa);
	AsignaPantallaActual(PantallaEditorNombre);
}
void CManejadorPantallas::AsignaPantallaPasosRampa(int id_rampa)
{
	if(PantallaPasosRampa==NULL)
		PantallaPasosRampa=new CPantallaPasosRampa(id_rampa);
	PantallaPasosRampa->SetIDRampa(id_rampa);
	AsignaPantallaActual(PantallaPasosRampa);

}
void CManejadorPantallas::MuestraPantallaEliminarRampa(int id_rampa)
{
	if(PantallaEliminarRampa==NULL)
		PantallaEliminarRampa=new CPantallaEliminarRampa();
	PantallaEliminarRampa->SetIdRampa(id_rampa);
	AsignaPantallaActual(PantallaEliminarRampa);

}
void CManejadorPantallas::MuestraPantallaEdicionPaso(int id_rampa,int id_paso)
{
	if(PantallaEdicionPaso==NULL)
		PantallaEdicionPaso=new CPantallaEdicionPaso();
	PantallaEdicionPaso->SetIdPaso(id_rampa,id_paso);
	AsignaPantallaActual(PantallaEdicionPaso);
}
void CManejadorPantallas::MuestraPantallaPaso(int id_rampa,int id_paso)
{
	if(PantallaPaso==NULL)
		PantallaPaso=new CPantallaPaso();
	PantallaPaso->SetIdPaso(id_rampa,id_paso);
	AsignaPantallaActual(PantallaPaso);
}
void CManejadorPantallas::MuestraPantallaEliminarPaso(int id_rampa,int id_paso)
{
	if(PantallaEliminarPaso==NULL)
		PantallaEliminarPaso=new CPantallaEliminarPaso();
	PantallaEliminarPaso->SetIdPaso(id_rampa,id_paso);
	AsignaPantallaActual(PantallaEliminarPaso);
}
void CManejadorPantallas::MuestraPantallaEjecucionRampa(int id_rampa)
{
	if(PantallaEjecucionRampa==NULL)
		PantallaEjecucionRampa=new CPantallaEjecucionRampa();
	PantallaEjecucionRampa->SetIDRampa(id_rampa);
	AsignaPantallaActual(PantallaEjecucionRampa);
}
