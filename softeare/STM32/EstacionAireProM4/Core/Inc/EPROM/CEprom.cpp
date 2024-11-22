/*
 * CEprom.cpp
 *
 *  Created on: Oct 29, 2024
 *      Author: W10
 */

#include <EPROM/CEprom.hpp>
#include "stm32f4xx.h"
#include "stm32f4xx_hal_conf.h"
extern I2C_HandleTypeDef hi2c1;

CEprom::CEprom()
{
	// TODO Auto-generated constructor stub
	Diferencia = -1;
	TemperaturaManual = -1;
	Memoria1_Temperatura = -1;
	Memoria1_VelocidadAire = -1;
	Memoria2_Temperatura = -1;
	Memoria2_VelocidadAire = -1;
	Memoria3_Temperatura = -1;
	Memoria3_VelocidadAire = -1;
	NRampas=-1;

}

CEprom::~CEprom()
{
	// TODO Auto-generated destructor stub
}

int CEprom::DameTemperaturaManual()
{
	if (TemperaturaManual != -1)
		return TemperaturaManual;
	uint16_t temperatura;
	if (HAL_I2C_Mem_Read(&hi2c1, ADDRESS_EEPROM, TEMPERATURAMANUAL, I2C_MEMADD_SIZE_8BIT, (uint8_t*) &temperatura, 2, HAL_MAX_DELAY) == HAL_OK)
	{
		if (temperatura >= 0 && temperatura <= 500)
		{
			TemperaturaManual = temperatura;
		}
	}
	return TemperaturaManual;
}

void CEprom::GuardaTemepraturaManual(int temperatura)
{
	TemperaturaManual = temperatura;
	HAL_I2C_Mem_Write(&hi2c1, ADDRESS_EEPROM, TEMPERATURAMANUAL, I2C_MEMADD_SIZE_8BIT, (uint8_t*) &temperatura, 2, HAL_MAX_DELAY);
}

int CEprom::DameAjusteTemperatura()
{
	if (Diferencia != -1)
		return Diferencia;
	if (HAL_I2C_Mem_Read(&hi2c1, ADDRESS_EEPROM, AJUSTETEMPERATURA, I2C_MEMADD_SIZE_8BIT, (uint8_t*) &Diferencia, 2, HAL_MAX_DELAY) == HAL_OK)
	{
		if (Diferencia >= -500 && Diferencia <= 500)
		{
			return Diferencia;
		}
	}
	Diferencia = 0;
	return Diferencia;
}

void CEprom::GuardaAjusteTemperatura(int diferencia)
{
	Diferencia=diferencia;
	HAL_I2C_Mem_Write(&hi2c1,ADDRESS_EEPROM,AJUSTETEMPERATURA,I2C_MEMADD_SIZE_8BIT,(uint8_t*)&diferencia,2,HAL_MAX_DELAY);
}

int CEprom::DameTemperatuarMemoria1()
{
	if (Memoria1_Temperatura == -1)
		LeeMemoria1();
	return Memoria1_Temperatura;

}

int CEprom::DameVelocidadMemoria1()
{
	if (Memoria1_VelocidadAire == -1)
		LeeMemoria1();
	return Memoria1_VelocidadAire;
}

void CEprom::GuardaMemoria1(int temperatura, int velocidad)
{
	Memoria1_Temperatura = temperatura;
	Memoria1_VelocidadAire = velocidad;
	uint16_t datos_w[2];
	datos_w[0] = temperatura;
	datos_w[1] = velocidad;
	HAL_I2C_Mem_Write(&hi2c1, ADDRESS_EEPROM, MEMORIA1, I2C_MEMADD_SIZE_8BIT, (uint8_t*) datos_w, 4, HAL_MAX_DELAY);

}

int CEprom::DameTemperatuarMemoria2()
{
	if (Memoria2_Temperatura == -1)
		LeeMemoria2();
	return Memoria2_Temperatura;

}

int CEprom::DameVelocidadMemoria2()
{
	if (Memoria2_VelocidadAire == -1)
		LeeMemoria2();
	return Memoria2_VelocidadAire;
}

void CEprom::GuardaMemoria2(int temperatura, int velocidad)
{
	Memoria2_Temperatura = temperatura;
	Memoria2_VelocidadAire = velocidad;
	uint16_t datos_w[2];
	datos_w[0] = temperatura;
	datos_w[1] = velocidad;
	HAL_I2C_Mem_Write(&hi2c1, ADDRESS_EEPROM, MEMORIA2, I2C_MEMADD_SIZE_8BIT, (uint8_t*) datos_w, 4, HAL_MAX_DELAY);

}

