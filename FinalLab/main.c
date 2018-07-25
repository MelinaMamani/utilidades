#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Letras.h"

/****************************************************
    Menu:
        1. Parse del archivo datos.csv
        2.
        3.
        4.
*****************************************************/


int main()
{
    char seguir = 's';
    Letra * lista = letras_new();
    ArrayList* arrayList = al_newArrayList();
    ArrayList* repetidos = al_newArrayList();
    ArrayList* depurados = al_newArrayList();

    do{
        switch(menu()){

        case 1:
            if(parserLetras(arrayList)){
                    printf("Letras cargadas. \n\n");
            }
            letras_print(lista, arrayList);
            break;

        case 2:
            letras_comprobar(arrayList, lista);
            letras_print(lista, arrayList);
            break;

        case 3:
            listar_letras(arrayList, repetidos, depurados);
            break;

        case 4:

            break;

        case 5:
            //save_employees(arrayList);
            seguir = 'n';
            break;
        }
    }while(seguir == 's');
    return 0;
}
