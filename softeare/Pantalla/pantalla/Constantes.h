#ifndef CONSTANTES_H
#define CONSTANTES_H

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
//definicion de colores baicos
enum COLOR
{
 BLACK= 0x0000,
 BLUE =0x001F,
 RED =0xF800,
 GREEN= 0x07E0,
 CYAN= 0x07FF,
 MAGENTA= 0xF81F,
 YELLOW =0xFFE0,
 WHITE =0xFFFF
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
#endif