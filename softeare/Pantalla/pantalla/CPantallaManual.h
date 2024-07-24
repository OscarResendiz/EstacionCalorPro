#ifndef CPANTALLAMANUAL_H
#define CPANTALLAMANUAL_H

#include "CPantallaBase.h"  //clase base para trabajar con pantallas
#include "Adafruit_GFX.h"   // Hardware-specific library
#include "Constantes.h"     // Hardware-specific library
#include "CEstacionBase.h"
#include "CManejadorControlesBase.h"
#include "CPantallaMenuPrincipal.h"
#include "CAdmiinstradorPantallasBase.h"

class CPantallaManual : public CPantallaBase, CManejadorControlesBase {
private:
  int SetTemperatura = 0;
  int Temperatura = 0;
  int NivelAire = 0;
  int EstadoBoquilla = 0;
  CEstacionBase *Estacion;
  CEtiquetaTft *LabelTemperatura;
  CEtiquetaTft *LabelTemperaturas;
  CEtiquetaTft *LabelAire;
  CEtiquetaTft *LabelEstado;

public:
  CPantallaManual(Adafruit_GFX *tft, CEstacionBase *estacion)
    : CPantallaBase(tft, 1, "Modo: Manual") {
    Estacion = estacion;
    
    LabelTemperatura = new CEtiquetaTft(tft, 5, 35, 50, 20, COLOR::BLACK, "Temperatura", COLOR::WHITE, 3, 0, COLOR::WHITE);    
    int centroX = DameCentroX();
    LabelTemperaturas = new CEtiquetaTft(tft, centroX - 150 / 2, 65, 150, 30, COLOR::WHITE, "000/000", COLOR::BLACK, 3, 1, COLOR::RED);
  LabelTemperaturas->SetSeparacion(5, 5);
    LabelAire = new CEtiquetaTft(tft, 5, 105, 200, 30, COLOR::BLACK, "Aire: 00", COLOR::WHITE, 3, 0, COLOR::RED);
    LabelEstado = new CEtiquetaTft(tft, 5, 145, 300, 35, COLOR::BLACK, "Estado: REPOSO", COLOR::WHITE, 3, 0, COLOR::RED);
  LabelEstado->SetSeparacion(25, 5);
    //asigno los evetos de la estacion
    Estacion->SetManejadorControles(this);
    
  }

  CPantallaManual()
    : CPantallaBase(1, "   Modo: Manual") {
  }
  virtual void SetTft(Adafruit_GFX *tft)
  {
    CPantallaBase::SetTft(tft);
    LabelTemperatura = new CEtiquetaTft(Tft, 5, 35, 50, 20, COLOR::BLACK, "Temperatura", COLOR::WHITE, 3, 0, COLOR::WHITE);
    int centroX = DameCentroX();
    LabelTemperaturas = new CEtiquetaTft(tft, centroX - 150 / 2, 65, 150, 30, COLOR::WHITE, "000/000", COLOR::BLACK, 3, 1, COLOR::RED);
    LabelTemperaturas->SetSeparacion(5, 5);
    LabelAire = new CEtiquetaTft(tft, 5, 105, 200, 30, COLOR::BLACK, "Aire: 00", COLOR::WHITE, 3, 0, COLOR::RED);
    LabelEstado = new CEtiquetaTft(tft, 5, 145, 300, 35, COLOR::BLACK, "Estado: REPOSO", COLOR::WHITE, 3, 0, COLOR::RED);
    LabelEstado->SetSeparacion(25, 5);
  }
  virtual void SetEstacion(CEstacionBase *estacion)
  {
    Estacion = estacion;
    //asigno los evetos de la estacion
    Estacion->SetManejadorControles(this);
  }
  virtual void Show() {
    CPantallaBase::Show();
    
    LabelTemperatura->Show();
    LeeDatosEstacion();
    LabelTemperaturas->SetTexto("%d/%d ", Temperatura, SetTemperatura);
    LabelTemperaturas->Show();
    LabelAire->SetTexto("Aire: %d", NivelAire);
    LabelAire->Show();
    EstadoBoquilla = Estacion->GetEstado();
    if (EstadoBoquilla == 1) {
      LabelEstado->SetColorFondo(COLOR::GREEN);
      LabelEstado->SetColorTexto(COLOR::BLACK);
      LabelEstado->SetTexto("Estado: ACTIVO");
    } else {
      LabelEstado->SetColorFondo(COLOR::RED);
      LabelEstado->SetColorTexto(COLOR::WHITE);
      LabelEstado->SetTexto("Estado: REPOSO");
    }
    LabelEstado->Show();
    
  }
private:
  void MuestraEstado() {
    if (EstadoBoquilla == 1) {
      LabelEstado->SetColorFondo(COLOR::BLUE);
      LabelEstado->SetColorTexto(COLOR::BLACK);
      LabelEstado->SetTexto("Estado: ACTIVO");
    } else {
      LabelEstado->SetColorFondo(COLOR::RED);
      LabelEstado->SetColorTexto(COLOR::WHITE);
      LabelEstado->SetTexto("Estado: REPOSO");
    }
    LabelEstado->Show();
  }
  void LeeDatosEstacion() {
    SetTemperatura = Estacion->GetTemperatura();
    Temperatura = Estacion->GetTemperaturaReal();
    NivelAire = Estacion->GetNivelAire();
  }
  virtual void OnTemperaturaEvent(int temperatura) {
    SetTemperatura = temperatura;
    MuestraTemperaturas();
  }
  void MuestraTemperaturas() {
    LabelTemperaturas->SetTexto("%d/%d ", Temperatura, SetTemperatura);
    LabelTemperaturas->Show();
  }
  void OnNivelAireEvent(int aire) {
    NivelAire = aire;
    LabelAire->SetTexto("Aire: %d", NivelAire);
    LabelAire->Show();
  }
  virtual void OnTemperaturaRealEvent(int temperatura) {
    Temperatura = temperatura;
    MuestraTemperaturas();
  }
  
  virtual void OnBotonDosClickEvent(int tiempoClick) {
//    AdmiinstradorPantallasBase->ShowMenuPrincipal();
}
  
  /*  virtual void OnBotonPerillaPresionadoEvent()
  {
    EstadoBoquilla=1;
    MuestraEstado();
  }

  virtual void OnBotonPerillaSueltoEvent()
  {
  //  EstadoBoquilla=0;
    //MuestraEstado();

  }
*/
  //eventos del Encoder
  virtual void OnPerillaIncremento() {
    Estacion->IncrementaTemperatura();
  }
  virtual void OnPerillaDecremento() {
    Estacion->DecrementaTemperatura();
  }
  virtual void OnBotonPerillaClickEvent(int tiempoClick) {
    Serial.println("Hola");
    if (EstadoBoquilla == 1)
      EstadoBoquilla = 0;
    else
      EstadoBoquilla = 1;
    MuestraEstado();  
  }
};
#endif