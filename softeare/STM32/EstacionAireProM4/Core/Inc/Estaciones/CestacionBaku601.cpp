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

/*
void PruebaTempratura(int n)
{
//	HAL_InitTick()
	int temperatura;
	MAX6675 thermocouple;
	double t=1/SystemCoreClock;
	//if(n==0)
	{
	thermocouple.SetConfigCkPin(GPIOA, GPIO_PIN_1);
	thermocouple.SetConfigCsPin(GPIOA, GPIO_PIN_2);
	thermocouple.SetConfigDatPin(GPIOA, GPIO_PIN_0);
	thermocouple.Init();
	}
	int x=10;
	while(x>1)
	{
	//	x--;

		temperatura=thermocouple.MAX6675_leex();
		SerialPrintf("\r\nTemperatura: %d intento = %d",temperatura,n);
		HAL_Delay(1000);
	}
}
*/
CestacionBaku601::~CestacionBaku601()
{
	// TODO Auto-generated destructor stub
}

CestacionBaku601::CestacionBaku601() :
		CEstacionBase()
{
	pwm.Init(TIM2, TIM_CHANNEL_1, 65535);

	//inicializa la termocupla
	thermocouple.SetConfigCkPin(GPIOA, GPIO_PIN_1);
	thermocouple.SetConfigCsPin(GPIOA, GPIO_PIN_2);
	thermocouple.SetConfigDatPin(GPIOA, GPIO_PIN_0);
	thermocouple.Init();


	calefactor.Configurar(GPIOB, GPIO_PIN_3);
	calefactor.Init();
//	PruebaTempratura(0);
	sensorMagnetico.Configurar(GPIOB, GPIO_PIN_5);
	sensorMagnetico.Init();
	sensorMagnetico.AsignaManejadorEventos(this);

}

//regresa la tenperatura actual de la estacion
float CestacionBaku601::GetTemperaturaRealx()
{
	//return //TemperaturaRealActual;//
	return thermocouple.MAX6675_leex(); //* .59;
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
	NivelAire=nivel;
	//pwm.SicloTrabajo(nivel);
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
	if (TemperaturaEspecificada < TemperaturaMaxima)
	{
		TemperaturaEspecificada++;
	}
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
//	ProcesaTemperaturaReal();
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
/*
 *int temperatura = GetTemperaturaReal();
	if (temperaturaRealAnterior != temperatura)
	{
		temperaturaRealAnterior = temperatura;
		TemperaturaRealEvent(temperaturaRealAnterior);
	}
	*/
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
		PotenciaCalefactor=0;
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
	TiempoEnfriando=0;
	//enciendo el aire
	int aire = GetNivelAire();
	pwm.SicloTrabajo(aire);
	//aqui se hace al calculo del PID
	//veo si ya paso el tiempo para hacer el muestreo
	TiempoActual=HAL_GetTick(); //me trae el tiempo en milisegundos
	if(TiempoActual<TiempoProximoMuestreo )
	{
		//a un no ha paso el tiempo para
		return;
	}
	//calculo el siguiente tiempo de muestreo
	TiempoProximoMuestreo=TiempoActual+TiempoMuestreoTemperatura;
	TemperaturaRealActual=GetTemperaturaRealx();//thermocouple.MAX6675_lee();
	int temperatura = TemperaturaRealActual;//GetTemperaturaReal();
	 PID_error = TemperaturaEspecificada - temperatura;                       //Calculo del error
	 Error_INT = Error_INT + PID_error * (1000 / TiempoMuestreoTemperatura);  //Calculo de la integral del error
	 PID_value = Kc * (PID_error + (1 / Tao_I) * Error_INT)/10;   //Calculo de la salida del controlador PI
	 //asigno la potencia del calefactor
	 PotenciaCalefactor=PID_value;
}

void CestacionBaku601::EnfriaYApagaPistola()
{
	//calefactor.Apagar();
	PotenciaCalefactor=0; //bajo toda la potencia
	float temperatura = GetTemperaturaRealx();
	if (temperatura <= TEMPERATURA_APAGADO)
	{
		if(TiempoEnfriando==0)
		{
			TiempoEnfriando=HAL_GetTick();
			return;
		}
		if(HAL_GetTick()-TiempoEnfriando<=10000)
		{
			return;
		}
		pwm.SicloTrabajo(0);
		return;
	}
	//pongo al maximo el aire para enfriar la pistola
	if(temperatura>10)
	{
		pwm.SicloTrabajo(100);
	}
}
void CestacionBaku601::CruceXCero(int gpio_pin)
{
	if(gpio_pin!=CruceCero_Pin)
		return;
	if(TiempoAntiReboresCruceXCero>0)
	{
		return;
	}
	TiempoAntiReboresCruceXCero=9;
	if(conteolecturatemperatura>10)
	{
		conteolecturatemperatura=0;
//		TemperaturaRealActual=thermocouple.MAX6675_lee();
	}
	conteolecturatemperatura++;
//	ProcesaTemperaturaReal();
	if(ciclos>=100)
	{
		ciclos=0;
	}
	if(ciclos<PotenciaCalefactor)
	{
		calefactor.Encender();
	}
	else
	{
		calefactor.Apagar();
	}
	ciclos=ciclos+1;
}
void CestacionBaku601::TimerTick()
{
		if(TiempoAntiReboresCruceXCero>0)
		{
			TiempoAntiReboresCruceXCero--;
		}
}
int CestacionBaku601::GetPID()
{
	return PotenciaCalefactor;
}
void CestacionBaku601::SetPID(int valor)
{
	PotenciaCalefactor=valor;
}
void CestacionBaku601::GPIO_INTERRUPCION(int GPIO_Pin)
{
	CruceXCero(GPIO_Pin);
}