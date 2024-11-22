/*
 * CControladorRampas.hpp
 *
 *  Created on: Oct 30, 2024
 *      Author: W10
 */

#ifndef INC_GUI_RAPATEMPERATURA_CCONTROLADORRAMPAS_HPP_
#define INC_GUI_RAPATEMPERATURA_CCONTROLADORRAMPAS_HPP_
#include <RapaTemperatura/CRampa.hpp>
#include <RapaTemperatura/CPaso.hpp>
#include <EPROM/CEprom.hpp>
#include <RapaTemperatura/CControlProgreso.hpp>

class CControladorRampas
{
private:
	int const NUMERO_MAXIMO_RAMPAS=100;
	int  NUMERO_MAXIMO_PASOS=2000;
	int TotalRampas=-1;
	int DireccionInicial=-1;
	int BytesRampa=-1;
	int BytesPaso=-1;
	char Key[3];
	int DireccionKey;
	int DireccionUltimoID_Rampa;
	int DireccionUltimoID_Paso;
	uint16_t UltimoID_Rampa;
	uint16_t UltimoID_Paso;
	int DireccionTablaRampas;
	int DireccionTablaPasos;
	CControlProgreso *ControlProgreso=NULL;
	int DameSiguienteID_Rampa();
	bool EliminaPasosRampa(int ID_Rampa);
	int tmpPasos[100];
	int posicionPasoActual;
	void OrdenaPasos();
public:
	CControladorRampas();
	virtual ~CControladorRampas();
	int DameNumeroRampas();
	CRampa DameRampa(int numero);
	void ActualizadaRampa(int ID_Rampa,char *nombre);
	bool MemoriaInicialidada();
	void InicializaMemoria();
	void SetControlProgreso(CControlProgreso *controlProgreso);
	CRampa AgregaRampa(char *nombre);
	bool ActualizaRampa(int ID_Rampa, char *nombre);
	bool EliminaRampa(int ID_Rampa);
	bool AgregarPasoRampa(int ID_Rampa,uint16_t Temperatura,uint8_t NivelAire,uint8_t Segundos);
	int DameSiguienteID_Paso();
	bool ActualizaPasoRampa(int ID_Paso,int ID_Rampa,uint16_t Temperatura,uint8_t NivelAire,uint8_t Segundos);
	bool EliminaPasoRampa(int ID_Paso);
	CPaso DamePasoRampa(int ID_Paso);
	int DameNumeroPasosRampa(int ID_Rampa);
	CPaso DameSiguientePaso();
};
extern CControladorRampas ControladorRampas;
#endif /* INC_GUI_RAPATEMPERATURA_CCONTROLADORRAMPAS_HPP_ */
