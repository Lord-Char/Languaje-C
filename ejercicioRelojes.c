/* ========================================================================== */
/*                                                                            */
/*   Filename.c                                                               */
/*   (c) 2012 Author                                                          */
/*                                                                            */
/*   Description                                                              */
/*  Reloj Digital - Analogico                                                 */
/* F1: Cambia a reloj analogico y viceversa                                   */
/* ========================================================================== */
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#define M_PI 3.14159265358979323846

// el reloj debe ajustarse a la hora de la pc, si es 24 hs o AM/PM
const unsigned char ASCII30 []={0x0E,0x13,0x15,0x15,0x19,0x11,0x0E,0x00};// el 0
const unsigned char ASCII31 []={0x02,0x06,0x02,0x02,0x02,0x02,0x07,0x00};// el 1
const unsigned char ASCII32 []={0x06,0x09,0x02,0x02,0x04,0x08,0x0F,0x00};// el 2
const unsigned char ASCII33 []={0x0E,0x11,0x01,0x07,0x01,0x11,0x0E,0x00};// el 3
const unsigned char ASCII34 []={0x04,0x0A,0x12,0x1F,0x02,0x02,0x0F,0x00};// el 4
const unsigned char ASCII35 []={0x0F,0x10,0x10,0x0E,0x01,0x01,0x1E,0x00};// el 5
const unsigned char ASCII36 []={0x0E,0x11,0x10,0x1F,0x11,0x11,0x0E,0x00};// el 6
const unsigned char ASCII37 []={0x1F,0x01,0x02,0x04,0x08,0x08,0x08,0x00};// el 7
const unsigned char ASCII38 []={0x0E,0x11,0x11,0x0E,0x11,0x11,0x0E,0x00};// el 8
const unsigned char ASCII39 []={0x0E,0x11,0x11,0x0F,0x01,0x01,0x0E,0x00};// el 9
const unsigned char ASCII3A []={0x00,0x06,0x06,0x00,0x06,0x06,0x00,0x00};// dos puntos
//array que almacena los caracteres del reloj digital en codigo binario
const unsigned char * const ROMCHAR [] = {ASCII30, ASCII31, ASCII32, ASCII33, ASCII34, ASCII35, ASCII36, ASCII37, ASCII38, ASCII39, ASCII3A};

