/*
 * CEstacionBase.hpp
 *
 *  Created on: Jul 23, 2024
 *      Author: W10
 */

#ifndef INC_ESTACIONES_CESTACIONBASE_HPP_
#define INC_ESTACIONES_CESTACIONBASE_HPP_
#include "ManejadorControles/CManejadorEventosControles.hpp"
#include <cstddef>
class CEstacionBase
{
protected:
	CManejadorEventosControles *ManejadorControles = NULL;

public:
	CEstacionBase();
	virtual ~CEstacionBase();
	virtual float GetTemperaturaReal(); ///regresa la tenperatura actual de la estacion
	virtual void SetTemperatura(int temperatura); //establece la temperatura que se quiere alcanzar
	virtual int GetTemperatura(); // regresa la temperatura seteada
	virtual void SetNivelAire(int nivel); //establece el nivel de aire
	virtual int GetNivelAire();
	virtual int GetEstado(); //regresa 1 si esta activo y 0 si esta en reposo
	//para que la misma estacion incremente la temperatura
	virtual void IncrementaTemperatura();
	//para que la misma estacion decremente la temeperatura
	virtual void DecrementaTemperatura();
	// asigna el evento que sellamara cuando cambie la temperatura que el usuario especifica
	virtual void SetManejadorControles(CManejadorEventosControles *obj);
	virtual void QuitaManejadorControles();
	//funcion que se debera llamar para controlar la estacion de calor
	virtual void Procesa();
	virtual void ActivarCalefactor();
	virtual void DesactivarCalefactor();
	virtual void CruceXCero(int gpio_pin);
	virtual void TimerTick();
	virtual int GetPID();
	virtual void SetPID(int valor);
protected:
	virtual void NivelAireEvent(int aire);
	virtual void TemperaturaRealEvent(int temperatura);
	virtual void GPIO_INTERRUPCION(int GPIO_Pin);
};

#endif /* INC_ESTACIONES_CESTACIONBASE_HPP_ */
