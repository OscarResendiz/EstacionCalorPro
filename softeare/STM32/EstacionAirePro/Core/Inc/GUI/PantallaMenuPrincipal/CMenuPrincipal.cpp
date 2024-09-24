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
	char cadena[30];
	for(int i=1;i<10;i++)
	{
		sprintf(cadena,"Opcion %d",i);
		Menu->AgregaItem(cadena, i);
	}
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
}
void CMenuPrincipal::Refresca()
{
	if(EsVisible()==false)
		Show();
	SetVisible(true);
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
	if(MENU_SALIR==identificador)
		ManejadorPantallas.MuestraPantallaManual();
}

