/*
 * Encoder.cpp
 *
 *  Created on: Jul 19, 2024
 *      Author: W10
 */

#include "Encoder/CEncoder.hpp"

CEncoder::CEncoder()
{
	// TODO Auto-generated constructor stub

}

CEncoder::~CEncoder()
{
	// TODO Auto-generated destructor stub
}

void CEncoder::Configurar(GPIO_TypeDef *clk_Port, uint16_t pinClk,GPIO_TypeDef *dt_Port, uint16_t pinDt, GPIO_TypeDef *boton_Port,uint16_t pinBoton, int id_Encoder)
{
	Clk_Port = clk_Port;
	PinClk = pinClk;

	Dt_Port = dt_Port;
	PinDt = pinDt;

	Boton_Port = boton_Port;
	PinBoton = pinBoton;

	ID_Encoder = id_Encoder;
	Boton = new CManejadorBoton();
	Boton->AsignaManejadorEventos(this);
	Boton->Configurar(Boton_Port, PinBoton, ID_BOTON);
	CLK_statusAnterior = LeeClk();

}

int CEncoder::LeeClk()
{
	return HAL_GPIO_ReadPin(Clk_Port, PinClk);
}
int CEncoder::LeeDt()
{
	return HAL_GPIO_ReadPin(Dt_Port, PinDt);
}

void CEncoder::Init()
{
	GPIO_InitTypeDef GPIO_InitStruct =
	{ 0 };
	// CKL
	GPIO_InitStruct.Pin = PinClk;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(Clk_Port, &GPIO_InitStruct);
	//DT
	GPIO_InitStruct.Pin = PinDt;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(Dt_Port, &GPIO_InitStruct);
	//Boton
	GPIO_InitStruct.Pin = PinBoton;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(Boton_Port, &GPIO_InitStruct);
}

void CEncoder::AsignaManejadorEventos(CManejadorEventosEncoder *manejador)
{
	Manejador = manejador;
}

void CEncoder::OnBotonSueltoEvent(int idBoton)
{
	if (Manejador == NULL)
	{
		return;
	}
	switch (idBoton)
	{
	case ID_BOTON:
		Manejador->OnBotonEncoderSueltoEvent(ID_Encoder);
		break;
	}
}

void CEncoder::OnBotonPresionadoEvent(int idBoton)
{
	if (Manejador == NULL)
	{
		return;
	}
	switch (idBoton)
	{
	case ID_BOTON:
		Manejador->OnBotonEncoderPresionadoEvent(ID_Encoder);
		break;
	}
}

void CEncoder::OnBotonClickEvent(int idBoton, int tiempoClick)
{

	switch (idBoton)
	{
	case ID_BOTON:
		Manejador->OnBotonEncoderClickEvent(ID_Encoder, tiempoClick);
		break;
	}
}

void CEncoder::Procesa()
{
	Boton->Procesa();
	leeEncoder();
}

void CEncoder::leeEncoder()
{
	CLK_status = LeeClk();
	if (CLK_status != CLK_statusAnterior && CLK_status == 1)
	{
		if (LeeDt() != CLK_status)
		{
			incrementa();
		}
		else
		{
			decrementa();
		}
	}
	CLK_statusAnterior = CLK_status;
}

void CEncoder::incrementa()
{
	Manejador->OnIncrementoEncoder(ID_Encoder);
}

void CEncoder::decrementa()
{
	Manejador->OnDecrementoEncoder(ID_Encoder);
}
