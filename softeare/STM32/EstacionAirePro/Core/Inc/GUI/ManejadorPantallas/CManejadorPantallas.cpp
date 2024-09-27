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
#include <GUI/ConfigurarPantallaMemoria/CConfigurarPantallaMemoria.hpp>

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

void CManejadorPantallas::RefrescaPantalla()
{
	if(CambioPantalla==true)
		PantallaActual->Show();
	PantallaActual->Refresca();
	CambioPantalla=false;
}
void CManejadorPantallas::AsignaPantallaActual(CPantallaBase* pantalla)
{
	if(PantallaActual!=NULL)
		PantallaActual->Ocultar();
	PantallaActual=pantalla;
	PantallaActual->SetEstacion(Estacion);
	PantallaActual->SetManejadorControles(ManejadorControles);
	CambioPantalla=true;
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
