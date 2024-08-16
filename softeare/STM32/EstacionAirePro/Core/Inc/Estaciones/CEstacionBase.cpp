/*
 * CEstacionBase.cpp
 *
 *  Created on: Jul 23, 2024
 *      Author: W10
 */

#include <Estaciones/CEstacionBase.hpp>

CEstacionBase::CEstacionBase()
{
	// TODO Auto-generated constructor stub

}

CEstacionBase::~CEstacionBase()
{
	// TODO Auto-generated destructor stub
}

float CEstacionBase::GetTemperaturaReal() //regresa la tenperatura actual de la estacion
{

}
void CEstacionBase::SetTemperatura(int temperatura) //establece la temperatura que se quiere alcanzar
{

}
int CEstacionBase::GetTemperatura() // regresa la temperatura seteada
{

}
void CEstacionBase::SetNivelAire(int nivel) //establece el nivel de aire
{

}
int CEstacionBase::GetNivelAire() //regresa el nivel de aire setado
{

}
int CEstacionBase::GetEstado() //regresa 1 si esta activo y 0 si esta en reposo
{

}
//para que la misma estacion incremente la temperatura
void CEstacionBase::IncrementaTemperatura()
{

}
//para que la misma estacion decremente la temeperatura
void CEstacionBase::DecrementaTemperatura()
{

}
// asigna el evento que sellamara cuando cambie la temperatura que el usuario especifica
void CEstacionBase::SetManejadorControles(CManejadorControlesBase *obj)
{
	ManejadorControles = obj;
}
//funcion que se debera llamar para controlar la estacion de calor
void CEstacionBase::Procesa()
{

}
void CEstacionBase::TemperaturaEvent(int temperatura)
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnTemperaturaEvent(temperatura);
}
void CEstacionBase::NivelAireEvent(int aire)
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnNivelAireEvent(aire);
}
void CEstacionBase::TemperaturaRealEvent(int temperatura)
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnTemperaturaRealEvent(temperatura);

}
//eventros del boton uno
void CEstacionBase::BotonUnoClickEvent(int tiempoClick)
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonUnoClickEvent(tiempoClick);

}
void CEstacionBase::BotonUnoPresionadoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonUnoPresionadoEvent();

}
void CEstacionBase::BotonUnoPresionadoLargoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonUnoPresionadoLargoEvent();

}
void CEstacionBase::BotonUnoSueltoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonUnoSueltoEvent();

}
//eventros del boton dos
void CEstacionBase::BotonDosClickEvent(int tiempoClick)
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonDosClickEvent(tiempoClick);

}
void CEstacionBase::BotonDosPresionadoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonDosPresionadoEvent();

}
void CEstacionBase::BotonDosPresionaLargodoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonDosPresionadoLargoEvent();

}
void CEstacionBase::BotonDosSueltoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonDosSueltoEvent();

}
//eventros del boton tres
void CEstacionBase::BotonTresClickEvent(int tiempoClick)
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonTresClickEvent(tiempoClick);

}
void CEstacionBase::BotonTresPresionadoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonTresPresionadoEvent();

}
void CEstacionBase::BotonTresPresionaLargodoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonTresPresionadoLargoEvent();

}
void CEstacionBase::BotonTresSueltoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonTresSueltoEvent();

}
//eventros del boton Cuatro
void CEstacionBase::BotonCuatroClickEvent(int tiempoClick)
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonCuatroClickEvent(tiempoClick);

}
void CEstacionBase::BotonCuatroPresionadoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonCuatroPresionadoEvent();

}
void CEstacionBase::BotonCuatroPresionaLargodoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonCuatroPresionadoLargoEvent();
}
void CEstacionBase::BotonCuatroSueltoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonCuatroSueltoEvent();

}
//eventros del boton Perilla
void CEstacionBase::BotonPerillaClickEvent(int tiempoClick)
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonPerillaClickEvent(tiempoClick);

}
void CEstacionBase::BotonPerillaPresionadoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonPerillaPresionadoEvent();

}
void CEstacionBase::BotonPerillaPresionadoLargoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonPerillaPresionadoLargoEvent();

}
void CEstacionBase::BotonPerillaSueltoEvent()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnBotonPerillaSueltoEvent();
}
//eventos del encoder
void CEstacionBase::EncoderIncremento()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnPerillaIncremento();

}
void CEstacionBase::EncoderDecremento()
{
	if (ManejadorControles == NULL)
		return;
	ManejadorControles->OnPerillaDecremento();

}
void CEstacionBase::InterrupcionEncoder()
{

}
