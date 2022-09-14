#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "VIDEO.cpp"
#include <time.h>
#define X713 0X0009
	//proporcion 1A = 2B
	int limA=12;
	int limB=20;
	int y=limA/2+3;
	int x=limB/2;
	int iniX=16;
	int iniY=7;
	int xr=0;
	int yr=0;
	int hudX=limB/2+5;
	int hudY=1;
	int lol;
	int first;
	int tiempoo;
	int room;
	int developertools=713;
	int game=1;
void info(int startt);
void swap(int ROOM,int xx,int yy);
void ifswap();
void position();
void finishGame();
/*	0 = piso 1
	1 = borde 0
	2 = pared 0
	3 = llave 1
	4 = puerta 1
	5 = frutas 1
	6 = inicio -
	7 = easter egg -
	8 = final 1
*/


int screen[22][12][23]={
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, // zero
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	},
	{
		{1,1,1,1,1,1,1,1,16,16,16,16,1,1,1,1,1,1,1,1}, // SALA QUE DEBERIA SER UN SUPER LABERINTO TROFEO - 1 - WIN
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,0,0,0,1,0,0,1,0,0,1,1,1,1,0,0,0,0},
		{1,0,1,0,0,0,1,0,0,1,0,1,0,1,0,1,0,0,0,0},
		{1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,1,0,0,0,0},
		{1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,1,0,0,0,0},
		{1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,1,0,0,0,1},
		{1,0,1,1,1,1,0,0,0,1,1,0,0,1,0,1,1,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1},
	},
	{
		{1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1}, // ARRIBA DEL CASTILLO - 2
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,2,2,2,2,2,2,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,2,2,2,2,2,2,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1},
	},
	{
		{1,1,1,1,1,0,1,0,1,0,0,1,0,1,0,1,1,1,1,1}, // CASTILLO - 3
		{1,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,1},
		{1,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,1},
		{1,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,1},
		{1,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,1},
		{1,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,1,1,4,4,1,1,1,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1},
	},
	{
		{1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1}, // ABAJO DEL CASTILLO - 4
		{0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0},
		{0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0},
		{1,1,0,0,1,0,0,1,1,0,0,1,1,0,0,1,0,0,1,1},
		{1,1,0,0,1,0,0,1,1,0,0,1,1,0,0,1,0,0,1,1},
		{1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1},
		{1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1},
		{1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0},
		{0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0},
		{1,1,0,1,0,1,1,1,1,0,0,1,1,1,1,0,1,0,1,1},
	},
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, // SALA SOLA IZQUIERDA - 5
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1},
		{1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1},
		{1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1},
		{1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1},
		{1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1},
		{1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1},
		{0,0,0,1,0,0,0,1,0,1,1,0,1,0,0,0,1,0,0,0},
		{0,0,0,1,0,0,0,1,0,1,1,0,1,0,0,0,1,0,0,0},
		{1,1,1,1,0,1,0,1,0,1,1,0,1,0,1,0,1,1,1,1},
	},
	{
		{1,1,0,1,0,1,1,1,1,0,0,1,1,1,1,0,1,0,1,1}, // CBA ABAJO DE - 6
		{0,0,0,1,0,0,0,1,1,0,0,1,1,0,0,0,1,0,0,0},
		{0,0,0,1,0,0,0,1,1,0,0,1,1,0,0,0,1,0,0,0},
		{1,1,1,1,1,1,0,1,1,0,0,1,1,0,1,1,1,1,1,1},
		{1,1,1,1,1,1,0,1,1,0,0,1,1,0,1,1,1,1,1,1},
		{0,0,0,0,0,1,0,1,1,0,0,1,1,0,1,0,0,0,0,0},
		{0,0,0,0,0,1,0,1,1,0,0,1,1,0,1,0,0,0,0,0},
		{1,1,0,1,0,1,0,1,1,0,0,1,1,0,1,0,1,0,1,1},
		{1,1,0,1,0,1,0,1,1,0,0,1,1,0,1,0,1,0,1,1},
		{0,0,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,0,0},
		{0,0,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,0,0},
		{1,1,1,1,0,1,0,1,0,0,0,0,1,0,1,0,1,1,1,1},
	},
	{
		{1,1,1,1,0,1,0,1,0,1,1,0,1,0,1,0,1,1,1,1}, // AL LADO CBA 4 - 7
		{0,0,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,0,0},
		{0,0,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,0,0},
		{1,1,0,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,1,1},
		{1,1,0,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,1,1},
		{0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0},
		{0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0},
		{1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1},
		{1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	},
	{
		{1,1,1,1,0,1,0,1,0,0,0,0,1,0,1,0,1,1,1,1}, // PRINCIPIO - 8
		{0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0},
		{0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0},
		{1,1,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,1,1},
		{1,1,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,1,1},
		{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
		{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
		{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
		{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
		{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
		{1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1},
	},
	{  
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, // SALA VACIA MONSTRUO - 9 *
		{1,0,0,0,0,0,0,0,0,2,0,0,0,2,0,0,2,2,2,1},
		{1,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,2,2,2,1},
		{1,2,2,2,0,0,2,2,2,2,2,2,2,2,0,0,2,2,2,1},
		{1,2,2,2,0,0,2,2,2,2,2,2,2,2,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,0,2,2,2,0,0,2,2,0,1},
		{1,2,2,2,0,0,2,2,2,0,0,0,0,2,0,0,2,2,0,1},
		{1,2,0,0,0,0,0,0,2,0,0,0,0,2,0,0,2,2,0,1},
		{1,0,0,0,0,0,0,0,2,0,0,2,2,2,0,0,2,2,0,1},
		{1,0,0,2,2,2,2,2,2,0,0,2,2,2,0,0,2,2,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,2,2,0,0},
		{1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1},
	},
	
	{
		{1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1}, // SALA QUE DEBERIA SER UN SUPER LABERINTO TROFEO - 10 *
		{1,0,0,0,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,1},
		{1,0,2,2,2,2,0,2,2,0,0,2,2,0,2,2,2,2,0,1},
		{1,0,2,0,0,0,0,2,0,0,0,2,0,0,2,0,0,2,0,1},
		{1,0,2,2,2,2,0,2,0,2,0,0,0,0,2,0,2,2,0,1},
		{1,0,0,2,0,0,0,2,0,2,2,2,2,2,2,0,2,2,0,1},
		{1,2,2,2,0,2,2,2,0,0,0,0,0,0,0,0,2,0,0,1},
		{1,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,0,2,1},
		{1,0,2,2,2,2,0,0,0,0,0,0,2,0,0,0,2,0,0,1},
		{1,0,2,7,2,2,2,2,2,0,2,2,2,0,2,0,2,2,0,1},
		{1,0,0,0,0,0,0,2,2,0,0,0,0,0,2,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	},
	{
		{1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1}, // SALA VACIA SIN MONSTRUO - 11 *
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,2,1},
		{1,0,0,0,0,2,2,2,2,2,2,2,2,0,0,2,0,0,2,1},
		{1,0,2,2,2,2,2,0,0,0,2,0,2,0,0,2,0,0,0,0},
		{1,0,0,0,0,2,0,0,2,0,0,0,2,0,0,2,0,2,0,0},
		{1,2,2,0,2,2,0,2,2,2,2,0,2,2,2,2,0,0,2,1},
		{1,0,0,0,0,2,0,2,3,0,2,0,0,0,0,0,0,0,2,1},
		{1,0,0,0,0,2,0,2,2,0,2,0,0,0,0,0,0,0,2,1},
		{1,2,2,0,0,2,0,0,0,0,2,2,2,2,2,2,0,0,2,1},
		{0,0,2,0,0,2,2,2,2,2,2,0,0,0,0,0,2,0,0,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	},
	{
		{1,1,1,1,1,0,1,0,1,0,0,1,0,1,0,1,1,1,1,1}, // CASTILLO LLAVE AMARILLO - 12
		{1,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,1},
		{1,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,1},
		{1,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,1},
		{1,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,1},
		{1,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,1,1,4,4,1,1,1,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1},
	},
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, // ARRIBA DEL CASTILLO AMARILLO - 13
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1},
	},
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, // SALA VACIA SIN MONSTRUO - 14 *
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,2,0,0,2,2,2,0,0,0,0,0,0,0,2,0,0,2,0,1},
		{0,0,0,0,0,0,0,0,0,2,2,2,0,0,2,0,0,2,0,1},
		{0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
		{1,2,2,2,0,2,0,0,2,0,0,2,2,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,2,0,0,0,0,0,0,2,2,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,2,2,0,0,0,0,0,0,0,0,0,2,0,0,0,0,1},
		{1,2,0,0,0,0,0,0,2,2,0,2,0,0,0,0,0,0,0,1},
		{1,2,0,0,0,0,0,0,0,0,0,2,0,0,0,0,2,2,0,1},
		{1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1},
	},
	{
		{1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1}, // MENU- 15
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	},
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, // AYUDA - 16
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},	
		{1,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,1},	
		{1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1},	
		{1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0},	
		{1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0},	
		{1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0},	
		{1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0},	
		{1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1},	
		{1,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,1},	
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},	
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	
	},
	{  /*1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0*/
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, // PUNTAJE - 17
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},	
		{1,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,1},	
		{1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1},	
		{0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1},	
		{0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1},	
		{0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1},	
		{0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1},	
		{1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1},	
		{1,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,1},	
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},	
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	},
	{
		{1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1}, // EASTEREGG - 18
		{1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1},	
		{1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1},	
		{1,0,2,10,10,10,0,10,10,10,0,10,0,10,0,10,0,2,0,1},	
		{1,0,2,0,9,0,0,9,0,9,0,9,10,9,0,9,0,2,0,1},
		{1,0,2,10,9,0,0,9,10,9,0,9,0,9,0,9,0,2,0,1},
		{1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1},	
		{1,0,2,10,0,10,0,10,10,10,0,10,10,0,0,10,0,2,0,1},
		{1,0,2,11,9,11,0,0,0,9,0,0,9,0,0,10,9,2,0,1},
		{1,0,2,9,11,9,0,0,0,9,0,10,9,10,0,10,11,2,0,1},	
		{1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	
	},
{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, // INSERT NAME - 19
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},	
		{1,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,1},	
		{1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1},	
		{1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1},	
		{1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1},	
		{1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1},	
		{1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1},	
		{1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1},	
		{1,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,1},	
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},	
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	
	}
	

};
int welcome[15][40]={
		{16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16},
		{16,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,16}, // ADVENTURE XJ! - 20	
		{16,15,12,12,12,15,15,15,12,15,12,15,12,15,12,12,12,15,12,15,15,15,15,12,15,15,12,15,12,15,12,15,15,15,12,12,12,15,16},	
		{16,15,15,15,12,15,15,15,12,15,12,15,12,15,12,15,12,15,12,12,12,15,12,12,12,15,12,15,12,15,12,12,12,15,12,15,12,15,16},	
		{16,15,12,12,12,15,12,12,12,15,12,15,12,15,12,12,12,15,12,15,12,15,15,12,15,15,12,15,12,15,12,15,14,15,12,12,12,15,16},	
		{16,15,12,15,12,15,12,15,12,15,12,15,12,15,12,15,15,15,12,15,12,15,15,12,15,15,12,15,12,15,12,15,15,15,12,15,15,15,16},	
		{16,15,12,12,12,15,12,12,12,15,15,12,15,15,12,12,12,15,12,15,12,15,15,12,12,15,12,12,12,15,12,15,15,15,12,12,12,15,16},	
		{16,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,16},	
		{16,15,15,15,15,15,15,15,15,15,15,15,15,15,12,15,12,15,12,12,12,15,15,12,15,15,15,15,15,15,15,15,15,15,15,15,15,15,16},	
		{16,15,15,15,15,15,15,15,15,15,15,15,15,15,12,13,12,15,15,12,15,15,15,12,15,15,15,15,15,15,15,15,15,15,15,15,15,15,16},	
		{16,15,15,15,15,15,15,15,15,15,15,15,15,15,15,12,15,15,15,12,15,15,15,12,15,15,15,15,15,15,15,15,15,15,15,15,15,15,16},	
		{16,15,15,15,15,15,15,15,15,15,15,15,15,15,12,14,12,15,15,12,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,16},	
		{16,15,15,15,15,15,15,15,15,15,15,15,15,15,12,15,12,15,12,12,15,15,15,12,15,15,15,15,15,15,15,15,15,15,15,15,15,15,16},		
		{16,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,16},
		{16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16},
	
};

