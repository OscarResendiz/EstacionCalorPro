/*
 * CestacionVirtual.cpp
 *
 *  Created on: Jul 25, 2024
 *      Author: W10
 */

#include <Estaciones/CestacionVirtual.hpp>
#include "Calefactor/Calefactor.hpp"
#include "Constantes.hpp"

CestacionVirtual::~CestacionVirtual()
{
	// TODO Auto-generated destructor stub
}

CestacionVirtual::CestacionVirtual() :
		CEstacionBase()
{
	pwm.Init(TIM2, TIM_CHANNEL_1, 65535);

	//inicializa la termocupla
	thermocouple.SetConfigCkPin(GPIOA, GPIO_PIN_1);
	thermocouple.SetConfigCsPin(GPIOA, GPIO_PIN_2);
	thermocouple.SetConfigDatPin(GPIOA, GPIO_PIN_0);
	thermocouple.Init();

	//configuracion de los botones
	BotonMemoria1.Configurar(GPIOA, GPIO_PIN_4, 1);
	BotonMemoria1.AsignaManejadorEventos(this);
	BotonMemoria1.Init();

	BotonMemoria2.Configurar(GPIOA, GPIO_PIN_6, 2);
	BotonMemoria2.AsignaManejadorEventos(this);
	BotonMemoria2.Init();

	BotonMemoria3.Configurar(GPIOB, GPIO_PIN_10, 3);
	BotonMemoria3.AsignaManejadorEventos(this);
	BotonMemoria3.Init();

	BotonManual.Configurar(GPIOB, GPIO_PIN_15, 4);
	BotonManual.AsignaManejadorEventos(this);
	BotonManual.Init();

	Encoder.Configurar(GPIOB, GPIO_PIN_11, GPIOB, GPIO_PIN_12, GPIOB,
			GPIO_PIN_13, 1);
	Encoder.AsignaManejadorEventos(this);
	Encoder.Init();

	controlVelocidadAire.Inicializa();
	calefactor.Configurar(GPIOB, GPIO_PIN_3);
	calefactor.Init();
	sensorMagnetico.Configurar(GPIOA, GPIO_PIN_8);
	sensorMagnetico.Init();
	sensorMagnetico.AsignaManejadorEventos(this);
}

//regresa la tenperatura actual de la estacion
float CestacionVirtual::GetTemperaturaReal()
{
	float temperatura = thermocouple.MAX6675_lee(); //* .59;
	return temperatura;
}

//establece la temperatura que se quiere alcanzar
void CestacionVirtual::SetTemperatura(int temperatura)
{
	TemperaturaEspecificada = temperatura;
	TemperaturaEvent(TemperaturaEspecificada);
}

// regresa la temperatura seteada
int CestacionVirtual::GetTemperatura()
{
	return TemperaturaEspecificada;
}

//establece el nivel de aire
void CestacionVirtual::SetNivelAire(int nivel)
{
	pwm.SicloTrabajo(nivel);
}

//regresa el nivel de aire setado
int CestacionVirtual::GetNivelAire()
{
	return controlVelocidadAire.LeeVelocidad();
}

//regresa 1 si esta activo y 0 si esta en reposo
int CestacionVirtual::GetEstado()
{
	return sensorMagnetico.Leer();
}

//eventos de CManejadorEventosBoton
void CestacionVirtual::OnBotonClickEvent(int idBoton, int tiempoClick)
{
	switch (idBoton)
	{
	case BOTON_MEMORIA1:
		BotonUnoClickEvent(tiempoClick);
		break;
	case BOTON_MEMORIA2:
		BotonDosClickEvent(tiempoClick);
		break;
	case BOTON_MEMORIA3:
		BotonTresClickEvent(tiempoClick);
		break;
	case BOTON_MANUAL:
		BotonCuatroClickEvent(tiempoClick);
		break;
	}
}

void CestacionVirtual::OnBotonPresionadoEvent(int idBoton)
{
	switch (idBoton)
	{
	case BOTON_MEMORIA1:
		BotonUnoPresionadoEvent();
		break;
	case BOTON_MEMORIA2:
		BotonDosPresionadoEvent();
		break;
	case BOTON_MEMORIA3:
		BotonTresPresionadoEvent();
		break;
	case BOTON_MANUAL:
		BotonCuatroPresionadoEvent();
		break;
	}

}

