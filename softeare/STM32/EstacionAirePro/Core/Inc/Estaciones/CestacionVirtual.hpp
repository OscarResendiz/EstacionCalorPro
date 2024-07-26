/*
 * CestacionVirtual.hpp
 *
 *  Created on: Jul 25, 2024
 *      Author: W10
 */

#ifndef INC_ESTACIONES_CESTACIONVIRTUAL_HPP_
#define INC_ESTACIONES_CESTACIONVIRTUAL_HPP_
#include "Estaciones/CEstacionBase.hpp"
#include "Boton/CManejadorEventosBoton.hpp"
#include "Encoder/CManejadorEventosEncoder.hpp"
#include "Boton/CManejadorBoton.hpp"
#include "Max6675/MAX6675.hpp"
#include "Encoder/CEncoder.hpp"
#include "ControlVelocidadAire/ControlVelocidadAire.hpp"

class CestacionVirtual: public CEstacionBase,CManejadorEventosBoton,CManejadorEventosEncoder
{
private:
	int TemperaturaMaxima = 500;
	int TemperaturaEspecificada = 100;
	int temperaturaAnterior = 0;
	int temperaturaRealAnterior = 0;
	int AireAnterior = 0;
protected:
	int CONFIG_TCSCK_PIN = 8;
	int CONFIG_TCCS_PIN = 11;
	int CONFIG_TCDO_PIN = 12;
// OBJETO UTILIZADO PARA LA COMUNICACION CON EL MAX6675
	MAX6675 thermocouple;
	CManejadorBoton BotonMemoria1;
	CManejadorBoton BotonMemoria2;
	CManejadorBoton BotonMemoria3;
	CManejadorBoton BotonManual;
	CEncoder Encoder;
	ControlVelocidadAire controlVelocidadAire;
public:
	CestacionVirtual();
	virtual ~CestacionVirtual();
	//regresa la tenperatura actual de la estacion
	virtual float GetTemperaturaReal();
	//establece la temperatura que se quiere alcanzar
	virtual void SetTemperatura(int temperatura);
	// regresa la temperatura seteada
	virtual int GetTemperatura();
	//establece el nivel de aire
	virtual void SetNivelAire(int nivel);
	//regresa el nivel de aire setado
	virtual int GetNivelAire();
	//regresa 1 si esta activo y 0 si esta en reposo
	virtual int GetEstado();
	virtual void Procesa();
private:
	//verifica el nivel de temperatura seleccinada por el usuario
	void ProcesaTemperatura();
	//verifica elnivel de aire
	void procesaAire();
	void ProcesaTemperaturaReal();
	void ProcesaBotones();
	//eventos de CManejadorEventosBoton
	virtual void OnBotonClickEvent(int idBoton, int tiempoClick);
	virtual void OnBotonPresionadoEvent(int idBoton);
	virtual void OnBotonSueltoEvent(int idBoton);
	//eventros del encoder
	virtual void OnIncrementoEncoder(int id_Encoder);
	virtual void OnDecrementoEncoder(int id_Encoder);
	virtual void OnBotonEncoderClickEvent(int id_Encoder, int tiempoClick);
	virtual void OnBotonEncoderPresionadoEvent(int id_Encoder);
	virtual void OnBotonEncoderPresionadoLargoEvent(int id_Encoder);
	virtual void OnBotonEncoderSueltoEvent(int id_Encoder);
	virtual void IncrementaTemperatura();
	virtual void DecrementaTemperatura();
};

#endif /* INC_ESTACIONES_CESTACIONVIRTUAL_HPP_ */
