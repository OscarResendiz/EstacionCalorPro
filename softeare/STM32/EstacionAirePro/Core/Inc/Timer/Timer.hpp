/*
 * Timer.c
 *
 *  Created on: Sep 10, 2024
 *      Author: W10
 */

#ifndef INC_TIMER_HPP_
#define INC_TIMER_HPP_

#include "main.h"
#include <stdio.h>
#include<stdbool.h>
class CTimer
{
private:
	TIM_HandleTypeDef HTim;
	uint32_t TIM_IRQ;
	uint32_t Periodo = 1;
public:
	bool Init(TIM_TypeDef *TimInstance,uint32_t periodo,IRQn_Type Tim_Irq);
	void Start();
	void Stop();
};

#endif /* INC_TIMER_C_ */
