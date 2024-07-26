/*
 * Principal.c
 *
 *  Created on: Jul 16, 2024
 *      Author: W10
 */
#include "Principal.hpp"
#include <stdio.h>
#include "Uart/Uart.hpp"
#include "max6675/max6675.hpp"
#include "ControlVelocidadAire/ControlVelocidadAire.hpp"
#include "Boton/CManejadorBoton.hpp"
#include <ILI9341/ILI9341_GFX.hpp>
#include <ILI9341/ILI9341_STM32_Driver.hpp>
#include <ILI9341/ILI9341_Touchscreen.hpp>
#include "GUI/CRectanguloTft.hpp"
#include "GUI/CEtiquetaTft.hpp"
#include "GUI/CPantallaBase.hpp"
#include "GUI/PantallaManual/CPantallaManual.hpp"
#include <Estaciones/CestacionVirtual.hpp>

//max6675 max6675;
ControlVelocidadAire controlVelocidadAire;
MAX6675 *max6675;
CManejadorBoton boton1;
CManejadorBoton boton2;
CManejadorBoton boton3;
CManejadorBoton boton4;
CManejadorBoton botonEncoder;
CestacionVirtual *estacion;
void IncializaSistema()
{
	USART1_UART_Init();
	estacion=new CestacionVirtual();
	max6675=new MAX6675();
	max6675->SetConfigCkPin(GPIOA, GPIO_PIN_1);
	max6675->SetConfigCsPin(GPIOA, GPIO_PIN_2);
	max6675->SetConfigDatPin(GPIOA, GPIO_PIN_0);
	max6675->Init();
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
	ILI9341_Init(); //initial driver setup to drive ili9341
	ILI9341_Fill_Screen(WHITE);
	ILI9341_Set_Rotation(SCREEN_HORIZONTAL_2);

}
void EjecutaSistema()
{
	float temperatura;
	char texto[100];
	int x = 0;
	int velocidadAire = 0;
	PruebaPantalla2();
	while (1)
	{
		temperatura = max6675->MAX6675_lee();
		SerialPrintf((char*) "temperatura %.2f <>%f\n\r", temperatura,temperatura);
		temperatura=estacion->GetTemperaturaReal();
		SerialPrintf((char*) "temperatura2 %.2f <>%f\n\r", temperatura,temperatura);
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
		HAL_Delay(1);
	}
}
void PruebaPantalla2()
{
	CPantallaManual *pantalla=new CPantallaManual();
	pantalla->SetEstacion(estacion);
	pantalla->Show();
	while(1)
	{
		estacion->Procesa();
		HAL_Delay(1);
	}
//	CRectanguloTft *rec=new CRectanguloTft(10, 20, 100, 50,	COLOR::RED, 1, COLOR::BLUE);
	//rec->Show();
//	CEtiquetaTft *label=new CEtiquetaTft(50, 100, 200, 50, COLOR::BLACK, "Hola oscar",COLOR::WHITE,3,0,COLOR::WHITE);
	//label->Show();
}

