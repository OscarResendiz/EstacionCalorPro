/*
 * ControlVelocidadAire.h
 *
 *  Created on: Jul 18, 2024
 *      Author: W10
 */

#ifndef CONTROLVELOCIDADAIRE_H_
#define CONTROLVELOCIDADAIRE_H_
#include "stm32f4xx.h"

class ControlVelocidadAire {
private:
	ADC_HandleTypeDef hadc1;
public:
	ControlVelocidadAire();
	virtual ~ControlVelocidadAire();
	void Inicializa();
	int LeeVelocidad();
private:
	void Error_Handler(void);
};

#endif /* CONTROLVELOCIDADAIRE_H_ */
