/*
 * CMenuPrincipal.h
 *
 *  Created on: Sep 19, 2024
 *      Author: W10
 */

#ifndef INC_GUI_PANTALLAMENUPRINCIPAL_CMENUPRINCIPAL_H_
#define INC_GUI_PANTALLAMENUPRINCIPAL_CMENUPRINCIPAL_H_
#include "GUI/CPantallaBase.hpp"
#include "Estaciones/CEstacionBase.hpp"
#include "GUI/Menu/CMenuItem.hpp"
#include "GUI/Menu/CMenu.hpp"
#include <GUI/Menu/CManejadorEventoMenu.hpp>

class CMenuPrincipal:public CPantallaBase, CManejadorEventoMenu
{
private:
	CMenu* Menu;
	CEstacionBase *Estacion;
	CMenuItem* item1,*item2;
	int MENU_SALIR=31;
public:
	CMenuPrincipal();
	virtual ~CMenuPrincipal();
	virtual void Show();
	virtual void Refresca();
	virtual void OnBotonCuatroClickEvent(int tiempoClick);
	virtual void OnPerillaIncremento();
	virtual void OnPerillaDecremento();
	virtual void OnBotonPerillaClickEvent(int tiempoClick);
	virtual void OnMenuEvent(int identificador);


};

#endif /* INC_GUI_PANTALLAMENUPRINCIPAL_CMENUPRINCIPAL_H_ */