/*
 * CRectanguloTft.hpp
 *
 *  Created on: Jul 24, 2024
 *      Author: W10
 */

#ifndef INC_GUI_CRECTANGULOTFT_HPP_
#define INC_GUI_CRECTANGULOTFT_HPP_
#include "GUI/CComponenteBaseTft.hpp"
#include "Constantes.hpp"

class CRectanguloTft: public CComponenteBaseTft
{
protected:
	int Xi, Yi, Ancho, Alto;          //pocicion inicial y tamaño del rectangulo
	int Contorno = 0; //indicador de si el rectangulo va a tener contorno 0=no 1=si
	int ColorControrno = COLOR::WHITE;  //color del contorno
public:
	virtual ~CRectanguloTft();
	//constructor
	CRectanguloTft(int xi = 0, int yi = 0, int ancho = 0, int alto = 0,	int backColor = COLOR::BLACK, int contorno = 0, int colorContorno =	COLOR::WHITE);
	//muestra el rectangulo en pantalla
	virtual void Show();
	virtual void CambiaPosicion(int x, int y);
	virtual void Redimenciona(int ancho, int alto);
	void SetColorFondo(int color);
	void SetColorContorno(int color);
	int DameColorFondo();
	int DameColorContorno();
	int DamePosicionX();
	int DamePosicionY();
	int DameAncho();
	int DameAlto();
	//regresa el punto central del rectangulo
	int DameCentroX();
	int DameCentroY();
};

#endif /* INC_GUI_CRECTANGULOTFT_HPP_ */
