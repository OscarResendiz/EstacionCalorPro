/*
 * CEprom.hpp
 *
 *  Created on: Oct 29, 2024
 *      Author: W10
 */

#ifndef INC_EPROM_CEPROM_HPP_
#define INC_EPROM_CEPROM_HPP_
#include "stm32f4xx.h"
#include "stm32f4xx_hal_conf.h"


class CEprom
{
private:
	int TAM_MAXIMO_MEMORIA=8192;
	int  ADDRESS_EEPROM= 0XA0;
	int  TEMPERATURAMANUAL=0;
	int  AJUSTETEMPERATURA=2;
	int  MEMORIA1=4;
	int  MEMORIA2=8;
	int  MEMORIA3=12;
	int  DIRNRAMPAS=16;
	int DIRECCION_INICIO_RAMPAS=18;
	//variables
	int Diferencia;
	int TemperaturaManual;
	int Memoria1_Temperatura;
	int Memoria1_VelocidadAire;
	int Memoria2_Temperatura;
	int Memoria2_VelocidadAire;
	int Memoria3_Temperatura;
	int Memoria3_VelocidadAire;
	int NRampas;

	void LeeMemoria1();
	void LeeMemoria2();
	void LeeMemoria3();
public:
	CEprom();
	virtual ~CEprom();
	int DameTemperaturaManual();
	void GuardaTemepraturaManual(int temperatura);
	int DameAjusteTemperatura();
	void GuardaAjusteTemperatura(int diferencia);
	int DameTemperatuarMemoria1();
	int DameVelocidadMemoria1();
	void GuardaMemoria1(int temperatura, int velocidad);
	int DameTemperatuarMemoria2();
	int DameVelocidadMemoria2();
	void GuardaMemoria2(int temperatura, int velocidad);
	int DameTemperatuarMemoria3();
	int DameVelocidadMemoria3();
	void GuardaMemoria3(int temperatura, int velocidad);
	int DameNumeroRampas();
	void GuardaNumeroRampas(int nrampas);
	int DameDireccionInicioRampas();
	bool GuardaBytes(int direccion, int numBytes, uint8_t *bloque);
	bool LeeBytes(int direccion, int numBytes, uint8_t*bloque);
	bool HayEspacio(int direccion,int nbytes);
	int DameCapacidadMaximaMemoria();
};

extern CEprom Eprom;
#endif /* INC_EPROM_CEPROM_HPP_ */