struct ent{
	char nombre[7];
	int timepo;
	int lug;
	int posX;
	int posY;
	int key;
	int key2;
	int keyegg;
	int keyX;
	int keyY;
	int roomX;
	int roomY;
	
};

struct secundario{
	char nombre[7];
	int timepo;
};

ent user;
secundario player[7];



void stopGame (secundario player[7]);

void ordenMenorMayor (secundario datos[7]) {
	
	secundario aux;

	for (int i=0;i<6;i++) {
		for (int j=0;j<6-i;j++) {
			
			if (datos[j].timepo>datos[j+1].timepo) {			
				aux=datos[j+1];
				datos[j+1]=datos[j];
				datos[j]=aux;		
			}
		}
	}
}

void archivosR(){
		FILE *fdatos;
	
		if ((fdatos=fopen ("Puntajes.dat","rb"))!=NULL) {
			for(int i=0;i<6;i++){
				fread (&player[i],sizeof(player[i]),1,fdatos);
			}			
		}
		else{
			fdatos=fopen("Puntajes.dat","wb");
			
			strcpy(player[0].nombre,"X713MP ");
			strcpy(player[1].nombre,"JOHI31 ");
			strcpy(player[2].nombre,"NAH115 ");
			strcpy(player[3].nombre,"NEBULA ");
			strcpy(player[4].nombre,"NASHGD ");
			strcpy(player[5].nombre,"ONUATR ");
			
			for(int i=0;i<6;i++){
				player[i].timepo=50+(20*i)-(i*7);
				fwrite (&player[i],sizeof(player[i]),1,fdatos);		
			}
			
			player[0].timepo=45;
		}
		
}//-----------------------------------

