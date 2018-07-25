#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Letras.h"

int menu(){
    int opcion;

    printf("Menu:\n");
    printf("1. Parse del archivo datos.csv\n");
    printf("2. Completar campos restantes\n");
    printf("3. Listar\n");
    printf("4. Generar 3 archivos\n");
    printf("5. Salir\n");

    printf("\nIngrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
    system("cls");
}

/*int letras_reorder(void* letraA,void* letraB)
{
    Letra* E1 = (Letra*) letraA;
    Letra* E2 = (Letra*) letraB;

    int returnAux = 0;

    if(letras_getLetra(E1) > letras_getLetra(E2))
    {
        returnAux = 1;
    }
    if(letras_getLetra(E1) < letras_getLetra(E2))
    {
        returnAux = -1;
    }

    return returnAux;
}

int letras_compare(void* pEmployeeA,void* pEmployeeB)
{
    Letra* E1 = (Letra*) pEmployeeA;
    Letra* E2 = (Letra*) pEmployeeB;

    int returnAux;

    if(stricmp(E1->name, E2->name)>0)
    {
        returnAux = 1;
    }
    if(stricmp(E1->name, E2->name)<0)
    {
        returnAux = -1;
    }
    if(stricmp(E1->name, E2->name)==0)
    {
        returnAux = 0;
    }

    return returnAux;
}*/

int letras_comparacion(char* letra1, void* letra2)
{
    int aux = 0;

    if( tolower(((Letra*)letra1)->letra) > tolower(((Letra*)letra2)->letra))
    {
        aux = 1;
    }
    if( tolower(((Letra*)letra1)->letra) < tolower(((Letra*)letra2)->letra))
    {
        aux = -1;
    }

    return aux;
}

void letras_print(Letra* this, ArrayList* arrayList)
{
    int i, id=1;

    xlkCenterPrintf("arrayList DE LETRAS",1);

    xlkSortPrintf(1,"%s,%s,%s,%s,%s",5,"ID","LETRA","NOMBRE","VOCAL","CONSONANTE");

            for( i=0;i <arrayList->len(arrayList);i++ )
            {
                this = arrayList->get(arrayList,i);
                xlkSortPrintf(3,"%d,%c,%s,%d,%d",5,id++,letras_getLetra(this), letras_getName(this), letras_getVocal(this), letras_getConsonante(this));
            }
}

void letras_comprobar(ArrayList* arrayList, Letra* letras)
{
    int i;

    for(i=0; i < arrayList->len(arrayList); i++)
    {
        letras = arrayList->get(arrayList,i);

        if(!isdigit(letras_getLetra(letras)))
        {
            if(letras_getLetra(letras) == 'a' || letras_getLetra(letras) == 'e' || letras_getLetra(letras) == 'i'|| letras_getLetra(letras) == 'o' || letras_getLetra(letras) == 'u')
            {
                letras_setVocal(letras,1);
            }
            else if(letras_getLetra(letras) == 'A' || letras_getLetra(letras) == 'E' || letras_getLetra(letras) == 'I'|| letras_getLetra(letras) == 'O' || letras_getLetra(letras) == 'U')
            {
                letras_setVocal(letras,1);
            }
            else
            {
                letras_setConsonante(letras,1);
            }
        }
    }
}

void listar_letras(ArrayList* arrayList, ArrayList* repetidos, ArrayList* depurados)
{
    int i, j, counter;
    char palabra[50];

    printf("\nIngrese un string: ");
    fflush(stdin);
    gets(palabra);


    for( i = 0 ; i < arrayList->len(arrayList) ; i++)
    {
        counter = 0;

        for( j = 0 ; j < arrayList->len(arrayList) ; j++)
        {
            if(tolower(((Letra*)arrayList->get(arrayList,j))->letra) == tolower(palabra[i]) )
            {
                counter++;

                if( repetidos->contains(repetidos,arrayList->get(arrayList,i)) == 0 )
                {
                    repetidos->add(repetidos,arrayList->get(arrayList,i));
                }
            }
        }
        if( counter == 1 )
        {
            repetidos->remove(repetidos, repetidos->indexOf(repetidos, arrayList->get(arrayList,i)) );
            depurados->add(depurados, arrayList->get(arrayList,i));
        }

    }

    //repetidos->sort(repetidos, letras_comparacion, 0);

    for(i = 0; i < repetidos->len(repetidos); i++)
    {
        printf("R: %c \n", ((Letra*)repetidos->get(repetidos, i))->letra);
    }

    /*depurados->sort(depurados, letras_comparacion, 1);

    printf("\n");

    for(i = 0; i < depurados->len(depurados); i++)
    {
        printf("%c \n", ((Letra*)depurados->get(depurados, i))->letra);
    }*/
}
/*int save_employees(ArrayList* arrayList)
{
    FILE* f;

    Letra* letra = letras_new();

    char estado[50];
    int returnAux = -1;
    int i;

    if(arrayList != NULL)
    {
        f = fopen("data.csv", "w");
        if(f != NULL)
        {
            fprintf(f,"id,name,lastname,isEmpty\n");
            for(i=0; i<arrayList->len(arrayList); i++)
            {

                letra = arrayList->get(arrayList,i);

                fprintf(f,"%c,%s,%d,%d\n",letras_getLetra(employee),letras_getName(employee),letras_getLastName(employee),estado);

            }

             fclose(f);
            for(i=0;i<arrayList->len(arrayList);i++)
            {
                  letra = arrayList->get(arrayList,i);
                  free(employee);
            }

            arrayList->deleteArrayList(arrayList);
        }
        returnAux = 0;
    }

    return returnAux;

}*/

Letra* letras_new(void)
{
    Letra* this = (Letra*) malloc(sizeof(Letra));

    return this;

}

void letras_delete(Letra* this)
{
    free(this);
}

void letras_setLetra(Letra* this, char caracter)
{
    if(caracter != "\n" && !isdigit(caracter))
        this->letra = caracter;
}

char letras_getLetra(Letra* this)
{
    return this->letra;
}

void letras_setName(Letra* this, char* name)
{
    if(strlen(name)<=20)
        strcpy(this->name, name);
}

char* letras_getName(Letra* this)
{
    return this->name;
}

void letras_setVocal(Letra* this, int num)
{
    if(num >= 0)
        this->vocal = num;
}

int letras_getVocal(Letra* this)
{
    return this->vocal;
}

void letras_setConsonante(Letra* this, int num)
{
    if(num >= 0)
        this->consonante = num;
}

int letras_getConsonante(Letra* this)
{
    return this->consonante;
}

