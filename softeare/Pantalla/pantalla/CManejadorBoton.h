#ifndef CMANEJADORBOTON_H
#define CMANEJADORBOTON_H
#include "constantes.h"
#include "CManejadorEventosBoton.h"
class CManejadorBoton {
private:
  int Identificador;
  int Pin;
  int Estado = 1;  //1 es abierto 0 es presionado
  int PreEstado = 1;
  int ReboteMilis = 0;
  int TiempoInicioClick = 0;
  CManejadorEventosBoton *Manejador = NULL;
  //void (CCoConsola3D::*onMouseWheelHandler)
public:
  CManejadorBoton(CManejadorEventosBoton *namejador, int identificador, int pin) {
    Pin = pin;
    pinMode(Pin, INPUT);
    Manejador = namejador;
    Identificador = identificador;
  }
  void Procesa() {
    int tiempoClick = 0;
    int estado =0;
    if (Manejador == NULL) {
      return;
    }
    estado = digitalRead(Pin);

    if (Estado == estado) {
      if (Estado == BOTON_PRESIONADO) {
        tiempoClick = millis() - TiempoInicioClick;
        if (tiempoClick >= TIRMPO_MILIS_BOTON_PRESIONADO_LARGO) {
          TiempoInicioClick = millis();
          Manejador->OnBotonPresionadoLargoEvent(Identificador);
        }
      }
      //no ha cambiado por lo que no hay evento que informar
      return;
    }
    if (estado != PreEstado) {
      //acaba de cambiar
      ReboteMilis = millis();  //leo el tiempo actual
      PreEstado = estado;
      return;
    }
    //leo el tiempo actual
    int tiempo = millis();
    if ((tiempo - ReboteMilis) < TIEMPO_REBOTE) {
      //como todavia no pasa el tiempo de espera para evitar rebotes no hago nada
      return;
    }
    //ya filtre los rebotes, por lo que ahora si informo del cambio de estado del boton
    Estado = estado;
    if (Estado == BOTON_SUELTO) {
      Manejador->OnBotonSueltoEvent(Identificador);
      tiempoClick = millis() - TiempoInicioClick;
      Manejador->OnBotonClickEvent(Identificador, tiempoClick);
    }
    if (Estado == BOTON_PRESIONADO) {
      TiempoInicioClick = millis();
      Manejador->OnBotonPresionadoEvent(Identificador);
    }
  }
};
#endif
