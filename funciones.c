#include "list.h"
#include "funciones.h"
#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


//abre y guarda el archivo en un mapa
void abrirArchivo(FILE * archivo, Map * Entregas,int n ){

    if(archivo == NULL){

        perror("ERROR");
        return;

    }
    //Se definen las variablas a usar
    int coorX;
    int coorY;
    int numeroEntrega;
    bool flag;

    numeroEntrega = 1;

    while(numeroEntrega <= n){//Se hace un while hasta que el id de las entregas sea menor o igual a la cantidad de entregas que queremos realizar

        fscanf(archivo, "%d %d", &coorX, &coorY);
        //printf("%d %d %d\n", coorX, coorY, numeroEntrega);

        entrega* oEntrega = crearEntrega(numeroEntrega, coorX, coorY,flag);

        insertMap(Entregas, oEntrega->numeroEntrega, oEntrega);

        numeroEntrega++;

    }

    fclose(archivo);


}

entrega* crearEntrega(int numEntrega, int coorX, int coorY,bool flag){//Se crea una entrega con sus variables correspondientes

    entrega* oEntrega = (entrega*) malloc(sizeof(entrega));//Se crea el objeto entrega
    flag = 0;
    oEntrega->numeroEntrega = numEntrega;
    oEntrega->coordenadaX = coorX;
    oEntrega->coordenadaY = coorY;
    oEntrega->flag = flag;

    return oEntrega;

}

void mostrarMapa(Map* mapa){//Muestra todo el mapa

    entrega* oEntrega = (entrega*) malloc(sizeof(entrega));

    oEntrega = firstMap(mapa);

    while(oEntrega != NULL){//Recorre el mapa printeando sus elementos hasta un NULL

        printf("Numero entrega: %d \n", oEntrega->numeroEntrega);
        printf("Coordenada X: %d \n", oEntrega->coordenadaX);
        printf("Coordenada Y: %d \n", oEntrega->coordenadaY);
        printf("\n");

        oEntrega = nextMap(mapa);

    }
    return;
}

void dis_entregas(Map* mapa,int idEntrega1,int idEntrega2){ //calcular distancia teniendo los ids de ambas entregas, imprime el valor de la distancia

    int aux,cont,suma_1,suma_2,distancia;
    entrega* oEntrega_1 = (entrega*) malloc(sizeof(entrega));
    entrega* oEntrega_2 = (entrega*) malloc(sizeof(entrega));

    oEntrega_1 = searchMap(mapa,idEntrega1);
    oEntrega_2 = searchMap(mapa,idEntrega2);

    aux = oEntrega_1->coordenadaX;//Se le asigna a aux el valor de coordenadaX procediente de la entrega correspondiente
    cont = oEntrega_2->coordenadaX;

    suma_1 = pow(aux - cont,2);//Obtiene el cuadrado de la diferencia de las coordenadas aux y cont

    aux = oEntrega_1->coordenadaY;//Se le asigna a aux el valor de coordenadaY procediente de la entrega correspondiente
    cont = oEntrega_2->coordenadaY;

    suma_2 = pow(aux - cont,2);

    distancia = sqrt(suma_1+suma_2);//Obtiene la raiz de la suma de ambas cuadrados obtenidos de suma_1 y suma_2
    printf("La distancia que hay entre estas entregas es de: %d metros\n",distancia);

    return;

}

int dis_entregas_1(Map* mapa,int idEntrega1,int idEntrega2){ //calcula distancia entre 2 entregas, teniendo su id y retorna dicho calculo

    int aux,cont,suma_1,suma_2,distancia;
    entrega* oEntrega_1 = (entrega*) malloc(sizeof(entrega));
    entrega* oEntrega_2 = (entrega*) malloc(sizeof(entrega));

    oEntrega_1 = searchMap(mapa,idEntrega1);
    oEntrega_2 = searchMap(mapa,idEntrega2);

    aux = oEntrega_1->coordenadaX;
    cont = oEntrega_2->coordenadaX;

    suma_1 = pow(aux - cont,2);

    aux = oEntrega_1->coordenadaY;
    cont = oEntrega_2->coordenadaY;

    suma_2 = pow(aux - cont,2);

    distancia = sqrt(suma_1+suma_2);

    return distancia;
}

