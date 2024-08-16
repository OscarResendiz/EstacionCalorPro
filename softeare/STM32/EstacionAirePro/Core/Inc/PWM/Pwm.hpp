/*
 * Pwm.h
 *
 *  Created on: Aug 14, 2024
 *      Author: W10
 */

#ifndef INC_PWM_PWM_HPP_
#define INC_PWM_PWM_HPP_
#include "stm32f1xx_hal.h"

class Pwm
{
private:
	TIM_HandleTypeDef Htim;
	void Error_Handler(void);
	void HAL_TIM_MspPostInit(TIM_HandleTypeDef* htim);

public:
	Pwm();
	virtual ~Pwm();
	void Init(TIM_TypeDef * timer, int chanel,int periodo); //=65535
	void SicloTrabajo(int siclo);
};

#endif /* INC_PWM_PWM_HPP_ */
