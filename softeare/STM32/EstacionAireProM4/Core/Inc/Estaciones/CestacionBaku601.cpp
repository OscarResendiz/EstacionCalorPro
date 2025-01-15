/*
 * CestacionVirtual.cpp
 *
 *  Created on: Jul 25, 2024
 *      Author: W10
 */

#include <Estaciones/CestacionBaku601.hpp>
#include "Calefactor/Calefactor.hpp"
#include "Constantes.hpp"
#include "Uart/Uart.hpp"
#include "SensorTemperatura/Max6675/MAX6675.hpp"
#include <SensorTemperatura/SensorAnalogico.hpp>

CestacionBaku601::~CestacionBaku601()
{
	// TODO Auto-generated destructor stub
}

void CestacionBaku601::IniciaMax6675()
{
	MAX6675 *max6675 = new MAX6675();
	max6675->SetConfigCkPin(GPIOA, GPIO_PIN_1);
	max6675->SetConfigCsPin(GPIOA, GPIO_PIN_2);
	max6675->SetConfigDatPin(GPIOA, GPIO_PIN_0);
	thermocouple = max6675;
}
void CestacionBaku601::IniciaSensorTemperaturaAnalogico()
{
	SensorAnalogico *sensorTemeratura = new SensorAnalogico();
	thermocouple = sensorTemeratura;
}
CestacionBaku601::CestacionBaku601() :
		CEstacionBase()
{
	pwm.Init(TIM2, TIM_CHANNEL_1, 65535);
	IniciaSensorTemperaturaAnalogico();
	thermocouple->Init();

	calefactor.Configurar(GPIOB, GPIO_PIN_3);
	calefactor.Init();
	sensorMagnetico.Configurar(GPIOB, GPIO_PIN_5);
	sensorMagnetico.Init();
	sensorMagnetico.AsignaManejadorEventos(this);

}

//regresa la tenperatura actual de la estacion
float CestacionBaku601::GetTemperaturaRealx()
{
	//return //TemperaturaRealActual;//
	return thermocouple->LeeTemepatura(); //* .59;
}

//establece la temperatura que se quiere alcanzar
void CestacionBaku601::SetTemperatura(int temperatura)
{
	TemperaturaEspecificada = temperatura;
}

// regresa la temperatura seteada
int CestacionBaku601::GetTemperatura()
{
	return TemperaturaEspecificada;
}

//establece el nivel de aire
void CestacionBaku601::SetNivelAire(int nivel)
{
	NivelAire = nivel;
}
int CestacionBaku601::GetNivelAire()
{
	return NivelAire;
}

//regresa 1 si esta activo y 0 si esta en reposo
int CestacionBaku601::GetEstado()
{
	return sensorMagnetico.Leer();
}

void CestacionBaku601::IncrementaTemperatura()
{
	if (TemperaturaEspecificada > TemperaturaMaxima)
	{
		TemperaturaEspecificada = TemperaturaMaxima;
	}
	TemperaturaEspecificada++;
}

void CestacionBaku601::DecrementaTemperatura()
{
	if (TemperaturaEspecificada > 0)
	{
		TemperaturaEspecificada--;
	}
}

void CestacionBaku601::ActivarCalefactor()
{
	EstadoCalefator = ENCENDIDO;
}

void CestacionBaku601::DesactivarCalefactor()
{
	EstadoCalefator = APAGADO;
}

void CestacionBaku601::OnSensorMagneticoChange(int estado)
{

}

void CestacionBaku601::Procesa()
{
	ProcesaTemperatura();
	procesaAire();
	ProcesaCalefactor();
}

//verifica el nivel de temperatura seleccinada por el usuario
void CestacionBaku601::ProcesaTemperatura()
{
	//leo la temperatura
	int temp = GetTemperatura();
	//veo si cambio
	if (temperaturaAnterior != temp)
	{
		temperaturaAnterior = temp;
	}
}

