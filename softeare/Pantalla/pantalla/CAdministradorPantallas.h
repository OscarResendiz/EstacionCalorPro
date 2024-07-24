#ifndef CADMINISTRADORPANTALLAS_H
#define CADMINISTRADORPANTALLAS_H
/*
#include "Adafruit_GFX.h"  // Hardware-specific library
#include "CPantallaBase.h"  //clase base para trabajar con pantallas
#include "CPantallaManual.h"
#include "CPantallaMenuPrincipal.h"
#include "CAdmiinstradorPantallasBase.h"
//#include "CEstacionBase.h"
//CPantallaManual xxx;

class CAdministradorPantallas:public CAdmiinstradorPantallasBase {
private:
   CEstacionBase *Estacion;
   CPantallaManual pantallaManual;
   CPantallaMenuPrincipal menuPrincipal;
public:
  CAdministradorPantallas() {
    pantallaManual.SetAdmiinstradorPantallasBase(this);
    menuPrincipal.SetAdmiinstradorPantallasBase(this);
  }
   void Setup(Adafruit_GFX *tft, CEstacionBase *estacion) {
    Estacion = estacion;
    pantallaManual.SetTft(tft);
    menuPrincipal.SetTft(tft);
    //pantallaManual
  }
   virtual void ShowPantallaManual() {
    pantallaManual.SetEstacion(Estacion);
    pantallaManual.Show();
  }
   virtual void ShowMenuPrincipal() {
    menuPrincipal.SetEstacion(Estacion);
    menuPrincipal.Show();
  }
};
static CAdministradorPantallas AdministradorPantallas;

*/
#endif
