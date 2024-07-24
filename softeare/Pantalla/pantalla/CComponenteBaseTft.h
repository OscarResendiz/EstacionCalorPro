#ifndef CCOMPONENTEBASE_H
#define CCOMPONENTEBASE_H
#include "Adafruit_GFX.h"  // Hardware-specific library
//clase base para todo el manejo de las pantallas del sistema
class CComponenteBaseTft {
protected:
  Adafruit_GFX *Tft;  //variable que representa la pantalla
public:
  CComponenteBaseTft(Adafruit_GFX *tft) {
    Tft = tft;
  }
  CComponenteBaseTft()
  {
    Tft=NULL;
  }
  void SetTft(Adafruit_GFX *tft)
  {
    Tft = tft;
  }
  //creo una capa que envuelve todas las funciones de la pantalla tft para mejorar el codigo
  virtual void drawPixel(int16_t x, int16_t y, uint16_t color) {
    Tft->drawPixel(x, y, color);
  }

  virtual void startWrite(void) {
    Tft->startWrite();
  }
  virtual void writePixel(int16_t x, int16_t y, uint16_t color) {
    Tft->writePixel(x, y, color);
  }
  virtual void writeFillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
    Tft->writeFillRect(x, y, w, h, color);
  }
  virtual void writeFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color) {
    Tft->writeFastVLine(x, y, h, color);
  }
  virtual void writeFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color) {
    Tft->writeFastHLine(x, y, w, color);
  }
  virtual void writeLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color) {
    Tft->writeLine(x0, y0, x1, y1, color);
  }
  virtual void endWrite(void) {
    Tft->endWrite();
  }
  virtual void setRotation(uint8_t r) {
    Tft->setRotation(r);
  }
  virtual void invertDisplay(bool i) {
    Tft->invertDisplay(i);
  }
  virtual void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color) {
    Tft->drawFastVLine(x, y, h, color);
  }
  virtual void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color) {
    Tft->drawFastHLine(x, y, w, color);
  }
  virtual void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
    Tft->fillRect(x, y, w, h, color);
  }
  virtual void fillScreen(uint16_t color) {
    Tft->fillScreen(color);
  }
  virtual void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color) {
    Tft->drawLine(x0, y0, x1, y1, color);
  }
  virtual void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
    Tft->drawRect(x, y, w, h, color);
  }
  void drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color) {
    Tft->drawCircle(x0, y0, r, color);
  }
  void drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color) {
    Tft->drawCircleHelper(x0, y0, r, cornername, color);
  }
  void fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color) {
    Tft->fillCircle(x0, y0, r, color);
  }
  void fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color) {
    Tft->fillCircleHelper(x0, y0, r, cornername, delta, color);
  }
  void drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color) {
    Tft->drawTriangle(x0, y0, x1, y1, x2, y2, color);
  }
  void fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color) {
    Tft->fillTriangle(x0, y0, x1, y1, x2, y2, color);
  }
  void drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color) {
    Tft->drawRoundRect(x0, y0, w, h, radius, color);
  }
  void fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color) {
    Tft->fillRoundRect(x0, y0, w, h, radius, color);
  }
  void drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h, uint16_t color) {
    Tft->drawBitmap(x, y,  bitmap, w, h, color);
  }
  void drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h, uint16_t color, uint16_t bg) {
    Tft->drawBitmap(x, y, bitmap, w, h, color, bg);
  }
  void drawBitmap(int16_t x, int16_t y, uint8_t *bitmap, int16_t w, int16_t h, uint16_t color) {
    Tft->drawBitmap(x, y, bitmap, w, h, color);
  }
  void drawBitmap(int16_t x, int16_t y, uint8_t *bitmap, int16_t w, int16_t h, uint16_t color, uint16_t bg) {
    Tft->drawBitmap(x, y, bitmap, w, h, color, bg);
  }
  void drawXBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h, uint16_t color) {
    Tft->drawXBitmap(x, y, bitmap, w, h, color);
  }
  void drawGrayscaleBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h) {
    Tft->drawGrayscaleBitmap(x, y, bitmap, w, h);
  }
  void drawGrayscaleBitmap(int16_t x, int16_t y, uint8_t *bitmap, int16_t w, int16_t h) {
    Tft->drawGrayscaleBitmap(x, y, bitmap, w, h);
  }
  void drawGrayscaleBitmap(int16_t x, int16_t y, const uint8_t bitmap[], const uint8_t mask[], int16_t w, int16_t h) {
    Tft->drawGrayscaleBitmap(x, y, bitmap, mask, w, h);
  }
  void drawGrayscaleBitmap(int16_t x, int16_t y, uint8_t *bitmap, uint8_t *mask, int16_t w, int16_t h) {
    Tft->drawGrayscaleBitmap(x, y, bitmap, mask, w, h);
  }
  void drawRGBBitmap(int16_t x, int16_t y, const uint16_t bitmap[], int16_t w, int16_t h) {
    Tft->drawRGBBitmap(x, y, bitmap, w, h);
  }
  void drawRGBBitmap(int16_t x, int16_t y, uint16_t *bitmap, int16_t w, int16_t h) {
    Tft->drawRGBBitmap(x, y, bitmap, w, h);
  }
  void drawRGBBitmap(int16_t x, int16_t y, const uint16_t bitmap[], const uint8_t mask[], int16_t w, int16_t h) {
    Tft->drawRGBBitmap(x, y, bitmap, mask, w, h);
  }
  void drawRGBBitmap(int16_t x, int16_t y, uint16_t *bitmap, uint8_t *mask, int16_t w, int16_t h) {
    Tft->drawRGBBitmap(x, y, bitmap, mask, w, h);
  }
  void drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size) {
    Tft->drawChar(x, y, c, color, bg, size);
  }
  void drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size_x, uint8_t size_y) {
    Tft->drawChar(x, y, c, color, bg, size_x, size_y);
  }
  void getTextBounds(const char *string, int16_t x, int16_t y, int16_t *x1, int16_t *y1, uint16_t *w, uint16_t *h) {
    Tft->getTextBounds(string, x, y, x1, y1, w, h);
  }
  void getTextBounds(const __FlashStringHelper *s, int16_t x, int16_t y, int16_t *x1, int16_t *y1, uint16_t *w, uint16_t *h) {
    Tft->getTextBounds(s, x, y, x1, y1, w, h);
  }
  void getTextBounds(const String &str, int16_t x, int16_t y, int16_t *x1, int16_t *y1, uint16_t *w, uint16_t *h) {
    Tft->getTextBounds(str, x, y, x1, y1, w, h);
  }
  void setTextSize(uint8_t s) {
    Tft->setTextSize(s);
  }
  void setTextSize(uint8_t sx, uint8_t sy) {
    Tft->setTextSize(sx, sy);
  }
  void setFont(const GFXfont *f = NULL) {
    Tft->setFont(f);
  }
  void setCursor(int16_t x, int16_t y) {
    Tft->setCursor(x, y);
  }
  void setTextColor(uint16_t c) {
    Tft->setTextColor(c);
  }
  void setTextColor(uint16_t c, uint16_t bg) {
    Tft->setTextColor(c, bg);
  }
  void setTextWrap(bool w) {
    Tft->setTextWrap(w);
  }
  void cp437(bool x = true) {
    Tft->cp437(x);
  }
  int16_t width(void) {
    return Tft->width();
  }
  int16_t height(void) {
   return Tft->height();
  }
  uint8_t getRotation(void) {
    return Tft->getRotation();
  }
  int16_t getCursorX(void) {
    return Tft->getCursorX();
  }
  int16_t getCursorY(void) {
    return Tft->getCursorY();
  }
  void println(char *texto) {
    Tft->println(texto);
  }
  void print(char *texto) {
    Tft->print(texto);
  }
  void println(unsigned int num, int base) {
    Tft->println(num, base);
  }
  void print(unsigned int num, int base) {
    Tft->print(num, base);
  }
  void printf(char *formato, ...) {

    char *p;
    char buffer[100];
    char tmp[100];
    int postmp=0;
    int posbuffer = 0;
    va_list pa;
    int encontrado=0;

    va_start(pa, formato);

    for (p = formato; *p; p++) {

      if (*p != '%') {
        buffer[posbuffer] = *p;
        posbuffer++;
        continue;
      }
      encontrado=0;
      switch (*++p) {
        case 'd':
          sprintf(tmp, "%d", va_arg(pa, int));
          encontrado=1;
          break;
        case 'i':
          sprintf(tmp, "%i", va_arg(pa, int));
          encontrado=1;
          break;
        case 'x':
          sprintf(tmp, "%x", va_arg(pa, int));
          encontrado=1;
          break;
        case 'p':
          sprintf(tmp, "%p", va_arg(pa, int));
          encontrado=1;
          break;
        case 'c':
          sprintf(tmp, "%c", va_arg(pa, int));
          encontrado=1;
          break;
        case 'f':
          sprintf(tmp, "%f", va_arg(pa, int));
          encontrado=1;
          break;
        case 's':
          sprintf(tmp, "%s", va_arg(pa, char *));
          encontrado=1;
          break;
        default:
          buffer[posbuffer] = *p;
          posbuffer++;
          break;
      }
      if(encontrado==1)
      {
          postmp=0;
          while(tmp[postmp]!='\0')
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
};

#endif