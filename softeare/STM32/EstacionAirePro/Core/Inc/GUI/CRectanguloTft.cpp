/*
 * CRectanguloTft.cpp
 *
 *  Created on: Jul 24, 2024
 *      Author: W10
 */

#include <GUI/CRectanguloTft.hpp>

CRectanguloTft::~CRectanguloTft()
{
	// TODO Auto-generated destructor stub
}

CRectanguloTft::CRectanguloTft(int xi, int yi, int ancho , int alto , int backColor , int contorno , int colorContorno )
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

void CRectanguloTft::Show()
{
  //dibujo el rectangulo
  fillRect(Xi, Yi, Ancho, Alto, BackColor);
  //hay que mostrar contorno?
  if (Contorno == 1) {
    drawRect(Xi, Yi, Ancho, Alto, ColorControrno);
  }
}

void CRectanguloTft::CambiaPosicion(int x, int y)
{
  Xi=x;
  Yi=y;
}

void CRectanguloTft::Redimenciona(int ancho, int alto)
{
  Ancho=ancho;
  Alto=alto;
}

void CRectanguloTft::SetColorFondo(int color)
{
  BackColor=color;
}

void CRectanguloTft::SetColorContorno(int color)
{
  ColorControrno=color;
}

int CRectanguloTft::DameColorFondo()
{
  return BackColor;
}

int CRectanguloTft::DameColorContorno()
{
  return ColorControrno;
}

int CRectanguloTft::DamePosicionX()
{
  return Xi;
}

int CRectanguloTft::DamePosicionY()
{
  return Yi;
}

int CRectanguloTft::DameAncho()
{
  return Ancho;
}

int CRectanguloTft::DameAlto()
{
  return Alto;
}

//regresa el punto central del rectangulo
int CRectanguloTft::DameCentroX()
{
  return Xi+(Ancho/2);
}

int CRectanguloTft::DameCentroY()
{
  return Yi+(Alto/2);
}
