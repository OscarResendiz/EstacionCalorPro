/*
 * CConfigurarPantallaMemoria.cpp
 *
 *  Created on: Sep 26, 2024
 *      Author: W10
 */

#include <GUI/ConfigurarPantallaMemoria/CConfigurarPantallaMemoria.hpp>
#include <GUI/ManejadorPantallas/CManejadorPantallas.hpp>

extern I2C_HandleTypeDef hi2c1;

CConfigurarPantallaMemoria::CConfigurarPantallaMemoria():
CPantallaBase(1, "CONF MEMORIA")

{
	// TODO Auto-generated constructor stub
	LabelMemoria=new CEtiquetaTft( 5, 35, 50, 20, COLOR::BLACK,"Memoria: ", COLOR::WHITE, 3, 0, COLOR::WHITE);
	LabelTemperatura = new CEtiquetaTft( 5, 65, 50, 20, COLOR::BLACK,"Temperatura", COLOR::WHITE, 3, 0, COLOR::WHITE);
	int centroX = DameCentroX();
	LabelTemperaturas = new CEtiquetaTft( centroX - 150 / 2, 105, 150, 30,COLOR::WHITE, "000/000", COLOR::BLACK, 3, 1, COLOR::RED);
	LabelTemperaturas->SetSeparacion(5, 5);
	LabelAire = new CEtiquetaTft( 5, 135, 200, 30, COLOR::BLACK, "Aire: 00",COLOR::WHITE, 3, 0, COLOR::RED);

	LabelGuardar=new CEtiquetaTft( 10, 200, 130, 30, COLOR::GREEN,"GUARDAR", COLOR::BLACK, 3, 1, COLOR::WHITE);
	LabelCancelar=new CEtiquetaTft( 160, 200, 145, 30, COLOR::RED,"CANCELAR", COLOR::BLACK, 3, 1, COLOR::WHITE);

}

CConfigurarPantallaMemoria::~CConfigurarPantallaMemoria()
{
	// TODO Auto-generated destructor stub
}

void CConfigurarPantallaMemoria::Show()
{
	VelocidadAireInicialPotenciometro=ManejadorControles->GetNivelAire();
	CPantallaBase::Show();
	LeeDatosMemoria();
	LabelTemperatura->Show();
	MuestraInformacion();
	LabelMemoria->SetTexto("Memoria: %d", NumeroMemoria);
	LabelMemoria->Show();
	LabelGuardar->Show();
	LabelCancelar->Show();
}

void CConfigurarPantallaMemoria::Refresca()
{
	int velocidad=ManejadorControles->GetNivelAire();
	if(VelocidadAireInicialPotenciometro>velocidad+1 ||VelocidadAireInicialPotenciometro<velocidad-1)
	{
		VelocidadAire =velocidad;
	}
	MuestraInformacion();
}
void CConfigurarPantallaMemoria::SetMemoria(int numeroMemoria)
{
	TemperaturaAnterior=-1;
	VelocidadAireAnterior=-1;
	NumeroMemoria=numeroMemoria;
	DireccionMemoria=DameDireccionMemoria();
}

void CConfigurarPantallaMemoria::LeeDatosMemoria()
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
	  }

}
int CConfigurarPantallaMemoria::DameDireccionMemoria()
{
	int direccion=1;
	switch(NumeroMemoria)
	{
	case 1:
		direccion=1;
		break;
	case 2:
		direccion=5;
		break;
	case 3:
		direccion=9;
		break;
	}
	return direccion;
}
void CConfigurarPantallaMemoria::MuestraInformacion()
{

	if(TemperaturaAnterior!=Temperatura)
	{
		LabelTemperaturas->SetTexto("%d", Temperatura);
		LabelTemperaturas->Show();
		TemperaturaAnterior=Temperatura;
	}

	if( VelocidadAireAnterior!=VelocidadAire)
	{
		LabelAire->SetTexto("Aire: %d", VelocidadAire);
		LabelAire->Show();
		VelocidadAireAnterior=VelocidadAire;
	}
}
void CConfigurarPantallaMemoria::OnPerillaIncremento()
{
	if(Temperatura<500)
		Temperatura++;
}
void CConfigurarPantallaMemoria::OnPerillaDecremento()
{
	if(Temperatura>0)
		Temperatura--;
}
void CConfigurarPantallaMemoria::OnBotonUnoClickEvent(int tiempoClick)
{
	//hay que guarar la informacion
 	uint16_t datos_w[2];

 	datos_w[0]=Temperatura;
 	datos_w[1]=VelocidadAire;
	HAL_I2C_Mem_Write(&hi2c1,ADDRESS_EEPROM,DireccionMemoria,I2C_MEMADD_SIZE_8BIT,(uint8_t*)datos_w,4,HAL_MAX_DELAY);
	 ManejadorPantallas.MuestraMenuPrincipal();
}
void CConfigurarPantallaMemoria::OnBotonDosClickEvent(int tiempoClick)
{
	 ManejadorPantallas.MuestraMenuPrincipal();

}
