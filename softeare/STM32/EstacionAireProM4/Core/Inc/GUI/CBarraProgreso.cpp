/*
 * CBarraProgreso.cpp
 *
 *  Created on: Oct 31, 2024
 *      Author: W10
 */

#include <GUI/CBarraProgreso.hpp>
#include <GUI/CRectanguloTft.hpp>

CBarraProgreso::CBarraProgreso(int xi, int yi, int ancho, int alto,	int backColor,int colorBarra, int contorno, int colorContorno):
CRectanguloTft(xi,yi,ancho,alto,backColor,contorno,colorContorno)
{
	// TODO Auto-generated constructor stub
	ColorBarra=colorBarra;
}

CBarraProgreso::~CBarraProgreso()
{
	// TODO Auto-generated destructor stub
}

void CBarraProgreso::SetMaximo(int maximo)
{
	Maximo=maximo;
}
void CBarraProgreso::SetValor(int valor)
{
	Valor=valor;
}
void CBarraProgreso::Show()
{
  //dibujo el rectangulo
  fillRect(Xi, Yi, Ancho, Alto, BackColor);

  int ancho2=Valor*Ancho/Maximo;
  if(ancho2==0)
	  ancho2=1;
  fillRect(Xi, Yi, ancho2, Alto, ColorBarra);
  //hay que mostrar contorno?
  if (Contorno == 1) {
    drawRect(Xi, Yi, Ancho, Alto, ColorControrno);
  }
}
