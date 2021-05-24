#include "list.h"
#include "funciones.h"
#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

//aqui se escriben las funciones

//abre y guarda el archivo en un mapa
void abrirArchivo(FILE * archivo, Map * Entregas,int n ){

    if(archivo == NULL){

        perror("ERROR");
        return;

    }

    int coorX;
    int coorY;
    int numeroEntrega;
    bool flag;

    numeroEntrega = 1;

    while(numeroEntrega <= n){

        fscanf(archivo, "%d %d", &coorX, &coorY);
        //printf("%d %d %d\n", coorX, coorY, numeroEntrega);

        entrega* oEntrega = crearEntrega(numeroEntrega, coorX, coorY,flag);

        insertMap(Entregas, oEntrega->numeroEntrega, oEntrega);

        numeroEntrega++;

    }

    fclose(archivo);


}

entrega* crearEntrega(int numEntrega, int coorX, int coorY,bool flag){

    entrega* oEntrega = (entrega*) malloc(sizeof(entrega));
    flag = 0;
    oEntrega->numeroEntrega = numEntrega;
    oEntrega->coordenadaX = coorX;
    oEntrega->coordenadaY = coorY;
    oEntrega->flag = flag;

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
    return;
}

void dis_entregas(Map* mapa,int x,int y){

    int aux,cont,suma_1,suma_2,distancia;
    entrega* oEntrega_1 = (entrega*) malloc(sizeof(entrega));
    entrega* oEntrega_2 = (entrega*) malloc(sizeof(entrega));

    oEntrega_1 = searchMap(mapa,x);
    oEntrega_2 = searchMap(mapa,y);

    aux = oEntrega_1->coordenadaX;
    cont = oEntrega_2->coordenadaX;

    suma_1 = pow(aux - cont,2);

    aux = oEntrega_1->coordenadaY;
    cont = oEntrega_2->coordenadaY;

    suma_2 = pow(aux - cont,2);

    distancia = sqrt(suma_1+suma_2);
    printf("La distancia que hay entre estas entregas es de: %d metros\n",distancia);

    return;

}
int dis_entregas_1(Map* mapa,int x,int y){

    int aux,cont,suma_1,suma_2,distancia;
    entrega* oEntrega_1 = (entrega*) malloc(sizeof(entrega));
    entrega* oEntrega_2 = (entrega*) malloc(sizeof(entrega));

    oEntrega_1 = searchMap(mapa,x);
    oEntrega_2 = searchMap(mapa,y);

    aux = oEntrega_1->coordenadaX;
    cont = oEntrega_2->coordenadaX;

    suma_1 = pow(aux - cont,2);

    aux = oEntrega_1->coordenadaY;
    cont = oEntrega_2->coordenadaY;

    suma_2 = pow(aux - cont,2);

    distancia = sqrt(suma_1+suma_2);

    return distancia;
}

int dis_entregas_2_0(Map* mapa,int x,int y,int numero){

    int aux,cont,suma_1,suma_2,distancia;
    entrega* oEntrega_1 = (entrega*) malloc(sizeof(entrega));

    oEntrega_1 = searchMap(mapa,numero);

    aux = oEntrega_1->coordenadaX;
    cont = x;

    suma_1 = pow(aux - cont,2);

    aux = oEntrega_1->coordenadaY;
    cont = y;

    suma_2 = pow(aux - cont,2);

    distancia = sqrt(suma_1+suma_2);

    return distancia;
}

void ruta_aleatoria(Map* mapa,int n,int x,int y){
    int aux,distancia,numero,cont = 0;
    entrega* oEntrega = (entrega*) malloc(sizeof(entrega));
    printf("Lugar de partida\n");
    printf("%d,%d\n",x,y);
    while(cont < n){
        numero = rand() % n + 1;
        oEntrega = searchMap(mapa,numero);
        if(cont == 0){
            distancia = dis_entregas_2_0(mapa,x,y,numero);

        }else{
            distancia = distancia + dis_entregas_1(mapa,aux,numero);
        }
        if(oEntrega->flag == 0){
            printf("------------%d-----------\n",oEntrega->numeroEntrega);
            printf("%d\n",oEntrega->coordenadaX);
            printf("%d\n",oEntrega->coordenadaY);
            oEntrega->flag = 1;
            //printf("%d\n",distancia); distancia en cada tramo
            aux = numero;
            cont++;
        }

    }
    printf("%d",distancia);//distancia total
    return;
}
