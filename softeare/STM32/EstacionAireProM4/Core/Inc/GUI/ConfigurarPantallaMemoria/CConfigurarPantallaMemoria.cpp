/*
 * CConfigurarPantallaMemoria.cpp
 *
 *  Created on: Sep 26, 2024
 *      Author: W10
 */

#include <GUI/ConfigurarPantallaMemoria/CConfigurarPantallaMemoria.hpp>
#include <GUI/ManejadorPantallas/CManejadorPantallas.hpp>
#include <EPROM/CEprom.hpp>

extern I2C_HandleTypeDef hi2c1;

CConfigurarPantallaMemoria::CConfigurarPantallaMemoria():
CPantallaBase(1, (char*)"CONF MEMORIA")

{
	// TODO Auto-generated constructor stub
	LabelMemoria=new CEtiquetaTft( 5, 35, 50, 20, COLOR::BLACK,(char*)"Memoria: ", COLOR::WHITE, 3, 0, COLOR::WHITE);
	LabelTemperatura = new CEtiquetaTft( 5, 65, 50, 20, COLOR::BLACK,(char*)"Temperatura", COLOR::WHITE, 3, 0, COLOR::WHITE);
	int centroX = DameCentroX();
	LabelTemperaturas = new CEtiquetaTft( centroX - 150 / 2, 105, 150, 30,COLOR::WHITE, (char*)"000/000", COLOR::BLACK, 3, 1, COLOR::RED);
	LabelTemperaturas->SetSeparacion(5, 5);
	LabelAire = new CEtiquetaTft( 5, 135, 200, 30, COLOR::BLACK,(char*) "Aire: 00",COLOR::WHITE, 3, 0, COLOR::RED);

	LabelGuardar=new CEtiquetaTft( 10, 200, 130, 30, COLOR::GREEN,(char*)"GUARDAR", COLOR::BLACK, 3, 1, COLOR::WHITE);
	LabelCancelar=new CEtiquetaTft( 160, 200, 145, 30, COLOR::RED,(char*)"CANCELAR", COLOR::BLACK, 3, 1, COLOR::WHITE);

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
	LabelMemoria->SetTexto((char*)"Memoria: %d", NumeroMemoria);
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
//	DireccionMemoria=DameDireccionMemoria();
}

void CConfigurarPantallaMemoria::LeeDatosMemoria()
{
	switch(NumeroMemoria)
	{
	case 1:
		Temperatura=Eprom.DameTemperatuarMemoria1();
		VelocidadAire=Eprom.DameVelocidadMemoria1();
		break;
	case 2:
		Temperatura=Eprom.DameTemperatuarMemoria2();
		VelocidadAire=Eprom.DameVelocidadMemoria2();
		break;
	case 3:
		Temperatura=Eprom.DameTemperatuarMemoria3();
		VelocidadAire=Eprom.DameVelocidadMemoria3();
		break;
	}
	/*
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
	  */

}
/*
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
*/
void CConfigurarPantallaMemoria::MuestraInformacion()
{

	if(TemperaturaAnterior!=Temperatura)
	{
		LabelTemperaturas->SetTexto((char*)"%d", Temperatura);
		LabelTemperaturas->Show();
		TemperaturaAnterior=Temperatura;
	}

	if( VelocidadAireAnterior!=VelocidadAire)
	{
		LabelAire->SetTexto((char*)"Aire: %d", VelocidadAire);
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
void CConfigurarPantallaMemoria::OnBotonUnoClickEvent()
{
	switch(NumeroMemoria)
	{
	case 1:
		Eprom.GuardaMemoria1(Temperatura, VelocidadAire);
		break;
	case 2:
		Eprom.GuardaMemoria2(Temperatura, VelocidadAire);
		break;
	case 3:
		Eprom.GuardaMemoria3(Temperatura, VelocidadAire);
		break;
	}
	/*
	//hay que guarar la informacion
 	uint16_t datos_w[2];
 	datos_w[0]=Temperatura;
 	datos_w[1]=VelocidadAire;
	HAL_I2C_Mem_Write(&hi2c1,ADDRESS_EEPROM,DireccionMemoria,I2C_MEMADD_SIZE_8BIT,(uint8_t*)datos_w,4,HAL_MAX_DELAY);
	*/
	 ManejadorPantallas.MuestraMenuPrincipal();
}
void CConfigurarPantallaMemoria::OnBotonDosClickEvent()
{
	 ManejadorPantallas.MuestraMenuPrincipal();

}
