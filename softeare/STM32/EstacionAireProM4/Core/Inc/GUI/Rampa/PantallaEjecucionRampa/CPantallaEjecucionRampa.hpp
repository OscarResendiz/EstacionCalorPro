/*
 * CPantallaEjecucionRampa.hpp
 *
 *  Created on: Jan 10, 2025
 *      Author: W10
 */

#ifndef INC_GUI_RAMPA_PANTALLAEJECUCIONRAMPA_CPANTALLAEJECUCIONRAMPA_HPP_
#define INC_GUI_RAMPA_PANTALLAEJECUCIONRAMPA_CPANTALLAEJECUCIONRAMPA_HPP_
#include "GUI/CPantallaBase.hpp"
#include <RapaTemperatura/CControladorPasosRampa.hpp>

class CPantallaEjecucionRampa: public CPantallaBase
{
private:
	int ID_Rampa;
	int NPasos;
	int Pasos[100];

	CPaso Paso;

	CEtiquetaTft *LabelGuardar;
	CEtiquetaTft *LabelCancelar;
	CEtiquetaTft *LabelPaso;
	CEtiquetaTft *LabelTemperatura;
	CEtiquetaTft *LabelAire;
	CEtiquetaTft *LabelTiempo;
public:
	CPantallaEjecucionRampa();
	virtual ~CPantallaEjecucionRampa();
	void SetIDRampa(int id_rampa);
	virtual void OnBotonUnoClickEvent();
	virtual void OnBotonTresClickEvent();
	virtual void Show();
};

#endif /* INC_GUI_RAMPA_PANTALLAEJECUCIONRAMPA_CPANTALLAEJECUCIONRAMPA_HPP_ */
