#ifndef CPANTALLAMENUPRINCIPAL_H
#define CPANTALLAMENUPRINCIPAL_H
#include "CPantallaBase.h"
//#include "CAdministradorPantallas.h"
#include "CManejadorControlesBase.h"
#include "Adafruit_GFX.h"   // Hardware-specific library
#include "Constantes.h"     // Hardware-specific library
#include "CEstacionBase.h"

class CPantallaMenuPrincipal :public CPantallaBase, CManejadorControlesBase {
private:
  CEstacionBase *Estacion;
public:
  CPantallaMenuPrincipal(Adafruit_GFX *tft, CEstacionBase *estacion)
    : CPantallaBase(tft, 1, "   Menu ") {
    Estacion = estacion;
    //asigno los evetos de la estacion
    Estacion->SetManejadorControles(this);
  }

  CPantallaMenuPrincipal()
    : CPantallaBase(1, "   Menu ") {
  }
  
  virtual void SetTft(Adafruit_GFX *tft) {
    CPantallaBase::SetTft(tft);
  }
  virtual void SetEstacion(CEstacionBase *estacion)
  {
    Estacion = estacion;
    //asigno los evetos de la estacion
    Estacion->SetManejadorControles(this);
  }

  virtual void Show() {
    CPantallaBase::Show();
  }
  virtual void OnBotonUnoClickEvent(int tiempoClick) {
  }
};
#endif