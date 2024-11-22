/*
 * CPantallaMenuRampa.hpp
 *
 *  Created on: Oct 29, 2024
 *      Author: W10
 */

#ifndef INC_GUI_PANTALLAMENURAMPA_CPANTALLAMENURAMPA_HPP_
#define INC_GUI_PANTALLAMENURAMPA_CPANTALLAMENURAMPA_HPP_

#include "GUI/CPantallaBase.hpp"
#include "Estaciones/CEstacionBase.hpp"
#include "GUI/Menu/CMenuItem.hpp"
#include "GUI/Menu/CMenu.hpp"
#include <GUI/Menu/CManejadorEventoMenu.hpp>
#include <GUI/PantallaMenuBase/CPantallaMenuBase.hpp>

enum MENU_RAMPA
{
	MENU_AGREGAR=-1,
	MENU_RAMPA_SALIR=-2
};
class CPantallaMenuRampa:public CPantallaMenuBase
{
private:
	CEstacionBase *Estacion;
	CMenuItem* item1,*item2;
public:
	CPantallaMenuRampa();
	virtual ~CPantallaMenuRampa();
	virtual void OnBotonCuatroClickEvent();
	virtual void OnMenuEvent(int identificador);

	virtual void OnBotonUnoClickEvent();
	virtual void OnBotonDosClickEvent();
	virtual void OnBotonTresClickEvent();
};

#endif /* INC_GUI_PANTALLAMENURAMPA_CPANTALLAMENURAMPA_HPP_ */
