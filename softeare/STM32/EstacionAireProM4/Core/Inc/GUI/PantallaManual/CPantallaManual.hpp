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
	int TemperaturaAnterior=-1;
	int NivelAireAnterior=-1;
	int EstadoBoquilla = 0;
	int EstadoBoquillaAnterior=-1;
	int pidAnteriro=0;
	bool TemperaturaGuardada=false;
	int tiempoescritura=0;
protected:
	int Temperatura = 0;
	CEtiquetaTft *LabelTemperatura;
	CEtiquetaTft *LabelTemperaturas;
	CEtiquetaTft *LabelAire;
	CEtiquetaTft *LabelEstado;
	int NivelAire = 0;

public:
	CPantallaManual(CEstacionBase *estacion);
	virtual ~CPantallaManual();
	CPantallaManual();
	virtual void Show();
	virtual void Refresca();

private:
	void OnNivelAireEvent(int aire);
	virtual void OnTemperaturaRealEvent(int temperatura);

	//eventos del Encoder
	virtual void OnBotonPerillaClickEvent();

	virtual void OnBotonUnoClickEvent();
	virtual void OnBotonDosClickEvent();
	virtual void OnBotonTresClickEvent();
protected:
	virtual void OnPerillaIncremento();
	virtual void OnPerillaDecremento();
	virtual void GuardaTemperatura();
	virtual void LeeDatosEstacion();
	virtual void MuestraEstado(bool forrzar);
	void MuestraTemperaturas(bool forrzar);
	void MuestraNivelAire(bool forrzar);
	virtual void MuestraInformacion(bool forzar);
};

#endif /* INC_GUI_PANTALLAMANUAL_CPANTALLAMANUAL_HPP_ */
