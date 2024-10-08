/**
  ******************************************************************************
  * File Name          : SPI.c
  * Description        : This file provides code for the configuration
  *                      of the SPI instances.
  ******************************************************************************
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "spi.h"

#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

SPI_HandleTypeDef Hspi;

/* SPI5 init function */
void SPI1_Init(void)
{
	Hspi.Instance = SPI1;
	Hspi.Init.Mode = SPI_MODE_MASTER;
	Hspi.Init.Direction = SPI_DIRECTION_2LINES;
	Hspi.Init.DataSize = SPI_DATASIZE_8BIT;
	Hspi.Init.CLKPolarity = SPI_POLARITY_LOW;
	Hspi.Init.CLKPhase = SPI_PHASE_1EDGE;
	Hspi.Init.NSS = SPI_NSS_SOFT;
	Hspi.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
	Hspi.Init.FirstBit = SPI_FIRSTBIT_MSB;
	Hspi.Init.TIMode = SPI_TIMODE_DISABLE;
	Hspi.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	Hspi.Init.CRCPolynomial = 7;
//  hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
//  hspi1.Init.NSSPMode = SPI_NSS_PULSE_DISABLE;
  if (HAL_SPI_Init(&Hspi) != HAL_OK)
  {
    Error_Handler();
  }

}
/*
void Error_Handler()
{

}
*/
//void HAL_SPI_MspInit(SPI_HandleTypeDef* spiHandle)
//{
//
//  GPIO_InitTypeDef GPIO_InitStruct;
//  if(spiHandle->Instance==SPI1)
//  {
//  /* USER CODE BEGIN SPI5_MspInit 0 */
//
//  /* USER CODE END SPI5_MspInit 0 */
//    /* Peripheral clock enable */
//    __HAL_RCC_SPI1_CLK_ENABLE();
//
//    /**SPI5 GPIO Configuration
//    PF7     ------> SPI5_SCK
//    PF8     ------> SPI5_MISO
//    PF9     ------> SPI5_MOSI
//    */
//    GPIO_InitStruct.Pin = GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;
//    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//    GPIO_InitStruct.Pull = GPIO_NOPULL;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
//    GPIO_InitStruct.Alternate = GPIO_AF5_SPI5;
//    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//
//  /* USER CODE BEGIN SPI5_MspInit 1 */
//
//  /* USER CODE END SPI5_MspInit 1 */
//  }
//}

//void HAL_SPI_MspDeInit(SPI_HandleTypeDef* spiHandle)
//{
//
//  if(spiHandle->Instance==SPI1)
//  {
//  /* USER CODE BEGIN SPI5_MspDeInit 0 */
//
//  /* USER CODE END SPI5_MspDeInit 0 */
//    /* Peripheral clock disable */
//    __HAL_RCC_SPI5_CLK_DISABLE();
//
//    /**SPI5 GPIO Configuration
//    PF7     ------> SPI5_SCK
//    PF8     ------> SPI5_MISO
//    PF9     ------> SPI5_MOSI
//    */
//    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9);
//
//  }
//  /* USER CODE BEGIN SPI5_MspDeInit 1 */
//
//  /* USER CODE END SPI5_MspDeInit 1 */
//}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
