#ifndef CONSOLEMANAGER_H_INCLUDED
#define CONSOLEMANAGER_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<string.h>
#include<iostream>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include <wincon.h>

using namespace std;


/**
Version 2.X
Fundadores de la biblioteca "ConsoleManager" - Adriel Elian Rasjido - Alan Gabriel Vaca
Biblioteca Colaborativa - UTN FRGP.

Integrantes:
-VERSION+ DESAROLLADOR/A
-BETA 1.X Adriel Elian Rasjido
-BETA 1.X Alan Gabriel Vaca
-CM_V 1.X José Enrique Menéndez Fernández
-CM_V 2.X Yesica Regina Laurentino Goncalves

AVISO*****(esta es una biblioteca para soporte visual y/o funciones secundarias,
           idea para acortar el tiempo de diseño y asi los usuarios puedan
           enfocarse en la logica)

¿QUIEN PUEDE USARLO?
En primera instacia fue creada para los alumnos o cursantes de la UTN
Aunque la implementacion puede ser usada fuera de la misma
SIEMPRE Y CUANDO, NO ALTEREN EL PRODUCTO, TAMPOCO LA ELIMINACION DE LOS
ARCHIVOS ADJUNTOS AL DESCARGABLE

ADVERTENCIA:Contiene una licencia MIT, NO debe ser borrada ni alterada
            para no incumplir las leyes y condiciones de privacidad
            (SI PUBLICAS TU PROYECTO/PROGRAMA UTILIZANDO ESTA BIBLIOTECA
            PUEDES USARLA SIEMPRE Y CUANDO NO INCUMPLAS LO ANTES PROPUESTO,
            ESTO ADMITE EL PODER VENDERLO PERO SIN ALTERACIONES)

¿PUEDO FORMAR PARTE DEL PROYECTO?
SI, ingresa al siguiente LINK: https://discord.gg/a4ZJh8XDwf
DEBES JUSTIFICAR QUE SOS ALUMNO O CURSANTE DE LA UTN (Presentando LEGAJO, INSCRIPCION y MATERIA)
Y ser aprobado por los administradores en un cuestionario.
¿QUÉ PASA SI NO SOY ACEPTADO?
Puedes ser postulante de ideas que seran usadas para futuras actualizacion.
**/

///VERSION 1.X EN ADELANTE
/*
Esta actualizacion trae 10 nuevas funciones
PARA MAS INFO VER EL VIDEO 1X
*/

///Titulo
//Solicita el nombre del titulo
void titulo(const char* nombrar){SetConsoleTitle(nombrar);}

///Gotoxy
//Solicitara los ejes X / Y para ubicarse
void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos; dwPos.X = x; dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }

///HANDLE (DECLARACION NO BORRAR)
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

///CURSOR
//Habilita con TRUE y desabilita con FALSE
void cursor(bool estado){
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = estado;
    SetConsoleCursorInfo(out, &cursorInfo);
}

///RECUADRO
//Al llamar esta funcion se podra crear recuadros
void recuadro(short x, short y, short ancho, short alto){
    int i, j;
    for(i=x; i<=x+ancho; i++){
        for(j=y; j<=y+alto; j++){gotoxy(i, j);
            if(i==x && j==y){cout << (char) 201;}                               ///ARRIBA  - IZQUIERDA
            else if(i==x+ancho && j==y){cout << (char) 187;}                    ///ARRIBA  - DERECHA
            else if(i==x && j==y+alto){cout << (char) 200;}                     ///ABAJO   - IZQUIERDA
            else if(i==x+ancho && j==y+alto){cout << (char) 188;}               ///ABAJO   - DERECHA
            else if(j==y || j==y+alto){cout << (char) 205;}                     ///ARRIBA  - ABAJO
            else if(i==x || i==x+ancho){cout << (char) 186;}                    ///DERECHA - IZQUIERDA
            else{cout << " ";}                                                  ///DENTRO DEL RECUADRO
        }
    }
}


