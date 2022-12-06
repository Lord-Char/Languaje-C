/* Armar un array de 10 strucs que defina una agenda con nombre, apellido y Numero de telefono.
[F1]: Carga un nuevo contacto, [F2]: Elimina un contacto [Flechas]: Recorre las estructuras */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#define SIZE 10

struct Agenda{
    char nombre[50];
    char apellido[50];
    int numTel;
};

void main(){
    //system ("mode 80,42"); //parece que aca no puedo configurar el tamaño de la ventana.
    int i = 1, contacto=0, j;
    struct Agenda persona[SIZE];
    char indice[107]="[F1]: Cargar un nuevo contacto\n[F2]: Eliminar un contacto\n[Flechas]: Recorrer las estructuras\n[ESQ]: Salir\r\n\n";
    
    for (j = 0; j < SIZE; j++) { //Inicializacion de los structs.
        strcpy(persona[j].nombre,"");
        strcpy(persona[j].apellido,"");
        persona[j].numTel = 0;  
    }

    printf("%s",indice);
    textcolor(LIGHTRED);
    cprintf("%c ", 17); //Flecha hacia la izquierda.
    normvideo(); //Colores vueltos a sus valores normales.
    printf("Pagina %d de 10", i); //Numero de pagina de la agenda.
    textcolor(LIGHTGREEN);
    cprintf(" %c\r\n\n", 16); //Flecha hacia la derecha.
    normvideo();
    textcolor(LIGHTRED);
    cprintf("Pagina vacia");
    normvideo();
    _setcursortype(_NOCURSOR); //Oculta el cursor.

    while((getch()) != 27){
        if(kbhit()){
            switch(getch()){
                case 59: //F1: Carga un nuevo dato.
                    if (contacto < SIZE) {
                        for (j = 1; j <= SIZE; j++) { //Recorre la agenda desde la pagina 1 a la 10
                            if (persona[j].numTel == 0) { //buscando la primera pagina vacia.
                                _setcursortype(_NORMALCURSOR); //Hace visible el cursor.
                                system("cls");
                                printf("%s",indice);
                                textcolor(LIGHTGREEN);
                                cprintf("Nuevo contacto en pagina %d\n", j);
                                normvideo();

                                printf("\r\nIngrese el nombre: ");
                                gets(persona[j].nombre);
                                
                                printf("Ingrese apellido: ");
                                gets(persona[j].apellido);

                                printf("Ingresar telefono: ");
                                scanf("%d", &persona[j].numTel);

                                textcolor(LIGHTGREEN);
                                cprintf("\r\nContacto guardado!");
                                normvideo();
                                _setcursortype(_NOCURSOR);
                                contacto++;
                                break; //Sale de bucle FOR, ya que agregamos de un contacto a la vez.
                            }
                        }
                    }
                    else {
                        textcolor(LIGHTRED);
                        cprintf("\r\nLa agenda esta llena\n");
                        normvideo();
                        break;
                    }
                break;
                case 60: //F2. Elimina un dato
                    if (persona[i].numTel != 0){
                        strcpy(persona[i].nombre,"");
                        strcpy(persona[i].apellido,"");
                        persona[i].numTel = 0;
                        if(contacto > 0){
                            contacto--;
                        }
                        textcolor(LIGHTRED);
                        cprintf("\r\nContacto borrado!");
                        normvideo();
                    }
                break;                    
                case 75: //Flecha izquierda. Recorre las estructuras.
                    if (i > 1 && i <= SIZE){
                        Beep(700,100); //Produce un sonido al cambiar de pagina.
                        system("cls");
                        printf("%s",indice);
                        i--;
                        if (i > 1) {
                            textcolor(LIGHTGREEN);
                            cprintf("%c ", 17);
                            normvideo();
                        }
                        else {
                            textcolor(LIGHTRED);
                            cprintf("%c ", 17);
                            normvideo();
                        }
                        printf("Pagina %d de 10", i);
                        if (i < 10) {
                            textcolor(LIGHTGREEN);
                            cprintf(" %c\r\n\n", 16);
                            normvideo();
                        }
                        else {
                            textcolor(LIGHTRED);
                            cprintf(" %c\r\n\n", 16);
                            normvideo();
                        }
                        if (persona[i].numTel == 0){
                            textcolor(LIGHTRED);
                            cprintf("Pagina vacia");
                            normvideo();
                            _setcursortype(_NOCURSOR);
                        }
                        else {
                            printf("Nombre: %s\nApellido: %s\nNumero de telefono: %d\n", persona[i].nombre, persona[i].apellido, persona[i].numTel);    
                        }  
                    }
                break;
                case 77: //Flecha derecha. Recorre las estructuras.
                    if (i >= 1 && i < SIZE){
                        Beep(700,100);
                        system("cls");
                        printf("%s", indice);
                        i++;
                        if (i > 1) {
                            textcolor(LIGHTGREEN);
                            cprintf("%c ", 17);
                            normvideo();
                        }
                        else {
                            textcolor(LIGHTRED);
                            cprintf("%c ", 17);
                            normvideo();
                        }
                        printf("Pagina %d de 10", i); //Numero de pagina de la agenda.
                        if (i < 10) {
                            textcolor(LIGHTGREEN);
                            cprintf(" %c\r\n\n", 16);
                            normvideo();
                        }
                        else {
                            textcolor(LIGHTRED);
                            cprintf(" %c\r\n\n", 16);
                            normvideo();
                        }
                        if (persona[i].numTel == 0){
                            textcolor(LIGHTRED);
                            cprintf("Pagina vacia");
                            normvideo();
                            _setcursortype(_NOCURSOR); 
                        }
                        else {
                            printf("Nombre: %s\nApellido: %s\nNumero de telefono: %d\n", persona[i].nombre, persona[i].apellido, persona[i].numTel);    
                        }  
                    }
                break;
            }
        }
    }
}