void archivosW(secundario datos[7]){
	FILE *fdatos;
	fdatos=fopen("Puntajes.dat","wb");
	
	ordenMenorMayor(datos);
	
	
	for(int i=0;i<6;i++){
			fwrite (&datos[i],sizeof(datos[i]),1,fdatos);
			
		}
	
	fclose(fdatos);
}
//         Y  X
int mapdis[8][5]={
	//	 0 1 2 3 4
		{0,97,98,1,17}, 	// y0 
		{0,2,0,12,0}, 	// y1
		{0,3,9,11,14},	// y2
		{91,4,5,96,10},	// y3
		{92,6,7,95,0},	// y4
		{93,8,94,0,0},	// y5	
		{16,15,17,0,19},	// y6	
		{0,18,0,0,0},	// y7	
	};

int change(int yy,int xx){
	
	user.posX=xx;
	user.posY=yy;	
	return(mapdis[user.posY][user.posX]);
}

int multiswap(int direccion){
	 
	 
	switch  (direccion){
	
		case 8: //arriba
			user.posY=user.posY-1; break;
		case 2: //abajo
			user.posY=user.posY+1; break;
			
		case 4: // izquierda
			user.posX=user.posX-1; break;
		
		case 6: //derecha
			user.posX=user.posX+1; break;
	}
	
	int	map=mapdis[user.posY][user.posX];
	
	if (map>40){
		switch (map){
			case 91:
				map=change(5,1); break;
			case 92:
				map=change(4,2); break;
			case 93:
				map=change(3,2); break;
			case 94:
				map=change(3,1); break;
			case 95:
				map=change(4,1); break;
			case 96:
				map=change(5,1); break;
			case 97:
				map=change(2,2); break;
			case 98:
				map=change(6,1);; break;
			
		}	
	}
	return (map);
}
	
