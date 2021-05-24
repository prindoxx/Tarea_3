#ifndef _FUNCIONES_H
#define _FUNCIONES_H
#include <stdio.h>
#include "map.h"
#include <stdbool.h>

typedef struct{

    int numeroEntrega;
    int coordenadaX;
    int coordenadaY;
    bool flag;
}entrega;

//crear estructuras ruta...con la ruta y los datos de entrega

void abrirArchivo(FILE * archivo, Map * Entregas, int n );

entrega* crearEntrega(int numEntrega, int coorX, int coorY,bool flag);

void mostrarMapa(Map* mapa);

void dis_entregas(Map* mapa,int x,int y);

void ruta_aleatoria(Map* mapa,int n,int x,int y);

int dis_entregas_1(Map* mapa,int x,int y);

int dis_entregas_2_0(Map* mapa,int x,int y,int numero);
#endif
