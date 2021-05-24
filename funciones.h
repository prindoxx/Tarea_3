#ifndef _FUNCIONES_H
#define _FUNCIONES_H
#include <stdio.h>
#include "map.h"

typedef struct{

    int numeroEntrega;
    int coordenadaX;
    int coordenadaY;

}entrega;

void abrirArchivo(FILE * archivo, Map * Entregas );

entrega* crearEntrega(int numEntrega, int coorX, int coorY);

void mostrarMapa(Map* mapa);

#endif