void CestacionVirtual::OnBotonSueltoEvent(int idBoton)
{
	switch (idBoton)
	{
	case BOTON_MEMORIA1:
		BotonUnoSueltoEvent();
		break;
	case BOTON_MEMORIA2:
		BotonDosSueltoEvent();
		break;
	case BOTON_MEMORIA3:
		BotonTresSueltoEvent();
		break;
	case BOTON_MANUAL:
		BotonCuatroSueltoEvent();
		break;
	}
}

//eventros del encoder
void CestacionVirtual::OnIncrementoEncoder(int id_Encoder)
{
	EncoderIncremento();
}

void CestacionVirtual::OnDecrementoEncoder(int id_Encoder)
{
	EncoderDecremento();
}

void CestacionVirtual::OnBotonEncoderClickEvent(int id_Encoder, int tiempoClick)
{
	BotonPerillaClickEvent(tiempoClick);
}

void CestacionVirtual::OnBotonEncoderPresionadoEvent(int id_Encoder)
{
	BotonPerillaPresionadoEvent();
}

void CestacionVirtual::OnBotonEncoderPresionadoLargoEvent(int id_Encoder)
{
	BotonPerillaPresionadoLargoEvent();
}

void CestacionVirtual::OnBotonEncoderSueltoEvent(int id_Encoder)
{
	BotonPerillaSueltoEvent();
}

void CestacionVirtual::IncrementaTemperatura()
{
	if (TemperaturaEspecificada < TemperaturaMaxima)
	{
		TemperaturaEspecificada++;
		TemperaturaEvent(TemperaturaEspecificada);
	}
}

void CestacionVirtual::DecrementaTemperatura()
{
	if (TemperaturaEspecificada > 0)
	{
		TemperaturaEspecificada--;
		TemperaturaEvent(TemperaturaEspecificada);
	}
}

void CestacionVirtual::InterrupcionEncoder()
{
	Encoder.Procesa();
}

void CestacionVirtual::ActivarCalefactor()
{
	EstadoCalefator = ENCENDIDO;
}

void CestacionVirtual::DesactivarCalefactor()
{
	EstadoCalefator = APAGADO;
}

void CestacionVirtual::EnfriaYApagaPistola()
{
	calefactor.Apagar();
	float temperatura = GetTemperaturaReal();
	if (temperatura <= TEMPERATURA_APAGADO)
	{
		pwm.SicloTrabajo(0);
		return;
	}
	//pongo al maximo el aire para enfriar la pistola
	pwm.SicloTrabajo(100);
}

void CestacionVirtual::OnSensorMagneticoChange(int estado)
{

}

void CestacionVirtual::Procesa()
{
	ProcesaTemperatura();
	ProcesaTemperaturaReal();
	procesaAire();
	ProcesaBotones();
	ProcesaCalefactor();
}

//verifica el nivel de temperatura seleccinada por el usuario
void CestacionVirtual::ProcesaTemperatura()
{
	//leo la temperatura
	int temp = GetTemperatura();
	//veo si cambio
	if (temperaturaAnterior != temp)
	{
		temperaturaAnterior = temp;
		//aviso que cambio la temperatura
		TemperaturaEvent(temperaturaAnterior);
	}
}

void CestacionVirtual::ProcesaTemperaturaReal()
{
	int temperatura = GetTemperaturaReal();
	if (temperaturaRealAnterior != temperatura)
	{
		temperaturaRealAnterior = temperatura;
		TemperaturaRealEvent(temperaturaRealAnterior);
	}
}

//verifica elnivel de aire
void CestacionVirtual::procesaAire()
{
	int aire = GetNivelAire();
	if (AireAnterior != aire)
	{
		AireAnterior = aire;
		NivelAireEvent(AireAnterior);
	}
}

void CestacionVirtual::ProcesaBotones()
{
	BotonMemoria1.Procesa();
	BotonMemoria2.Procesa();
	BotonMemoria3.Procesa();
	BotonManual.Procesa();
}

void CestacionVirtual::ProcesaCalefactor()
{
	if (EstadoCalefator == APAGADO)
	{
		//esta apagado el calefactor
		calefactor.Apagar();
		return;
	}
	int sensor = sensorMagnetico.Leer();
	if (sensor == BOTON_PRESIONADO)
	{
		//el usuario coloco la pistola en su base por lo que hay que enfriarla
		EnfriaYApagaPistola();
		return;
	}
	float temperatura = GetTemperaturaReal();
	if (temperatura < TemperaturaEspecificada)
	{
		calefactor.Encender();
	}
	else
	{
		calefactor.Apagar();
	}
}