void ifswapX(){
	switch (x){
				case 0:
					
					swap(multiswap(4),limB-1,y); break;
				case 19:
					
					swap(multiswap(6),0,y); break;			
			}	
}

void ifswapY(){
	switch (y){
				case 0:
					
					swap(multiswap(8),x,limA-1); break;
				case 11:
					
					swap(multiswap(2),x,0); break;	
						}
	
}	

void paintearD (int unit){
	
	switch (unit){
				
				case 0: set (1,GRIS_CLARO); printf ("  "); set(); break;
				
				case 1: 
					if (room<9){
						set (X713); printf ("€€"); set(); break;					
					}
					else{
						if (room>14){
							set (CIAN); printf ("€€"); set(); break;
						} 
						else set (JOHI); printf ("€€"); set(); break;
					}				
				
				case 2: set (1,GRIS_CLARO); printf ("  "); set(); break;
				
				case 3: set (NEGRO,GRIS_CLARO); printf ("Ω="); set(); break;
				
				case 4: set (0,GRIS_CLARO); printf ("##"); set(); break;
				
				case 5: set (ROJOI); printf ("õõ"); set(); break;
				
				case 6: set (1,GRIS_CLARO); printf ("∞∞"); set(); break;
				
				case 7: set (AMARILLOI,GRIS_CLARO); printf ("˛ "); set(); break;
				
				case 8: set (AMARILLOI,5); printf ("##"); set(); break;
				
				case 9: set (AZUL_INTENSO); printf ("€€"); set(); break;
				
				case 10: set (AZUL_INTENSO,GRIS_CLARO); printf ("‹‹"); set(); break;
				
				case 11: set (AZUL_INTENSO,GRIS_CLARO); printf ("ﬂﬂ"); set(); break;
				
				case 12: set (BLANCO_INTENSO,AZUL_INTENSO); printf ("€€"); set(); break;
				
				case 13: set (BLANCO_INTENSO,AZUL_INTENSO); printf ("‹‹"); set(); break;
				
				case 14: set (BLANCO_INTENSO,AZUL_INTENSO); printf ("ﬂﬂ"); set(); break;
				
				case 15: set (1,AZUL_INTENSO); printf ("  "); set(); break;
				
				case 16: set (MAGENTA_INTENSO); printf ("€€"); set(); break;
				
				case 17: set (AMARILLOI,GRIS_CLARO); printf ("Ω="); set(); break;
				
			}
}

