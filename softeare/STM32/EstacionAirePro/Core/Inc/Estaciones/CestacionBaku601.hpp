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
#include "Max6675/MAX6675.hpp"
#include "PWM/Pwm.hpp"
#include "Calefactor/Calefactor.hpp"
#include <SensorMagnetico/SensorMagnetico.hpp>


class CestacionBaku601: public CEstacionBase,CManejadorEventoSensorMagnetico
{
private:
	int TemperaturaMaxima = 500;
	int TemperaturaEspecificada = 100;
	int temperaturaAnterior = 0;
	int temperaturaRealAnterior = 0;
	int AireAnterior = 0;
	double TiempoEnfriando=0;
	int PotenciaCalefactor=5;
	int TiempoCalefactorEncendido=0;
	//variables para el calculo del PID
	int TiempoMuestreoTemperatura=500; //por defualt hace el muestreo de temperatura cada segundo
	int TiempoActual=0;
	int TiempoProximoMuestreo=0;
	float PID_error;
	float Error_INT=0;
	float PID_value = 0;
	// Constantes de PID
	float Kc = 5;
	float Tao_I =600;//500; //80;
	int TiempoAntiReboresCruceXCero=1;
	int ciclos=0;
protected:
	int CONFIG_TCSCK_PIN = 8;
	int CONFIG_TCCS_PIN = 11;
	int CONFIG_TCDO_PIN = 12;
	int EstadoCalefator=APAGADO;
// OBJETO UTILIZADO PARA LA COMUNICACION CON EL MAX6675
	MAX6675 thermocouple;
	Pwm pwm;
	Calefactor calefactor;
	SensorMagnetico sensorMagnetico;
	int NivelAire=0;
public:
	CestacionBaku601();
	virtual ~CestacionBaku601();
	//regresa la tenperatura actual de la estacion
	virtual float GetTemperaturaReal();
	//establece la temperatura que se quiere alcanzar
	virtual void SetTemperatura(int temperatura);
	// regresa la temperatura seteada
	virtual int GetTemperatura();
	//establece el nivel de aire
	virtual void SetNivelAire(int nivel);
	//regresa 1 si esta activo y 0 si esta en reposo
	virtual int GetEstado();
	virtual void Procesa();
	virtual void ActivarCalefactor();
	virtual void DesactivarCalefactor();
	virtual void CruceXCero(int gpio_pin);
	virtual void TimerTick();
	virtual int GetPID();
	virtual void SetPID(int valor);
	virtual void GPIO_INTERRUPCION(int GPIO_Pin);
private:
	//verifica el nivel de temperatura seleccinada por el usuario
	void ProcesaTemperatura();
	//verifica elnivel de aire
	void procesaAire();
	void ProcesaTemperaturaReal();
	//eventros del encoder
	virtual void IncrementaTemperatura();
	virtual void DecrementaTemperatura();
	void ProcesaCalefactor();
	virtual void OnSensorMagneticoChange(int estado);
	void EnfriaYApagaPistola();
};

#endif /* INC_ESTACIONES_CESTACIONVIRTUAL_HPP_ */
