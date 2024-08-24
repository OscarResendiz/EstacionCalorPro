/*
 * Calefactor.hpp
 *
 *  Created on: Aug 22, 2024
 *      Author: W10
 */

#ifndef INC_CALEFACTOR_CALEFACTOR_HPP_
#define INC_CALEFACTOR_CALEFACTOR_HPP_
#include "stm32f1xx.h"
#include "Constantes.hpp"
class Calefactor
{
private:
	GPIO_TypeDef * GPIO_Port;
	uint16_t Gpio_Pin;
	int Estado=APAGADO;
public:
	Calefactor();
	virtual ~Calefactor();
	void Configurar(GPIO_TypeDef *puerto, uint16_t pin);
	void Init();
	void Encender();
	void Apagar();
	int DameEstado();
};

#endif /* INC_CALEFACTOR_CALEFACTOR_HPP_ */
