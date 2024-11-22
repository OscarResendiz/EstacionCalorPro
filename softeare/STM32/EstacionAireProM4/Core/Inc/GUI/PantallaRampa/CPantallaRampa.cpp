/*
 * PantallaRampa.cpp
 *
 *  Created on: Oct 30, 2024
 *      Author: W10
 */

#include <GUI/PantallaRampa/CPantallaRampa.hpp>
#include <RapaTemperatura/CRampa.hpp>
#include <RapaTemperatura/CControladorRampas.hpp>
#include "GUI/Menu/CMenuItem.hpp"
#include <GUI/PantallaMenuBase/CPantallaMenuBase.hpp>

CPantallaRampa::CPantallaRampa():
	CPantallaMenuBase((char*) " Rampa")
{
	// TODO Auto-generated constructor stub
	AgregaMenuItem((char*)"Ejecutar", EJECUTAR);
	AgregaMenuItem((char*)"Modificar",MODIFICAR);
	AgregaMenuItem((char*)"Eliminar", ELIMINAR);
	AgregaMenuItem((char*)"Salir", SALIR);

}

CPantallaRampa::~CPantallaRampa()
{
	// TODO Auto-generated destructor stub
}

void CPantallaRampa::SetNumeroRampa(int nrampa)
{
	NumeroRampa=nrampa;
	this->LabelTitulo->SetTexto((char*)"Rampa: %d",NumeroRampa);
}
void CPantallaRampa::OnMenuEvent(int identificador)
{
	/*
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
		ManejadorPantallas.MuestraCPantallaCalibracion();
		break;
	default:
		ManejadorPantallas.MuestraPantallaRampa(identificador);
	}
*/
}
