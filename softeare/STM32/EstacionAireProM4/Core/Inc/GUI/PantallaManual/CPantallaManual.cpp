/*
 * CPantallaManual.cpp
 *
 *  Created on: Jul 25, 2024
 *      Author: W10
 */

#include <GUI/PantallaManual/CPantallaManual.hpp>
#include <GUI/ManejadorPantallas/CManejadorPantallas.hpp>
#include <Uart/Uart.hpp>
#include "Constantes.hpp"
#include <EPROM/CEprom.hpp>

extern I2C_HandleTypeDef hi2c1;
extern UART_HandleTypeDef huart1;

CPantallaManual::~CPantallaManual()
{
	// TODO Auto-generated destructor stub
}

CPantallaManual::CPantallaManual() :
		CPantallaBase(1, (char*)"   Modo: Manual")
{
	LabelTemperatura = new CEtiquetaTft( 5, 35, 50, 20, COLOR::BLACK,(char*)"Temperatura", COLOR::WHITE, 3, 0, COLOR::WHITE);
	int centroX = DameCentroX();
	LabelTemperaturas = new CEtiquetaTft( centroX - 150 / 2, 65, 150, 30,COLOR::WHITE,(char*) "000/000", COLOR::BLACK, 3, 1, COLOR::RED);
	LabelTemperaturas->SetSeparacion(5, 5);
	LabelAire1 = new CEtiquetaTft( 5, 105, 200, 30, COLOR::BLACK, (char*)"Aire:",COLOR::WHITE, 3, 0, COLOR::RED);
	LabelAire2 = new CEtiquetaTft( 110, 105, 100, 30, COLOR::WHITE, (char*)"00",COLOR::BLACK, 3, 0, COLOR::RED);
	LabelEstado = new CEtiquetaTft( 5, 145, 300, 35, COLOR::BLACK,(char*)"Estado: REPOSO", COLOR::WHITE, 3, 0, COLOR::RED);
	LabelEstado->SetSeparacion(15, 5);
}


void CPantallaManual::MuestraEstado(bool forzar)
{
	if(forzar==false)
	{
		if(EstadoBoquillaAnterior==EstadoBoquilla )
		{
			if(EsVisible()==true)
			{
				return;
			}
		}
	}
	EstadoBoquillaAnterior=EstadoBoquilla;
	if (EstadoBoquilla == 1)
	{
		LabelEstado->SetColorFondo(COLOR::BLUE);
		LabelEstado->SetColorTexto(COLOR::BLACK);
		LabelEstado->SetTexto((char*)"Estado: ACTIVO");
	}
	else
	{
		LabelEstado->SetColorFondo(COLOR::RED);
		LabelEstado->SetColorTexto(COLOR::WHITE);
		LabelEstado->SetTexto((char*)"Estado: REPOSO");
	}
	LabelEstado->Show();
}

void CPantallaManual::LeeDatosEstacion()
{
	SetTemperatura = Estacion->GetTemperatura();
	Temperatura = Estacion->GetTemperaturaRealx();
	NivelAire = ManejadorControles->GetNivelAire();
	Estacion->SetNivelAire(NivelAire);
	EstadoBoquilla=Estacion->GetEstado();
}


void CPantallaManual::MuestraTemperaturas(bool forzar)
{
	if(forzar==false)
	{
		if(TemperaturaAnterior==Temperatura &&SetTemperaturaAnterior==SetTemperatura)
			return;
	}

	TemperaturaAnterior=Temperatura;
	SetTemperaturaAnterior=SetTemperatura;
	LabelTemperaturas->SetTexto((char*)"%d/%d", Temperatura, SetTemperatura);
	LabelTemperaturas->Show();
}

void CPantallaManual::OnNivelAireEvent(int aire)
{
	NivelAire = aire;
	Estacion->SetNivelAire(NivelAire);
}

void CPantallaManual::MuestraNivelAire(bool forzar)
{
	if(forzar==false)
	{
		if(NivelAireAnterior==NivelAire && EsVisible()==true )
			return;
	}
	NivelAireAnterior=NivelAire;
	Estacion->SetNivelAire(NivelAire);
	LabelAire2->SetTexto((char*)"%d", NivelAire);
	LabelAire2->Show();

}

void CPantallaManual::OnTemperaturaRealEvent(int temperatura)
{
}

//eventos del Encoder
void CPantallaManual::OnPerillaIncremento()
{
	Estacion->IncrementaTemperatura();
	TemperaturaGuardada=false;
}

void CPantallaManual::OnPerillaDecremento()
{
	Estacion->DecrementaTemperatura();
	TemperaturaGuardada=false;
}

void CPantallaManual::Refresca()
{
	if(TemperaturaGuardada==false)
		GuardaTemperatura();
	MuestraInformacion(false);
}
 void CPantallaManual::OnBotonPerillaClickEvent()
 {
	 ManejadorPantallas.MuestraMenuPrincipal();
 }
 void CPantallaManual::MuestraInformacion(bool forzar)
 {
		LeeDatosEstacion();
		MuestraTemperaturas(forzar);
		MuestraEstado(forzar);
		MuestraNivelAire(forzar);
		//marco como visible
		SetVisible(true);

 }
 void CPantallaManual::GuardaTemperatura()
 {
 	uint16_t temperatura=Estacion->GetTemperatura();
 	int t= HAL_GetTick();
 	if(t>tiempoescritura)
 	{
 		Eprom.GuardaTemepraturaManual(temperatura);
 		TemperaturaGuardada=true;
 		tiempoescritura=t+1000;
 	}

 }
void CPantallaManual::LeeMemoria()
{

 	uint16_t temperatura=Eprom.DameTemperaturaManual();
	Estacion->SetTemperatura(temperatura);
	TemperaturaGuardada=true;
}

 void CPantallaManual::Show()
 {
 	CPantallaBase::Show();
 	LabelTemperatura->Show();
 	LabelAire1->Show();
 	//leo la temperatura desde la memoria
 	LeeMemoria();
 	LeeDatosEstacion();
 	MuestraInformacion(true);
 }
void CPantallaManual::OnBotonTresClickEvent()
{
	ManejadorPantallas.MuestraPantallaMemoria(3);
}
void CPantallaManual::OnBotonUnoClickEvent()
{
	ManejadorPantallas.MuestraPantallaMemoria(1);
}
void CPantallaManual::OnBotonDosClickEvent()
{
	ManejadorPantallas.MuestraPantallaMemoria(2);
}
void CPantallaManual::SetEstacion(CEstacionBase *estacion)
{
	CPantallaBase::SetEstacion(estacion);
	Estacion->ActivarCalefactor();
}
