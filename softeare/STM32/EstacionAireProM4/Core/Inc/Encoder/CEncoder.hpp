/*
 * Encoder.hpp
 * clase que controla el encoder
 *  Created on: Jul 19, 2024
 *      Author: W10
 */

#ifndef ENCODER_HPP_
#define ENCODER_HPP_
#include "Boton/CManejadorEventosBoton.hpp"
#include "Boton/CManejadorBoton.hpp"
#include "Encoder/CManejadorEventosEncoder.hpp"
#define ID_CLK 1
#define ID_DT 2
#define ID_BOTON 3

class CEncoder: CManejadorEventosBoton
{
private:
	GPIO_TypeDef *Clk_Port;
	uint16_t PinClk;

	GPIO_TypeDef *Dt_Port;
	uint16_t PinDt;

	GPIO_TypeDef *Boton_Port;
	uint16_t PinBoton;

	CManejadorBoton *Boton;
	CManejadorEventosEncoder *Manejador;

	int ID_Encoder;
	int CLK_status = 0;
	int DT_status = 0;
	int CLK_Rebotes = 0;
	int DT_Rebotes = 0;
	int CLK_PreStatus = 0;
	int DT_PreStatus = 0;
	int CLK_statusAnterior;
	int DT_statusAnterior;
	int estado;
public:
	CEncoder();
	virtual ~CEncoder();
	void Configurar(GPIO_TypeDef *clk_Port, uint16_t pinClk,GPIO_TypeDef *dt_Port, uint16_t pinDt, GPIO_TypeDef *boton_Port,uint16_t pinBoton, int id_Encoder);
	void Init();
	void AsignaManejadorEventos(CManejadorEventosEncoder *manejador);
	virtual void Procesa(int gpio_pin);
protected:
	int LeeClk();
	int LeeDt();
	virtual void OnBotonClickEvent(int idBoton);
	void leeEncoder(int gpio_pin);
	void incrementa();
	void decrementa();

};

#endif /* ENCODER_HPP_ */