void CestacionBaku601::ProcesaTemperaturaReal()
{
}

//verifica elnivel de aire
void CestacionBaku601::procesaAire()
{
	int aire = GetNivelAire();
	if (AireAnterior != aire)
	{
		AireAnterior = aire;
		NivelAireEvent(AireAnterior);
	}
}

void CestacionBaku601::ProcesaCalefactor()
{
	if (EstadoCalefator == APAGADO)
	{
		//esta apagado el calefactor
		PotenciaCalefactor = 0;
		calefactor.Apagar();
		return;
	}
	EstadoSensorMagnetico = sensorMagnetico.Leer();
	if (EstadoSensorMagnetico == BOTON_PRESIONADO)
	{
		//el usuario coloco la pistola en su base por lo que hay que enfriarla
		EnfriaYApagaPistola();
		return;
	}
	TiempoEnfriando = 0;
	//enciendo el aire
	int aire = GetNivelAire();
	pwm.SicloTrabajo(aire);
	//aqui se hace al calculo del PID
	//veo si ya paso el tiempo para hacer el muestreo
	TiempoActual = HAL_GetTick(); //me trae el tiempo en milisegundos
	if (TiempoActual < TiempoProximoMuestreo)
	{
		//a un no ha paso el tiempo para
		return;
	}
	//calculo el siguiente tiempo de muestreo
	TiempoProximoMuestreo = TiempoActual + TiempoMuestreoTemperatura;
	TemperaturaRealActual = GetTemperaturaRealx();
	int temperatura = TemperaturaRealActual;
	PID_error = TemperaturaEspecificada - temperatura;                       //Calculo del error
	Error_INT = Error_INT + PID_error * (1000 / TiempoMuestreoTemperatura);  //Calculo de la integral del error
	PID_value = Kc * (PID_error + (1 / Tao_I) * Error_INT) / 10;   //Calculo de la salida del controlador PI
	//asigno la potencia del calefactor
	PotenciaCalefactor = PID_value;
}

void CestacionBaku601::EnfriaYApagaPistola()
{
	PotenciaCalefactor = 0; //bajo toda la potencia
	float temperatura = GetTemperaturaRealx();
	if (temperatura <= TEMPERATURA_APAGADO)
	{
		if (TiempoEnfriando == 0)
		{
			TiempoEnfriando = HAL_GetTick();
			return;
		}
		if (HAL_GetTick() - TiempoEnfriando <= 10000)
		{
			return;
		}
		pwm.SicloTrabajo(0);
		return;
	}
	//pongo al maximo el aire para enfriar la pistola
	if (temperatura > 10)
	{
		pwm.SicloTrabajo(100);
	}
}
void CestacionBaku601::CruceXCero(int gpio_pin)
{
	if (EstadoSensorMagnetico == BOTON_PRESIONADO)
	{
		calefactor.Apagar();
		return;
	}
	if (gpio_pin != CruceCero_Pin)
		return;
	if (conteolecturatemperatura > 10)
	{
		conteolecturatemperatura = 0;
	}
	conteolecturatemperatura++;
	if (ciclos >= 100)
	{
		ciclos = 0;
	}
	if (ciclos < PotenciaCalefactor)
	{
		calefactor.Encender();
	}
	else
	{
		calefactor.Apagar();
	}
	ciclos = ciclos + 1;
}
void CestacionBaku601::TimerTick()
{
	if (TiempoAntiReboresCruceXCero > 0)
	{
		TiempoAntiReboresCruceXCero--;
	}
	else
	{
		CruceXCero(CruceCero_Pin);
		TiempoAntiReboresCruceXCero =250;// 2000;
	}
}
int CestacionBaku601::GetPID()
{
	return PotenciaCalefactor;
}
void CestacionBaku601::SetPID(int valor)
{
	PotenciaCalefactor = valor;
}
void CestacionBaku601::GPIO_INTERRUPCION(int GPIO_Pin)
{
}
