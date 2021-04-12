/*mario tristan 01100313  */
/*gerson garcia  01100207*/
#include <iostream.h>
#include <stdlib.h>
#include <dos.h>
#include <stdio.h>
#include <conio.h>

/*Definimos el puerto serie COM1*/
#define PUERTO 0x3F8

/*Declaramos la funcion saludo que da un saludo de bienvenida*/
void saludo();

/*Declaramos la funcion margen para dibujar la pantalla*/
void margen();

/*La funcion inicializar se encarga de enviar todos los parametros 
necesarios para inicializar el puerto*/
void inicializar();

/*Inicio del programa*/
void main(void)
{

	unsigned char TECLA, CH;
	int i=3,j=3,m=3,f=14;
	saludo();
	clrscr();
	margen();//llamamos a la funcion margen para que dibuje la pantalla
	gotoxy(3,3);

	inicializar();//llamamos a la funcion inicializar para que prepare al 
puerto

	while (TECLA!=27)//Mientras no presionemos escape...
	{
		if (inportb(PUERTO+5)&1)//
		{
			CH=inportb(PUERTO);//guardo en CH el valor que esta en el puerto
			//limpiamos el puerto
			if (CH==13)//preguntamos si el caracter recibido es enter
			{
				i=3;
				f++;//controla la posicion del cursor

				if (f==23)
				{
					window(3,14,77,22);
					delline();
					f=22;
					window(1,1,80,25);
					gotoxy(i,f);
				}
			}
			if (CH!=NULL)//preguntamos si el caracter no es nulo
			{
				if(CH=='\r')//para que el cursor se mantenga siempre al final
				CH='\n';
				gotoxy(i,f);printf("%c",CH);//imprimimos el caracter
				i++;
				if (i==78)
				{
					i=3;
					f++;
					if (f==23)
					{
						window(3,14,77,22);
						delline();
						f=22;
						window(1,1,80,25);
						gotoxy(i,f);
					}
				}

			}

		}
		if (kbhit())//preguntamos si se presiono alguna tecla
		{
			gotoxy(j,m); //mandamos el cursor al final de cada caracter
			j++;//con j escribimos la palabra
			if (j==78)
			{
				j=3;
				m++;
				if (m==13)
				{
					window(3,3,77,12);
					delline();
					m=12;
					window(1,1,80,25);
					gotoxy(j,m);
				}
			}
			TECLA=getche();//guardamos la tecla presionada
			if (TECLA==13)//preguntamos si la tecla presionada es un enter
			{
				gotoxy(3,m+1);printf("");//al apretar enter probocamos un salto de linea
				j=3;
				m++;
				if (m==13)
				{
					window(3,3,77,12);
					delline();
					m=12;
					window(1,1,80,25);
					gotoxy(j,m);
				}
			}
			if (TECLA!=27)//preguntamos si es distinto de escape
			{
				while(!inportb(PUERTO+5)&1);
				outportb(PUERTO,TECLA);//enviamos el caracter al puerto
			}
		}
	}
}

void saludo()
{
	clrscr();
	textbackground(WHITE);//Definimos los colores de la pantalla
	textcolor(BLUE);
	clrscr();
	gotoxy(19,3);printf("лллл   ллл              ллллл л   л  ллл  ллллл");
	gotoxy(19,4);printf("л     л   л             л     л   л л   л   л  ");
	gotoxy(19,5);printf("ллл   ллллл     ллллл   л     ллллл ллллл   л  ");
	gotoxy(19,6);printf("л     л   л             л     л   л л   л   л  ");
	gotoxy(19,7);printf("ллллл л   л             ллллл л   л л   л   л  ");
	textcolor(BLACK);
	gotoxy(19,9);cprintf("ллллллллллллллллллллллллллллллллллллллллллллллл");
	gotoxy(19,12);printf("    Programa de Chat por Puerto Serial. ");
	gotoxy(30,18);printf("ARQUITECTURA DE COMPUTADORAS II");
	gotoxy(30,23);printf("Hecho por: ");
	gotoxy(41,24);printf("MARIO TRISTAN << 01100313 >>");
	gotoxy(41,26);printf("GERSON GARCIA << 01100208 >>");
	gotoxy(23,29);printf("Presione una tecla para seguir...");
	getche();

}

void margen ()
{
  int i;
  textcolor(RED);
  clrscr();
  for (i = 1; i < 80; i++) //Dibujamos los margenes
  {
    gotoxy (i, 1); printf ("л");
    gotoxy (i,24); printf ("л");
  }

  for (i = 1; i < 80; i++)
  {
    gotoxy (i, 2); printf ("Э");
    gotoxy (i,23); printf ("Э");
  }

  for (i = 1; i < 80; i++)
  {
    gotoxy (i,13); printf ("Э");
  }

  for (i = 2; i < 24; i++)
  {
    gotoxy (1 ,i); printf ("л");
    gotoxy (79,i); printf ("л");
  }

  for (i = 2; i < 24; i++)
  {
    gotoxy (2 ,i); printf ("К");
    gotoxy (78,i); printf ("К");
  }
  gotoxy (2 , 2); printf ("Щ");
  gotoxy (2 ,23); printf ("Ш");
  gotoxy (78, 2); printf ("Л");
  gotoxy (78,23); printf ("М");
  textcolor(BLUE);

  gotoxy(3,2);cprintf("Escribiste:");

  gotoxy(3,13);cprintf("Recibiste:");
  gotoxy(64,24);cprintf("ESC -> Salir.");
  textcolor(BLACK);
    textbackground(RED);
  gotoxy(30,40);cprintf(">>--Gerson Garcia--<<");
  gotoxy(30,42);cprintf(">>--Mario Tristan--<<");
}

void inicializar()
{
	outportb(PUERTO+1,0);//
	outportb(PUERTO+3,0x80);//
	outportb(PUERTO+0,0x0C);//
	outportb(PUERTO+1,0x00);//
	outportb(PUERTO+3,0x03);//
	outportb(PUERTO+2,0XC7);
	outportb(PUERTO+4,0X0B);

}