int main()
{
    clock_t lastTime, currentTime;
    int  counter, i, j,k, mask, interval,time_timer,xSeg, ySeg, xMin, yMin, xHour, yHour;
    char opt;
    struct tm *tblock;
    struct time hora; 
    char strHora [32], aux;
    float angleHour, radioSeg, angleMin, radioMin, angleSeg, radioHour; 
    // no se como declarar el numero pi M_PI

                  
        textmode(C4350); //imprime la consola en modo 80*50
        textcolor (YELLOW); // imprime los caracteres que simulan la hora en color de referencia
        counter = 1;
        _setcursortype (_NOCURSOR); // oculta el cursor


                  
while(1){
gotoxy(25, 45);
    printf("[F1]: Tipo de Reloj -- [ESC]:Termina");   
    gettime(&hora);       

        if(kbhit()){
            opt = getch();
                if(opt == 0){
opt = getch();
    if(opt == 59){
        if(counter == 0){
            counter = 1;
                }
else{
    counter = 0;
}
    }   
                }        
else{
    if(opt == 27)
        break;
}    
        }
//Si el counter es 0 (cero) se muestra el reloj analogico
    if(counter == 0){    
        //Aca empieza el reloj digital
        
// ciclo for para la hora
    aux = hora.ti_hour / 10;             
        for (i=0; i<8; i++){                                
            mask = 0x80;
                for (j=0; j<8; j++){
gotoxy (j+10, i+2);
    if (ROMCHAR [aux][i] & mask)
        cprintf ("%c ", 254);
            else
                cprintf (" ");
mask >>= 1;   
                }
        }        

aux = hora.ti_hour % 10;
    for (i=0; i<8; i++){
        mask = 0x80; 
            for (j=0; j<8; j++){
                gotoxy (j+18, i+2);
if (ROMCHAR [aux][i] & mask)
    cprintf ("%c ", 254);
        else
            cprintf (" ");
                mask >>= 1; 
            }
    }
        
//ciclo for para los dos puntos
    for (i=0; i<8; i++){
        mask = 0x80;
            for (j=0; j<8; j++){
                gotoxy (j+26, i+2);
if (ROMCHAR [10][i] & mask)
    cprintf ("%c ", 254);
        else
            cprintf (" ");
                mask >>= 1;   
            }
    }        

//ciclo for para los minutos           
    aux = hora.ti_min / 10; 
        for (i=0; i<8; i++){
            mask = 0x80;
                for (j=0; j<8; j++){
gotoxy (j+34, i+2);
    if (ROMCHAR [aux][i] & mask)
        cprintf ("%c ", 254);
            else
                cprintf (" ");
mask >>= 1;   
                }
        }        

aux = hora.ti_min % 10;
    for (i=0; i<8; i++){
        mask = 0x80; 
            for (j=0; j<8; j++){
                gotoxy (j+42, i+2);
if (ROMCHAR [aux][i] & mask)
    cprintf ("%c ", 254);
        else
            cprintf (" ");
                mask >>= 1; 
            }
    }
            
//ciclo for para los dos puntos
    for (i=0; i<8; i++){
        mask = 0x80;
            for (j=0; j<8; j++){
                gotoxy (j+50, i+2);
if (ROMCHAR [10][i] & mask)
    cprintf ("%c ", 254);
        else
            cprintf (" ");
                mask >>= 1;   
            }
    }        
            
//ciclo for para los segundos
    aux = hora.ti_sec / 10; 
        for (i=0; i<8; i++){
            mask = 0x80;
                for (j=0; j<8; j++){
gotoxy (j+58, i+2);
    if (ROMCHAR [aux][i] & mask)
        cprintf ("%c ", 254);
            else
                cprintf (" ");
mask >>= 1;   
                }
        }        
aux = hora.ti_sec % 10;
    for (i=0; i<8; i++){
        mask = 0x80; 
            for (j=0; j<8; j++){
                gotoxy (j+66, i+2);
if (ROMCHAR [aux][i] & mask)
    cprintf ("%c ", 254);
        else
            cprintf (" ");
                mask >>= 1; 
            }      
    }
Sleep(1000);
    system("cls");    
        }
            else {//Sino se muestra el reloj digital           
                gettime(&hora);
                
//Aca empieza el reloj analogico
    for(j=5; j<70;j++){
        gotoxy(1,j);
            clreol();   
    }        
//Ciclo for para mostrar la esfera del reloj analogico
    for(k=0; k<360; k=k+2){
        xSeg = 40 + floor(16*cos(k*M_PI/180)+0.5);
        ySeg = 20 + floor(16*sin(k*M_PI/180)+0.5);
            gotoxy(xSeg, ySeg);
                cprintf("%c", 219);
    } 

//Aguja del segundero
    angleSeg = (6*hora.ti_sec - 90)*M_PI/180 ;
    radioSeg = 15;

for(i=0; i<radioSeg; i++){
    xSeg = 40 + floor(i*cos(angleSeg)+0.5);
    ySeg = 20 + floor(i*sin(angleSeg)+0.5);
        gotoxy(xSeg, ySeg);
        cprintf("%c", 219);
}

//Aguja del minutero 
    angleMin = (6*hora.ti_min - 90)*M_PI/180 ;
    radioMin = 10;         

for(i=0; i<radioMin; i++){
    xMin = 40 + floor(i*cos(angleMin)+0.5);
    yMin = 20 + floor(i*sin(angleMin)+0.5);
        gotoxy(xMin, yMin);
        cprintf("%c", 219);
}

//Aguja de la hora
    aux = hora.ti_hour;     
    angleHour =  (30*aux - 90)*M_PI/180 ;;
    radioHour = 7;

for(i=0; i<radioHour; i++){
    xHour = 40 + floor(i*cos(angleHour)+0.5);
    yHour = 20 + floor(i*sin(angleHour)+0.5);
        gotoxy(xHour, yHour);
        cprintf("%c", 219);
}

//Sleep nos refresca la pantalla (en milisegundos)    
    Sleep(1000);
        clrscr(); 
            }
                }        

getch();
    return 0;
        }
        