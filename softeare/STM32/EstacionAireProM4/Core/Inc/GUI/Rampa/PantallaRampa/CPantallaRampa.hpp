/*
 * PantallaRampa.hpp
 *
 *  Created on: Oct 30, 2024
 *      Author: W10
 */

#ifndef INC_GUI_PANTALLARAMPA_HPP_
#define INC_GUI_PANTALLARAMPA_HPP_
#include <RapaTemperatura/CRampa.hpp>
#include <RapaTemperatura/CControladorRampas.hpp>
#include "GUI/CPantallaBase.hpp"
#include <GUI/Menu/CManejadorEventoMenu.hpp>
#include "GUI/Menu/CMenuItem.hpp"
#include "GUI/Menu/CMenu.hpp"
#include <GUI/PantallaMenuBase/CPantallaMenuBase.hpp>

enum MENU_PANTALLA_RAMPA
{
	PANTALLA_RAMPA_EJECUTAR,
	PANTALLA_RAMPA_MODIFICAR,
	PANTALLA_RAMPA_ELIMINAR,
	PANTALLA_RAMPA_SALIR,
	PANTALLA_RAMPA_PASOS
};
class CPantallaRampa:public CPantallaMenuBase
{
private:
	int ID_Rampa;
public:
	CPantallaRampa();
	virtual ~CPantallaRampa();
	void SetNumeroRampa(int id_Rampa);
	virtual void OnMenuEvent(int identificador);
};

#endif /* INC_GUI_PANTALLARAMPA_HPP_ */
