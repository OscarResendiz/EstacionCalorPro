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

class CPantallaRampa:public CPantallaMenuBase
{
private:
	int const EJECUTAR=1;
	int const MODIFICAR=2;
	int const ELIMINAR=3;
	int const SALIR=4;
	int NumeroRampa;
public:
	CPantallaRampa();
	virtual ~CPantallaRampa();
	void SetNumeroRampa(int nrampa);
	virtual void OnMenuEvent(int identificador);
};

#endif /* INC_GUI_PANTALLARAMPA_HPP_ */
