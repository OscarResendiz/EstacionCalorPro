/*
 * CPantallaInicializaMemoria.hpp
 *
 *  Created on: Oct 31, 2024
 *      Author: W10
 */

#ifndef INC_GUI_PANTALLAINICIALIZAMEMORIA_CPANTALLAINICIALIZAMEMORIA_HPP_
#define INC_GUI_PANTALLAINICIALIZAMEMORIA_CPANTALLAINICIALIZAMEMORIA_HPP_
#include "GUI/CPantallaBase.hpp"
#include "ManejadorControles/CManejadorEventosControles.hpp"
#include "Estaciones/CEstacionBase.hpp"
#include <GUI/CBarraProgreso.hpp>
#include <RapaTemperatura/CControlProgreso.hpp>

class CPantallaInicializaMemoria: public CPantallaBase,CControlProgreso
{
private:
	CBarraProgreso *BarraProgreso;
public:
	CPantallaInicializaMemoria();
	virtual ~CPantallaInicializaMemoria();
	virtual void Show();
	virtual void OnProgreso(int valor, int maximo);
//	virtual void OnMensaje(char *texto);
	virtual void OnFinProgreso();
	virtual void Refresca();

};

#endif /* INC_GUI_PANTALLAINICIALIZAMEMORIA_CPANTALLAINICIALIZAMEMORIA_HPP_ */
