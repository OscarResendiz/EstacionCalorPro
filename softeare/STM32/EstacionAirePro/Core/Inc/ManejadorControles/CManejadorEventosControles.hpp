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

	virtual void OnBotonUnoClickEvent(int tiempoClick);
	virtual void OnBotonUnoPresionadoEvent();
	virtual void OnBotonUnoPresionadoLargoEvent();
	virtual void OnBotonUnoSueltoEvent();

	virtual void OnBotonDosClickEvent(int tiempoClick);
	virtual void OnBotonDosPresionadoEvent();
	virtual void OnBotonDosPresionadoLargoEvent();
	virtual void OnBotonDosSueltoEvent();

	virtual void OnBotonTresClickEvent(int tiempoClick);
	virtual void OnBotonTresPresionadoEvent();
	virtual void OnBotonTresPresionadoLargoEvent();
	virtual void OnBotonTresSueltoEvent();

	virtual void OnBotonCuatroClickEvent(int tiempoClick);
	virtual void OnBotonCuatroPresionadoEvent();
	virtual void OnBotonCuatroPresionadoLargoEvent();
	virtual void OnBotonCuatroSueltoEvent();

	virtual void OnBotonPerillaClickEvent(int tiempoClick);
	virtual void OnBotonPerillaPresionadoEvent();
	virtual void OnBotonPerillaPresionadoLargoEvent();
	virtual void OnBotonPerillaSueltoEvent();

	virtual void OnPerillaIncremento();
	virtual void OnPerillaDecremento();
};

#endif /* INC_MANEJADORCONTROLES_CMANEJADORCONTROLESBASE_HPP_ */
