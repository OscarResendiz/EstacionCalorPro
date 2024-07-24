#ifndef CETIQUETATFT_H
#define CETIQUETATFT_H
#include "CRectanguloTft.h"
#include "CComponenteBaseTft.h"
//clase que representa una etiqueta que puede mostrar texto 
class CEtiquetaTft:public CRectanguloTft
{
  protected:
    char Texto[100];
    int ColorTexto;
    int TextSize=3;
    int SeparacionIzquierda=1; //separacion entre el borde inicial del rectangulo y el texto
    int SeparacionArriba=1; //Separacion entre el borde de arriba del rectangulo y el texto
  public:
  CEtiquetaTft(Adafruit_GFX *tft, int xi = 0, int yi = 0, int ancho = 0, int alto = 0, int backColor = COLOR::BLACK, char *texto="", int colorTexto=COLOR::WHITE,int textSize=3,int contorno = 0, int colorContorno = COLOR::WHITE)
  :CRectanguloTft(tft, xi , yi , ancho , alto , backColor , contorno ,  colorContorno )
  {
    strcpy(Texto,texto);
    ColorTexto=colorTexto;
    TextSize=textSize;
  }
  CEtiquetaTft(int xi = 0, int yi = 0, int ancho = 0, int alto = 0, int backColor = COLOR::BLACK, char *texto="", int colorTexto=COLOR::WHITE,int textSize=3,int contorno = 0, int colorContorno = COLOR::WHITE)
  :CRectanguloTft(xi , yi , ancho , alto , backColor , contorno ,  colorContorno )
  {
    strcpy(Texto,texto);
    ColorTexto=colorTexto;
    TextSize=textSize;

  }
  void SetTexto(char *formato, ...)
  {
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
    strcpy(Texto,buffer);
    //Texto=buffer;
  }
  char * DameTexto()
  {
    return Texto;
  }
  void SetSeparacion(int izquieda,int arriba )
  {
      SeparacionIzquierda=izquieda;
      SeparacionArriba=arriba;
  }
  int DameSeparacionArriba()
  {
    return SeparacionArriba;
  }
  int DameSeparacionIzquierda()
  {
    return SeparacionIzquierda;
  }
  void SetColorTexto(int color)
  {
    ColorTexto=color;
  }
  int DameColorTexto()
  {
    return ColorTexto;
  }
  virtual void Show()
  {
    //mandamos a dibujar el rectangulo
    CRectanguloTft::Show();
    //me posiciono el la pocicion del texto
    setCursor(Xi+SeparacionIzquierda,Yi+SeparacionArriba);
    //asigno tamaño de la letra
    setTextSize(TextSize);
    //asigno el color de texto
    setTextColor(ColorTexto);
    //muestro el texto;
    print(Texto);
  }
  void SetTextSize(int textZize)
  {
    TextSize=textZize;
  }
  int DameTextSize()
  {
    return TextSize;
  }
};
#endif