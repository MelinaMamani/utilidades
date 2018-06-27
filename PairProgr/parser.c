#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    char var1[10], var2[51], var3[51], var4[10];
    int cant;

    pFile= fopen("data.csv", "r");

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


            Employee* eAux = employee_new();

            employee_setId(eAux,atoi(var1));
            employee_setName(eAux,var2);
            employee_setLastName(eAux,var3);
            employee_setIsEmpty(eAux,var4);
            pArrayListEmployee->add(pArrayListEmployee,eAux);
        }

    fclose(pFile);

    return 0;
}

