/*
 * CPantallaCalibracion.hpp
 *
 *  Created on: Oct 22, 2024
 *      Author: W10
 */

#ifndef INC_GUI_PANTALLACALIBRACION_CPANTALLACALIBRACION_HPP_
#define INC_GUI_PANTALLACALIBRACION_CPANTALLACALIBRACION_HPP_
#include "GUI/CPantallaBase.hpp"
#include "ManejadorControles/CManejadorEventosControles.hpp"
#include "Estaciones/CEstacionBase.hpp"

class CPantallaCalibracion: public CPantallaBase
{
private:
	CEtiquetaTft *LabelGuardar;
	CEtiquetaTft *LabelCancelar;
	CEtiquetaTft *LabelTemperatura;
	CEtiquetaTft *TextTemperatura;
	CEtiquetaTft *LabelAire;
	CEtiquetaTft *LabelDiferencia;
	CEtiquetaTft *TextDiferencia;
	CEtiquetaTft *LabelTemperatura2;
	CEtiquetaTft *TextTemperatura2;

	int Temperatura;
	int Diferencia;
	int DiferenciaAnterior;
	int VelocidadAire=0;
	int VelocidadAireAnterior;
	int TemperaturaAnterior;
	bool TemperaturaODiferencia;

	void MuestraInformacion();
	void LeeMemoria();
public:
	CPantallaCalibracion();
	virtual ~CPantallaCalibracion();
	virtual void Show();
	virtual void Refresca();
	virtual void OnBotonTresClickEvent();
	virtual void OnPerillaIncremento();
	virtual void OnPerillaDecremento();
	virtual void OnBotonPerillaClickEvent();
	virtual void LeeDatosEstacion();
	virtual void OnBotonUnoClickEvent();
	virtual void SetEstacion(CEstacionBase *estacion);
};

#endif /* INC_GUI_PANTALLACALIBRACION_CPANTALLACALIBRACION_HPP_ */
