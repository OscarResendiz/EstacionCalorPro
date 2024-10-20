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

//#define MENU_SALIR 0
//#define MENU_MEMORIA_1 1
//#define MENU_MEMORIA_2 2
//#define MENU_MEMORIA_3 3
//#define MENU_RAMPA 4
enum MENU_PRINCIPAL
{
	MENU_SALIR=0,
	MENU_MEMORIA_1=1,
	MENU_MEMORIA_2=2,
	MENU_MEMORIA_3=3,
	MENU_RAMPA=4

};

class CMenuPrincipal:public CPantallaBase, CManejadorEventoMenu
{
private:
	CMenu* Menu;
	CEstacionBase *Estacion;
	CMenuItem* item1,*item2;

public:
	CMenuPrincipal();
	virtual ~CMenuPrincipal();
	virtual void Show();
	virtual void Refresca();
	virtual void OnBotonCuatroClickEvent();
	virtual void OnPerillaIncremento();
	virtual void OnPerillaDecremento();
	virtual void OnBotonPerillaClickEvent();
	virtual void OnMenuEvent(int identificador);

	virtual void OnBotonUnoClickEvent();
	virtual void OnBotonDosClickEvent();
	virtual void OnBotonTresClickEvent();

};

#endif /* INC_GUI_PANTALLAMENUPRINCIPAL_CMENUPRINCIPAL_H_ */
