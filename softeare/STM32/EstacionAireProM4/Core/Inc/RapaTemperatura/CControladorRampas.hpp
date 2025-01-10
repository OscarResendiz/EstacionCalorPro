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
	char *KEY=(char*)"002";
	int const NUMERO_MAXIMO_RAMPAS=30;
	int TotalRampas=-1;
	int DireccionInicial=-1;
	int BytesRampa=-1;
	char Key[3];
	int DireccionKey;
	int DireccionUltimoID_Rampa;
	uint16_t UltimoID_Rampa;
	int DireccionTablaRampas;
	CControlProgreso *ControlProgreso=NULL;
	int DameSiguienteID_Rampa();
	CRampa LeeRampaMemoria(int direccion);
	void GuardaRampaMemoria(int direccion, CRampa *rampa);
public:
	CControladorRampas();
	virtual ~CControladorRampas();
	int DameNumeroRampas();
	CRampa DameRampa(int id_Rampa);
	CRampa  DameRampaNumero(int posicion);
	void ActualizadaRampa(int ID_Rampa,char *nombre);
	bool MemoriaInicialidada();
	void InicializaMemoria();
	void SetControlProgreso(CControlProgreso *controlProgreso);
	CRampa AgregaRampa(char *nombre);
	bool ActualizaRampa(int ID_Rampa, char *nombre);
	bool EliminaRampa(int ID_Rampa);


};
extern CControladorRampas ControladorRampas;
#endif /* INC_GUI_RAPATEMPERATURA_CCONTROLADORRAMPAS_HPP_ */
