/*
 * Boton.h
 *
 *  Created on: Jul 19, 2024
 *      Author: W10
 */

#ifndef BOTON_H_
#define BOTON_H_
#include "stm32f1xx.h"
#include "Boton/CManejadorEventosBoton.hpp"
class CManejadorBoton
{
private:
	GPIO_TypeDef * GPIO_Port;
	uint16_t Gpio_Pin;
	uint8_t Identificador;
	  int Estado = 1;  //1 es abierto 0 es presionado
	  int PreEstado = 1;
	  int ReboteMilis = 0;
	  int TiempoInicioClick = 0;
	  CManejadorEventosBoton *Manejador = NULL;
public:
	  CManejadorBoton();
	virtual ~CManejadorBoton();
	void Configurar(GPIO_TypeDef *puerto, uint16_t pin,uint8_t identificador);
	void Init();
	int Leer();
	void AsignaManejadorEventos(CManejadorEventosBoton * manejador);
	void Procesa(int gpio_pin);
};

#endif /* BOTON_H_ */