void PruebaPantalla()
{
	ILI9341_Draw_Text("FPS TEST, 40 loop 2 screens", 10, 10, BLACK, 1,
	WHITE);
	HAL_Delay(2000);
	ILI9341_Fill_Screen(WHITE);

	uint32_t Timer_Counter = 0;
	for (uint32_t j = 0; j < 2; j++)
	{
		for (uint16_t i = 0; i < 10; i++)
		{
			ILI9341_Fill_Screen(WHITE);
			ILI9341_Fill_Screen(BLACK);
		}

	}
	Timer_Counter /= 2;

	char counter_buff[30];
	ILI9341_Fill_Screen(WHITE);
	ILI9341_Set_Rotation(SCREEN_HORIZONTAL_2);
	sprintf(counter_buff, "Timer counter value: ");
	ILI9341_Draw_Text(counter_buff, 10, 10, BLACK, 1, WHITE);

	sprintf(counter_buff, "Time: .3f Sec");
	ILI9341_Draw_Text(counter_buff, 10, 30, BLACK, 2, WHITE);

	sprintf(counter_buff, "FPS:  .2f");
	ILI9341_Draw_Text(counter_buff, 10, 50, BLACK, 2, WHITE);
	sprintf(counter_buff, "MB/S: .2f");
	ILI9341_Draw_Text(counter_buff, 10, 70, BLACK, 2, WHITE);
	sprintf(counter_buff, "SPI Utilized: .2f");
	ILI9341_Draw_Text(counter_buff, 10, 90, BLACK, 2, WHITE);
	HAL_Delay(10000);

	static uint16_t x = 0;
	static uint16_t y = 0;

	char Temp_Buffer_text[40];

//----------------------------------------------------------COUNTING MULTIPLE SEGMENTS
	ILI9341_Fill_Screen(WHITE);
	ILI9341_Set_Rotation(SCREEN_HORIZONTAL_2);
	ILI9341_Draw_Text("Counting multiple segments at once", 10, 10, BLACK, 1,
			WHITE);
	HAL_Delay(2000);
	ILI9341_Fill_Screen(WHITE);

	for (uint16_t i = 0; i <= 10; i++)
	{
		sprintf(Temp_Buffer_text, "Counting: %d", i);
		ILI9341_Draw_Text(Temp_Buffer_text, 10, 10, BLACK, 2, WHITE);
		ILI9341_Draw_Text(Temp_Buffer_text, 10, 30, BLUE, 2, WHITE);
		ILI9341_Draw_Text(Temp_Buffer_text, 10, 50, RED, 2, WHITE);
		ILI9341_Draw_Text(Temp_Buffer_text, 10, 70, GREEN, 2, WHITE);
		ILI9341_Draw_Text(Temp_Buffer_text, 10, 90, BLACK, 2, WHITE);
		ILI9341_Draw_Text(Temp_Buffer_text, 10, 110, BLUE, 2, WHITE);
		ILI9341_Draw_Text(Temp_Buffer_text, 10, 130, RED, 2, WHITE);
		ILI9341_Draw_Text(Temp_Buffer_text, 10, 150, GREEN, 2, WHITE);
		ILI9341_Draw_Text(Temp_Buffer_text, 10, 170, WHITE, 2, BLACK);
		ILI9341_Draw_Text(Temp_Buffer_text, 10, 190, BLUE, 2, BLACK);
		ILI9341_Draw_Text(Temp_Buffer_text, 10, 210, RED, 2, BLACK);
	}

	HAL_Delay(1000);

//----------------------------------------------------------COUNTING SINGLE SEGMENT
	ILI9341_Fill_Screen(WHITE);
	ILI9341_Set_Rotation(SCREEN_HORIZONTAL_2);
	ILI9341_Draw_Text("Counting single segment", 10, 10, BLACK, 1, WHITE);
	HAL_Delay(2000);
	ILI9341_Fill_Screen(WHITE);

	for (uint16_t i = 0; i <= 100; i++)
	{
		sprintf(Temp_Buffer_text, "Counting: %d", i);
		ILI9341_Draw_Text(Temp_Buffer_text, 10, 10, BLACK, 3, WHITE);
	}

	HAL_Delay(1000);

//----------------------------------------------------------ALIGNMENT TEST
	ILI9341_Fill_Screen(WHITE);
	ILI9341_Set_Rotation(SCREEN_HORIZONTAL_2);
	ILI9341_Draw_Text("Rectangle alignment check", 10, 10, BLACK, 1, WHITE);
	HAL_Delay(2000);
	ILI9341_Fill_Screen(WHITE);

	ILI9341_Draw_Hollow_Rectangle_Coord(50, 50, 100, 100, BLACK);
	ILI9341_Draw_Filled_Rectangle_Coord(20, 20, 50, 50, BLACK);
	ILI9341_Draw_Hollow_Rectangle_Coord(10, 10, 19, 19, BLACK);
	HAL_Delay(1000);

//----------------------------------------------------------LINES EXAMPLE
	ILI9341_Fill_Screen(WHITE);
	ILI9341_Set_Rotation(SCREEN_HORIZONTAL_2);
	ILI9341_Draw_Text("Randomly placed and sized", 10, 10, BLACK, 1, WHITE);
	ILI9341_Draw_Text("Horizontal and Vertical lines", 10, 20, BLACK, 1,
	WHITE);
	HAL_Delay(2000);
	ILI9341_Fill_Screen(WHITE);

	for (uint32_t i = 0; i < 30000; i++)
	{
		uint32_t random_num = 0;
		uint16_t xr = 0;
		uint16_t yr = 0;
		uint16_t radiusr = 0;
		uint16_t colourr = 0;
		xr = random_num;
		yr = random_num;
		radiusr = random_num;
		colourr = random_num;

		xr &= 0x01FF;
		yr &= 0x01FF;
		radiusr &= 0x001F;
		ILI9341_Draw_Horizontal_Line(xr, yr, radiusr, colourr);
		ILI9341_Draw_Vertical_Line(xr, yr, radiusr, colourr);
	}

	HAL_Delay(1000);

//----------------------------------------------------------HOLLOW CIRCLES EXAMPLE
	ILI9341_Fill_Screen(WHITE);
	ILI9341_Set_Rotation(SCREEN_HORIZONTAL_2);
	ILI9341_Draw_Text("Randomly placed and sized", 10, 10, BLACK, 1, WHITE);
	ILI9341_Draw_Text("Circles", 10, 20, BLACK, 1, WHITE);
	HAL_Delay(2000);
	ILI9341_Fill_Screen(WHITE);

	for (uint32_t i = 0; i < 3000; i++)
	{
		uint32_t random_num = 0;
		uint16_t xr = 0;
		uint16_t yr = 0;
		uint16_t radiusr = 0;
		uint16_t colourr = 0;
		xr = random_num;
		yr = random_num;
		radiusr = random_num;
		colourr = random_num;

		xr &= 0x01FF;
		yr &= 0x01FF;
		radiusr &= 0x001F;
		ILI9341_Draw_Hollow_Circle(xr, yr, radiusr * 2, colourr);
	}
	HAL_Delay(1000);

//----------------------------------------------------------FILLED CIRCLES EXAMPLE
	ILI9341_Fill_Screen(WHITE);
	ILI9341_Set_Rotation(SCREEN_HORIZONTAL_2);
	ILI9341_Draw_Text("Randomly placed and sized", 10, 10, BLACK, 1, WHITE);
	ILI9341_Draw_Text("Filled Circles", 10, 20, BLACK, 1, WHITE);
	HAL_Delay(2000);
	ILI9341_Fill_Screen(WHITE);

	for (uint32_t i = 0; i < 1000; i++)
	{
		uint32_t random_num = 0;
		uint16_t xr = 0;
		uint16_t yr = 0;
		uint16_t radiusr = 0;
		uint16_t colourr = 0;
		xr = random_num;
		yr = random_num;
		radiusr = random_num;
		colourr = random_num;

		xr &= 0x01FF;
		yr &= 0x01FF;
		radiusr &= 0x001F;
		ILI9341_Draw_Filled_Circle(xr, yr, radiusr / 2, colourr);
	}
	HAL_Delay(1000);

//----------------------------------------------------------HOLLOW RECTANGLES EXAMPLE
	ILI9341_Fill_Screen(WHITE);
	ILI9341_Set_Rotation(SCREEN_HORIZONTAL_2);
	ILI9341_Draw_Text("Randomly placed and sized", 10, 10, BLACK, 1, WHITE);
	ILI9341_Draw_Text("Rectangles", 10, 20, BLACK, 1, WHITE);
	HAL_Delay(2000);
	ILI9341_Fill_Screen(WHITE);

	for (uint32_t i = 0; i < 20000; i++)
	{
		uint32_t random_num = 0;
		uint16_t xr = 0;
		uint16_t yr = 0;
		uint16_t radiusr = 0;
		uint16_t colourr = 0;
		xr = random_num;
		yr = random_num;
		radiusr = random_num;
		colourr = random_num;

		xr &= 0x01FF;
		yr &= 0x01FF;
		radiusr &= 0x001F;
		ILI9341_Draw_Hollow_Rectangle_Coord(xr, yr, xr + radiusr, yr + radiusr,
				colourr);
	}
	HAL_Delay(1000);

//----------------------------------------------------------FILLED RECTANGLES EXAMPLE
	ILI9341_Fill_Screen(WHITE);
	ILI9341_Set_Rotation(SCREEN_HORIZONTAL_2);
	ILI9341_Draw_Text("Randomly placed and sized", 10, 10, BLACK, 1, WHITE);
	ILI9341_Draw_Text("Filled Rectangles", 10, 20, BLACK, 1, WHITE);
	HAL_Delay(2000);
	ILI9341_Fill_Screen(WHITE);

	for (uint32_t i = 0; i < 20000; i++)
	{
		uint32_t random_num = 0;
		uint16_t xr = 0;
		uint16_t yr = 0;
		uint16_t radiusr = 0;
		uint16_t colourr = 0;
		xr = random_num;
		yr = random_num;
		radiusr = random_num;
		colourr = random_num;

		xr &= 0x01FF;
		yr &= 0x01FF;
		radiusr &= 0x001F;
		ILI9341_Draw_Rectangle(xr, yr, radiusr, radiusr, colourr);
	}
	HAL_Delay(1000);

//----------------------------------------------------------INDIVIDUAL PIXEL EXAMPLE

	ILI9341_Fill_Screen(WHITE);
	ILI9341_Set_Rotation(SCREEN_HORIZONTAL_2);
	ILI9341_Draw_Text("Slow draw by selecting", 10, 10, BLACK, 1, WHITE);
	ILI9341_Draw_Text("and adressing pixels", 10, 20, BLACK, 1, WHITE);
	HAL_Delay(2000);
	ILI9341_Fill_Screen(WHITE);

	x = 0;
	y = 0;
	while (y < 240)
	{
		while ((x < 320) && (y < 240))
		{

			if (x % 2)
			{
				ILI9341_Draw_Pixel(x, y, BLACK);
			}

			x++;
		}

		y++;
		x = 0;
	}

	x = 0;
	y = 0;

	while (y < 240)
	{
		while ((x < 320) && (y < 240))
		{

			if (y % 2)
			{
				ILI9341_Draw_Pixel(x, y, BLACK);
			}

			x++;
		}

		y++;
		x = 0;
	}
	HAL_Delay(2000);
}

