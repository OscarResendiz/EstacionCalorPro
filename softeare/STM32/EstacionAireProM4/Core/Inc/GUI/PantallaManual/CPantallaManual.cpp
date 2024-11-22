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
	LabelAire = new CEtiquetaTft( 5, 105, 200, 30, COLOR::BLACK, (char*)"Aire: 00",COLOR::WHITE, 3, 0, COLOR::RED);
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
		if(TemperaturaAnterior==Temperatura &&SetTemperaturaAnterior==SetTemperatura)//&& EsVisible()==true )
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
	LabelAire->SetTexto((char*)"Aire: %d", NivelAire);
	LabelAire->Show();

}

void CPantallaManual::OnTemperaturaRealEvent(int temperatura)
{
//	Temperatura = temperatura;
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
// 	uint8_t datos_w[10];
 	int t= HAL_GetTick();
 	if(t>tiempoescritura)
 	{
 		Eprom.GuardaTemepraturaManual(temperatura);
// 		HAL_I2C_Mem_Write(&hi2c1,ADDRESS_EEPROM,DIRMEMORIARPROM::TEMPERATURAMANUAL,I2C_MEMADD_SIZE_8BIT,(uint8_t*)&temperatura,2,HAL_MAX_DELAY);
 		TemperaturaGuardada=true;
 		tiempoescritura=t+1000;
 	}

 }
void CPantallaManual::LeeMemoria()
{

 	uint16_t temperatura=Eprom.DameTemperaturaManual();
	Estacion->SetTemperatura(temperatura);
	TemperaturaGuardada=true;

/*
 	  if( HAL_I2C_Mem_Read(&hi2c1,ADDRESS_EEPROM,DIRMEMORIARPROM::TEMPERATURAMANUAL,I2C_MEMADD_SIZE_8BIT,(uint8_t*)&temperatura,2,HAL_MAX_DELAY)==HAL_OK)
 	  {
 		 	if(temperatura>=0 && temperatura<=500)
 		 	{
 		 		Estacion->SetTemperatura(temperatura);
 		 	}
 		 	TemperaturaGuardada=true;
 	  }
 	  */
}

 void CPantallaManual::Show()
 {
 	CPantallaBase::Show();
 	LabelTemperatura->Show();
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
