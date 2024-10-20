/*
 * CManejadorControlesBase.hpp
 *
 *  Created on: Jul 19, 2024
 *      Author: W10
 */

#ifndef INC_MANEJADORCONTROLES_CMANEJADORCONTROLESBASE_HPP_
#define INC_MANEJADORCONTROLES_CMANEJADORCONTROLESBASE_HPP_

class CManejadorEventosControles
{
public:
	CManejadorEventosControles();
	virtual ~CManejadorEventosControles();

	virtual void OnTemperaturaRealEvent(int temperatura);

	virtual void OnNivelAireEvent(int aire);

	virtual void OnBotonUnoClickEvent();

	virtual void OnBotonDosClickEvent();

	virtual void OnBotonTresClickEvent();

	virtual void OnBotonCuatroClickEvent();

	virtual void OnBotonPerillaClickEvent();

	virtual void OnPerillaIncremento();
	virtual void OnPerillaDecremento();
};

#endif /* INC_MANEJADORCONTROLES_CMANEJADORCONTROLESBASE_HPP_ */
