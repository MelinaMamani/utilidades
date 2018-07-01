#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 2

struct persona
    {
    char nombre[20];
    int edad;
    };

void main(void)
{
    /*struct persona auxiliarpersona;
    struct persona * punteroPersona;
    punteroPersona = &auxiliarpersona;

    //Metodo tradicional

    printf("Ingrese edad: ");
    scanf("%d", &(*punteroPersona).edad);

    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%[^\n]", (*punteroPersona).nombre);

    printf("\n%d - %s", (*punteroPersona).edad, (*punteroPersona).nombre);

    //Otro metodo (flechas)

    printf("Ingrese edad: ");
    scanf("%d", &punteroPersona->edad);

    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%[^\n]", punteroPersona->nombre);

    printf("\n%d - %s", punteroPersona->edad, punteroPersona->nombre);*/

    int i;

    struct persona personas[CANTIDAD];
    struct persona* punteroPersonas;
    punteroPersonas = personas;

    /*for(i=0; i<CANTIDAD; i++){
        printf("Ingrese edad: ");
        scanf("%d", &(*(punteroPersonas+i)).edad);

        printf("Ingrese nombre: ");
        fflush(stdin);
        scanf("%[^\n]", (*(punteroPersonas+i)).nombre);
    }

    for(i=0; i<CANTIDAD; i++){
        printf("\n%d - %s", (*(punteroPersonas+i)).edad, (*(punteroPersonas+i)).nombre);
    }*/


    //Otro metodo
    for(i=0; i<CANTIDAD; i++){
        printf("Ingrese edad: ");
        scanf("%d", &punteroPersonas[i].edad);

        printf("Ingrese nombre: ");
        fflush(stdin);
        scanf("%[^\n]", punteroPersonas[i].nombre);
    }

    for(i=0; i<CANTIDAD; i++){
        printf("\n%d - %s", punteroPersonas[i].edad, punteroPersonas[i].nombre);
    }
}
