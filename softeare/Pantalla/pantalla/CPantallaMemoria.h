#ifndef CPANTALLAMEMORIA_H
#define CPANTALLAMEMORIA_H

#include "CPantallaBase.h" //clase base para trabajar con pantallas
#include "Adafruit_GFX.h"  // Hardware-specific library
#include "Constantes.h"  // Hardware-specific library
#include "CEstacionBase.h"
class CPantallaMemoria:public CPantallaBase
{
  private:
    int SetTemperatura=0;
    int Temperatura=0;
    int NivelAire=0;
    CEstacionBase *Estacion;
    CEtiquetaTft *LabelTemperatura;
    CEtiquetaTft *LabelTemperaturas;
    CEtiquetaTft *LabelAire;
    CEtiquetaTft *LabelEstado;
  public:
  CPantallaMemoria(Adafruit_GFX *tft, CEstacionBase *estacion)
  :CPantallaBase(tft,1," Modo: memoria 1")
  {
    Estacion=estacion;
    LabelTemperatura=new CEtiquetaTft(tft,5,35,50,20,COLOR::BLACK, "Temperatura",COLOR::WHITE,3,0, COLOR::WHITE);
    int centroX=DameCentroX();
    LabelTemperaturas=new CEtiquetaTft(tft,centroX-150/2 ,65,150,30,COLOR::WHITE, "000/000",COLOR::BLACK,3,1, COLOR::RED);
    LabelTemperaturas->SetSeparacion(5,5);
    LabelAire=new CEtiquetaTft(tft,5 ,105,150,30,COLOR::BLACK, "Aire: 00",COLOR::WHITE,3,0, COLOR::RED);
//    LabelAire->SetSeparacion(5,5);
    LabelEstado=new CEtiquetaTft(tft,5 ,145,300,35,COLOR::BLACK, "Estado: REPOSO",COLOR::WHITE,3,0, COLOR::RED);
    LabelEstado->SetSeparacion(25,5);
  }
  
  virtual void  Show()
  {
    CPantallaBase::Show();
    LabelTemperatura->Show();
    LeeDatosEstacion();
    LabelTemperaturas->SetTexto("%d/%d ",Temperatura,SetTemperatura);
    LabelTemperaturas->Show();
    LabelAire->SetTexto("Aire: %d",NivelAire);
    LabelAire->Show();
    if(Estacion->GetEstado()==1)
    {
      LabelEstado->SetColorFondo(COLOR::GREEN);
      LabelEstado->SetColorTexto(COLOR::BLACK);
      LabelEstado->SetTexto("Estado: ACTIVO");
    }
    else
    {
      LabelEstado->SetColorFondo(COLOR::RED);
      LabelEstado->SetColorTexto(COLOR::WHITE);
      LabelEstado->SetTexto("Estado: REPOSO");
    }
    LabelEstado->Show();
  }
  private: 
  void LeeDatosEstacion()
  {
     SetTemperatura=Estacion->GetTemperatura();
     Temperatura=Estacion->GetTemperaturaReal();
     NivelAire=Estacion->GetNivelAire();

  }
};
#endif