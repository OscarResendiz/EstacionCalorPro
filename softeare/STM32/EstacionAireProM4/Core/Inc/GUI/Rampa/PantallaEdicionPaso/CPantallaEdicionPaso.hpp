/*
 * CPantallaEdicionPaso.hpp
 *
 *  Created on: Jan 8, 2025
 *      Author: W10
 */

#ifndef INC_GUI_RAMPA_PANTALLAEDICIONPASO_CPANTALLAEDICIONPASO_HPP_
#define INC_GUI_RAMPA_PANTALLAEDICIONPASO_CPANTALLAEDICIONPASO_HPP_
#include "GUI/CPantallaBase.hpp"

enum ESTADO_EDICION_PASO
{
	SELECIONANDO,
	EDITANDO
};
class CPantallaEdicionPaso: public CPantallaBase
{
private:
	int ID_Paso;
	int ID_Rampa;
	int Temperatura;
	int NivelAire;
	int Minutos;
	char TextoTiempo[100];
	CEtiquetaTft *LabelGuardar;
	CEtiquetaTft *LabelCancelar;
	CEtiquetaTft *LabelRampa;

	CEtiquetaTft *LabelTemperatura;
	CEtiquetaTft *TextTemperatura;

	CEtiquetaTft *LabelAire;
	CEtiquetaTft *TextAire;

	CEtiquetaTft *LabelTiempo;
	CEtiquetaTft *TextTiempo;

	CEtiquetaTft *Textos[3];
	int Seleccionado;
	ESTADO_EDICION_PASO Estado;
	void SegundosATexto(int tiempoMinutos);
	void NavegarIncremento();
	void NavegarDecremento();
	void ValorIncremento();
	void ValorDecremento();
	void MuestraTemperatura();
	void MuestraAire();
	void MuestraTiempo();
public:
	CPantallaEdicionPaso();
	virtual ~CPantallaEdicionPaso();
	void SetIdPaso(int id_Rampa,int id_paso);
	virtual void OnPerillaIncremento();
	virtual void OnPerillaDecremento();
	virtual void OnBotonUnoClickEvent();
	virtual void OnBotonTresClickEvent();
	virtual void Show();
	virtual void OnBotonPerillaClickEvent();

};

#endif /* INC_GUI_RAMPA_PANTALLAEDICIONPASO_CPANTALLAEDICIONPASO_HPP_ */