///GAMA DE COLORES
//Se podra visualizar toda la gama completa de colores
void gamaColores(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for(int k = 1; k < 255; k++){SetConsoleTextAttribute(hConsole, k);
    cout << k << " Gracias por usar ConsoleManager :)" << endl;
  }
}
///COLOR
//Al llamar esta funcion se solicitara el nombre del color en español
void color(const char* nombre){
if(strcmp(nombre,"negro")==0)           {SetConsoleTextAttribute(hConsole,0);}
else if(strcmp(nombre,"azul")==0)       {SetConsoleTextAttribute(hConsole,1);}
else if(strcmp(nombre,"verde")==0)      {SetConsoleTextAttribute(hConsole,2);}
else if(strcmp(nombre,"aguamarina")==0) {SetConsoleTextAttribute(hConsole,3);}
else if(strcmp(nombre,"rojo")==0)       {SetConsoleTextAttribute(hConsole,4);}
else if(strcmp(nombre,"morado")==0)     {SetConsoleTextAttribute(hConsole,5);}
else if(strcmp(nombre,"amarillo")==0)   {SetConsoleTextAttribute(hConsole,6);}
else if(strcmp(nombre,"blanco")==0)     {SetConsoleTextAttribute(hConsole,7);}
else if(strcmp(nombre,"gris")==0)       {SetConsoleTextAttribute(hConsole,8);}
else if(strcmp(nombre,"verdeclaro")==0) {SetConsoleTextAttribute(hConsole,10);}
else if(strcmp(nombre,"celeste")==0)    {SetConsoleTextAttribute(hConsole,11);}
else if(strcmp(nombre,"salmon")==0)     {SetConsoleTextAttribute(hConsole,12);}
else if(strcmp(nombre,"violeta")==0)    {SetConsoleTextAttribute(hConsole,13);}
else if(strcmp(nombre,"default")==0)    {SetConsoleTextAttribute(hConsole,7);}
}

///FONDO
//Al llamar esta funcion se solicitara el nombre del color tanto del fondo como el del texto
void fondo(char* color){
if(strcmp(color,"default")==0){system("color 07");}
}
void fondo(char* color_fondo, char* color_texto){
string letra; string fondo;
if(strcmp(color_texto,"negro")==0)           {letra="0";}
else if(strcmp(color_texto,"azul")==0)       {letra="1";}
else if(strcmp(color_texto,"verde")==0)      {letra="2";}
else if(strcmp(color_texto,"aguamarina")==0) {letra="3";}
else if(strcmp(color_texto,"rojo")==0)       {letra="4";}
else if(strcmp(color_texto,"morado")==0)     {letra="5";}
else if(strcmp(color_texto,"amarillo")==0)   {letra="6";}
else if(strcmp(color_texto,"blanco")==0)     {letra="7";}
else if(strcmp(color_texto,"gris")==0)       {letra="8";}
else if(strcmp(color_texto,"verdeclaro")==0) {letra="10";}
else if(strcmp(color_texto,"celeste")==0)    {letra="11";}
else if(strcmp(color_texto,"salmon")==0)     {letra="12";}
else if(strcmp(color_texto,"violeta")==0)    {letra="13";}

if(strcmp(color_fondo,"negro")==0)           {fondo="0";}
else if(strcmp(color_fondo,"azul")==0)       {fondo="1";}
else if(strcmp(color_fondo,"verde")==0)      {fondo="2";}
else if(strcmp(color_fondo,"aguamarina")==0) {fondo="3";}
else if(strcmp(color_fondo,"rojo")==0)       {fondo="4";}
else if(strcmp(color_fondo,"morado")==0)     {fondo="5";}
else if(strcmp(color_fondo,"amarillo")==0)   {fondo="6";}
else if(strcmp(color_fondo,"blanco")==0)     {fondo="7";}
else if(strcmp(color_fondo,"gris")==0)       {fondo="8";}
else if(strcmp(color_fondo,"verdeclaro")==0) {fondo="10";}
else if(strcmp(color_fondo,"celeste")==0)    {fondo="11";}
else if(strcmp(color_fondo,"salmon")==0)     {letra="12";}
else if(strcmp(color_fondo,"violeta")==0)    {letra="13";}
std::string colores = "color " + fondo + letra;
system(colores.c_str());
}

