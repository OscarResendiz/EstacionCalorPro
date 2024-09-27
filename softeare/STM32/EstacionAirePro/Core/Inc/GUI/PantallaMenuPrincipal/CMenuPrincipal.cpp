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
	CPantallaBase(1, " Menu Principal")
{
	Menu=new CMenu(4,30,310, 210,COLOR::WHITE,1, COLOR::RED);
	Menu->AsignaManejadorEventosMenu(this);
	Menu->AsignaColoresItems(COLOR::BLACK, 0X776F, COLOR::WHITE, COLOR::BLACK);

	Menu->AgregaItem("Conf Memoria 1", MENU_MEMORIA_1);
	Menu->AgregaItem("Conf Memoria 2", MENU_MEMORIA_2);
	Menu->AgregaItem("Conf Memoria 3", MENU_MEMORIA_3);
	Menu->AgregaItem("Salir", MENU_SALIR);
}

CMenuPrincipal::~CMenuPrincipal()
{
	// TODO Auto-generated destructor stub
}

void CMenuPrincipal::Show()
{
	CPantallaBase::Show();
	Menu->Show();
	SetVisible(true);
}
void CMenuPrincipal::Refresca()
{
	if(EsVisible()==false)
		Show();
}
void CMenuPrincipal::OnBotonCuatroClickEvent(int tiempoClick)
{
	ManejadorPantallas.MuestraPantallaManual();
}
void CMenuPrincipal::OnPerillaIncremento()
{
	Menu->OnSeleccionaSiguiente();
}
void CMenuPrincipal::OnPerillaDecremento()
{
	Menu->OnSeleccionaAnterior();
}
void CMenuPrincipal::OnBotonPerillaClickEvent(int tiempoClick)
{
	Menu->OnClickSeleccionado();
}
void CMenuPrincipal::OnMenuEvent(int identificador)
{
	switch(identificador)
	{
	case MENU_SALIR:
		ManejadorPantallas.MuestraPantallaManual();
		break;
	case MENU_MEMORIA_1:
	case MENU_MEMORIA_2:
	case MENU_MEMORIA_3:
		ManejadorPantallas.MuestraPantallaConfiguracionMemoria(identificador);
		break;
	}

}

