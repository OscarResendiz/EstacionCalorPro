/*
 * CManejadorControles.cpp
 *
 *  Created on: Sep 26, 2024
 *      Author: W10
 */

#include <ManejadorControles/CManejadorControles.hpp>
#include "Constantes.hpp"
#include "Uart/Uart.hpp"

CManejadorControles::CManejadorControles()
{
	// TODO Auto-generated constructor stub
	//configuracion de los botones
	BotonMemoria1.Configurar(GPIOC, GPIO_PIN_14, 1);
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

	Encoder.Configurar(GPIOB, GPIO_PIN_2, GPIOB, GPIO_PIN_12, GPIOB,
			GPIO_PIN_8, 1);
	Encoder.AsignaManejadorEventos(this);
	Encoder.Init();

	controlVelocidadAire.Inicializa();

}

CManejadorControles::~CManejadorControles()
{
	// TODO Auto-generated destructor stub
}

void CManejadorControles::GPIO_INTERRUPCION(int GPIO_Pin)
{
	ProcesaBotones(GPIO_Pin);
	InterrupcionEncoder(GPIO_Pin);
}

void CManejadorControles::ProcesaBotones(int gpio_pin)
{
	BotonMemoria1.Procesa(gpio_pin);
	BotonMemoria2.Procesa(gpio_pin);
	BotonMemoria3.Procesa(gpio_pin);
///	SerialPrintf("\r\n ProcesaBotones");

	BotonManual.Procesa(gpio_pin);
}
void CManejadorControles::InterrupcionEncoder(int GPIO_Pin)
{
	Encoder.Procesa(GPIO_Pin);
}

//regresa el nivel de aire setado
int CManejadorControles::GetNivelAire()
{
	return controlVelocidadAire.LeeVelocidad();
}

//eventros del boton uno
void CManejadorControles::BotonUnoClickEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonUnoClickEvent();

}
//eventros del boton dos
void CManejadorControles::BotonDosClickEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonDosClickEvent();

}
//eventros del boton tres
void CManejadorControles::BotonTresClickEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonTresClickEvent();

}
//eventros del boton Cuatro
void CManejadorControles::BotonCuatroClickEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonCuatroClickEvent();

}
//eventros del boton Perilla
void CManejadorControles::BotonPerillaClickEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonPerillaClickEvent();

}
//eventos del encoder
void CManejadorControles::EncoderIncremento()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnPerillaIncremento();

}
void CManejadorControles::EncoderDecremento()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnPerillaDecremento();

}

void CManejadorControles::OnBotonClickEvent(int idBoton)
{
	switch (idBoton)
	{
	case BOTON_MEMORIA1:
		BotonUnoClickEvent();
		break;
	case BOTON_MEMORIA2:
		BotonDosClickEvent();
		break;
	case BOTON_MEMORIA3:
		BotonTresClickEvent();
		break;
	case BOTON_MANUAL:
		BotonCuatroClickEvent();
		break;
	}
}


//eventros del encoder
void CManejadorControles::OnIncrementoEncoder(int id_Encoder)
{
	EncoderIncremento();
}

void CManejadorControles::OnDecrementoEncoder(int id_Encoder)
{
	EncoderDecremento();
}

void CManejadorControles::OnBotonEncoderClickEvent(int id_Encoder )
{
	BotonPerillaClickEvent();
}





void CManejadorControles::SetManejadorControles(CManejadorEventosControles *obj)
{
	ManejadorControles = obj;
}

void CManejadorControles::TimerTick()
{

}
