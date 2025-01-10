/*
 * CPantallaEditorNombre.cpp
 *
 *  Created on: Jan 3, 2025
 *      Author: W10
 */

#include <GUI/Rampa/PantallaEditorNombre/CPantallaEditorNombre.hpp>
#include <GUI/ManejadorPantallas/CManejadorPantallas.hpp>

CPantallaEditorNombre::CPantallaEditorNombre(int id_Rampa) :
		CPantallaMenuBase((char*) "   Editor")
{
	ID_Rampa=id_Rampa;
	// TODO Auto-generated constructor stub
	LabelNombre = new CEtiquetaTft(5, 35, 50, 20, COLOR::BLACK, (char*) "Nombre:", COLOR::WHITE, 3, 0, COLOR::WHITE);
	TextNombre = new CEtiquetaTft(10, 65, 300, 30, COLOR::WHITE, (char*) "", COLOR::BLACK, 3, 0, COLOR::WHITE);
	Opciones=NULL;
	Menu->SetPosicion(10, 100);
	//inico el teclado
	int x1=10;
	int x2=x1+20;
	int x3=x2+20;
	int x4=x3+20;
	int x5=x4+20;
	int x6=x5+20;
	int x7=x6+20;
	int x8=x7+20;
	int x9=x8+20;
	int x10=x9+20;

	int y1=5;
	int y2=y1+25;
	int y3=y2+25;
	int y4=y3+25;
	int y5=y4+30;
	AgregaMenuItem((char*) "0", EDITOR_TECLAS::TECLA_0,x1,y1,10,10);
	AgregaMenuItem((char*) "1", EDITOR_TECLAS::TECLA_1,x2,y1,10,10);
	AgregaMenuItem((char*) "2", EDITOR_TECLAS::TECLA_2,x3,y1,10,10);
	AgregaMenuItem((char*) "3", EDITOR_TECLAS::TECLA_3,x4,y1,10,10);
	AgregaMenuItem((char*) "4", EDITOR_TECLAS::TECLA_4,x5,y1,10,10);
	AgregaMenuItem((char*) "5", EDITOR_TECLAS::TECLA_5,x6,y1,10,10);
	AgregaMenuItem((char*) "6", EDITOR_TECLAS::TECLA_6,x7,y1,10,10);
	AgregaMenuItem((char*) "7", EDITOR_TECLAS::TECLA_7,x8,y1,10,10);
	AgregaMenuItem((char*) "8", EDITOR_TECLAS::TECLA_8,x9,y1,10,10);
	AgregaMenuItem((char*) "9", EDITOR_TECLAS::TECLA_9,x10,y1,10,10);

	AgregaMenuItem((char*) "Q", EDITOR_TECLAS::TECLA_Q,x1,y2,10,10);
	AgregaMenuItem((char*) "W", EDITOR_TECLAS::TECLA_W,x2,y2,10,10);
	AgregaMenuItem((char*) "E", EDITOR_TECLAS::TECLA_E,x3,y2,10,10);
	AgregaMenuItem((char*) "R", EDITOR_TECLAS::TECLA_R,x4,y2,10,10);
	AgregaMenuItem((char*) "T", EDITOR_TECLAS::TECLA_T,x5,y2,10,10);
	AgregaMenuItem((char*) "Y", EDITOR_TECLAS::TECLA_Y,x6,y2,10,10);
	AgregaMenuItem((char*) "U", EDITOR_TECLAS::TECLA_U,x7,y2,10,10);
	AgregaMenuItem((char*) "I", EDITOR_TECLAS::TECLA_I,x8,y2,10,10);
	AgregaMenuItem((char*) "O", EDITOR_TECLAS::TECLA_O,x9,y2,10,10);
	AgregaMenuItem((char*) "P", EDITOR_TECLAS::TECLA_P,x10,y2,10,10);

	AgregaMenuItem((char*) "A", EDITOR_TECLAS::TECLA_A,x1,y3,10,10);
	AgregaMenuItem((char*) "S", EDITOR_TECLAS::TECLA_S,x2,y3,10,10);
	AgregaMenuItem((char*) "D", EDITOR_TECLAS::TECLA_D,x3,y3,10,10);
	AgregaMenuItem((char*) "F", EDITOR_TECLAS::TECLA_F,x4,y3,10,10);
	AgregaMenuItem((char*) "G", EDITOR_TECLAS::TECLA_G,x5,y3,10,10);
	AgregaMenuItem((char*) "H", EDITOR_TECLAS::TECLA_H,x6,y3,10,10);
	AgregaMenuItem((char*) "J", EDITOR_TECLAS::TECLA_J,x7,y3,10,10);
	AgregaMenuItem((char*) "K", EDITOR_TECLAS::TECLA_K,x8,y3,10,10);
	AgregaMenuItem((char*) "L", EDITOR_TECLAS::TECLA_L,x9,y3,10,10);
	AgregaMenuItem((char*) "Z", EDITOR_TECLAS::TECLA_Z,x10,y3,10,10);

	AgregaMenuItem((char*) "X", EDITOR_TECLAS::TECLA_X,x2,y4,10,10);
	AgregaMenuItem((char*) "C", EDITOR_TECLAS::TECLA_C,x3,y4,10,10);
	AgregaMenuItem((char*) "V", EDITOR_TECLAS::TECLA_V,x4,y4,10,10);
	AgregaMenuItem((char*) "__", EDITOR_TECLAS::TECLA_TABULADOR,x5,y4,10,10);
	AgregaMenuItem((char*) "B", EDITOR_TECLAS::TECLA_B,x7,y4,10,10);
	AgregaMenuItem((char*) "N", EDITOR_TECLAS::TECLA_N,x8,y4,10,10);
	AgregaMenuItem((char*) "M", EDITOR_TECLAS::TECLA_M,x9,y4,10,10);

	AgregaMenuItem((char*) "<-", EDITOR_TECLAS::TECLA_DELETE,x10+30,y1,20,10,COLOR::RED,COLOR::BLACK);


	AgregaMenuItem((char*) "Aceptar", EDITOR_TECLAS::TECLA_ACEPTAR,x1,y5,10,10,COLOR::BLUE,COLOR::BLACK);
	AgregaMenuItem((char*) "Cancelar", EDITOR_TECLAS::TECLA_CANCELAR,x8,y5,10,10,COLOR::RED,COLOR::BLACK);

	for(int i=0;i<=MAXTEXT;i++)
		Texto[i]='\0';

}

