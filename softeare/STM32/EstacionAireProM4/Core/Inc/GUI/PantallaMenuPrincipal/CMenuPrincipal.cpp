/*
 * CMenuPrincipal.cpp
 *
 *  Created on: Sep 19, 2024
 *      Author: W10
 */

#include <GUI/PantallaMenuPrincipal/CMenuPrincipal.h>
#include <GUI/ManejadorPantallas/CManejadorPantallas.hpp>
#include "GUI/Menu/CMenuItem.hpp"
#include "GUI/CEtiquetaTft.hpp"
#include "GUI/Menu/CMenu.hpp"
#include "string.h"

CMenuPrincipal::CMenuPrincipal():
	CPantallaMenuBase((char*) " Menu Principal")
{
	AgregaMenuItem((char*)"Conf Memoria 1", MENU_PRINCIPAL::MENU_MEMORIA_1);
	AgregaMenuItem((char*)"Conf Memoria 2",(int)MENU_PRINCIPAL::MENU_MEMORIA_2);
	AgregaMenuItem((char*)"Conf Memoria 3", (int)MENU_PRINCIPAL::MENU_MEMORIA_3);
	AgregaMenuItem((char*)"Calibrar", (int)MENU_PRINCIPAL::MENU_CALIBRAR);
	AgregaMenuItem((char*)"Rampa", (int)MENU_PRINCIPAL::MENU_RAMPA);
	AgregaMenuItem((char*)"Salir", MENU_SALIR);
}

CMenuPrincipal::~CMenuPrincipal()
{
	// TODO Auto-generated destructor stub
}
void CMenuPrincipal::OnMenuEvent(int identificador)
{
	switch(identificador)
	{
	case MENU_PRINCIPAL::MENU_SALIR:
		ManejadorPantallas.MuestraPantallaManual();
		break;
	case MENU_PRINCIPAL::MENU_MEMORIA_1:
	case MENU_PRINCIPAL::MENU_MEMORIA_2:
	case MENU_PRINCIPAL::MENU_MEMORIA_3:
		ManejadorPantallas.MuestraPantallaConfiguracionMemoria(identificador);
		break;
	case MENU_PRINCIPAL::MENU_CALIBRAR:
		ManejadorPantallas.MuestraCPantallaCalibracion();
		break;
	case MENU_PRINCIPAL::MENU_RAMPA:
		ManejadorPantallas.MuestraMenuRampa();
		break;
	}

}

void CMenuPrincipal::OnBotonTresClickEvent()
{
	ManejadorPantallas.MuestraPantallaMemoria(3);
}
void CMenuPrincipal::OnBotonUnoClickEvent()
{
	ManejadorPantallas.MuestraPantallaMemoria(1);
}
void CMenuPrincipal::OnBotonDosClickEvent()
{
	ManejadorPantallas.MuestraPantallaMemoria(2);
}
void CMenuPrincipal::OnBotonCuatroClickEvent()
{
	ManejadorPantallas.MuestraPantallaManual();
}
