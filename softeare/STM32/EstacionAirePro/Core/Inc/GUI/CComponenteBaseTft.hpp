/*
 * CComponenteBaseTft.hpp
 *
 *  Created on: Jul 23, 2024
 *      Author: W10
 */

#ifndef INC_GUI_CCOMPONENTEBASETFT_HPP_
#define INC_GUI_CCOMPONENTEBASETFT_HPP_
#include "ILI9341/ILI9341_GFX.hpp"
#include "Constantes.hpp"
#include "stdio.h"
#include <stdarg.h>
#include "string.h"
class CComponenteBaseTft
{
private:
    int CursorX=0;
    int CursorY=0;
    int TextSize;
    int ColorTexto;
protected:
	int BackColor = COLOR::BLACK;       //color de fondo

public:
	CComponenteBaseTft();
	virtual ~CComponenteBaseTft();
	//creo una capa que envuelve todas las funciones de la pantalla tft para mejorar el codigo
	virtual void drawPixel(int16_t x, int16_t y, uint16_t color);
	virtual void startWrite(void);
	virtual void writePixel(int16_t x, int16_t y, uint16_t color);
	virtual void writeFillRect(int16_t x, int16_t y, int16_t w, int16_t h,
			uint16_t color);
	virtual void writeFastVLine(int16_t x, int16_t y, int16_t h,
			uint16_t color);
	virtual void writeFastHLine(int16_t x, int16_t y, int16_t w,
			uint16_t color);
	virtual void writeLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
			uint16_t color);
	virtual void endWrite(void);
	virtual void setRotation(uint8_t r);
	virtual void invertDisplay(bool i);
	virtual void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
	virtual void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
	virtual void fillRect(int16_t x, int16_t y, int16_t w, int16_t h,
			uint16_t color);
	virtual void fillScreen(uint16_t color);
	virtual void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
			uint16_t color);
	virtual void drawRect(int16_t x, int16_t y, int16_t w, int16_t h,
			uint16_t color);
	void drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
	void drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,
			uint16_t color);
	void fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
	void fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,
			int16_t delta, uint16_t color);
	void drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
			int16_t x2, int16_t y2, uint16_t color);
	void fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
			int16_t x2, int16_t y2, uint16_t color);
	void drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h,
			int16_t radius, uint16_t color);
	void fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h,
			int16_t radius, uint16_t color);
	void drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w,
			int16_t h, uint16_t color);
	void drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w,
			int16_t h, uint16_t color, uint16_t bg);
	void drawBitmap(int16_t x, int16_t y, uint8_t *bitmap, int16_t w, int16_t h,
			uint16_t color);
	void drawBitmap(int16_t x, int16_t y, uint8_t *bitmap, int16_t w, int16_t h,
			uint16_t color, uint16_t bg);
	void drawXBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w,
			int16_t h, uint16_t color);
	void drawGrayscaleBitmap(int16_t x, int16_t y, const uint8_t bitmap[],
			int16_t w, int16_t h);
	void drawGrayscaleBitmap(int16_t x, int16_t y, uint8_t *bitmap, int16_t w,
			int16_t h);
	void drawGrayscaleBitmap(int16_t x, int16_t y, const uint8_t bitmap[],
			const uint8_t mask[], int16_t w, int16_t h);
	void drawGrayscaleBitmap(int16_t x, int16_t y, uint8_t *bitmap,
			uint8_t *mask, int16_t w, int16_t h);
	void drawRGBBitmap(int16_t x, int16_t y, const uint16_t bitmap[], int16_t w,
			int16_t h);
	void drawRGBBitmap(int16_t x, int16_t y, uint16_t *bitmap, int16_t w,
			int16_t h);
	void drawRGBBitmap(int16_t x, int16_t y, const uint16_t bitmap[],
			const uint8_t mask[], int16_t w, int16_t h);
	void drawRGBBitmap(int16_t x, int16_t y, uint16_t *bitmap, uint8_t *mask,
			int16_t w, int16_t h);
	void drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color,
			uint16_t bg, uint8_t size);
	void drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color,
			uint16_t bg, uint8_t size_x, uint8_t size_y);
	void getTextBounds(const char *string, int16_t x, int16_t y, int16_t *x1,
			int16_t *y1, uint16_t *w, uint16_t *h);
	void setTextSize(uint8_t s);
	void setTextSize(uint8_t sx, uint8_t sy);
	void setCursor(int16_t x, int16_t y);
	void setTextColor(uint16_t c);
	void setTextColor(uint16_t c, uint16_t bg);
	void setTextWrap(bool w);
	void cp437(bool x = true);
	int16_t width(void);
	int16_t height(void);
	uint8_t getRotation(void);
	int16_t getCursorX(void);
	int16_t getCursorY(void);
	void println(char *texto);
	void print(char *texto);
	void println(unsigned int num, int base);
	void print(unsigned int num, int base);
	void printf(char *formato, ...);
};

#endif /* INC_GUI_CCOMPONENTEBASETFT_HPP_ */