int borde[3][20]={
	{1,7,7,2,2,2,2,2,2,2,2,2,2,3,0,0,0,0},
	{4,8,8,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0},
	{5,7,7,2,2,2,2,2,2,2,2,2,2,6,0,0,0,0}	
};

void paintgame(){
	
	
	system ("cls");
	

	paintF(iniX-1,iniY-1,borde[0],1,18,MAGENTAI);
	for (int a=0;a<limA;a++) paintF(iniX-1,a+iniY,borde[1],1,18,MAGENTAI);
	paintF(iniX-1,limA+iniY,borde[2],1,18,MAGENTAI);
	
	go (iniX,iniY);
	
	for (int a=0;a<limA;a++ ){
		
		for (int b=0;b<limB;b++){
			
			if (b==0 && a>0) go(iniX,a+iniY);//printf ("\n");
			
			paintearD(screen[room][a][b]);
			 
		}
	}
	go(x*2+iniX,y+iniY);
	printf ("‹ﬂ");
		

}
		
void cursor(){
	
	
	fflush(stdin);
	xr=(x*2)+iniX;
	yr=y+iniY;
	switch (tolower(getch())){
		
		case 'w': 
			if (y>0 && screen[room][y-1][x]!=1 && screen[room][y-1][x]!=2){
						
				go(xr,yr);
				paintearD(screen[room][y][x]);				
				y=y-1;				
				go(xr,y+iniY);
				//set (BLANCO,0);					
				printf ("‹ﬂ");
				set();	
				}
			else ifswapY();
			break;
			
		case 's': 
			if (y<limA-1 && screen[room][y+1][x]!=1 && screen[room][y+1][x]!=2){
				go(xr,yr);				
				paintearD(screen[room][y][x]);			
				y=y+1;				
				go(xr,y+iniY);			
				printf ("‹ﬂ");
				}	
			else ifswapY();
			break;
			
		case 'a':
			if (x>0 && screen[room][y][x-1]!=1 && screen[room][y][x-1]!=2){				
				go(xr,yr);				
				paintearD(screen[room][y][x]);				
				x=x-1;				
				go(x*2+iniX,yr);				
				printf ("‹ﬂ");
				}
			else ifswapX();
			break;
			
		case 'd':
			if (x<limB-1 && screen[room][y][x+1]!=1 && screen[room][y][x+1]!=2){			
				go(xr,yr);				
				paintearD(screen[room][y][x]);		
				x=x+1;				
				go(x*2+iniX,yr);				
				printf ("‹ﬂ");	
				}
			else ifswapX();
			break;
			
		/*	
		case 'x':
			 	check=1;
				break;
		case 'y':
				/*if(check7==1){
					check1=1;
					check7=0;
				} 
				if(check==1){
			developertools==713;
			cuadro("û ",40,0);
			break;
			check==0;
			if (developertools==713){
				developertools=0;				
			} 
		}
				break;*/
	
				
		case 'j':
		
		if (developertools==713) swap (room+1,x,y); break;
		
		case 'h':
		if (developertools==713) swap (room-1,x,y); break;
		
		case 'k':
			if (developertools==713){
				user.key=1;
				user.key2=1;
				user.keyegg=1;	
			}
			 break;
			
		case 'm':
			if (developertools==713){
			stopGame(player);
		}
		case 'b':
			if (developertools==713){
			finishGame();
		}
		case 'o':
			if (developertools==713){
			for(int i=0;i<6;i++){
				
				strcpy(player[i].nombre,player[6].nombre);
				player[i].timepo=20*(i+1);			
			}
		}
			break;
		
		default: 
		
			go(x*2+iniX,y+iniY);				
			printf ("û");
	}	
	
	
}

