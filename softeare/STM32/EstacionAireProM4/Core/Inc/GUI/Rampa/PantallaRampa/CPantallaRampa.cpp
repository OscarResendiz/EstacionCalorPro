/*
 * PantallaRampa.cpp
 *
 *  Created on: Oct 30, 2024
 *      Author: W10
 */

#include <GUI/Rampa/PantallaRampa/CPantallaRampa.hpp>
#include <RapaTemperatura/CRampa.hpp>
#include <RapaTemperatura/CControladorRampas.hpp>
#include "GUI/Menu/CMenuItem.hpp"
#include <GUI/PantallaMenuBase/CPantallaMenuBase.hpp>
#include <GUI/ManejadorPantallas/CManejadorPantallas.hpp>

CPantallaRampa::CPantallaRampa():
	CPantallaMenuBase((char*) " Rampa")
{
	// TODO Auto-generated constructor stub
	AgregaMenuItem((char*)"Ejecutar", MENU_PANTALLA_RAMPA::PANTALLA_RAMPA_EJECUTAR);
	AgregaMenuItem((char*)"Modificar",MENU_PANTALLA_RAMPA::PANTALLA_RAMPA_MODIFICAR);
	AgregaMenuItem((char*)"EDITAR PASOS",MENU_PANTALLA_RAMPA::PANTALLA_RAMPA_PASOS);
	AgregaMenuItem((char*)"Eliminar", MENU_PANTALLA_RAMPA::PANTALLA_RAMPA_ELIMINAR);
	AgregaMenuItem((char*)"Salir", MENU_PANTALLA_RAMPA::PANTALLA_RAMPA_SALIR);

}

CPantallaRampa::~CPantallaRampa()
{
	// TODO Auto-generated destructor stub
}

void CPantallaRampa::SetNumeroRampa(int id_Rampa)
{
	ID_Rampa=id_Rampa;
	CRampa rampa=ControladorRampas.DameRampa(ID_Rampa);
	this->SetTituloPantalla(rampa.Nombre);
}
void CPantallaRampa::OnMenuEvent(int identificador)
{

	switch(identificador)
	{
	case MENU_PANTALLA_RAMPA::PANTALLA_RAMPA_SALIR:
		ManejadorPantallas.MuestraMenuRampa();
		break;
	case MENU_PANTALLA_RAMPA::PANTALLA_RAMPA_MODIFICAR:
		ManejadorPantallas.MuestraPantallaEditorNombre(ID_Rampa);
		break;
	case MENU_PANTALLA_RAMPA::PANTALLA_RAMPA_ELIMINAR:
		ManejadorPantallas.MuestraPantallaEliminarRampa(ID_Rampa);
		break;
	case MENU_PANTALLA_RAMPA::PANTALLA_RAMPA_PASOS:
		ManejadorPantallas.AsignaPantallaPasosRampa(ID_Rampa);
		break;
	case MENU_PANTALLA_RAMPA::PANTALLA_RAMPA_EJECUTAR:
		ManejadorPantallas.MuestraPantallaEjecucionRampa(ID_Rampa);
		break;
	}

}
