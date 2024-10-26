/*
 * Constantes.hpp
 *
 *  Created on: Jul 16, 2024
 *      Author: W10
 */

#ifndef INC_CONSTANTES_HPP_
#define INC_CONSTANTES_HPP_

#define Diaplay_CS_Pin GPIO_PIN_0
#define Diaplay_CS_GPIO_Port GPIOB
#define Display_DC_Pin GPIO_PIN_1
#define Display_DC_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
#define T_IRQ_Pin GPIO_PIN_2
#define T_IRQ_GPIO_Port GPIOE
#define T_CLK_Pin GPIO_PIN_3
#define T_CLK_GPIO_Port GPIOE
#define T_MISO_Pin GPIO_PIN_4
#define T_MISO_GPIO_Port GPIOE
#define T_MOSI_Pin GPIO_PIN_5
#define T_MOSI_GPIO_Port GPIOE
#define T_CS_Pin GPIO_PIN_6
#define T_CS_GPIO_Port GPIOE
#define User_Blue_Button_Pin GPIO_PIN_13
#define User_Blue_Button_GPIO_Port GPIOC
#define MCO_Pin GPIO_PIN_0
#define MCO_GPIO_Port GPIOH
#define RMII_MDC_Pin GPIO_PIN_1
#define RMII_MDC_GPIO_Port GPIOC
#define RMII_REF_CLK_Pin GPIO_PIN_1
#define RMII_REF_CLK_GPIO_Port GPIOA
#define RMII_MDIO_Pin GPIO_PIN_2
#define RMII_MDIO_GPIO_Port GPIOA
#define RMII_CRS_DV_Pin GPIO_PIN_7
#define RMII_CRS_DV_GPIO_Port GPIOA
#define RMII_RXD0_Pin GPIO_PIN_4
#define RMII_RXD0_GPIO_Port GPIOC
#define RMII_RXD1_Pin GPIO_PIN_5
#define RMII_RXD1_GPIO_Port GPIOC
#define RMII_TXD1_Pin GPIO_PIN_13
#define RMII_TXD1_GPIO_Port GPIOB
#define LD3_Pin GPIO_PIN_14
#define LD3_GPIO_Port GPIOB
#define STLK_RX_Pin GPIO_PIN_8
#define STLK_RX_GPIO_Port GPIOD
#define STLK_TX_Pin GPIO_PIN_9
#define STLK_TX_GPIO_Port GPIOD
#define USB_PowerSwitchOn_Pin GPIO_PIN_6
#define USB_OverCurrent_Pin GPIO_PIN_7
#define CS_Pin GPIO_PIN_0
#define CS_GPIO_Port GPIOB
#define DC_Pin GPIO_PIN_1
#define DC_GPIO_Port GPIOB
#define USB_SOF_Pin GPIO_PIN_8
#define USB_SOF_GPIO_Port GPIOA
#define USB_VBUS_Pin GPIO_PIN_9
#define USB_VBUS_GPIO_Port GPIOA
#define USB_ID_Pin GPIO_PIN_10
#define USB_ID_GPIO_Port GPIOA
#define USB_DM_Pin GPIO_PIN_11
#define USB_DM_GPIO_Port GPIOA
#define USB_DP_Pin GPIO_PIN_12
#define USB_DP_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define RST_Pin GPIO_PIN_5
#define RST_GPIO_Port GPIOC
#define RMII_TX_EN_Pin GPIO_PIN_11
#define RMII_TX_EN_GPIO_Port GPIOG
#define RMII_TXD0_Pin GPIO_PIN_13
#define RMII_TXD0_GPIO_Port GPIOG
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define LD2_Pin GPIO_PIN_9
#define LD2_GPIO_Port GPIOB
//#define  GPIO_SPEED_FREQ_VERY_HIGH   ((uint32_t)0x00000003U)  /*!< High speed    */
#define GPIO_AF11_ETH           ((uint8_t)0x0BU)  /* ETHERNET Alternate Function mapping */
/* USER CODE END Private defines */
#define BOTON_SUELTO 1
#define BOTON_PRESIONADO 0
#define TIRMPO_MILIS_BOTON_PRESIONADO_LARGO 5000
#define TIEMPO_REBOTE 100
#define TIEMPO_REBOTEENCODER 2
#define BOTON_MEMORIA1 1
#define BOTON_MEMORIA2 2
#define BOTON_MEMORIA3 3
#define BOTON_MANUAL 4
#define BOTON_PERILLA 5
#define APAGADO 0
#define ENCENDIDO 1
#define TEMPERATURA_APAGADO 30
#define CruceCero_Pin GPIO_PIN_4
#define EncoderClk_Pin GPIO_PIN_11
#define ADDRESS_EEPROM 0XA0
//definicion de colores baicos
//0X ROJO VERDE AZUL AZUL
//0XRGB?
enum COLOR
{
 BLACK= 0x0000,
 BLUE =0x001F,
 RED =0xF800,
 GREEN= 0x07E0,
 CYAN= 0x07FF,
 MAGENTA= 0xF81F,
 YELLOW =0xFFE0,
 WHITE =0xFFFF,
 GREY=0xDEDE
};
//definicion de tamaños de texto
enum TEXTSIZE
{
  TEXTSIZE_1=1,
  TEXTSIZE_2=2,
  TEXTSIZE_3=3,
  TEXTSIZE_4=4,
  TEXTSIZE_5=5,
  TEXTSIZE_6=6,
  TEXTSIZE_7=7,
  TEXTSIZE_8=8,
  TEXTSIZE_9=9,
  TEXTSIZE_10=10
};
enum ROTACION
{
  VERTICAL=1,
  VETICAL_INVERTIDO=2,
  HORIZONTAL=3,
  HORIZONTAL_INVERTIDO=4
};

enum DIRMEMORIARPROM
{
	TEMPERATURAMANUAL=0,
	AJUSTETEMPERATURA=2,
	MEMORIA1=4,
	MEMORIA2=8,
	MEMORIA3=12
};

#endif /* INC_CONSTANTES_HPP_ */