CPantallaEditorNombre::~CPantallaEditorNombre()
{
	// TODO Auto-generated destructor stub
}

void CPantallaEditorNombre::Show()
{
	CPantallaMenuBase::Show();
	LabelNombre->Show();
	TextNombre->Show();
}
void CPantallaEditorNombre::Refresca()
{
}
void CPantallaEditorNombre::OnMenuEvent(int identificador)
{
	char tecla='\0';
	switch(identificador)
	{
	case EDITOR_TECLAS::TECLA_0:
		tecla='0';
		break;
	case EDITOR_TECLAS::TECLA_1:
		tecla='1';
		break;
	case EDITOR_TECLAS::TECLA_2:
		tecla='2';
		break;
	case EDITOR_TECLAS::TECLA_3:
		tecla='3';
		break;
	case EDITOR_TECLAS::TECLA_4:
		tecla='4';
		break;
	case EDITOR_TECLAS::TECLA_5:
		tecla='5';
		break;
	case EDITOR_TECLAS::TECLA_6:
		tecla='6';
		break;
	case EDITOR_TECLAS::TECLA_7:
		tecla='7';
		break;
	case EDITOR_TECLAS::TECLA_8:
		tecla='8';
		break;
	case EDITOR_TECLAS::TECLA_9:
		tecla='9';
		break;
	case EDITOR_TECLAS::TECLA_A:
		tecla='A';
		break;
	case EDITOR_TECLAS::TECLA_E:
		tecla='E';
		break;
	case EDITOR_TECLAS::TECLA_I:
		tecla='I';
		break;
	case EDITOR_TECLAS::TECLA_O:
		tecla='O';
		break;
	case EDITOR_TECLAS::TECLA_U:
		tecla='U';
		break;
	case EDITOR_TECLAS::TECLA_B:
		tecla='B';
		break;
	case EDITOR_TECLAS::TECLA_C:
		tecla='C';
		break;
	case EDITOR_TECLAS::TECLA_D:
		tecla='D';
		break;
	case EDITOR_TECLAS::TECLA_F:
		tecla='F';
		break;
	case EDITOR_TECLAS::TECLA_G:
		tecla='G';
		break;
	case EDITOR_TECLAS::TECLA_H:
		tecla='H';
		break;
	case EDITOR_TECLAS::TECLA_J:
		tecla='J';
		break;
	case EDITOR_TECLAS::TECLA_K:
		tecla='K';
		break;
	case EDITOR_TECLAS::TECLA_L:
		tecla='L';
		break;
	case EDITOR_TECLAS::TECLA_M:
		tecla='M';
		break;
	case EDITOR_TECLAS::TECLA_N:
		tecla='N';
		break;
	case EDITOR_TECLAS::TECLA_P:
		tecla='P';
		break;
	case EDITOR_TECLAS::TECLA_Q:
		tecla='Q';
		break;
	case EDITOR_TECLAS::TECLA_R:
		tecla='R';
		break;
	case EDITOR_TECLAS::TECLA_S:
		tecla='S';
		break;
	case EDITOR_TECLAS::TECLA_T:
		tecla='T';
		break;
	case EDITOR_TECLAS::TECLA_V:
		tecla='V';
		break;
	case EDITOR_TECLAS::TECLA_TABULADOR:
		tecla=' ';
		break;
	case EDITOR_TECLAS::TECLA_W:
		tecla='W';
		break;
	case EDITOR_TECLAS::TECLA_X:
		tecla='X';
		break;
	case EDITOR_TECLAS::TECLA_Y:
		tecla='Y';
		break;
	case EDITOR_TECLAS::TECLA_Z:
		tecla='Z';
		break;
	case EDITOR_TECLAS::TECLA_DELETE:
		tecla='<';
		break;
	case EDITOR_TECLAS::TECLA_ACEPTAR:
		GuardaNombreRampa();
		break;
	case EDITOR_TECLAS::TECLA_CANCELAR:
		ManejadorPantallas.MuestraMenuRampa();
		break;

	}
	if(tecla!='\0')
	{
		if(tecla=='<')
		{
			Texto[PosicionTexto]='\0';
			if(PosicionTexto>0)
				PosicionTexto--;
		}
		else
		{
			Texto[PosicionTexto]=tecla;
			if(PosicionTexto<MAXTEXT-1)
				PosicionTexto++;
		}
		TextNombre->SetTexto(Texto);
		TextNombre->Show();
	}
}
void CPantallaEditorNombre::AsignaID(int id_Rampa)
{
	if(id_Rampa==-1)
	{
		for(int i=0;i<MAXTEXT;i++)
			Texto[i]='\0';
		PosicionTexto=0;
		TextNombre->SetTexto(Texto);
		TextNombre->Show();
	}
	else
	{
			CRampa rampa=ControladorRampas.DameRampa(id_Rampa);
			strcpy(Texto,rampa.Nombre);
			PosicionTexto=strlen(Texto)-1;
			TextNombre->SetTexto(Texto);
			TextNombre->Show();
	}
	ID_Rampa=id_Rampa;
}
void CPantallaEditorNombre::GuardaNombreRampa()
{
	if(ID_Rampa==-1)
	{
		//hay que crear la rampa
		CRampa rampa=ControladorRampas.AgregaRampa(Texto);
		ID_Rampa=rampa.ID_RAMPA;
	}
	else
	{
		//hay que actualizar
		ControladorRampas.ActualizaRampa(ID_Rampa, Texto);
	}
	ManejadorPantallas.AsignaPantallaPasosRampa(ID_Rampa);

}
void CPantallaEditorNombre::Seleccionada()
{

}
void CPantallaEditorNombre::OnBotonUnoClickEvent()
{
	OnMenuEvent(EDITOR_TECLAS::TECLA_ACEPTAR);
}
void CPantallaEditorNombre::OnBotonTresClickEvent()
{
	OnMenuEvent(EDITOR_TECLAS::TECLA_CANCELAR);

}
void CPantallaEditorNombre::OnBotonCuatroClickEvent()
{
	OnMenuEvent(EDITOR_TECLAS::TECLA_DELETE);

}
