/*
 * CManejadorControles.hpp
 * clase que se encarga de manejar los controles como botones, perillas, potenciometros, etc de la estacion
 *  Created on: Sep 26, 2024
 *      Author: W10
 */

#ifndef INC_MANEJADORCONTROLES_CMANEJADORCONTROLES_HPP_
#define INC_MANEJADORCONTROLES_CMANEJADORCONTROLES_HPP_
#include "Boton/CManejadorBoton.hpp"
#include "Encoder/CEncoder.hpp"
#include "ControlVelocidadAire/ControlVelocidadAire.hpp"
#include "ManejadorControles/CManejadorEventosControles.hpp"

class CManejadorControles:public CManejadorEventosBoton,CManejadorEventosEncoder
{
private:
	CManejadorEventosControles *ManejadorControles = NULL;

	CManejadorBoton BotonMemoria1;
	CManejadorBoton BotonMemoria2;
	CManejadorBoton BotonMemoria3;
	CManejadorBoton BotonManual;
	CEncoder Encoder;
	ControlVelocidadAire controlVelocidadAire;

	virtual void OnBotonEncoderSueltoEvent(int id_Encoder);
	virtual void OnBotonEncoderPresionadoLargoEvent(int id_Encoder);
	virtual void OnBotonEncoderPresionadoEvent(int id_Encoder);
	virtual void OnBotonEncoderClickEvent(int id_Encoder, int tiempoClick);
	virtual void OnDecrementoEncoder(int id_Encoder);
	virtual void OnIncrementoEncoder(int id_Encoder);
	//eventos de CManejadorEventosBoton
	virtual void OnBotonClickEvent(int idBoton, int tiempoClick);
	virtual void OnBotonPresionadoEvent(int idBoton);
	virtual void OnBotonSueltoEvent(int idBoton);

protected:
	//eventros del boton uno
	virtual void BotonUnoClickEvent(int tiempoClick);
	virtual void BotonUnoPresionadoEvent();
	virtual void BotonUnoPresionadoLargoEvent();
	virtual void BotonUnoSueltoEvent();
	//eventros del boton dos
	virtual void BotonDosClickEvent(int tiempoClick);
	virtual void BotonDosPresionadoEvent();
	virtual void BotonDosPresionaLargodoEvent();
	virtual void BotonDosSueltoEvent();
	//eventros del boton tres
	virtual void BotonTresClickEvent(int tiempoClick);
	virtual void BotonTresPresionadoEvent();
	virtual void BotonTresPresionaLargodoEvent();
	virtual void BotonTresSueltoEvent();
	//eventros del boton Cuatro
	virtual void BotonCuatroClickEvent(int tiempoClick);
	virtual void BotonCuatroPresionadoEvent();
	virtual void BotonCuatroPresionaLargodoEvent();
	virtual void BotonCuatroSueltoEvent();
	//eventros del boton Perilla
	virtual void BotonPerillaClickEvent(int tiempoClick);
	virtual void BotonPerillaPresionadoEvent();
	virtual void BotonPerillaPresionadoLargoEvent();
	virtual void BotonPerillaSueltoEvent();
	//eventos del encoder
	virtual void EncoderIncremento();
	virtual void EncoderDecremento();


public:
	CManejadorControles();
	virtual ~CManejadorControles();
	virtual void GPIO_INTERRUPCION(int GPIO_Pin);
	void ProcesaBotones(int gpio_pin);
	virtual void InterrupcionEncoder(int GPIO_Pin);
	int GetNivelAire();
	virtual void SetManejadorControles(CManejadorEventosControles *obj);
	void TimerTick();

};

#endif /* INC_MANEJADORCONTROLES_CMANEJADORCONTROLES_HPP_ */
