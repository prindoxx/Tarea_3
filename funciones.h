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


void abrirArchivo(FILE * archivo, Map * Entregas, int n );

entrega* crearEntrega(int numEntrega, int coorX, int coorY,bool flag);

void mostrarMapa(Map* mapa);

void dis_entregas(Map* mapa,int idEntrega1,int idEntrega2);

void ruta_aleatoria(Map* mapa,int cantEntregas,int x,int y);

int dis_entregas_1(Map* mapa,int idEntrega1,int idEntrega2);

int dis_entregas_2_0(Map* mapa,int x,int y,int idEntrega1);
#endif
