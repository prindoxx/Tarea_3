#include "list.h"
#include "funciones.h"
#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//aqui se escriben las funciones

//abre y guarda el archivo en un mapa
void abrirArchivo(FILE * archivo, Map * Entregas ){

    if(archivo == NULL){

        perror("ERROR");
        return 1;

    }

    int coorX;
    int coorY;
    int numeroEntrega;

    numeroEntrega = 1;

    while(feof(archivo) == 0){

        fscanf(archivo, "%d %d", &coorX, &coorY);
        //printf("%d %d %d\n", coorX, coorY, numeroEntrega);

        entrega* oEntrega = crearEntrega(numeroEntrega, coorX, coorY);

        insertMap(Entregas, oEntrega->numeroEntrega, oEntrega);

        numeroEntrega++;

    }

    fclose(archivo);


}

entrega* crearEntrega(int numEntrega, int coorX, int coorY){

    entrega* oEntrega = (entrega*) malloc(sizeof(entrega));

    oEntrega->numeroEntrega = numEntrega;
    oEntrega->coordenadaX = coorX;
    oEntrega->coordenadaY = coorY;

    return oEntrega;

}

void mostrarMapa(Map* mapa){

    entrega* oEntrega = (entrega*) malloc(sizeof(entrega));

    oEntrega = firstMap(mapa);

    while(oEntrega != NULL){

        printf("Numero entrega: %d \n", oEntrega->numeroEntrega);
        printf("Coordenada X: %d \n", oEntrega->coordenadaX);
        printf("Coordenada Y: %d \n", oEntrega->coordenadaY);
        printf("\n");

        oEntrega = nextMap(mapa);

    }

}
