#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "biblio.h"


void ordenAlfabetico(int legajos[], char nombres[][21], int notas[], float alturas[], int tamano)
{
    int i;
    int j;
    char aux[21];
    int legajoAuxiliar;
    int notaAuxiliar;
    int alturaAuxiliar;


    for(i = 0; i < tamano -1; i++)
    {
        for(j = i+1; j < tamano; j++)
        {
            if(tolower(nombres[j][0]) < tolower(nombres[i][0]))
            {
                    legajoAuxiliar = legajos[j];
                    legajos[j] = legajos[i];
                    legajos[i]= legajoAuxiliar;

                    strcpy(aux, nombres[j]);
                    strcpy(nombres[j], nombres[i]);
                    strcpy(nombres[i], aux);

                    notaAuxiliar = notas[j];
                    notas[j] = notas[i];
                    notas[i]= notaAuxiliar;

                    alturaAuxiliar = alturas[j];
                    alturas[j] = alturas[i];
                    alturas[i]= alturaAuxiliar;
            }
        }
    }


    for(i = 0; i < tamano; i++)
    {
        puts(nombres[i]);
    }
}


void cargarAlumnos(int legajos[], char nombres[][21], int notas[], float alturas[], int dimension)
{
    int i;
    for(i = 0; i < dimension; i++)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajos[i]);

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombres[i]);

        printf("Ingrese nota: ");
        scanf("%d", &notas[i]);

        printf("Ingrese altura: ");
        scanf("%f", &alturas[i]);
    }
}

void mostrarAlumnos(int legajos[], char nombres[][21], int notas[], float alturas[], int dimension)
{
    printf("%4s %20s %2s %5s\n","Legajo","Nombre","Nota","Altura");

    int i;
    for(i=0; i<dimension; i++)
    {
        printf("%4d %20s %2d %5f \n", legajos[i], nombres[i], notas[i], alturas[i]);
    }
}
