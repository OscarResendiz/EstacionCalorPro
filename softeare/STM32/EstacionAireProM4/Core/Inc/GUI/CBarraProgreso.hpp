/*
 * CBarraProgreso.hpp
 *
 *  Created on: Oct 31, 2024
 *      Author: W10
 */

#ifndef INC_GUI_CBARRAPROGRESO_HPP_
#define INC_GUI_CBARRAPROGRESO_HPP_
#include <GUI/CRectanguloTft.hpp>

class CBarraProgreso: public CRectanguloTft
{
private:
	int Maximo;
	int Valor;
	int ColorBarra;
public:
	CBarraProgreso(int xi = 0, int yi = 0, int ancho = 0, int alto = 0,	int backColor = COLOR::WHITE,int colorBarra = COLOR::GREEN, int contorno = 0, int colorContorno =	COLOR::WHITE);
	virtual ~CBarraProgreso();
	void SetMaximo(int maximo);
	void SetValor(int valor);
	virtual void Show();
};

#endif /* INC_GUI_CBARRAPROGRESO_HPP_ */
