#ifndef CRECTANGULOTFT_H
#define CRECTANGULOTFT_H
#include "CComponenteBaseTft.h"
//clase que define un rectangulo
class CRectanguloTft : public CComponenteBaseTft 
{
protected:
  int Xi, Yi, Ancho, Alto;                 //pocicion inicial y tamaño del rectangulo
  int BackColor = COLOR::BLACK;       //color de fondo
  int Contorno = 0;                   //indicador de si el rectangulo va a tener contorno 0=no 1=si
  int ColorControrno = COLOR::WHITE;  //color del contorno
public:
  //constructor
  CRectanguloTft(Adafruit_GFX *tft, int xi = 0, int yi = 0, int ancho = 0, int alto = 0, int backColor = COLOR::BLACK, int contorno = 0, int colorContorno = COLOR::WHITE)
    : CComponenteBaseTft(tft) 
    {
    Xi = xi;
    Ancho = ancho;
    Yi = yi;
    Alto = alto;
    BackColor = backColor;
    ColorControrno = colorContorno;
    Contorno = contorno;
  }
  CRectanguloTft(int xi = 0, int yi = 0, int ancho = 0, int alto = 0, int backColor = COLOR::BLACK, int contorno = 0, int colorContorno = COLOR::WHITE)
  {
    Xi = xi;
    Ancho = ancho;
    Yi = yi;
    Alto = alto;
    BackColor = backColor;
    ColorControrno = colorContorno;
    Contorno = contorno;
  }
  //muestra el rectangulo en pantalla
  virtual void Show() {
    //dibujo el rectangulo
    fillRect(Xi, Yi, Ancho, Alto, BackColor);
    //hay que mostrar contorno?
    if (Contorno == 1) {
      drawRect(Xi, Yi, Ancho, Alto, ColorControrno);
    }
  }
  virtual void CambiaPosicion(int x, int y)
  {
    Xi=x;
    Yi=y;
  }
  virtual void Redimenciona(int ancho, int alto)
  {
    Ancho=ancho;
    Alto=alto;
  }
  SetColorFondo(int color)
  {
    BackColor=color;
  }
  SetColorContorno(int color)
  {
    ColorControrno=color;
  }
  DameColorFondo()
  {
    return BackColor;
  }
  DameColorContorno()
  {
    return ColorControrno;
  }
  DamePosicionX()
  {
    return Xi;
  }
  DamePosicionY()
  {
    return Yi;
  }
  DameAncho()
  {
    return Ancho;
  }
  DameAlto()
  {
    return Alto;
  }
  //regresa el punto central del rectangulo
  int DameCentroX()
  {
    return Xi+(Ancho/2);
  }
  int DameCentroY()
  {
    return Yi+(Alto/2);
  }
};
#endif