/*
 * CComponenteBaseTft.cpp
 *
 *  Created on: Jul 23, 2024
 *      Author: W10
 */

#include <GUI/CComponenteBaseTft.hpp>
#include "stdio.h"
#include <stdarg.h>
#include "string.h"
#include "ILI9341/ILI9341_GFX.hpp"
CComponenteBaseTft::CComponenteBaseTft()
{
	// TODO Auto-generated constructor stub

}

CComponenteBaseTft::~CComponenteBaseTft()
{
	// TODO Auto-generated destructor stub
}

//creo una capa que envuelve todas las funciones de la pantalla tft para mejorar el codigo
void CComponenteBaseTft::CComponenteBaseTft::drawPixel(int16_t x, int16_t y,
		uint16_t color)
{
	//Tft->drawPixel(x, y, color);
}

void CComponenteBaseTft::startWrite(void)
{
	//Tft->startWrite();
}
void CComponenteBaseTft::writePixel(int16_t x, int16_t y, uint16_t color)
{
	//Tft->writePixel(x, y, color);
}
void CComponenteBaseTft::writeFillRect(int16_t x, int16_t y, int16_t w,
		int16_t h, uint16_t color)
{
	//Tft->writeFillRect(x, y, w, h, color);
}
void CComponenteBaseTft::writeFastVLine(int16_t x, int16_t y, int16_t h,
		uint16_t color)
{
	//Tft->writeFastVLine(x, y, h, color);
}
void CComponenteBaseTft::writeFastHLine(int16_t x, int16_t y, int16_t w,
		uint16_t color)
{
	//Tft->writeFastHLine(x, y, w, color);
}
void CComponenteBaseTft::writeLine(int16_t x0, int16_t y0, int16_t x1,
		int16_t y1, uint16_t color)
{
	//Tft->writeLine(x0, y0, x1, y1, color);
}
void CComponenteBaseTft::endWrite(void)
{
	//Tft->endWrite();
}
void CComponenteBaseTft::setRotation(uint8_t r)
{
	//Tft->setRotation(r);
}
void CComponenteBaseTft::invertDisplay(bool i)
{
	//Tft->invertDisplay(i);
}
void CComponenteBaseTft::drawFastVLine(int16_t x, int16_t y, int16_t h,
		uint16_t color)
{
	//Tft->drawFastVLine(x, y, h, color);
}
void CComponenteBaseTft::drawFastHLine(int16_t x, int16_t y, int16_t w,
		uint16_t color)
{
	//Tft->drawFastHLine(x, y, w, color);
}
void CComponenteBaseTft::fillScreen(uint16_t color)
{
	//Tft->fillScreen(color);
}
void CComponenteBaseTft::drawLine(int16_t x0, int16_t y0, int16_t x1,
		int16_t y1, uint16_t color)
{
	//Tft->drawLine(x0, y0, x1, y1, color);
}
void CComponenteBaseTft::drawCircle(int16_t x0, int16_t y0, int16_t r,
		uint16_t color)
{
	//Tft->drawCircle(x0, y0, r, color);
}
void CComponenteBaseTft::drawCircleHelper(int16_t x0, int16_t y0, int16_t r,
		uint8_t cornername, uint16_t color)
{
	//Tft->drawCircleHelper(x0, y0, r, cornername, color);
}
void CComponenteBaseTft::fillCircle(int16_t x0, int16_t y0, int16_t r,
		uint16_t color)
{
	//Tft->fillCircle(x0, y0, r, color);
}
void CComponenteBaseTft::fillCircleHelper(int16_t x0, int16_t y0, int16_t r,
		uint8_t cornername, int16_t delta, uint16_t color)
{
	//Tft->fillCircleHelper(x0, y0, r, cornername, delta, color);
}
void CComponenteBaseTft::drawTriangle(int16_t x0, int16_t y0, int16_t x1,
		int16_t y1, int16_t x2, int16_t y2, uint16_t color)
{
	//Tft->drawTriangle(x0, y0, x1, y1, x2, y2, color);
}
void CComponenteBaseTft::fillTriangle(int16_t x0, int16_t y0, int16_t x1,
		int16_t y1, int16_t x2, int16_t y2, uint16_t color)
{
	//Tft->fillTriangle(x0, y0, x1, y1, x2, y2, color);
}
void CComponenteBaseTft::drawRoundRect(int16_t x0, int16_t y0, int16_t w,
		int16_t h, int16_t radius, uint16_t color)
{
	//Tft->drawRoundRect(x0, y0, w, h, radius, color);
}
void CComponenteBaseTft::fillRoundRect(int16_t x0, int16_t y0, int16_t w,
		int16_t h, int16_t radius, uint16_t color)
{
	//Tft->fillRoundRect(x0, y0, w, h, radius, color);
}
void CComponenteBaseTft::drawBitmap(int16_t x, int16_t y,
		const uint8_t bitmap[], int16_t w, int16_t h, uint16_t color)
{
	//Tft->drawBitmap(x, y,  bitmap, w, h, color);
}
void CComponenteBaseTft::drawBitmap(int16_t x, int16_t y,
		const uint8_t bitmap[], int16_t w, int16_t h, uint16_t color,
		uint16_t bg)
{
	//Tft->drawBitmap(x, y, bitmap, w, h, color, bg);
}
void CComponenteBaseTft::drawBitmap(int16_t x, int16_t y, uint8_t *bitmap,
		int16_t w, int16_t h, uint16_t color)
{
	//Tft->drawBitmap(x, y, bitmap, w, h, color);
}
void CComponenteBaseTft::drawBitmap(int16_t x, int16_t y, uint8_t *bitmap,
		int16_t w, int16_t h, uint16_t color, uint16_t bg)
{
	//Tft->drawBitmap(x, y, bitmap, w, h, color, bg);
}
void CComponenteBaseTft::drawXBitmap(int16_t x, int16_t y,
		const uint8_t bitmap[], int16_t w, int16_t h, uint16_t color)
{
	//Tft->drawXBitmap(x, y, bitmap, w, h, color);
}
void CComponenteBaseTft::drawGrayscaleBitmap(int16_t x, int16_t y,
		const uint8_t bitmap[], int16_t w, int16_t h)
{
	//Tft->drawGrayscaleBitmap(x, y, bitmap, w, h);
}
void CComponenteBaseTft::drawGrayscaleBitmap(int16_t x, int16_t y,
		uint8_t *bitmap, int16_t w, int16_t h)
{
	//Tft->drawGrayscaleBitmap(x, y, bitmap, w, h);
}
void CComponenteBaseTft::drawGrayscaleBitmap(int16_t x, int16_t y,
		const uint8_t bitmap[], const uint8_t mask[], int16_t w, int16_t h)
{
	//Tft->drawGrayscaleBitmap(x, y, bitmap, mask, w, h);
}
void CComponenteBaseTft::drawGrayscaleBitmap(int16_t x, int16_t y,
		uint8_t *bitmap, uint8_t *mask, int16_t w, int16_t h)
{
	//Tft->drawGrayscaleBitmap(x, y, bitmap, mask, w, h);
}
void CComponenteBaseTft::drawRGBBitmap(int16_t x, int16_t y,
		const uint16_t bitmap[], int16_t w, int16_t h)
{
	//Tft->drawRGBBitmap(x, y, bitmap, w, h);
}
void CComponenteBaseTft::drawRGBBitmap(int16_t x, int16_t y, uint16_t *bitmap,
		int16_t w, int16_t h)
{
	//Tft->drawRGBBitmap(x, y, bitmap, w, h);
}
void CComponenteBaseTft::drawRGBBitmap(int16_t x, int16_t y,
		const uint16_t bitmap[], const uint8_t mask[], int16_t w, int16_t h)
{
	//Tft->drawRGBBitmap(x, y, bitmap, mask, w, h);
}
void CComponenteBaseTft::drawRGBBitmap(int16_t x, int16_t y, uint16_t *bitmap,
		uint8_t *mask, int16_t w, int16_t h)
{
	//Tft->drawRGBBitmap(x, y, bitmap, mask, w, h);
}
void CComponenteBaseTft::drawChar(int16_t x, int16_t y, unsigned char c,
		uint16_t color, uint16_t bg, uint8_t size)
{
	//Tft->drawChar(x, y, c, color, bg, size);
}
void CComponenteBaseTft::drawChar(int16_t x, int16_t y, unsigned char c,
		uint16_t color, uint16_t bg, uint8_t size_x, uint8_t size_y)
{
	//Tft->drawChar(x, y, c, color, bg, size_x, size_y);
}
void CComponenteBaseTft::getTextBounds(const char *string, int16_t x, int16_t y,
		int16_t *x1, int16_t *y1, uint16_t *w, uint16_t *h)
{
	//Tft->getTextBounds(string, x, y, x1, y1, w, h);
}
//void CComponenteBaseTft::getTextBounds(const __FlashStringHelper *s, int16_t x,
//int16_t y, int16_t *x1, int16_t *y1, uint16_t *w, uint16_t *h)
//{
//Tft->getTextBounds(s, x, y, x1, y1, w, h);
//}
//void CComponenteBaseTft::getTextBounds(const String &str, int16_t x, int16_t y,
//int16_t *x1, int16_t *y1, uint16_t *w, uint16_t *h)
//{
//Tft->getTextBounds(str, x, y, x1, y1, w, h);
//}
//void CComponenteBaseTft::setFont(const GFXfont *f = NULL)
//{
//Tft->setFont(f);
//}
void CComponenteBaseTft::setTextColor(uint16_t c, uint16_t bg)
{
	//Tft->setTextColor(c, bg);
}
void CComponenteBaseTft::setTextWrap(bool w)
{
	//Tft->setTextWrap(w);
}
void CComponenteBaseTft::cp437(bool x)
{
	//Tft->cp437(x);
}
int16_t CComponenteBaseTft::width(void)
{
	return 319;
}
int16_t CComponenteBaseTft::height(void)
{
	return 239;
}
uint8_t CComponenteBaseTft::getRotation(void)
{
	return //Tft->getRotation();
	0;
}
int16_t CComponenteBaseTft::getCursorX(void)
{
	return //Tft->getCursorX();
	0;
}
int16_t CComponenteBaseTft::getCursorY(void)
{
	return //Tft->getCursorY();
	0;
}
void CComponenteBaseTft::println(char *texto)
{
	//Tft->println(texto);
}
void CComponenteBaseTft::println(unsigned int num, int base)
{
	//Tft->println(num, base);
}
void CComponenteBaseTft::print(unsigned int num, int base)
{
	//Tft->print(num, base);
}
void CComponenteBaseTft::printf(char *formato, ...)
{

	char *p;
	char buffer[100];
	char tmp[100];
	int postmp = 0;
	int posbuffer = 0;
	va_list pa;
	int encontrado = 0;

	va_start(pa, formato);

	for (p = formato; *p; p++)
	{

		if (*p != '%')
		{
			buffer[posbuffer] = *p;
			posbuffer++;
			continue;
		}
		encontrado = 0;
		switch (*++p)
		{
		case 'd':
			sprintf(tmp, "%d", va_arg(pa, int));
			encontrado = 1;
			break;
		case 'i':
			sprintf(tmp, "%i", va_arg(pa, int));
			encontrado = 1;
			break;
		case 'x':
			sprintf(tmp, "%x", va_arg(pa, int));
			encontrado = 1;
			break;
		case 'p':
			sprintf(tmp, "%p", va_arg(pa, int));
			encontrado = 1;
			break;
		case 'c':
			sprintf(tmp, "%c", va_arg(pa, int));
			encontrado = 1;
			break;
		case 'f':
			sprintf(tmp, "%f", va_arg(pa, int));
			encontrado = 1;
			break;
		case 's':
			sprintf(tmp, "%s", va_arg(pa, char*));
			encontrado = 1;
			break;
		default:
			buffer[posbuffer] = *p;
			posbuffer++;
			break;
		}
		if (encontrado == 1)
		{
			postmp = 0;
			while (tmp[postmp] != '\0')
			{
				buffer[posbuffer] = tmp[postmp];
				posbuffer++;
				postmp++;
			}
		}
	}
	va_end(pa);
	buffer[posbuffer] = '\0';
	print(buffer);
}
void CComponenteBaseTft::fillRect(int16_t x, int16_t y, int16_t w, int16_t h,uint16_t color)
{
	ILI9341_Draw_Filled_Rectangle_Coord(x, y, x+w, y+h, color);
}
void CComponenteBaseTft::drawRect(int16_t x, int16_t y, int16_t w, int16_t h,uint16_t color)
{
	ILI9341_Draw_Hollow_Rectangle_Coord(x, y,x+w,y+h,color);
	//Tft->drawRect(x, y, w, h, color);
}
void CComponenteBaseTft::setCursor(int16_t x, int16_t y)
{
    CursorX=x;
    CursorY=y;
}
void CComponenteBaseTft::setTextSize(uint8_t s)
{
	TextSize=s;
}
void CComponenteBaseTft::setTextSize(uint8_t sx, uint8_t sy)
{
	//Tft->setTextSize(sx, sy);
}
void CComponenteBaseTft::setTextColor(uint16_t c)
{
	ColorTexto=c;
}
void CComponenteBaseTft::print(char *texto)
{
	ILI9341_Draw_Text(texto, CursorX,CursorY, ColorTexto, TextSize, BackColor);
}