//Al llamar estas funcion se te solicitara las posiciones y las opciones
///MENUES VERTICALES
int menuVertical_2(int x, int y, int ancho, char *opc1, char *opc2){
cursor(false); int opc, pos=1;
while(true){
    switch(opc){
        case 80: //ABAJO
            pos++; if(pos>2){pos=1;}
        break;
        case 72: //ARRIBA
            pos--; if(pos<1){pos=2;}
        break;
        case 13: //ENTER
            color("default"); return pos;
        }
        switch(pos){
        case 1:
            color("amarillo");
            recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("blanco");
            recuadro(x,y+3,ancho,2);
            gotoxy(x+2,y+4); cout << opc2;
        break;
        case 2:
            color("blanco");
            recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("amarillo");
            recuadro(x,y+3,ancho,2);
            gotoxy(x+2,y+4); cout << opc2;
        break;
        }
        opc = getch();
    }
}
int menuVertical_3(int x, int y, int ancho, char *opc1, char *opc2, char *opc3){
cursor(false);
int opc, pos=1;
while(true){
    switch(opc){
        case 80: //ABAJO
            pos++; if(pos>3){pos=1;}
        break;
        case 72: //ARRIBA
            pos--; if(pos<1){pos=3;}
        break;
        case 13: //ENTER
            color("default"); return pos;
        }
        switch(pos){
        case 1:
            color("amarillo");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("blanco");recuadro(x,y+3,ancho,2);
            gotoxy(x+2,y+4); cout << opc2;
            recuadro(x,y+6,ancho,2);
            gotoxy(x+2,y+7); cout << opc3;
        break;
        case 2:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("amarillo");recuadro(x,y+3,ancho,2);
            gotoxy(x+2,y+4); cout << opc2;
            color("blanco");
            recuadro(x,y+6,ancho,2);
            gotoxy(x+2,y+7); cout << opc3;
        break;
        case 3:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            recuadro(x,y+3,ancho,2);
            gotoxy(x+2,y+4); cout << opc2;
            color("amarillo");recuadro(x,y+6,ancho,2);
            gotoxy(x+2,y+7); cout << opc3;
        break;
        }opc = getch();
    }
}
int menuVertical_4(int x, int y, int ancho, char *opc1, char *opc2, char *opc3, char *opc4){
cursor(false);
int opc, pos=1;
while(true){
    switch(opc){
        case 80: //ABAJO
            pos++;if(pos>4){pos=1;}
        break;
        case 72: //ARRIBA
            pos--;if(pos<1){pos=4;}
        break;
        case 13: //ENTER
            color("default");return pos;
        }
        switch(pos){
        case 1:
            color("amarillo");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("blanco");recuadro(x,y+3,ancho,2);
            gotoxy(x+2,y+4); cout << opc2;
            recuadro(x,y+6,ancho,2);
            gotoxy(x+2,y+7); cout << opc3;
            recuadro(x,y+9,ancho,2);
            gotoxy(x+2,y+10); cout << opc4;
        break;
        case 2:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("amarillo");recuadro(x,y+3,ancho,2);
            gotoxy(x+2,y+4); cout << opc2;
            color("blanco");
            recuadro(x,y+6,ancho,2);
            gotoxy(x+2,y+7); cout << opc3;
            recuadro(x,y+9,ancho,2);
            gotoxy(x+2,y+10); cout << opc4;
        break;
        case 3:
            color("blanco");
            recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            recuadro(x,y+3,ancho,2);
            gotoxy(x+2,y+4); cout << opc2;
            color("amarillo");recuadro(x,y+6,ancho,2);
            gotoxy(x+2,y+7); cout << opc3;
            color("blanco");recuadro(x,y+9,ancho,2);
            gotoxy(x+2,y+10); cout << opc4;
        break;
        case 4:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            recuadro(x,y+3,ancho,2);
            gotoxy(x+2,y+4); cout << opc2;
            recuadro(x,y+6,ancho,2);
            gotoxy(x+2,y+7); cout << opc3;
            color("amarillo");recuadro(x,y+9,ancho,2);
            gotoxy(x+2,y+10); cout << opc4;
        break;
        }opc = getch();
    }
}
int menuVertical_5(int x, int y, int ancho, char *opc1, char *opc2, char *opc3, char *opc4, char *opc5){
cursor(false);
int opc, pos=1;
while(true){
    switch(opc){
        case 80: //ABAJO
            pos++;if(pos>5){pos=1;}
        break;
        case 72: //ARRIBA
            pos--;if(pos<1){pos=5;}
        break;
        case 13: //ENTER
            color("default");return pos;
        }
        switch(pos){
        case 1:
            color("amarillo");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("blanco");recuadro(x,y+3,ancho,2);
            gotoxy(x+2,y+4); cout << opc2;
            recuadro(x,y+6,ancho,2);
            gotoxy(x+2,y+7); cout << opc3;
            recuadro(x,y+9,ancho,2);
            gotoxy(x+2,y+10); cout << opc4;
            recuadro(x,y+12,ancho,2);
            gotoxy(x+2,y+13); cout << opc5;
        break;
        case 2:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("amarillo");recuadro(x,y+3,ancho,2);
            gotoxy(x+2,y+4); cout << opc2;
            color("blanco");
            recuadro(x,y+6,ancho,2);
            gotoxy(x+2,y+7); cout << opc3;
            recuadro(x,y+9,ancho,2);
            gotoxy(x+2,y+10); cout << opc4;
            recuadro(x,y+12,ancho,2);
            gotoxy(x+2,y+13); cout << opc5;
        break;
        case 3:
            color("blanco");
            recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            recuadro(x,y+3,ancho,2);
            gotoxy(x+2,y+4); cout << opc2;
            color("amarillo");recuadro(x,y+6,ancho,2);
            gotoxy(x+2,y+7); cout << opc3;
            color("blanco");recuadro(x,y+9,ancho,2);
            gotoxy(x+2,y+10); cout << opc4;
            recuadro(x,y+12,ancho,2);
            gotoxy(x+2,y+13); cout << opc5;
        break;
        case 4:
            color("blanco");
            recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            recuadro(x,y+3,ancho,2);
            gotoxy(x+2,y+4); cout << opc2;
            recuadro(x,y+6,ancho,2);
            gotoxy(x+2,y+7); cout << opc3;
            color("amarillo");recuadro(x,y+9,ancho,2);
            gotoxy(x+2,y+10); cout << opc4;
            color("blanco");recuadro(x,y+12,ancho,2);
            gotoxy(x+2,y+13); cout << opc5;
        break;
        case 5:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            recuadro(x,y+3,ancho,2);
            gotoxy(x+2,y+4); cout << opc2;
            recuadro(x,y+6,ancho,2);
            gotoxy(x+2,y+7); cout << opc3;
            recuadro(x,y+9,ancho,2);
            gotoxy(x+2,y+10); cout << opc4;
            color("amarillo");recuadro(x,y+12,ancho,2);
            gotoxy(x+2,y+13); cout << opc5;
        break;
        }opc = getch();
    }
}

