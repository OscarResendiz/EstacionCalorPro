/*
 * CPantallaMemoria.hpp
 *
 *  Created on: Sep 27, 2024
 *      Author: W10
 */

#ifndef INC_GUI_PANTALLAMEMORIA_CPANTALLAMEMORIA_HPP_
#define INC_GUI_PANTALLAMEMORIA_CPANTALLAMEMORIA_HPP_
#include "GUI/CPantallaBase.hpp"
#include "ManejadorControles/CManejadorEventosControles.hpp"
#include "Estaciones/CEstacionBase.hpp"

class CPantallaMemoria: public CPantallaBase
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
	int NumeroMemoria;
	CEtiquetaTft *LabelMemoria;

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
	virtual void OnBotonPerillaClickEvent(int tiempoClick);
	virtual void OnBotonUnoClickEvent(int tiempoClick);
	virtual void OnBotonDosClickEvent(int tiempoClick);
	virtual void OnBotonTresClickEvent(int tiempoClick);
	virtual void OnBotonCuatroClickEvent(int tiempoClick);
	void GuardaTemperatura();
public:
	CPantallaMemoria(CEstacionBase *estacion);
	CPantallaMemoria();
	virtual ~CPantallaMemoria();
	virtual void Show();
	virtual void Refresca();
	void SetMemoria(int numeroMemoria);
};

#endif /* INC_GUI_PANTALLAMEMORIA_CPANTALLAMEMORIA_HPP_ */
