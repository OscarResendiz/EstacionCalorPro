/*
 * CPantallaPasosRampa.hpp
 *
 *  Created on: Jan 6, 2025
 *      Author: W10
 */

#ifndef INC_GUI_RAMPA_PANTALLAPASOSRAMPA_CPANTALLAPASOSRAMPA_HPP_
#define INC_GUI_RAMPA_PANTALLAPASOSRAMPA_CPANTALLAPASOSRAMPA_HPP_
#include "GUI/CPantallaBase.hpp"
#include "Estaciones/CEstacionBase.hpp"
#include "GUI/Menu/CMenuItem.hpp"
#include "GUI/Menu/CMenu.hpp"
#include <GUI/Menu/CManejadorEventoMenu.hpp>
#include <GUI/PantallaMenuBase/CPantallaMenuBase.hpp>
enum MENU_PASO
{
	MENU_PASO_AGREGAR=-1,
	MENU_PASO_SALIR=-2
};

class CPantallaPasosRampa:public CPantallaMenuBase
{
private:
	CEstacionBase *Estacion;
	CMenuItem* item1,*item2;
	int ID_Rampa;
public:
	CPantallaPasosRampa(int id_Rampa);
	virtual ~CPantallaPasosRampa();
	virtual void OnMenuEvent(int identificador);
	virtual void SetIDRampa(int idRampa);
};

#endif /* INC_GUI_RAMPA_PANTALLAPASOSRAMPA_CPANTALLAPASOSRAMPA_HPP_ */
