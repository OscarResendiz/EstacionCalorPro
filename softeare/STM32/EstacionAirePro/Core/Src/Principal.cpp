/*
 * Principal.c
 *
 *  Created on: Jul 16, 2024
 *      Author: W10
 */
#include "Principal.hpp"
#include <stdio.h>
#include "Uart/Uart.hpp"
#include "Max6675/Max6675.hpp"
#include "ControlVelocidadAire/ControlVelocidadAire.hpp"
#include "Boton/CManejadorBoton.hpp"
//MAX6675 max6675;
ControlVelocidadAire controlVelocidadAire;
MAX6675 max6675;
CManejadorBoton boton1;
CManejadorBoton boton2;
CManejadorBoton boton3;
CManejadorBoton boton4;
CManejadorBoton botonEncoder;
void IncializaSistema()
{
	USART1_UART_Init();
	max6675.SetConfigCkPin(GPIOA, GPIO_PIN_1);
	max6675.SetConfigCsPin(GPIOA, GPIO_PIN_2);
	max6675.SetConfigDatPin(GPIOA, GPIO_PIN_0);
	max6675.Init();
	controlVelocidadAire.Inicializa();
	boton1.Configurar(GPIOA, GPIO_PIN_4, 1);
	boton1.Init();

	boton2.Configurar(GPIOA, GPIO_PIN_6, 2);
	boton2.Init();

	boton3.Configurar(GPIOB, GPIO_PIN_10, 3);
	boton3.Init();

	boton4.Configurar(GPIOB, GPIO_PIN_14, 4);
	boton4.Init();

	botonEncoder.Configurar(GPIOB, GPIO_PIN_13, 5);
	botonEncoder.Init();
}
void EjecutaSistema()
{
	float temperatura;
	char texto[100];
	int x = 0;
	int velocidadAire = 0;
	while (1)
	{
		temperatura = max6675.MAX6675_lee();
		SerialPrintf((char*) "temperatura %.2f \n\r", temperatura);
		velocidadAire = controlVelocidadAire.LeeVelocidad();
		SerialPrintf("Velicidad de aire: %d \n\r", velocidadAire);

		if (boton1.Leer() == 0)
			SerialPrintf("Boton1 Presionado\r\n");
		else
			SerialPrintf("Boton1 Suelto\r\n");

		if (boton2.Leer() == 0)
			SerialPrintf("Boton2 Presionado\r\n");
		else
			SerialPrintf("Boton2 Suelto\r\n");

		if (boton3.Leer() == 0)
			SerialPrintf("Boton3 Presionado\r\n");
		else
			SerialPrintf("Boton3 Suelto\r\n");

		if (boton4.Leer() == 0)
			SerialPrintf("Boton4 Presionado\r\n");
		else
			SerialPrintf("Boton4 Suelto\r\n");

		if (botonEncoder.Leer() == 0)
			SerialPrintf("Encoder Presionado\r\n");
		else
			SerialPrintf("Encoder Suelto\r\n");
		x = HAL_GetTick();
		SerialPrintf("Ticks=%d\r\n", x);
		HAL_Delay(500);
	}
}

