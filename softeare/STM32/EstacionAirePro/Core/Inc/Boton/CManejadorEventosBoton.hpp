/*
 * EventosBoton.hpp
 *
 *  Created on: Jul 19, 2024
 *      Author: W10
 */

#ifndef EVENTOSBOTON_HPP_
#define EVENTOSBOTON_HPP_

class CManejadorEventosBoton
{
public:
	CManejadorEventosBoton();
	virtual ~CManejadorEventosBoton();
	virtual void OnBotonClickEvent(int idBoton, int tiempoClick);
	virtual void OnBotonPresionadoEvent(int idBoton);
	virtual void OnBotonSueltoEvent(int idBoton);
	virtual void OnBotonPresionadoLargoEvent(int idBoton);
};

#endif /* EVENTOSBOTON_HPP_ */
