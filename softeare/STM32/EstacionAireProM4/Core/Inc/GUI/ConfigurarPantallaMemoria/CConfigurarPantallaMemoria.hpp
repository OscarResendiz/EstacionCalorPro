/*
 * CConfigurarPantallaMemoria.hpp
 *
 *  Created on: Sep 26, 2024
 *      Author: W10
 */

#ifndef INC_GUI_CONFIGURARPANTALLAMEMORIA_CCONFIGURARPANTALLAMEMORIA_HPP_
#define INC_GUI_CONFIGURARPANTALLAMEMORIA_CCONFIGURARPANTALLAMEMORIA_HPP_
#include "GUI/CPantallaBase.hpp"

class CConfigurarPantallaMemoria: public CPantallaBase
{
private:
	CEtiquetaTft *LabelGuardar;
	CEtiquetaTft *LabelCancelar;
	CEtiquetaTft *LabelMemoria;
	CEtiquetaTft *LabelTemperatura;
	CEtiquetaTft *LabelTemperaturas;
	CEtiquetaTft *LabelAire;
	int NumeroMemoria;
//	int DireccionMemoria;
	int Temperatura;
	int VelocidadAire=0;
	int TemperaturaAnterior;
	int VelocidadAireAnterior;
	int VelocidadAireInicialPotenciometro;

	void LeeDatosMemoria();
//	int DameDireccionMemoria();
	void MuestraInformacion();
public:
	CConfigurarPantallaMemoria();
	virtual ~CConfigurarPantallaMemoria();
	virtual void Show();
	virtual void Refresca();
	virtual void SetMemoria(int numeroMemoria);
	virtual void OnPerillaIncremento();
	virtual void OnPerillaDecremento();
	virtual void OnBotonUnoClickEvent();
	virtual void OnBotonDosClickEvent();

};

#endif /* INC_GUI_CONFIGURARPANTALLAMEMORIA_CCONFIGURARPANTALLAMEMORIA_HPP_ */