int CEprom::DameTemperatuarMemoria3()
{
	if (Memoria3_Temperatura == -1)
		LeeMemoria3();
	return Memoria3_Temperatura;

}
int CEprom::DameVelocidadMemoria3()
{
	if (Memoria3_VelocidadAire == -1)
		LeeMemoria3();
	return Memoria3_VelocidadAire;
}
void CEprom::GuardaMemoria3(int temperatura, int velocidad)
{
	Memoria3_Temperatura = temperatura;
	Memoria3_VelocidadAire = velocidad;
	uint16_t datos_w[2];
	datos_w[0] = temperatura;
	datos_w[1] = velocidad;
	HAL_I2C_Mem_Write(&hi2c1, ADDRESS_EEPROM, MEMORIA3, I2C_MEMADD_SIZE_8BIT, (uint8_t*) datos_w, 4, HAL_MAX_DELAY);
}
void CEprom::LeeMemoria1()
{
	uint16_t datos_r[2];
	if (HAL_I2C_Mem_Read(&hi2c1, ADDRESS_EEPROM, MEMORIA1, I2C_MEMADD_SIZE_8BIT, (uint8_t*) datos_r, 4, HAL_MAX_DELAY) == HAL_OK)
	{
		Memoria1_Temperatura = datos_r[0];
		Memoria1_VelocidadAire = datos_r[1];
		if (Memoria1_Temperatura < 0 || Memoria1_Temperatura > 500)
		{
			Memoria1_Temperatura = 100;
		}
		if (Memoria1_VelocidadAire < 0 || Memoria1_VelocidadAire > 100)
		{
			Memoria1_VelocidadAire = 50;
		}
	}
}
void CEprom::LeeMemoria2()
{
	uint16_t datos_r[2];
	if (HAL_I2C_Mem_Read(&hi2c1, ADDRESS_EEPROM, MEMORIA2, I2C_MEMADD_SIZE_8BIT, (uint8_t*) datos_r, 4, HAL_MAX_DELAY) == HAL_OK)
	{
		Memoria2_Temperatura = datos_r[0];
		Memoria2_VelocidadAire = datos_r[1];
		if (Memoria2_Temperatura < 0 || Memoria2_Temperatura > 500)
		{
			Memoria2_Temperatura = 100;
		}
		if (Memoria2_VelocidadAire < 0 || Memoria2_VelocidadAire > 100)
		{
			Memoria2_VelocidadAire = 50;
		}
	}
}
void CEprom::LeeMemoria3()
{
	uint16_t datos_r[2];
	if (HAL_I2C_Mem_Read(&hi2c1, ADDRESS_EEPROM, MEMORIA3, I2C_MEMADD_SIZE_8BIT, (uint8_t*) datos_r, 4, HAL_MAX_DELAY) == HAL_OK)
	{
		Memoria3_Temperatura = datos_r[0];
		Memoria3_VelocidadAire = datos_r[1];
		if (Memoria3_Temperatura < 0 || Memoria3_Temperatura > 500)
		{
			Memoria3_Temperatura = 100;
		}
		if (Memoria3_VelocidadAire < 0 || Memoria3_VelocidadAire > 100)
		{
			Memoria3_VelocidadAire = 50;
		}
	}
}

int CEprom::DameNumeroRampas()
{
	if (NRampas != -1)
		return NRampas;
	if (HAL_I2C_Mem_Read(&hi2c1, ADDRESS_EEPROM, DIRNRAMPAS, I2C_MEMADD_SIZE_8BIT, (uint8_t*) &NRampas, 2, HAL_MAX_DELAY) == HAL_OK)
	{
			return NRampas;
	}
	NRampas = -1;
	return 0;
}
void CEprom::GuardaNumeroRampas(int nrampas)
{
	NRampas=nrampas;
	HAL_I2C_Mem_Write(&hi2c1,ADDRESS_EEPROM,DIRNRAMPAS,I2C_MEMADD_SIZE_8BIT,(uint8_t*)&NRampas,2,HAL_MAX_DELAY);

}
int CEprom::DameDireccionInicioRampas()
{
	return DIRECCION_INICIO_RAMPAS;
}
bool CEprom::GuardaBytes(int direccion, int numBytes,uint8_t* bloque)
{
	return HAL_I2C_Mem_Write(&hi2c1,ADDRESS_EEPROM,direccion,I2C_MEMADD_SIZE_8BIT,bloque,numBytes,HAL_MAX_DELAY)== HAL_OK;
}
bool CEprom::LeeBytes(int direccion, int numBytes,uint8_t* bloque)
{
	if(HAL_I2C_Mem_Read(&hi2c1, ADDRESS_EEPROM, direccion, I2C_MEMADD_SIZE_8BIT,  bloque, numBytes, HAL_MAX_DELAY) == HAL_OK)
	{
			return true;
	}
	return false;
}
bool CEprom::HayEspacio(int direccion,int nbytes)
{
	return (direccion+nbytes)<TAM_MAXIMO_MEMORIA;
}

int CEprom::DameCapacidadMaximaMemoria()
{
	return TAM_MAXIMO_MEMORIA;
}
