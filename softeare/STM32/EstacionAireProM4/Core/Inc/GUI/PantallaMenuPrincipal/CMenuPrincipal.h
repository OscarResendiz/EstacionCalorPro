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
#include <GUI/PantallaMenuBase/CPantallaMenuBase.hpp>

enum MENU_PRINCIPAL
{
	MENU_SALIR=0,
	MENU_MEMORIA_1=1,
	MENU_MEMORIA_2=2,
	MENU_MEMORIA_3=3,
	MENU_RAMPA=4,
	MENU_CALIBRAR=5

};

class CMenuPrincipal:public CPantallaMenuBase
{
private:
	CEstacionBase *Estacion;
	CMenuItem* item1,*item2;

public:
	CMenuPrincipal();
	virtual ~CMenuPrincipal();
	virtual void OnBotonCuatroClickEvent();
	virtual void OnMenuEvent(int identificador);

	virtual void OnBotonUnoClickEvent();
	virtual void OnBotonDosClickEvent();
	virtual void OnBotonTresClickEvent();

};

#endif /* INC_GUI_PANTALLAMENUPRINCIPAL_CMENUPRINCIPAL_H_ */