///MENUES HORIZONTALES
int menuHorizontal_2(int x,int y, int ancho, char *opc1, char *opc2){
cursor(false);
int opc, pos=1;
while(true){
    switch(opc){
        case 77: //DERECHA
            pos++;if(pos>2){pos=1;}
        break;
        case 75: //IZQUIERDA
            pos--;if(pos<1){pos=2;}
        break;
        case 13: //ENTER
            color("default");return pos;
        }
        switch(pos){
        case 1:
            color("amarillo");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("blanco");recuadro(x+ancho+2,y,ancho,2);
            gotoxy(x+ancho+4,y+1); cout << opc2;
        break;
        case 2:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("amarillo");recuadro(x+ancho+2,y,ancho,2);
            gotoxy(x+ancho+4,y+1); cout << opc2;
        break;
        }opc = getch();
    }
}
int menuHorizontal_3(int x,int y, int ancho, char *opc1, char *opc2, char *opc3){
cursor(false);
int opc, pos=1;
while(true){
    switch(opc){
        case 77: //DERECHA
            pos++;if(pos>3){pos=1;}
        break;
        case 75: //IZQUIERDA
            pos--;if(pos<1){pos=3;}
        break;
        case 13: //ENTER
            color("default");return pos;
        }
        switch(pos){
        case 1:
            color("amarillo");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("blanco");recuadro(x+ancho+2,y,ancho,2);
            gotoxy(x+ancho+4,y+1); cout << opc2;
            recuadro(x+ancho*2+4,y,ancho,2);
            gotoxy(x+ancho*2+6,y+1); cout << opc3;
        break;
        case 2:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("amarillo");
            recuadro(x+ancho+2,y,ancho,2);
            gotoxy(x+ancho+4,y+1); cout << opc2;
            color("blanco");recuadro(x+ancho*2+4,y,ancho,2);
            gotoxy(x+ancho*2+6,y+1); cout << opc3;
        break;
        case 3:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            recuadro(x+ancho+2,y,ancho,2);
            gotoxy(x+ancho+4,y+1); cout << opc2;
            color("amarillo");recuadro(x+ancho*2+4,y,ancho,2);
            gotoxy(x+ancho*2+6,y+1); cout << opc3;
        break;
        }opc = getch();
    }
}
int menuHorizontal_4(int x,int y, int ancho, char *opc1, char *opc2, char *opc3, char *opc4){
cursor(false);
int opc, pos=1;
while(true){
    switch(opc){
        case 77: //DERECHA
            pos++;if(pos>4){pos=1;}
        break;
        case 75: //IZQUIERDA
            pos--;if(pos<1){pos=4;}
        break;
        case 13: //ENTER
            color("default");return pos;
        }
        switch(pos){
        case 1:
            color("amarillo");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("blanco");recuadro(x+ancho+2,y,ancho,2);
            gotoxy(x+ancho+4,y+1); cout << opc2;
            recuadro(x+ancho*2+4,y,ancho,2);
            gotoxy(x+ancho*2+6,y+1); cout << opc3;
            recuadro(x+ancho*3+6,y,ancho,2);
            gotoxy(x+ancho*3+8,y+1); cout << opc4;
        break;
        case 2:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("amarillo");recuadro(x+ancho+2,y,ancho,2);
            gotoxy(x+ancho+4,y+1); cout << opc2;
            color("blanco");
            recuadro(x+ancho*2+4,y,ancho,2);
            gotoxy(x+ancho*2+6,y+1); cout << opc3;
            recuadro(x+ancho*3+6,y,ancho,2);
            gotoxy(x+ancho*3+8,y+1); cout << opc4;
        break;
        case 3:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            recuadro(x+ancho+2,y,ancho,2);
            gotoxy(x+ancho+4,y+1); cout << opc2;
            color("amarillo");recuadro(x+ancho*2+4,y,ancho,2);
            gotoxy(x+ancho*2+6,y+1); cout << opc3;
            color("blanco");
            recuadro(x+ancho*3+6,y,ancho,2);
            gotoxy(x+ancho*3+8,y+1); cout << opc4;
        break;
        case 4:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            recuadro(x+ancho+2,y,ancho,2);
            gotoxy(x+ancho+4,y+1); cout << opc2;
            recuadro(x+ancho*2+4,y,ancho,2);
            gotoxy(x+ancho*2+6,y+1); cout << opc3;
            color("amarillo");recuadro(x+ancho*3+6,y,ancho,2);
            gotoxy(x+ancho*3+8,y+1); cout << opc4;
        break;
        }opc = getch();
    }
}
int menuHorizontal_5(int x,int y, int ancho, char *opc1, char *opc2, char *opc3, char *opc4, char *opc5){
cursor(false);
int opc, pos=1;
while(true){
    switch(opc){
        case 77: //DERECHA
            pos++;if(pos>5){pos=1;}
        break;
        case 75: //IZQUIERDA
            pos--;if(pos<1){pos=5;}
        break;
        case 13: //ENTER
            color("default");return pos;
        }
        switch(pos){
        case 1:
            color("amarillo");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("blanco");recuadro(x+ancho+2,y,ancho,2);
            gotoxy(x+ancho+4,y+1); cout << opc2;
            recuadro(x+ancho*2+4,y,ancho,2);
            gotoxy(x+ancho*2+6,y+1); cout << opc3;
            recuadro(x+ancho*3+6,y,ancho,2);
            gotoxy(x+ancho*3+8,y+1); cout << opc4;
            recuadro(x+ancho*4+8,y,ancho,2);
            gotoxy(x+ancho*4+10,y+1); cout << opc5;
        break;
        case 2:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("amarillo");recuadro(x+ancho+2,y,ancho,2);
            gotoxy(x+ancho+4,y+1); cout << opc2;
            color("blanco");
            recuadro(x+ancho*2+4,y,ancho,2);
            gotoxy(x+ancho*2+6,y+1); cout << opc3;
            recuadro(x+ancho*3+6,y,ancho,2);
            gotoxy(x+ancho*3+8,y+1); cout << opc4;
            recuadro(x+ancho*4+8,y,ancho,2);
            gotoxy(x+ancho*4+10,y+1); cout << opc5;
        break;
        case 3:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            recuadro(x+ancho+2,y,ancho,2);
            gotoxy(x+ancho+4,y+1); cout << opc2;
            color("amarillo");recuadro(x+ancho*2+4,y,ancho,2);
            gotoxy(x+ancho*2+6,y+1); cout << opc3;
            color("blanco");
            recuadro(x+ancho*3+6,y,ancho,2);
            gotoxy(x+ancho*3+8,y+1); cout << opc4;
            recuadro(x+ancho*4+8,y,ancho,2);
            gotoxy(x+ancho*4+10,y+1); cout << opc5;
        break;
        case 4:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            recuadro(x+ancho+2,y,ancho,2);
            gotoxy(x+ancho+4,y+1); cout << opc2;
            recuadro(x+ancho*2+4,y,ancho,2);
            gotoxy(x+ancho*2+6,y+1); cout << opc3;
            color("amarillo");recuadro(x+ancho*3+6,y,ancho,2);
            gotoxy(x+ancho*3+8,y+1); cout << opc4;
            color("blanco");
            recuadro(x+ancho*4+8,y,ancho,2);
            gotoxy(x+ancho*4+10,y+1); cout << opc5;
        break;
        case 5:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            recuadro(x+ancho+2,y,ancho,2);
            gotoxy(x+ancho+4,y+1); cout << opc2;
            recuadro(x+ancho*2+4,y,ancho,2);
            gotoxy(x+ancho*2+6,y+1); cout << opc3;
            recuadro(x+ancho*3+6,y,ancho,2);
            gotoxy(x+ancho*3+8,y+1); cout << opc4;
            color("amarillo");recuadro(x+ancho*4+8,y,ancho,2);
            gotoxy(x+ancho*4+10,y+1); cout << opc5;
        break;
        }opc = getch();
    }
}

