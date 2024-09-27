/*
 * CManejadorControles.cpp
 *
 *  Created on: Sep 26, 2024
 *      Author: W10
 */

#include <ManejadorControles/CManejadorControles.hpp>
#include "Constantes.hpp"

CManejadorControles::CManejadorControles()
{
	// TODO Auto-generated constructor stub
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
void CManejadorControles::BotonUnoClickEvent(int tiempoClick)
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonUnoClickEvent(tiempoClick);

}
void CManejadorControles::BotonUnoPresionadoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonUnoPresionadoEvent();

}
void CManejadorControles::BotonUnoPresionadoLargoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonUnoPresionadoLargoEvent();

}
void CManejadorControles::BotonUnoSueltoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonUnoSueltoEvent();

}
//eventros del boton dos
void CManejadorControles::BotonDosClickEvent(int tiempoClick)
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonDosClickEvent(tiempoClick);

}
void CManejadorControles::BotonDosPresionadoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonDosPresionadoEvent();

}
void CManejadorControles::BotonDosPresionaLargodoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonDosPresionadoLargoEvent();

}
void CManejadorControles::BotonDosSueltoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonDosSueltoEvent();

}
//eventros del boton tres
void CManejadorControles::BotonTresClickEvent(int tiempoClick)
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonTresClickEvent(tiempoClick);

}
void CManejadorControles::BotonTresPresionadoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonTresPresionadoEvent();

}
void CManejadorControles::BotonTresPresionaLargodoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonTresPresionadoLargoEvent();

}
void CManejadorControles::BotonTresSueltoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonTresSueltoEvent();

}
//eventros del boton Cuatro
void CManejadorControles::BotonCuatroClickEvent(int tiempoClick)
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonCuatroClickEvent(tiempoClick);

}
void CManejadorControles::BotonCuatroPresionadoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonCuatroPresionadoEvent();

}
void CManejadorControles::BotonCuatroPresionaLargodoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonCuatroPresionadoLargoEvent();
}
void CManejadorControles::BotonCuatroSueltoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonCuatroSueltoEvent();

}
//eventros del boton Perilla
void CManejadorControles::BotonPerillaClickEvent(int tiempoClick)
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonPerillaClickEvent(tiempoClick);

}
void CManejadorControles::BotonPerillaPresionadoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonPerillaPresionadoEvent();

}
void CManejadorControles::BotonPerillaPresionadoLargoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonPerillaPresionadoLargoEvent();

}
void CManejadorControles::BotonPerillaSueltoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonPerillaSueltoEvent();
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

void CManejadorControles::OnBotonClickEvent(int idBoton, int tiempoClick)
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

void CManejadorControles::OnBotonPresionadoEvent(int idBoton)
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

void CManejadorControles::OnBotonSueltoEvent(int idBoton)
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
void CManejadorControles::OnIncrementoEncoder(int id_Encoder)
{
	EncoderIncremento();
}

void CManejadorControles::OnDecrementoEncoder(int id_Encoder)
{
	EncoderDecremento();
}

void CManejadorControles::OnBotonEncoderClickEvent(int id_Encoder, int tiempoClick)
{
	BotonPerillaClickEvent(tiempoClick);
}

void CManejadorControles::OnBotonEncoderPresionadoEvent(int id_Encoder)
{
	BotonPerillaPresionadoEvent();
}

void CManejadorControles::OnBotonEncoderPresionadoLargoEvent(int id_Encoder)
{
	BotonPerillaPresionadoLargoEvent();
}

void CManejadorControles::OnBotonEncoderSueltoEvent(int id_Encoder)
{
	BotonPerillaSueltoEvent();
}


void CManejadorControles::SetManejadorControles(CManejadorEventosControles *obj)
{
	ManejadorControles = obj;
}

void CManejadorControles::TimerTick()
{

}
