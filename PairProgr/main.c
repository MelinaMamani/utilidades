#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    char seguir = 's';
    FILE* p;
    Employee* lista = employee_new();
    ArrayList* arrayList = al_newArrayList();

    do{
        switch(menu()){

        case 1:
            if(parserEmployee(p, arrayList)){
                    printf("Empleados cargados. \n\n");
            }
            break;

        case 2:
            arrayList->sort(arrayList, employee_reorder, 1);
            employee_print(lista, arrayList);
            break;

        case 3:
            arrayList->sort(arrayList, employee_compare, 1);
            employee_print(lista, arrayList);
            break;

        case 4:
            employee_add(lista, arrayList);
            break;

        case 5:
            employee_remove(lista, arrayList);
            break;

        case 6:
            arrayList->sort(arrayList, employee_reorder, 1);
            employee_subList(lista, arrayList);
            break;

        case 7:
            arrayList->sort(arrayList, employee_reorder, 1);
            save_employees(arrayList);
            seguir = 'n';
            break;
        }
    }while(seguir == 's');
    return 0;
}
