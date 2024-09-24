/*
 * CEstacionBase.hpp
 *
 *  Created on: Jul 23, 2024
 *      Author: W10
 */

#ifndef INC_ESTACIONES_CESTACIONBASE_HPP_
#define INC_ESTACIONES_CESTACIONBASE_HPP_
#include "ManejadorControles/CManejadorControlesBase.hpp"
#include <cstddef>
class CEstacionBase
{
protected:
	CManejadorControlesBase *ManejadorControles = NULL;

public:
	CEstacionBase();
	virtual ~CEstacionBase();
	virtual float GetTemperaturaReal(); ///regresa la tenperatura actual de la estacion
	virtual void SetTemperatura(int temperatura); //establece la temperatura que se quiere alcanzar
	virtual int GetTemperatura(); // regresa la temperatura seteada
	virtual void SetNivelAire(int nivel); //establece el nivel de aire
	virtual int GetNivelAire(); //regresa el nivel de aire setado
	virtual int GetEstado(); //regresa 1 si esta activo y 0 si esta en reposo
	//para que la misma estacion incremente la temperatura
	virtual void IncrementaTemperatura();
	//para que la misma estacion decremente la temeperatura
	virtual void DecrementaTemperatura();
	// asigna el evento que sellamara cuando cambie la temperatura que el usuario especifica
	virtual void SetManejadorControles(CManejadorControlesBase *obj);
	virtual void QuitaManejadorControles();
	//funcion que se debera llamar para controlar la estacion de calor
	virtual void Procesa();
	virtual void InterrupcionEncoder();
	virtual void ActivarCalefactor();
	virtual void DesactivarCalefactor();
	virtual void CruceXCero(int gpio_pin);
	virtual void TimerTick();
	virtual int GetPID();
	virtual void SetPID(int valor);
protected:
	virtual void NivelAireEvent(int aire);
	virtual void TemperaturaRealEvent(int temperatura);
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
	virtual void GPIO_INTERRUPCION(int GPIO_Pin);
};

#endif /* INC_ESTACIONES_CESTACIONBASE_HPP_ */