int dis_entregas_2_0(Map* mapa,int x,int y,int idEntrega){ //calcula la distancia entre una posicion y una entrega a traves de su id, retorna el valor de la distancia

    int posX, posY;
    int suma_1,suma_2,distancia;
    int entregaPosX, entregaPosY;

    entrega* oEntrega_1 = (entrega*) malloc(sizeof(entrega));

    oEntrega_1 = searchMap(mapa,idEntrega);

    entregaPosX = oEntrega_1->coordenadaX;//Se le asigna a la posicion X el valor de coordenada X de su correspondiente entrega
    posX = x;

    suma_1 = pow(entregaPosX - posX,2);//Se obtiene el cuadrado de la resta entre la coordenada de la entrega y el punto X que entrega la funcion

    entregaPosY = oEntrega_1->coordenadaY;//Se le asigna a la posicion Y el valor de coordenada Y de su correspondiente entrega
    posY = y;

    suma_2 = pow(entregaPosY - posY,2);//Se obtiene el cuadrado de la resta entre la coordenada de la entrega y el punto Y que entrega la funcion

    distancia = sqrt(suma_1+suma_2);

    return distancia;
}

void calcular_menor_ruta(Map* mapa,int cantEntregas,int x,int y){//Esta funcion calcula las 3 menores rutas desde un punto dado

    int distancia = 0;
    int min = 2000000000;
    int cont = 0;
    int id = 0;
    int numero;

    entrega* oEntrega = (entrega*) malloc(sizeof(entrega));
    int* vector = (int*) malloc(cantEntregas * sizeof(int));//Se crea un vector para almacenar la distancia de cada uno de los puntos


    for(int i=0 ; i < cantEntregas ; i++){//Calcula las distancias desde el punto ingresado hasta las demas rutas y las almacena en el vector

        distancia = dis_entregas_2_0(mapa, x, y, (i+1));
        vector[i] = distancia;
    }

    if(cantEntregas < 3){
        numero = cantEntregas;
    }
    else numero=3;
    printf("Las %d entregas mas cercanas son:\n", numero);

    while(cont < numero){//Este while compara las distancias y entrega las 3 menores que hay desde el punto inicial
        for(int j=0 ; j < cantEntregas ; j++){

            if(min > vector[j]){
                min = vector[j];
                id = j+1;
            }
        }
        printf("id: %d  distancia: %d\n", id, vector[id-1]);
        cont++;
        vector[id-1] = 2000000000;
        min = 2000000000;
    }


}

void ruta_aleatoria(Map* mapa,int cantEntregas,int x,int y){

    int aux, distancia, numero;
    int cont = 0;

    entrega* oEntrega = (entrega*) malloc(sizeof(entrega));

    //printf("Lugar de partida\n");
    //printf("%d,%d\n",x,y);

    while(cont < cantEntregas){//Crea un numero aleatorio dentro de la cantidad de entregas maxima que se pueden tener
        numero = rand() % cantEntregas + 1;

        oEntrega = searchMap(mapa,numero);//Se busca dicho numero aleatorio con searchMap y se le asigna a oEntrega

        if(cont == 0){
            distancia = dis_entregas_2_0(mapa,x,y,numero);//Se busca dicho numero aleatorio con searchMap y se le asigna a oEntrega

        }else{
            distancia = distancia + dis_entregas_1(mapa,aux,numero);//Suma la distancia acumulada y la del siguiente punto con el fin de que se sumen todas las distancias
        }
        if(oEntrega->flag == 0){//Suma la distancia acumulada y la del siguiente punto con el fin de que se sumen todas las distancias

            printf("------------%d-----------\n",oEntrega->numeroEntrega);
            printf("%d\n",oEntrega->coordenadaX);
            printf("%d\n",oEntrega->coordenadaY);
            oEntrega->flag = 1;

            aux = numero;
            cont++;
        }

    }



    printf("Distancia total del recorrido: %d\n",distancia);//distancia total
    return;
}
