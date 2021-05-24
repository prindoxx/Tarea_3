#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    FILE * archivo = fopen("tarea3_tsp.txt", "rb");

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
        printf("%d %d %d\n", coorX, coorY, numeroEntrega);

        numeroEntrega++;

    }

    return 0;
}
