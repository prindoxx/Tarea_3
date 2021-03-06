#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "map.h"
#include <stdbool.h>



/*
  funci?n para comparar claves de tipo string
  retorna 1 si son iguales
*/
int is_equal_string(void * key1, void * key2) {
    if(strcmp((char*)key1, (char*)key2)==0)return 1;
    return 0;
}

/*
  funci?n para comparar claves de tipo string
  retorna 1 si son key1<key2
*/
int lower_than_string(void * key1, void * key2) {
    if(strcmp((char*)key1, (char*)key2) < 0) return 1;
    return 0;
}

/*
  funci?n para comparar claves de tipo int
  retorna 1 si son iguales
*/
int is_equal_int(void * key1, void * key2) {
    if((int*)key1 == (int*)key2) return 1;
    return 0;
}

/*
  funci?n para comparar claves de tipo int
  retorna 1 si son key1<key2
*/
int lower_than_int(void * key1, void * key2) {
    if(*(int*)key1 < *(int*)key2) return 1;
    return 0;
}


int main(){
    int x,y;
    int cantEntregas;
    int idEntrega1, idEntrega2;
    FILE * archivo = fopen("tarea3_tsp.txt", "rb");
    Map* Entregas = createMap(is_equal_int);//Se crea el mapa para poder agregar la entregas, su clave sera el numero de entrega
    int op;

    while(1){//Muestra el menu


        printf("Seleccione una opcion:\n");
        printf("1. Importar archivo de coordenadas \n");
        printf("2. Distancia entre entregas \n");
        printf("3. Mostrar 3 entregas mas cercanas a las coordenadas ingresadas \n");
        printf("4. Crear ruta \n");
        printf("5. Generar ruta aleatoria \n");
        printf("6. Mejorar ruta \n");
        printf("7. Mostrar rutas \n");
        printf("8. Mejor ruta \n");
        printf("0. Salir \n");
        printf("Escriba el numero de la opcion: ");
        scanf("%i", &op);

        switch (op){
        //case 0 es para salir del programa
        case 0:

            return 0;

        case 1://Importa un archivo CSV

            printf("Ingrese el numero de entregas a realizar\n");
            scanf("%d",&cantEntregas);
            abrirArchivo(archivo, Entregas, cantEntregas);
            mostrarMapa(Entregas);

            break;

        case 2://Este caso calcula la distancia entre 2 puntos de entrega


            printf("Ingrese el id de entregas a seleccionar\n");
            printf("Entrega 1:\n");
            scanf("%d",&idEntrega1);
            printf("Entrega 2:\n");
            scanf("%d",&idEntrega2);
            printf("\n");

            dis_entregas(Entregas,idEntrega1,idEntrega2);

            break;

        case 3://Este caso muestra las 3 entregas mas cercanas al lugar de partida


            printf("Ingrese las coordenadas de su lugar de partida\n");
            scanf("%d",&x);
            scanf("%d",&y);

            calcular_menor_ruta(Entregas,cantEntregas,x,y);

            break;

        case 4://No se hizo



            break;

        case 5:// Este caso es para crear una ruta aleatoria segun algun punto de partida dado
            printf("Ingrese su lugar de partida\n");
            scanf("%d",&x);
            scanf("%d",&y);

            ruta_aleatoria(Entregas,cantEntregas,x,y);

            break;

        case 6://No se hizo



            break;

        case 7://No se hizo


            break;


        case 8://No se hizo

            printf("8. Mostrar mejor ruta\n");

            break;


        default:

            break;


        }


    }

    return 0;
}

