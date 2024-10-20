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
	virtual void OnBotonClickEvent(int idBoton);
};

#endif /* EVENTOSBOTON_HPP_ */
