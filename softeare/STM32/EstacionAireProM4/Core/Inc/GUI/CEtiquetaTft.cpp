/*
 * CEtiquetaTft.cpp
 *
 *  Created on: Jul 24, 2024
 *      Author: W10
 */

#include <GUI/CEtiquetaTft.hpp>


CEtiquetaTft::~CEtiquetaTft()
{
	// TODO Auto-generated destructor stub
}

CEtiquetaTft::CEtiquetaTft(int xi, int yi, int ancho, int alto,	int backColor, char *texto, int colorTexto, int textSize, int contorno,	int colorContorno) :
		CRectanguloTft(xi, yi, ancho, alto, backColor, contorno, colorContorno)
{
	strcpy(Texto, texto);
	ColorTexto = colorTexto;
	TextSize = textSize;
}

void CEtiquetaTft::SetTexto(char *formato, ...)
{
//	LimpiaTexto();
	char *p;
	char buffer[100];
	char tmp[100];
	for(int i=0;i<100;i++)
	{
		buffer[i]='\0';
		tmp[i]='\0';
	}
	int postmp = 0;
	int posbuffer = 0;
	va_list pa;
	int encontrado = 0;

	va_start(pa, formato);

	for (p = formato; *p; p++)
	{

		if (*p != '%')
		{
			buffer[posbuffer] = *p;
			posbuffer++;
			continue;
		}
		encontrado = 0;
		switch (*++p)
		{
		case 'd':
			sprintf(tmp, "%d", va_arg(pa, int));
			encontrado = 1;
			break;
		case 'i':
			sprintf(tmp, "%i", va_arg(pa, int));
			encontrado = 1;
			break;
		case 'x':
			sprintf(tmp, "%x", va_arg(pa, int));
			encontrado = 1;
			break;
		case 'p':
			sprintf(tmp, "%p", va_arg(pa, void*));
			encontrado = 1;
			break;
		case 'c':
			sprintf(tmp, "%c", va_arg(pa, int));
			encontrado = 1;
			break;
		case 'f':
			sprintf(tmp, "%f", va_arg(pa, double));
			encontrado = 1;
			break;
		case 's':
			sprintf(tmp, "%s", va_arg(pa, char *));
			encontrado = 1;
			break;
		default:
			buffer[posbuffer] = *p;
			posbuffer++;
			break;
		}
		if (encontrado == 1)
		{
			postmp = 0;
			while (tmp[postmp] != '\0')
			{
				buffer[posbuffer] = tmp[postmp];
				posbuffer++;
				postmp++;
			}
		}
	}
	va_end(pa);
	buffer[posbuffer] = '\0';
	strcpy(Texto, buffer);
}

char* CEtiquetaTft::DameTexto()
{
	return Texto;
}

void CEtiquetaTft::SetSeparacion(int izquieda, int arriba)
{
	SeparacionIzquierda = izquieda;
	SeparacionArriba = arriba;
}

int CEtiquetaTft::DameSeparacionArriba()
{
	return SeparacionArriba;
}

int CEtiquetaTft::DameSeparacionIzquierda()
{
	return SeparacionIzquierda;
}

void CEtiquetaTft::SetColorTexto(int color)
{
	ColorTexto = color;
}

int CEtiquetaTft::DameColorTexto()
{
	return ColorTexto;
}

void CEtiquetaTft::Show()
{
	//mandamos a dibujar el rectangulo
	CRectanguloTft::Show();
	//me posiciono el la pocicion del texto
	setCursor(Xi + SeparacionIzquierda, Yi + SeparacionArriba);
	//asigno tamaño de la letra
	setTextSize (TextSize);
	//asigno el color de texto
	setTextColor (ColorTexto);
	//muestro el texto;
	print (Texto);
}
void CEtiquetaTft::SetTextSize(int textZize)
{
	TextSize = textZize;
}

int CEtiquetaTft::DameTextSize()
{
	return TextSize;
}
void CEtiquetaTft::SetBackColor(int color)
{
	BackColor=color;
}
void CEtiquetaTft::LimpiaTexto()
{
	setTextColor (BackColor);
	//muestro el texto;
	print (Texto);
	setTextColor (ColorTexto);
	//muestro el texto;
//	print (Texto);

}
