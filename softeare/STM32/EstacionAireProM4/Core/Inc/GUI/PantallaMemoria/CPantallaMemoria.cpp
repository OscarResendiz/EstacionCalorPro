/*
 * CPantallaMemoria.cpp
 *
 *  Created on: Sep 27, 2024
 *      Author: W10
 */

#include <GUI/PantallaMemoria/CPantallaMemoria.hpp>
#include <GUI/ManejadorPantallas/CManejadorPantallas.hpp>
#include "Uart/Uart.hpp"
#include "Constantes.hpp"
extern I2C_HandleTypeDef hi2c1;
extern UART_HandleTypeDef huart1;

CPantallaMemoria::~CPantallaMemoria()
{
	// TODO Auto-generated destructor stub
}


CPantallaMemoria::CPantallaMemoria() :
		CPantallaManual()
{
	LabelTitulo->SetTexto((char*)"MODO: MEMORIA");
	LabelMemoria=new CEtiquetaTft( 5, 35, 50, 20, COLOR::BLACK,(char*)"Memoria: ", COLOR::WHITE, 3, 0, COLOR::WHITE);
	LabelTemperatura->CambiaPosicion(5,65);
	int centroX = DameCentroX();
	LabelTemperaturas->CambiaPosicion(centroX - 150 / 2, 95);
	LabelAire->CambiaPosicion(5, 135);
	LabelEstado->CambiaPosicion(5, 175);

}


 void CPantallaMemoria::GuardaTemperatura()
 {
 }


 void CPantallaMemoria::Show()
 {
	 CPantallaManual::Show();
 	//leo la temperatura desde la memoria
	LabelMemoria->SetTexto((char*)"Memoria: %d", NumeroMemoria);
	LabelMemoria->Show();
	LeeDatosMemoria();
	Estacion->SetTemperatura(Temperatura);
	VelocidadAireInicialPotenciometro=ManejadorControles->GetNivelAire();
 }


void CPantallaMemoria::SetMemoria(int numeroMemoria)
{
	NumeroMemoria=numeroMemoria;
	DireccionMemoria=DameDireccionMemoria();
}


void CPantallaMemoria::OnBotonCuatroClickEvent()
{
	ManejadorPantallas.MuestraPantallaManual();
}

void CPantallaMemoria::LeeDatosMemoria()
{
	uint16_t datos_r[2];
	  if( HAL_I2C_Mem_Read(&hi2c1,ADDRESS_EEPROM,DireccionMemoria,I2C_MEMADD_SIZE_8BIT,(uint8_t*)datos_r,4,HAL_MAX_DELAY)==HAL_OK)
	  {
			Temperatura=datos_r[0];
			VelocidadAire=datos_r[1];

		 	if(Temperatura<0 || Temperatura>500)
		 	{
		 		Temperatura=100;
		 	}
		 	if(VelocidadAire<0 || VelocidadAire>100)
		 	{
		 		VelocidadAire=50;
		 	}
		 	Estacion->SetNivelAire(VelocidadAire);
	  }

}
int CPantallaMemoria::DameDireccionMemoria()
{
	int direccion=1;
	switch(NumeroMemoria)
	{
	case 1:
		direccion=DIRMEMORIARPROM::MEMORIA1;
		break;
	case 2:
		direccion=DIRMEMORIARPROM::MEMORIA2;
		break;
	case 3:
		direccion=DIRMEMORIARPROM::MEMORIA3;
		break;
	}
	return direccion;
}
void CPantallaMemoria::LeeDatosEstacion()
{
	CPantallaManual::LeeDatosEstacion();
	int velocidad=ManejadorControles->GetNivelAire();
	if(VelocidadAireInicialPotenciometro>velocidad+1 ||VelocidadAireInicialPotenciometro<velocidad-1)
	{
		NivelAire =velocidad;
		CambioNIvelAire=true;
	}
	else
	{
		NivelAire =VelocidadAire;
		CambioNIvelAire=false;
	}
}
void CPantallaMemoria::OnPerillaIncremento()
{
	ManejadorPantallas.MuestraPantallaManual();
}
void CPantallaMemoria::OnPerillaDecremento()
{
	ManejadorPantallas.MuestraPantallaManual();
}
void CPantallaMemoria::MuestraInformacion(bool forzar)
{
		LeeDatosEstacion();
		if(CambioNIvelAire==true)
		{
			ManejadorPantallas.MuestraPantallaManual();
			return;
		}
		MuestraTemperaturas(forzar);
		MuestraEstado(forzar);
		MuestraNivelAire(forzar);
		//marco como visible
		SetVisible(true);
}

