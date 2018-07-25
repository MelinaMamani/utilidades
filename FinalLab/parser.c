#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Letras.h"

int parserLetras(ArrayList* pArrayListLetras)
{
    char var1[5], var2[51], var3[51], var4[10];
    int cant;

    FILE* pFile= fopen("datos.csv", "r");

    if((pFile)==NULL){
        printf("No se pudo abrir el archivo.\n");
    }

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", var1, var2, var3, var4);

    while(!feof(pFile)){


            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", var1, var2, var3, var4);

            if(cant!=4){
                if(feof(pFile)){
                    break;
                }
                else{
                    printf("Error.\n");
                    exit(EXIT_FAILURE);
                }
            }


            Letra* eAux = letras_new();

            letras_setLetra(eAux,var1[0]);
            letras_setName(eAux,var2);
            letras_setVocal(eAux,atoi(var3));
            letras_setConsonante(eAux,atoi(var4));
            pArrayListLetras->add(pArrayListLetras,eAux);
        }

    fclose(pFile);

    return 0;
}