///PROBABILIDAD
//Al llamar esta funcion se solicitara "1 de cada x intentos" tiene la probabilidad de crear una accion
bool probabilidad(int num){
srand(time(NULL)); int probable=rand()%(101-1);
if(num>=probable){return true;} return false;
}

///MARGENES
//Al llamar esta funcion se solicitara cadena de numeros(esta actuara como cadena de caracteres)
//posiciones x,y - el tamaño del vector, numero restrictor de caracteres
int margenTextoEscribir(int *texto, int x, int y, int tam, int restriccion){
for(int i=0;i<tam;i++){texto[i]=0;}
int tecla=1, px = 0, py = 0, t=0;
while(tecla!=13){
    px++;gotoxy(x-1+px,y+py);
    tecla = getch();t++;
    cout<<char(tecla);
    if(t%restriccion==0){py++;px=0;}
    if(tecla!=8){texto[t]=tecla;}
    else{px--;t-=2;cout<<" ";px--;}
}return *texto;
}
//Al llamar esta funcion se solicitara cadena de numeros(esta actuara como cadena de caracteres) anteriormente ingresado
//posiciones x,y - el tamaño del vector, numero restrictor de caracteres
void margenTextoMostrar(int *texto,int x, int y, int tam, int restriccion){
    int px = 0, py = 0;
    for(int i=1;i<tam;i++){px++;
    gotoxy(x-1+px,y+py);
    cout<<char(texto[i]);
    if(i%restriccion==0){
    py++;px=0;}
    }
}




