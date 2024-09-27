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
void CEstacionBase::SetManejadorControles(CManejadorEventosControles *obj)
{
	ManejadorControles = obj;
}
//funcion que se debera llamar para controlar la estacion de calor
void CEstacionBase::Procesa()
{

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
void CEstacionBase::ActivarCalefactor()
{

}
void CEstacionBase::DesactivarCalefactor()
{

}
void CEstacionBase::CruceXCero(int gpio_pin)
{

}
void CEstacionBase::TimerTick()
{

}
int CEstacionBase::GetPID()
{
	return 0;
}
void CEstacionBase::SetPID(int valor)
{

}
void CEstacionBase::GPIO_INTERRUPCION(int GPIO_Pin)
{

}
void CEstacionBase::QuitaManejadorControles()
{
	ManejadorControles = NULL;
}
