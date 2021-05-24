#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "map.h"

/*
  función para comparar claves de tipo string
  retorna 1 si son iguales
*/
int is_equal_string(void * key1, void * key2) {
    if(strcmp((char*)key1, (char*)key2)==0)return 1;
    return 0;
}

/*
  función para comparar claves de tipo string
  retorna 1 si son key1<key2
*/
int lower_than_string(void * key1, void * key2) {
    if(strcmp((char*)key1, (char*)key2) < 0) return 1;
    return 0;
}

/*
  función para comparar claves de tipo int
  retorna 1 si son iguales
*/
int is_equal_int(void * key1, void * key2) {
    if((int*)key1 == (int*)key2) return 1;
    return 0;
}

/*
  función para comparar claves de tipo int
  retorna 1 si son key1<key2
*/
int lower_than_int(void * key1, void * key2) {
    if(*(int*)key1 < *(int*)key2) return 1;
    return 0;
}

int main(){

    FILE * archivo = fopen("tarea3_tsp.txt", "rb");

    //Se crea el mapa para poder agregar la entregas, su clave sera el numero de entrega
    Map* Entregas = createMap(is_equal_int);

    abrirArchivo(archivo, Entregas);

    mostrarMapa(Entregas);

}
