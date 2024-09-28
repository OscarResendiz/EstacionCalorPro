/*
 * CPantallaMemoria.cpp
 *
 *  Created on: Sep 27, 2024
 *      Author: W10
 */

#include <GUI/PantallaMemoria/CPantallaMemoria.hpp>
#include <GUI/ManejadorPantallas/CManejadorPantallas.hpp>
#include "Uart/Uart.h"
#include "Constantes.hpp"
extern I2C_HandleTypeDef hi2c1;
extern UART_HandleTypeDef huart1;

CPantallaMemoria::~CPantallaMemoria()
{
	// TODO Auto-generated destructor stub
}


CPantallaMemoria::CPantallaMemoria() :
		CPantallaBase(1, "   Modo: MEMORIA")
{
	LabelMemoria=new CEtiquetaTft( 5, 35, 50, 20, COLOR::BLACK,"Memoria: ", COLOR::WHITE, 3, 0, COLOR::WHITE);
	LabelTemperatura = new CEtiquetaTft( 5, 65, 50, 20, COLOR::BLACK,"Temperatura", COLOR::WHITE, 3, 0, COLOR::WHITE);
	int centroX = DameCentroX();
	LabelTemperaturas = new CEtiquetaTft( centroX - 150 / 2, 95, 150, 30,COLOR::WHITE, "000/000", COLOR::BLACK, 3, 1, COLOR::RED);
	LabelTemperaturas->SetSeparacion(5, 5);
	LabelAire = new CEtiquetaTft( 5, 135, 200, 30, COLOR::BLACK, "Aire: 00",COLOR::WHITE, 3, 0, COLOR::RED);
	LabelEstado = new CEtiquetaTft( 5, 175, 300, 35, COLOR::BLACK,"Estado: REPOSO", COLOR::WHITE, 3, 0, COLOR::RED);
	LabelEstado->SetSeparacion(15, 5);

}


void CPantallaMemoria::MuestraEstado(bool forzar)
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
		LabelEstado->SetTexto("Estado: ACTIVO");
	}
	else
	{
		LabelEstado->SetColorFondo(COLOR::RED);
		LabelEstado->SetColorTexto(COLOR::WHITE);
		LabelEstado->SetTexto("Estado: REPOSO");
	}
	LabelEstado->Show();
}

void CPantallaMemoria::LeeDatosEstacion()
{
	SetTemperatura = Estacion->GetTemperatura();
	Temperatura = Estacion->GetTemperaturaReal();
	NivelAire = ManejadorControles->GetNivelAire();
	EstadoBoquilla=Estacion->GetEstado();
}


void CPantallaMemoria::MuestraTemperaturas(bool forzar)
{
	if(forzar==false)
	{
		if(TemperaturaAnterior==Temperatura &&SetTemperaturaAnterior==SetTemperatura && EsVisible()==true )
			return;
	}
	TemperaturaAnterior=Temperatura;
	SetTemperaturaAnterior=SetTemperatura;
	LabelTemperaturas->SetTexto("%d/%d", Temperatura, SetTemperatura);
	LabelTemperaturas->Show();
}

void CPantallaMemoria::OnNivelAireEvent(int aire)
{
	NivelAire = aire;
	Estacion->SetNivelAire(NivelAire);
}

void CPantallaMemoria::MuestraNivelAire(bool forzar)
{
	if(forzar==false)
	{
		if(NivelAireAnterior==NivelAire && EsVisible()==true )
			return;
	}
	NivelAireAnterior=NivelAire;
	Estacion->SetNivelAire(NivelAire);
	LabelAire->SetTexto("Aire: %d", NivelAire);
	LabelAire->Show();

}

void CPantallaMemoria::OnTemperaturaRealEvent(int temperatura)
{
	Temperatura = temperatura;
}

//eventos del Encoder
void CPantallaMemoria::OnPerillaIncremento()
{
	Estacion->IncrementaTemperatura();
	TemperaturaGuardada=false;
}

void CPantallaMemoria::OnPerillaDecremento()
{
	Estacion->DecrementaTemperatura();
	TemperaturaGuardada=false;
}

void CPantallaMemoria::Refresca()
{
	if(TemperaturaGuardada==false)
		GuardaTemperatura();
	MuestraInformacion(false);
}
 void CPantallaMemoria::OnBotonPerillaClickEvent(int tiempoClick)
 {
	 ManejadorPantallas.MuestraMenuPrincipal();
 }
 void CPantallaMemoria::MuestraInformacion(bool forzar)
 {
		LeeDatosEstacion();
		MuestraTemperaturas(forzar);
		MuestraEstado(forzar);
		MuestraNivelAire(forzar);
		//marco como visible
		SetVisible(true);

 }
 void CPantallaMemoria::GuardaTemperatura()
 {
 	uint8_t temperatura=Estacion->GetTemperatura();
 	uint8_t datos_w[10];
 	int t= HAL_GetTick();
 	if(t>tiempoescritura)
 	{

 		HAL_I2C_Mem_Write(&hi2c1,ADDRESS_EEPROM,0,I2C_MEMADD_SIZE_8BIT,&temperatura,1,HAL_MAX_DELAY);
 		TemperaturaGuardada=true;
 		tiempoescritura=t+1000;
 	}

 }
 void CPantallaMemoria::Show()
 {
 	CPantallaBase::Show();
 	LabelTemperatura->Show();
 	//leo la temperatura desde la memoria
	LabelMemoria->SetTexto("Memoria: %d", NumeroMemoria);
	LabelMemoria->Show();

 	uint8_t temperatura;
 	uint8_t datos_w[10];
 	uint8_t datos_r[10];
 	char buf_tx[30];
 	  if( HAL_I2C_Mem_Read(&hi2c1,ADDRESS_EEPROM,0,I2C_MEMADD_SIZE_8BIT,&temperatura,1,HAL_MAX_DELAY)==HAL_OK)
 	  {
 		 	if(temperatura>=0 && temperatura<=500)
 		 	{
 		 		Estacion->SetTemperatura(temperatura);
 		 	}
 		 	TemperaturaGuardada=true;
 	  }
 	LeeDatosEstacion();
 	MuestraInformacion(true);
 }

void CPantallaMemoria::SetMemoria(int numeroMemoria)
{
	NumeroMemoria=numeroMemoria;
}
void CPantallaMemoria::OnBotonCuatroClickEvent(int tiempoClick)
{
	ManejadorPantallas.MuestraPantallaManual();
}

void CPantallaMemoria::OnBotonUnoClickEvent(int tiempoClick)
{

}

void CPantallaMemoria::OnBotonDosClickEvent(int tiempoClick)
{

}

void CPantallaMemoria::OnBotonTresClickEvent(int tiempoClick)
{

}