///VERSION 2.X EN ADELANTE
/*
Esta actualizacion trae 10 nuevas funciones y
contiene un parche a errores anteriores de otras funciones pasadas
PARA MAS INFO VER EL VIDEO 2X
*/

///ACCESO A LOS LINKS E INFO
//Solicita numero de version desde 0 en adelante
void ConsoleManager(int version){
switch(version){
case 0:
	system("start https://www.youtube.com/watch?v=RI5D2YiKIh8");
break;
case 1:
	system("start https://www.youtube.com/watch?v=x2qKqkqx3kk");
break;
case 2:
	system("start https://www.youtube.com/watch?v=mRKZonPx4pw");
break;
default:
	system("start https://www.youtube.com/channel/UCS_-386mFHUuaviv4DWTAjg");
break;
}
}

///Ajuste de la pantalla
//Solitara la cantidad de Columnas y Filas
void pantalla(int columnas, int filas){
char ejex[3],ejey[3];
itoa(columnas,ejex,10); itoa(filas,ejey,10);
string code1 = "mode con: cols=";
string code2 = " lines=";
string comando =  code1 + ejex + code2 + ejey;
system(comando.c_str());
}


///COLOR NUMERICO
//Solitara el Color en valor numerico
void color(int num){
	SetConsoleTextAttribute(hConsole,num);
}