void hud();

void info(int startt){
	cuadro(user.nombre,7,0);
	
	paintF(hudX,hudY-1,borde[0],1,18,MAGENTAI);
	paintF(hudX,hudY,borde[1],1,18,MAGENTAI);
	paintF(hudX,hudY+1,borde[2],1,18,MAGENTAI);

	go (hudX+3,hudY);
	player[6].timepo=user.timepo=(clock() - startt )/ 1000;
	printf ("Time: %3d Seg | X: %2d | Y: %2d  ",user.timepo,x,y);
	
	if (user.key==1) {
		set (BLANCO_INTENSO); printf ("Ω= "); set();
	}
	else{
		printf ("   ");
	}
	
	if (user.key2==1) {
		set (AMARILLOI); printf (" Ω="); set();
	}
	else{
		printf ("   ");
	}
	
	if(user.keyegg==1){
		cuadro(" ˛  ",hudX+42,0);
		screen[15][11][8]=0;	
		screen[15][11][9]=0;	
		screen[15][11][10]=0;	
		screen[15][11][11]=0;
		
		screen[1][4][0]=0;	
		screen[1][5][0]=0;	
		screen[1][6][0]=0;	
		screen[1][7][10]=0;	
	} 
}

void hudEND(){
	
	cuadro(" S A L I R  ",iniX+13,iniY-4);	
	cuadro(" P U N T A J E S  ",iniX+42,iniY+limA/2-2);
	cuadro(" TIEMPO:     Seg  ",MAGENTA,iniX+10,iniY+limA+1);
	go(iniX+20,iniY+limA+2);
	printf ("%3d",user.timepo);
	if (user.keyegg==1){
		cuadro("  M E N U   ",iniX-15,iniY+limA/2-2);				
	} 
}

void swap(int ROOM,int xx,int yy){
	room=ROOM;
	x=xx;
	y=yy;	
	paintgame();
	if (ROOM==15) hud();
	if (ROOM==1) hudEND();
	if (game==0 && user.keyegg==0) cuadro(" GANASTE! Pero eso no significa que sea el final...  ",ROJOI,3,hudY-1);
	if (game==0 && user.keyegg==1) cuadro(" GANASTE! ENCONTRASTE LA LLAVE, VUELVE AL MENU!      ",VERDEI,3,hudY-1);
	lol=0;
}

void stopGame(secundario datos[7]){
	game=0;
	archivosW(datos);
	if (user.keyegg==0) cuadro(" GANASTE! Pero eso no significa que sea el final...  ",ROJOI,3,hudY-1);
	if (user.keyegg==1) cuadro(" GANASTE! TAMBIEN TIENES LA LLAVE... VUELVE AL MENU! ",VERDEI,3,hudY-1);
	
	
	for (;;){
		cursor();
		position();
		if(user.keyegg==1){
			cuadro(" ˛  ",hudX+42,0);
			screen[15][11][8]=0;	
			screen[15][11][9]=0;	
			screen[15][11][10]=0;	
			screen[15][11][11]=0;	
			
			screen[1][4][0]=0;	
			screen[1][5][0]=0;	
			screen[1][6][0]=0;	
			screen[1][7][0]=0;
			cuadro(" GANASTE! ENCONTRASTE LA LLAVE, VUELVE AL MENU!      ",VERDEI,3,hudY-1);	
	} 
		go(0,0);
	} 
}

void finishGame(){
	system("CLS");
	cuadro(" Gracias por jugar!  ",22,3);
	cuadro(" By X7REME13 and Johi  ",MAGENTAI,21,6);
	Sleep(3170);
	exit(0);
}

void ramkey(){
	
	do{
		user.keyY=rand()%limA;
		user.keyX=rand()%limB;
		user.roomX=rand()%2+1;
		user.roomY=rand()%2+3;
		
	}while(screen[mapdis[user.roomY][user.roomX]][user.keyY][user.keyX]!=0);
	
	screen[mapdis[user.roomY][user.roomX]][user.keyY][user.keyX]=3;
	
}


