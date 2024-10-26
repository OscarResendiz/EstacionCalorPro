/*
 * CEtiquetaTft.hpp
 *
 *  Created on: Jul 24, 2024
 *      Author: W10
 */

#ifndef INC_GUI_CETIQUETATFT_HPP_
#define INC_GUI_CETIQUETATFT_HPP_
#include "GUI/CRectanguloTft.hpp"
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
	virtual ~CEtiquetaTft();
	  CEtiquetaTft(int xi = 0, int yi = 0, int ancho = 0, int alto = 0, int backColor = COLOR::BLACK, char *texto=(char *)"", int colorTexto=COLOR::WHITE,int textSize=3,int contorno = 0, int colorContorno = COLOR::WHITE);
	  void SetTexto(char *formato, ...);
	  char * DameTexto();
	  void SetSeparacion(int izquieda,int arriba );
	  int DameSeparacionArriba();
	  int DameSeparacionIzquierda();
	  void SetColorTexto(int color);
	  int DameColorTexto();
	  virtual void Show();
	  void SetTextSize(int textZize);
	  int DameTextSize();
	  void SetBackColor(int color);
	  virtual void LimpiaTexto();
};

#endif /* INC_GUI_CETIQUETATFT_HPP_ */