///COMBOBOX
//Creara un combobox con opciones solicita ejes y opciones
int comboBox2(int x,int y,int largo, char *opc1, char *opc2){
    int opc = 0, pos=1;
    while(true){
        cursor(false);
        switch(opc){
            case 77:
            pos++;
            if(pos>2){pos=1;}
            break;
            case 75:
            pos--;
            if(pos<1){pos=2;}
            break;
            case 13: //ENTER
            switch(pos){
                case 1:
                    return 1;
                break;
                case 2:
                    return 2;
                break;
            }
        }
        switch(pos){
            case 1:
                recuadro(x,y,largo,2);
                gotoxy(x+4,y+1); cout << opc1;
            break;
            case 2:
                recuadro(x,y,largo,2);
                gotoxy(x+4,y+1); cout << opc2;
            break;
        }opc = getch();
    }
}
int comboBox3(int x,int y,int largo, char *opc1, char *opc2, char *opc3){
int opc = 0, pos=1;
    while(true){
    cursor(false);
    switch(opc){
        case 77:
        pos++;
        if(pos>3){pos=1;}
        break;
        case 75:
        pos--;
        if(pos<1){pos=3;}
        break;
        case 13: //ENTER
            switch(pos){
                case 1:
                    return 1;
                break;
                case 2:
                    return 2;
                break;
                case 3:
                    return 3;
                break;
            }
    }
    switch(pos){
        case 1:
            recuadro(x,y,largo,2);
            gotoxy(x+4,y+1); cout << opc1;
        break;
        case 2:
            recuadro(x,y,largo,2);
            gotoxy(x+4,y+1); cout << opc2;
        break;
        case 3:
            recuadro(x,y,largo,2);
            gotoxy(x+4,y+1); cout << opc3;
        break;
    }opc = getch();
    }
}
int comboBox4(int x,int y,int largo, char *opc1, char *opc2, char *opc3, char *opc4){
    int opc = 0, pos=1;
    while(true){
    cursor(false);
    switch(opc){
        case 77:
        pos++;
        if(pos>4){pos=1;}
        break;
        case 75:
        pos--;
        if(pos<1){pos=4;}
        break;
        case 13: //ENTER
            switch(pos){
                case 1:
                    return 1;
                break;
                case 2:
                    return 2;
                break;
                case 3:
                    return 3;
                break;
                case 4:
                    return 4;
                break;
            }
        }
        switch(pos){
            case 1:
                recuadro(x,y,largo,2);
                gotoxy(x+4,y+1); cout << opc1;
            break;
            case 2:
                recuadro(x,y,largo,2);
                gotoxy(x+4,y+1); cout << opc2;
            break;
            case 3:
                recuadro(x,y,largo,2);
                gotoxy(x+4,y+1); cout << opc3;
            break;
            case 4:
                recuadro(x,y,largo,2);
                gotoxy(x+4,y+1); cout << opc4;
            break;
        }opc = getch();
    }
}
int comboBox5(int x,int y,int largo, char *opc1, char *opc2, char *opc3, char *opc4, char *opc5){
    int opc = 0, pos=1;
    while(true){
        cursor(false);
        switch(opc){
            case 77:
            pos++;
            if(pos>5){pos=1;}
            break;
            case 75:
            pos--;
            if(pos<1){pos=5;}
            break;
            case 13: //ENTER
                switch(pos){
                    case 1:
                        return 1;
                    break;
                    case 2:
                        return 2;
                    break;
                    case 3:
                        return 3;
                    break;
                    case 4:
                        return 4;
                    break;
                    case 5:
                        return 5;
                    break;
                }
        }
        switch(pos){
            case 1:
                recuadro(x,y,largo,2);
                gotoxy(x+4,y+1); cout << opc1;
            break;
            case 2:
                recuadro(x,y,largo,2);
                gotoxy(x+4,y+1); cout << opc2;
            break;
            case 3:
                recuadro(x,y,largo,2);
                gotoxy(x+4,y+1); cout << opc3;
            break;
            case 4:
                recuadro(x,y,largo,2);
                gotoxy(x+4,y+1); cout << opc4;
            break;
            case 5:
                recuadro(x,y,largo,2);
                gotoxy(x+4,y+1); cout << opc5;
            break;
        }opc = getch();
    }
}