void position(){
		switch (room){
			case 0:
				finishGame();
			case 1:
				if (y==0){
						if (x>=8 && x<=11) finishGame(); 
					
				}
				break;
				
			case 2:
				setcolortext (JOHI,GRIS_CLARO);
				go(iniX+14,iniY+2);	printf ("^^^^^^^^^^^^\n");
				go(iniX+14,iniY+3);	printf ("  NIVEL 2:  \n");
				go(iniX+14,iniY+4);	printf ("  LABERINTO \n");
				go(iniX+14,iniY+5);	printf ("TRANSPARENTE\n");
				set(0,GRIS_CLARO);
				go(iniX+14,iniY+6);	printf ("ÕÕÕÕÕÕÕÕÕÕÕÕ\n");
				
				
				setcolortext (X713,GRIS_CLARO);
				
				go(iniX+14,iniY+7);	printf ("FELICIDADES\n");
				go(iniX+14,iniY+8);	printf ("COMPLETASTE\n");
				go(iniX+14,iniY+9);	printf ("EL  NIVEL 1\n");
				set();
				break;
			case 3:
				switch (x){
					case 10:
						if (y==7){
							if (user.key==1){
								swap(3,10,3);
							}  break;												
						}
						if (y==4){
							if (user.key==1){
								 swap(3,10,8);
							}	break;											
						}
					case 9:
						if (y==7){
							if (user.key==1){
								swap(3,9,3);
							} 	break;											
						}  
						if (y==4){
							if (user.key==1){
								swap(3,9,8);
							} 	break;											
						} 
					
							
				}break;
			
			case 12:
				switch (x){
					case 10:
						if (y==7){
							if (user.key2==1){
								swap(12,10,3);
								stopGame(player);
							}  break;												
						}
						if (y==4){
							if (user.key2==1){
								 swap(12,10,8);
								 
							}	break;											
						}
					case 9:
						if (y==7){
							if (user.key2==1){
								swap(12,9,3);
								stopGame(player);
							} 	break;											
						}  
						if (y==4){
							if (user.key2==1){
								swap(12,9,8);
							} 	break;											
						} 
					
							
				}break;
			case 7: 
				switch (y){
					case 11:
						if (x>=8 && x<=11) swap(change(2,2),x,1); break; 
						
				}	break;
	
			case 9: 
				switch (y){
					case 11:
						if (lol==0){
						go(x*2+iniX,y+iniY);
						paintearD(screen[room][y][x]);				
						y=y-1;				
						go(x*2+iniX,y+iniY);
						//set (BLANCO,0);					
						printf ("‹ﬂ");
						set();
						lol=1;
						}
						else if (x>=8 && x<=11){
							swap(change(1,1),x,0);
							lol=0;
							break; 
						} 
						
				
				}	break;
				
			case 15:
				
				if (game==0){
					
					if (y==0){
						if (x>=8 && x<=11) finishGame(); 	
				}
				screen[15][0][8]=16;	
				screen[15][0][9]=16;	
				screen[15][0][10]=16;	
				screen[15][0][11]=16;
				cuadro(" S A L I R  ",iniX+13,iniY-4);				
					
				}
				break;
				
				
			case 11:
				if (y==6){
					if (x==8){
						user.key2=1;
						screen[11][6][8]=0;	
										
					}
				}
			break;
			
			case 10:
				if (y==9){
					if (x==3){
						user.keyegg=1;
						screen[10][9][3]=0;	
					}					
			}
			break;
				
			
				break;
			case 16: 
				setcolortext (ROJO,GRIS_CLARO);
				go(iniX+16,iniY+3);	printf ("OBJETIVO"); 
				setcolortext (VERDE,GRIS_CLARO); 
				go(iniX+7,iniY+4);	printf (" Encuentra las llaves ");
				set (NEGRO,GRIS_CLARO); printf ("Ω=\n"); setcolortext (VERDE,GRIS_CLARO);
				go(iniX+7,iniY+5);	printf (" para poder acceder a los \n");
				go(iniX+7,iniY+6);	printf ("castillos de los distintos\n");
				go(iniX+7,iniY+7);	printf ("niveles en el menor tiempo\n");
				go(iniX+7,iniY+8);	printf ("          posible         \n");
				setcolortext (); 
				break;

			case 17:
				
				
			
				
				setcolortext (VERDEI,MAGENTA);
				go(iniX+7,iniY+2);	printf ("         PUNTAJES          \n");
				go(iniX+7,iniY+3);	printf ("  # ∫ Nombre  ∫   Tiempo   \n");
				
				setcolortext (JOHI,MAGENTA);
				go(iniX+7,iniY+4);	printf ("  1 ∫ %6s ∫  %3d seg   \n",player[0].nombre,player[0].timepo);
				
				setcolortext (CIAN_INTENSO,MAGENTA);
				for(int i=0;i<5;i++){
					go(iniX+7,iniY+5+i);	printf ("  %d ∫ %6s ∫  %3d seg   \n",i+2,player[i+1].nombre,player[i+1].timepo);	
				}
				
				
				
				setcolortext ();
				break;
			
			case 18:
				go(iniX+7,iniY+1);	printf ("       DIRECTED BY:       \n"); 
				break;
			
			case 19:
				go(iniX+5,iniY+3);	printf ("                            \n");
				go(iniX+5,iniY+4);	printf ("   INSERTE SU NOMBRE AQUI   \n");
				go(iniX+5,iniY+5);	printf ("                            \n");
				go(iniX+5,iniY+6);	printf ("           ______           \n"); // SON 6 GUIONES
				go(iniX+5,iniY+7);	printf ("           ^^^^^^           \n");
				go(iniX+5,iniY+8);	printf ("                            \n");
				
				go(iniX+16,iniY+6);for (int i=0;i<6;i++){
					player[6].nombre[i]=toupper(getch());
					printf("%c",player[6].nombre[i]);
				}
				
				strcat(player[6].nombre," ");
				strcpy(user.nombre,player[6].nombre);
				
				swap (15,limB/2,limA/2-1);
		}//cierre del super switch
	
	
	
	if (mapdis[user.roomY][user.roomX]==room){
		if (user.keyY==y){
			if (user.keyX==x){
				user.key=1;
				screen[mapdis[user.roomY][user.roomX]][user.keyY][user.keyX]=0;					
			}
		}
		
	}
}
			
