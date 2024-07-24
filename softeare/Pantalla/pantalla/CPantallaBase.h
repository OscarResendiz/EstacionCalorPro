#ifndef CPANTALLABASE_H
#define CPANTALLABASE_H
#include "Adafruit_GFX.h"  // Hardware-specific library
#include "Constantes.h"    // Hardware-specific library
#include "CRectanguloTft.h"
#include "CEtiquetaTft.h"
#include "CAdmiinstradorPantallasBase.h"

//clase que sirve como base para las demas pantallas del sistema
class CPantallaBase : public CRectanguloTft {
protected:
//  CAdmiinstradorPantallasBase *AdmiinstradorPantallasBase;
  CEtiquetaTft *LabelTitulo;
  int VerTitulo = 1;
  char Titulo[100];
public:
  //constructor
  CPantallaBase(Adafruit_GFX *tft, int verTitulo = 1, char *titulo = "")
    : CRectanguloTft(tft, 0, 0, 0, 0, COLOR::BLACK, 1, COLOR::BLUE) {
    setRotation(3);  //ROTACION::HORIZONTAL); //en horizontal
    //asigno el tamaño por default que es el de la pantalla
    int ancho = width();
    int alto = height();
    Redimenciona(ancho, alto);
    VerTitulo = verTitulo;
    strcpy(Titulo,titulo);
    LabelTitulo = new CEtiquetaTft(tft, Xi, Yi, ancho, 30, COLOR::BLUE, titulo, COLOR::WHITE, 3, 0, COLOR::BLUE);
  }
  CPantallaBase(int verTitulo = 1, char *titulo = "")
    : CRectanguloTft(0, 0, 0, 0, COLOR::BLACK, 1, COLOR::BLUE) {
    VerTitulo = verTitulo;
    strcpy(Titulo,titulo);
  }
  virtual void SetTft(Adafruit_GFX *tft) {
    CRectanguloTft::SetTft(tft);
    setRotation(3);  //ROTACION::HORIZONTAL); //en horizontal
    int ancho = width();
    int alto = height();
    Redimenciona(ancho, alto);
    LabelTitulo = new CEtiquetaTft(Tft, Xi, Yi, ancho, 30, COLOR::BLUE, Titulo, COLOR::WHITE, 3, 0, COLOR::BLUE);
  }
  //funcion que se tiene que reemplazar para verse
  virtual void Show() {
    //dibujo el fondo
    CRectanguloTft::Show();
    //dibujo el titulo
    LabelTitulo->Show();
  }
public:
/*
  virtual void SetAdmiinstradorPantallasBase(CAdmiinstradorPantallasBase *admin) {
    AdmiinstradorPantallasBase = admin;
  }
  */
};
#endif