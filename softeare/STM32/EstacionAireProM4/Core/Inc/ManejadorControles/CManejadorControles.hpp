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

	virtual void OnBotonEncoderClickEvent(int id_Encoder);
	virtual void OnDecrementoEncoder(int id_Encoder);
	virtual void OnIncrementoEncoder(int id_Encoder);
	//eventos de CManejadorEventosBoton
	virtual void OnBotonClickEvent(int idBoton);

protected:
	//eventros del boton uno
	virtual void BotonUnoClickEvent();
	//eventros del boton dos
	virtual void BotonDosClickEvent();
	//eventros del boton tres
	virtual void BotonTresClickEvent();
	//eventros del boton Cuatro
	virtual void BotonCuatroClickEvent();
	//eventros del boton Perilla
	virtual void BotonPerillaClickEvent();
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