void hud(){
	
 	cuadro(" J U G A R  ",iniX+13,iniY-4);
	cuadro(" A Y U D A  ",iniX-15,iniY+limA/2-2);
	cuadro(" P U N T A J E S  ",iniX+42,iniY+limA/2-2);
	if (user.keyegg==1){
		cuadro(" C R E D I T O S  ",iniX+10,iniY+limA+1);
		
	} 
	
 }
 
 void welcomes(){
 	system("CLS");
 	go(8,3);
 	
 	for (int a=0;a<15;a++ ){
		
		for (int b=0;b<39;b++){
			
			if (b==0 && a>0) go(8,a+3);//printf ("\n");
			
			paintearD(welcome[a][b]);
			 
		}
		
	}
	paintF(hudX+10,18,borde[0],1,18,MAGENTAI);
	paintF(hudX+10,19,borde[1],1,18,MAGENTAI);
	paintF(hudX+10,20,borde[2],1,18,MAGENTAI);
	
	go(hudX+12,19);
	set(JOHI);
	for (int i=0;i<38;i++){
		printf ("-");
		
	}
	go(hudX+12,19);
	set(X713);
	for (int i=0;i<38;i++){
		printf ("û");
		Sleep(i*5);		
	}
	printf ("\r");
	set();
 }

int main(){

	settitle("ADVENTURE XJ! by X7REME13 and Johi");
	system ("cls");
	user.key=0;
	user.key2=0;
	user.keyegg=0;
	user.posX=1;
	user.posY=6;

	srand (time(NULL));	
	ramkey();

	
	welcomes();
	
	archivosR();
	
	swap(19,limB/2,limA/2);
	position();
	int tiempoo=clock();
	info(tiempoo);
	
	setcolortext (CIAN,GRIS_CLARO);
	go(iniX+7,iniY+3);	printf ("         CONTROLES        \n");
	go(iniX+7,iniY+6);	printf ("      W =>   ARRIBA       \n");
	go(iniX+7,iniY+7);	printf ("      S =>   ABAJO        \n");
	go(iniX+7,iniY+8);	printf ("      A =>  IZQUIERDA     \n");
	go(iniX+7,iniY+9);	printf ("      D =>   DERECHA      \n");
				
				
	if (strcmp(player[6].nombre,"DEV713 ")==0){
		developertools=713;
		cuadro(" û  ",VERDEI,VERDEI,2,0);
		getch();
	} 
	
	//---------------
	for(;;){
		position();
		cursor();
		info(tiempoo);
		go(0,0);	
	}
	//---------------
	
}

