#include <windows.h>
#include <stdio.h>
#define NEGRO 0X0000
#define AZUL 0X0001
#define VERDE 0X0002
#define CIAN 0X0003
#define ROJO 0X0004
#define MAGENTA 0X0005
#define MARRON 0X0006
#define GRIS_CLARO 0X0007
#define GRIS_OSCURO 0X0008
#define AZUL_INTENSO 0X0009
#define VERDE_INTENSO 0X000A
#define VERDEI 0X000A
#define CIAN_INTENSO 0X000B
#define ROJO_INTENSO 0X000C
#define ROJOI 0X000C
#define MAGENTA_INTENSO 0X000D
#define MAGENTAI 0X000D
#define AMARILLO_INTENSO 0X000E
#define AMARILLOI 0X000E
#define JOHI 0X000E
#define BLANCO_INTENSO 0X000F
#define BLANCO 0X000F
#define setcolortext set
#define gotoxy go
void gotoxy(int, int);
void setcolortext (); 
void setcolortext (int); 
void setcolortext (int,int); 

//----------------------------------------------------------------------------
//------- FUNCIONES RESERVADAS PARA VIDEO ------------------------------------
//----------------------------------------------------------------------------
void gotoxy(int x, int y){
        HANDLE hCon;
        hCon=GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X=x;
        dwPos.Y=y;
        SetConsoleCursorPosition(hCon,dwPos);
}
void setcolortext () { 
    HANDLE hCon;
    hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (hCon,GRIS_CLARO);
}
void setcolortext (int texto) { 
    HANDLE hCon;
    int numero;
    hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (hCon,texto);
}

void setcolortext (int texto,int fondo){
    HANDLE hCon;
    int numero;
    hCon=GetStdHandle(STD_OUTPUT_HANDLE);
    numero = fondo*16+texto;
	SetConsoleTextAttribute (hCon,numero);
}

void settitle (char *texto){
    SetConsoleTitle(texto);
}

void paintF(int x, int y, int *figura,int limY,int limX,int color){
	
	int j=0;
	gotoxy(x,y);
	for (int a=0;a<limY;a++ ){
		gotoxy(x,y);
		y++;
		for (int b=0;b<limX;b++){
			switch (figura[j]){

				case 0: printf (" ");  break;								 //Vv Tuberias vV
				
				case 1: setcolortext (color); printf ("ษ"); setcolortext(); break; //sup-izq
				
				case 2: setcolortext (color); printf ("อ"); setcolortext(); break;//vert
				
				case 3: setcolortext (color); printf ("ป"); setcolortext(); break;//sup-der
							
				case 4: setcolortext (color); printf ("บ"); setcolortext(); break;//horiz
				
				case 5: setcolortext (color); printf ("ศ"); setcolortext(); break;//inf-izq
				
				case 6: setcolortext (color); printf ("ผ"); setcolortext(); break;//inf-der
				
				case 7: setcolortext (color); printf ("อออออออออออออออ"); setcolortext(); break;//vert x15
				
				case 8:  printf ("               "); break;//void x15
			}
			j++;
		}
	}
}






void paintU(int thing,int color){
	

			switch (thing){

				case 0: printf (" ");  break;								 //Vv Tuberias vV
				
				case 1: setcolortext (color); printf ("ษ"); setcolortext(); break; //sup-izq
				
				case 2: setcolortext (color); printf ("อ"); setcolortext(); break;//vert
				
				case 3: setcolortext (color); printf ("ป"); setcolortext(); break;//sup-der
							
				case 4: setcolortext (color); printf ("บ"); setcolortext(); break;//horiz
				
				case 5: setcolortext (color); printf ("ศ"); setcolortext(); break;//inf-izq
				
				case 6: setcolortext (color); printf ("ผ"); setcolortext(); break;//inf-der
				
				case 7: setcolortext (color); printf ("อออออออออออออออ"); setcolortext(); break;//vert x15
				
				case 8:  printf ("               "); break;//void x15
			}
			
		
	
}


void cuadro(char *text,int x,int y){
	int top[3]={1,4,5};
	int midS[3]={2,0,2,};
	int midL[3]={7,8,7,};	
	int bot[3]={3,4,6,};
	
	int len=strlen(text);
	
	paintF (x,y,top,3,1,9);
	
	for (int j=1;j<len;j++)	paintF (x+j,y,midS,3,1,9);
	gotoxy(x+1,y+1);
	printf ("%s",text);
	paintF (x+len,y,bot,3,1,9);
	printf ("\n");
	
}

void cuadro(char *text,int ColorBorde,int x,int y){
	int top[3]={1,4,5};
	int midS[3]={2,0,2,};
	int midL[3]={7,8,7,};	
	int bot[3]={3,4,6,};
	
	int len=strlen(text);
	
	paintF (x,y,top,3,1,ColorBorde);
	
	for (int j=1;j<len;j++)	paintF (x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	printf ("%s",text);
	paintF (x+len,y,bot,3,1,ColorBorde);
	printf ("\n");
	
}

void cuadro(char *text,int ColorBorde,int ColorTexto,int x,int y){
	int top[3]={1,4,5};
	int midS[3]={2,0,2,};
	int midL[3]={7,8,7,};	
	int bot[3]={3,4,6,};
	
	int len=strlen(text);
	
	paintF (x,y,top,3,1,ColorBorde);
	
	for (int j=1;j<len;j++)	paintF (x+j,y,midS,3,1,ColorBorde);
	go(x+1,y+1);
	setcolortext(ColorTexto);
	printf ("%s",text);
	setcolortext();
	paintF (x+len,y,bot,3,1,ColorBorde);
	printf ("\n");
	
}

//--------------------------------------------------------------------
