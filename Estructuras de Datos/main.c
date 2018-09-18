#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define A 3


//DECLARACION DE LA ESTRUCTURA DE DATOS
typedef struct //Indico que voy a definir un tipo de dato
{
    int legajo;
    char nombre[50];
    int nota;
    float altura;
} eAlumno; //Esta es la forma típica de nombrar estructuras. Se trata de un alias


//PROTOTIPO DE FUNCIONES
void mostrarUnAlumno(eAlumno); // Declaro la función después de haber declarado la estructura de dato
eAlumno cargarAlumno();
void cargarListadoDeAlumnos(eAlumno[], int);
void mostrarListadoDeAlumnos(eAlumno[], int);
void ordenarListadoDeAlumnos(eAlumno[], int);


int main()
{
    /*eAlumno miAlumno = {1234, "Juan", 8, 1.78}; // Declaro tipo de dato e inicializo

    eAlumno miAlumno; // Declaro pero no inicializo

    printf("Ingrese legajo: "); // Pido datos al usuario
    scanf("%d", &miAlumno.legajo);

    printf("\nIngrese nombre: ");
    fflush(stdin);
    gets(miAlumno.nombre);


    printf("\nIngrese nota: ");
    scanf("%d", &miAlumno.nota);

    printf("\nIngrese altura: ");
    scanf("%f", &miAlumno.altura);*/

    /*eAlumno miAlumno;
    miAlumno = cargarAlumno();
    mostrarUnAlumno(miAlumno);*/


    /*eAlumno listadoMain[A];
    cargarListadoDeAlumnos(listadoMain, A);
    mostrarListadoDeAlumnos(listadoMain, A);
    ordenarListadoDeAlumnos(listadoMain, A);
    mostrarListadoDeAlumnos(listadoMain, A);
    */


    //---------MENU DE OPCIONES-----//

    eAlumno listadoAlumnos[A];
    char opcion;

    do
    {
        printf("a. Alta de alumno\no. Ordenar alumnos\nm. Mostrar alumnos\n");
        printf("Ingrese una opcion: ");
        opcion = getche(); //funcion que devuelve un caracter

        switch(opcion)
        {
        case 'a':
            cargarListadoDeAlumnos();
            break;

        case 'o':
            ordenarListadoDeAlumnos();
            break;

        case 'm':
            mostrarListadoDeAlumnos();
            break;

        }
    }





    return 0;
}



//DESARROLLO DE LAS FUNCIONES
void mostrarUnAlumno(eAlumno unAlumno)
{
    printf("%10d%20s%10d%10f\n", unAlumno.legajo, unAlumno.nombre, unAlumno.nota, unAlumno.altura);
}


eAlumno cargarAlumno()
{
    eAlumno miAlumno;

    printf("\nIngrese legajo: ");
    scanf("%d", &miAlumno.legajo);

    printf("\nIngrese nombre: ");
    fflush(stdin);
    gets(miAlumno.nombre); // Cuando accedo a un array dentro de una estructura de datos, no necesito poner & ya que se trata de una dirección de memoria

    printf("\nIngrese nota: ");
    scanf("%d", &miAlumno.nota);

    printf("\nIngrese altura: ");
    scanf("%f", &miAlumno.altura);

    return miAlumno;
}


void cargarListadoDeAlumnos(eAlumno listado[], int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        //listado[i] = cargarAlumno();
        // Otra opción:
        printf("Ingrese legajo: ");
        scanf("%d", &listado[i].legajo);
    }
}


void mostrarListadoDeAlumnos(eAlumno listado[], int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        mostrarUnAlumno(listado[i]);
    }
    printf("\n");
}

void ordenarListadoDeAlumnos(eAlumno listado[], int tam)
{
    int i;
    int j;
    eAlumno aux;

    for(i = 0; i < tam - 1; i++)
    {
        for(j = i +1; j < tam; j++)
        {
            if(strcmp(listado[i].nombre, listado[j].nombre) > 0)
            {
                aux = listado[i];
                listado[i] = listado[j];
                listado[j] = aux;
            }
        }
    }
}

