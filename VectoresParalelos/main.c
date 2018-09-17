#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "biblio.h"
#define T 4


int main()
{
    int legajos[T];
    char nombres[T][21];
    int notas[T];
    float alturas[T];
    int opcion;

    cargarAlumnos(legajos, nombres, notas, alturas, T);
    mostrarAlumnos(legajos, nombres, notas, alturas, T);

    do
    {
        printf("\nMENU DE OPCIONES\n");
        printf("1. Ordenar los nombres\n");
        printf("2. Ver alumnos aprobados\n");
        printf("3. Ver alumnos cuyos nombres comienzan con P\n");
        printf("4. Alumno/os con mas nota\n");
        printf("5. Modificar una nota (ingresando legajo)\n");
        printf("6. Salir\n");
        scanf("%d", &opcion);


        switch(opcion)
        {

        case 1:
            ordenAlfabetico(legajos, nombres, notas, alturas, T);
            break;

        case 2:

            break;

        case 3:

            break;

        case 4:

            break;

        case 5:

            break;

        case 6:
            break;

        default:
            printf("Ingrese una opcion valida\n");
            system("pause");
        }
    }
    while(opcion != 6);
    return 0;
}


void cargarAlumnos(int legajos[], char nombres[][21], int notas[], float alturas[], int tamano)
{
    int i;
    for(i = 0; i < tamano; i++)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajos[i]);


        printf("Ingrese nombre: ");
        fflush(stdin);
        char buffer[1024];
        gets(buffer);
        while(strlen(buffer)>20)
        {
            printf("Error. Reingrese nombre: ");
            fflush(stdin);
            gets(buffer);
        }
        strcpy(nombres[i], buffer);


        printf("Ingrese nota: ");
        scanf("%d", &notas[i]);


        printf("Ingrese altura: ");
        scanf("%f", &alturas[i]);
    }
}


void mostrarAlumnos(int legajos[], char nombres[][21], int notas[], float alturas[], int tamano)
{
    printf("%6s %20s %4s %5s\n","Legajo","Nombre","Nota","Altura");

    int i;
    for(i=0; i < tamano; i++)
    {
        printf("%4d %20s %2d %5f \n", legajos[i], nombres[i], notas[i], alturas[i]);
    }
}


void ordenAlfabetico(int legajos[], char nombres[][21], int notas[], float alturas[], int tamano)
{
    int i;
    int j;
    char auxString[100];
    int auxInt;
    int auxFloat;


    for(i = 0; i < tamano -1; i++)
    {
        for(j = i+1; j < tamano; j++)
        {
            if(strcmp(nombres[i], nombres[j])>0)
            {
                auxInt = legajos[j];
                legajos[j] = legajos[i];
                legajos[i]= auxInt;

                strcpy(auxString, nombres[j]);
                strcpy(nombres[j], nombres[i]);
                strcpy(nombres[i], auxString);

                auxInt = notas[j];
                notas[j] = notas[i];
                notas[i]= auxInt;

                auxFloat = alturas[j];
                alturas[j] = alturas[i];
                alturas[i]= auxFloat;
            }
        }
    }

    printf("%6s %20s %4s %5s\n","Legajo","Nombre","Nota","Altura");
    for(i=0; i < tamano; i++)
        printf("%4d %20s %2d %5f \n", legajos[i], nombres[i], notas[i], alturas[i]);
}



/*
Tarea:

Hacer un menu de opciones, que incluya las siguientes funciones:

-ordene los nombres
-muestre los alumnos aprobados (nota>6))
-muestre los alumnos cuyos nombres comienzan con p
-El alumno con mas nota (sabiendo que puede ser mas que uno)
-Ingresar un legajo y permitir la modificacion de la nota

Transformar la carga en una carga aleatoria
*/
