/*
 * CPantallaManual.hpp
 *
 *  Created on: Jul 25, 2024
 *      Author: W10
 */

#ifndef INC_GUI_PANTALLAMANUAL_CPANTALLAMANUAL_HPP_
#define INC_GUI_PANTALLAMANUAL_CPANTALLAMANUAL_HPP_
#include "GUI/CPantallaBase.hpp"
#include "ManejadorControles/CManejadorEventosControles.hpp"
#include "Estaciones/CEstacionBase.hpp"

class CPantallaManual: public CPantallaBase
{
private:
	int SetTemperatura = 0;
	int SetTemperaturaAnterior=-1;
	int Temperatura = 0;
	int TemperaturaAnterior=-1;
	int NivelAire = 0;
	int NivelAireAnterior=-1;
	int EstadoBoquilla = 0;
	int EstadoBoquillaAnterior=-1;
	int pidAnteriro=0;
	bool TemperaturaGuardada=false;
	int tiempoescritura=0;
	CEtiquetaTft *LabelTemperatura;
	CEtiquetaTft *LabelTemperaturas;
	CEtiquetaTft *LabelAire;
	CEtiquetaTft *LabelEstado;

public:
	CPantallaManual(CEstacionBase *estacion);
	virtual ~CPantallaManual();
	CPantallaManual();
	virtual void Show();
	virtual void Refresca();

private:
	void MuestraEstado(bool forrzar);
	void MuestraNivelAire(bool forrzar);
	void LeeDatosEstacion();
	void MuestraTemperaturas(bool forrzar);
	void OnNivelAireEvent(int aire);
	virtual void OnTemperaturaRealEvent(int temperatura);
	void MuestraInformacion(bool forzar);

	//eventos del Encoder
	virtual void OnPerillaIncremento();
	virtual void OnPerillaDecremento();
	virtual void OnBotonPerillaClickEvent();

	virtual void OnBotonUnoClickEvent();
	virtual void OnBotonDosClickEvent();
	virtual void OnBotonTresClickEvent();
	void GuardaTemperatura();

};

#endif /* INC_GUI_PANTALLAMANUAL_CPANTALLAMANUAL_HPP_ */