///DIBUJAR DADO
//Crea dados prediseñados
void dado(int x, int y, int valor){
   recuadro(x,y,8,4);
   switch(valor){
   case 1:
         gotoxy(x+4,y+2);cout<< char(254);
         break;
   case 2:
         gotoxy(x+2,y+1);cout<<char(254);
         gotoxy(x+6,y+3);cout<<char(254);
         break;
   case 3:
         gotoxy(x+2,y+1);cout<<char(254);
         gotoxy(x+4,y+2);cout<<char(254);
         gotoxy(x+6,y+3);cout<<char(254);
         break;
   case 4:
         gotoxy(x+2,y+1);cout<<char(254);
         gotoxy(x+6,y+3);cout<<char(254);
         gotoxy(x+6,y+1);cout<<char(254);
         gotoxy(x+2,y+3);cout<<char(254);
         break;
   case 5:
         gotoxy(x+2,y+1);cout<<char(254);
         gotoxy(x+6,y+3);cout<<char(254);
         gotoxy(x+4,y+2);cout<<char(254);
         gotoxy(x+6,y+1);cout<<char(254);
         gotoxy(x+2,y+3);cout<<char(254);
         break;
   case 6:
         gotoxy(x+2,y+1);cout<<char(254);
         gotoxy(x+6,y+3);cout<<char(254);
         gotoxy(x+6,y+1);cout<<char(254);
         gotoxy(x+2,y+3);cout<<char(254);
         gotoxy(x+6,y+2);cout<<char(254);
         gotoxy(x+2,y+2);cout<<char(254);
         break;
   }
}

///SUBRAYADO
//Subraya el texto que le pases
void subrayar(char* color_texto,char* texto){
	int letra;
	if(strcmp(color_texto,"negro")==0)           {letra=7;}
	else if(strcmp(color_texto,"azul")==0)       {letra=31;}
	else if(strcmp(color_texto,"verde")==0)      {letra=47;}
	else if(strcmp(color_texto,"aguamarina")==0) {letra=159;}
	else if(strcmp(color_texto,"rojo")==0)       {letra=79;}
	else if(strcmp(color_texto,"morado")==0)     {letra=223;}
	else if(strcmp(color_texto,"amarillo")==0)   {letra=111;}
	else if(strcmp(color_texto,"blanco")==0)     {letra=240;}
	else if(strcmp(color_texto,"gris")==0)       {letra=240;}
	else if(strcmp(color_texto,"verdeclaro")==0) {letra=175;}
	else if(strcmp(color_texto,"celeste")==0)    {letra=63;}
	else if(strcmp(color_texto,"salmon")==0)     {letra=207;}
	else if(strcmp(color_texto,"violeta")==0)    {letra=95;}
	color(letra);cout<<texto;color(7);
}

///PANTALLA COMPLETA
//Se creara una pantalla completa
void pantallaCompleta(){
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
    return;
}

///MENSAJE EMERGENTE
//Se creara un mensaje por una ventana emergente
void mensajeEmergente(string mensajeMostrar,string tituloVentana){
	MessageBox(NULL,mensajeMostrar.c_str(),tituloVentana.c_str(),MB_ICONEXCLAMATION | MB_OK);
}

///CARACTERES
//Se encarga de mostrar todas los codigo ASCII de los caracteres
void caracteresASCII(){
	for(int x=33;x<=254;x++){
	if(x==33||x==48||x==58||x==65||x==91||x==97||x==123||x==166||x==224||x==238){
	cout<<endl;}color("blanco");cout<<"CARACTER: '";
	if(x<=47){color("rojo");}
	else if(x<=57){color("azul");}
	else if(x<=64){color("verde");}
	else if(x<=90){color("aguamarina");}
	else if(x<=96){color("morado");}
	else if(x<=122){color("amarillo");}
	else if(x<=165){color("salmon");}
	else if(x<=223){color("verdeclaro");}
	else if(x<=237){color("celeste");}
	else{color("violeta");}cout<<char(x);
	color("blanco");cout<<"' = char(";
	if(x<=47){color("rojo");}
	else if(x<=57){color("azul");}
	else if(x<=64){color("verde");}
	else if(x<=90){color("aguamarina");}
	else if(x<=96){color("morado");}
	else if(x<=122){color("amarillo");}
	else if(x<=165){color("salmon");}
	else if(x<=223){color("verdeclaro");}
	else if(x<=237){color("celeste");}
	else{color("violeta");}cout<<x;
	color("blanco");cout<<")"<<endl;
}
}


#endif // CONSOLEMANAGER_H_INCLUDED
