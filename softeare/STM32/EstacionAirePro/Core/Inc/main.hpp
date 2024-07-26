/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
//#define DAT_MAX_Pin GPIO_PIN_0
//#define DAT_MAX_GPIO_Port GPIOA
//#define CK_MAX_Pin GPIO_PIN_1
//#define CK_MAX_GPIO_Port GPIOA
//#define CS_MAX_Pin GPIO_PIN_2
//#define CS_MAX_GPIO_Port GPIOA
#define MAX_SO_Pin GPIO_PIN_0
#define MAX_SO_GPIO_Port GPIOA
#define MAX_SK_Pin GPIO_PIN_1
#define MAX_SK_GPIO_Port GPIOA
#define MAX_CS_Pin GPIO_PIN_2
#define MAX_CS_GPIO_Port GPIOA
#define Btn1_Pin GPIO_PIN_4
#define Btn1_GPIO_Port GPIOA
#define Display_DC_Pin GPIO_PIN_1
#define Display_DC_GPIO_Port GPIOB

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
