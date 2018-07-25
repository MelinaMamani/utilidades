#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"

typedef struct
{
    int numero;

} eNumeros;

int enumeros_repeticion( void* enumero, void* enumero2);
int enumeros_comparacion(void* eNumero1, void* eNumero2);

int main()
{
    ArrayList* lista = al_newArrayList();
    ArrayList* repetidos = al_newArrayList();
    ArrayList* depurados = al_newArrayList();

    eNumeros* numero = (eNumeros*) malloc(sizeof(eNumeros));
    numero->numero = 10;
    lista->add(lista, numero);

    eNumeros* numero2 = (eNumeros*) malloc(sizeof(eNumeros));
    numero2->numero = 20;
    lista->add(lista, numero2);

    eNumeros* numero3 = (eNumeros*) malloc(sizeof(eNumeros));
    numero3->numero = 20;
    lista->add(lista, numero3);


    eNumeros* numero4 = (eNumeros*) malloc(sizeof(eNumeros));
    numero4->numero = 40;
    lista->add(lista, numero4);


    eNumeros* numero5 = (eNumeros*) malloc(sizeof(eNumeros));
    numero5->numero = 70;
    lista->add(lista, numero5);

    eNumeros* numero6 = (eNumeros*) malloc(sizeof(eNumeros));
    numero6->numero = 40;
    lista->add(lista, numero6);

    eNumeros* numero7 = (eNumeros*) malloc(sizeof(eNumeros));
    numero7->numero = 0;
    lista->add(lista, numero7);

    eNumeros* numero8 = (eNumeros*) malloc(sizeof(eNumeros));
    numero8->numero = 80;
    lista->add(lista, numero8);

    eNumeros* numero9 = (eNumeros*) malloc(sizeof(eNumeros));
    numero9->numero = 80;
    lista->add(lista, numero9);

    eNumeros* numero11 = (eNumeros*) malloc(sizeof(eNumeros));
    numero11->numero = 80;
    lista->add(lista, numero11);

    eNumeros* numero10 = (eNumeros*) malloc(sizeof(eNumeros));
    numero10->numero = 60;
    lista->add(lista, numero10);

    int counter;

    for( int i = 0 ; i < lista->len(lista) ; i++)
    {
        counter = 0;
        for( int j = 0 ; j < lista->len(lista) ; j++)
        {
            if( enumeros_repeticion(lista->get(lista,i),lista->get(lista,j)) == 1  )
            {
                counter++;
                if( repetidos->contains(repetidos,lista->get(lista,i)) == 0 )
                {
                    repetidos->add(repetidos,lista->get(lista,i));
                }
            }
        }
        if( counter == 1 )
        {
            repetidos->remove(repetidos, repetidos->indexOf(repetidos, lista->get(lista,i)) );
            depurados->add(depurados,lista->get(lista,i));
        }

    }

    repetidos->sort(repetidos, enumeros_comparacion, 0);

    for(int i = 0; i < repetidos->len(repetidos); i++)
    {
        printf("%d \n", ((eNumeros*)repetidos->get(repetidos, i))->numero);
    }

    depurados->sort(depurados, enumeros_comparacion, 1);

    printf("\n");

    for(int i = 0; i < depurados->len(depurados); i++)
    {
        printf("%d \n", ((eNumeros*)depurados->get(depurados, i))->numero);
    }

    return 0;
}

int enumeros_comparacion(void* eNumero1, void* eNumero2)
{
    int aux = 0;
    if( ((eNumeros*)eNumero1)->numero > ((eNumeros*)eNumero2)->numero)
    {
        aux = 1;
    }
    if( ((eNumeros*)eNumero1)->numero < ((eNumeros*)eNumero2)->numero)
    {
        aux = -1;
    }

    return aux;
}

int enumeros_repeticion( void* enumero, void* enumero2)
{
    int repeticion = 0;
    if( ((eNumeros*)enumero)->numero == ((eNumeros*)enumero2)->numero )
    {
        repeticion = 1;
    }
    return repeticion;
}


/*
    for( int i = 0 ; i < lista->len(lista) ; i++)
    {
        if( i == 0)
        {
            lista2->add(lista2, lista->get(lista,i));
            continue;
        }
        for( int j = 0 ; j < lista2->len(lista2) ; j++)
        {
            if( enumeros_repeticion(lista->get(lista,i),lista2->get(lista2,j)) == 1  )
            {
                break;
            }
            if( j == lista2->len(lista2)-1)
            {
                lista2->add(lista2,lista->get(lista,i));
            }
        }
    }*/
