/*
 * CPantallaMenuRampa.cpp
 *
 *  Created on: Oct 29, 2024
 *      Author: W10
 */

#include <GUI/Rampa/PantallaMenuRampa/CPantallaMenuRampa.hpp>
#include <GUI/ManejadorPantallas/CManejadorPantallas.hpp>
#include "GUI/Menu/CMenuItem.hpp"
#include "GUI/CEtiquetaTft.hpp"
#include "GUI/Menu/CMenu.hpp"
#include "string.h"
#include <RapaTemperatura/CControladorRampas.hpp>
#include <GUI/PantallaMenuBase/CPantallaMenuBase.hpp>

CPantallaMenuRampa::CPantallaMenuRampa():
CPantallaMenuBase((char*) " Menu Rampa")
{

}

CPantallaMenuRampa::~CPantallaMenuRampa()
{
	// TODO Auto-generated destructor stub
}
void CPantallaMenuRampa::OnBotonCuatroClickEvent()
{
	ManejadorPantallas.MuestraPantallaManual();
}
void CPantallaMenuRampa::OnMenuEvent(int identificador)
{
	switch(identificador)
	{
	case MENU_RAMPA::MENU_RAMPA_SALIR:
		ManejadorPantallas.MuestraMenuPrincipal();
		break;
//	case MENU_PRINCIPAL::MENU_MEMORIA_1:
//	case MENU_PRINCIPAL::MENU_MEMORIA_2:
//	case MENU_PRINCIPAL::MENU_MEMORIA_3:
//		ManejadorPantallas.MuestraPantallaConfiguracionMemoria(identificador);
//		break;
	case MENU_RAMPA::MENU_AGREGAR:
		ManejadorPantallas.MuestraPantallaEditorNombre(-1);
//		ManejadorPantallas.MuestraPantallaEliminarRampa(0);
		break;
	default:
		ManejadorPantallas.MuestraPantallaRampa(identificador);
	}

}

void CPantallaMenuRampa::OnBotonTresClickEvent()
{
	ManejadorPantallas.MuestraPantallaMemoria(3);
}
void CPantallaMenuRampa::OnBotonUnoClickEvent()
{
	ManejadorPantallas.MuestraPantallaMemoria(1);
}
void CPantallaMenuRampa::OnBotonDosClickEvent()
{
	ManejadorPantallas.MuestraPantallaMemoria(2);
}
void CPantallaMenuRampa::Seleccionada()
{
	this->BorraMenu();
	char texto[20];
	// TODO Auto-generated constructor stub
	int nrampas=ControladorRampas.DameNumeroRampas();
	for(int i=0;i<nrampas;i++)
	{
		CRampa rampa=ControladorRampas.DameRampaNumero(i);
		sprintf(texto,"%s",rampa.Nombre);
		AgregaMenuItem(texto, rampa.ID_RAMPA);
	}
	AgregaMenuItem((char*)"Agregar", MENU_RAMPA::MENU_AGREGAR);
	AgregaMenuItem((char*)"Salir", MENU_RAMPA::MENU_RAMPA_SALIR);
}
