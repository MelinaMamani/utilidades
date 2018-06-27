#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"

int menu(){
    int opcion;

    printf("Menu Empleados:\n");
    printf("1. Parse del archivo data.csv\n");
    printf("2. Listar Empleados\n");
    printf("3. Ordenar por nombre\n");
    printf("4. Agregar un elemento\n");
    printf("5. Elimina un elemento\n");
    printf("6. Listar Empleados (Desde/Hasta)\n");
    printf("7. Salir\n");

    printf("\nIngrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
    system("cls");
}

int employee_reorder(void* pEmployeeA,void* pEmployeeB)
{
    Employee* E1 = (Employee*) pEmployeeA;
    Employee* E2 = (Employee*) pEmployeeB;

    int returnAux;

    if(employee_getId(E1) > employee_getId(E2))
    {
        returnAux = 1;
    }
    if(employee_getId(E1) < employee_getId(E2))
    {
        returnAux = -1;
    }

    return returnAux;
}

int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    Employee* E1 = (Employee*) pEmployeeA;
    Employee* E2 = (Employee*) pEmployeeB;

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
}

void one_employee_print(Employee* this)
{
    if(this !=NULL)
    {
        xlkSortPrintf(3,"%d,%s,%s",3,employee_getId(this), employee_getName(this), employee_getLastName(this));
    }
}

void employee_print(Employee* this, ArrayList* arrayList)
{
    int i, pause = 1;

    xlkCenterPrintf("LISTA DE EMPLEADOS",1);

    xlkSortPrintf(1,"%s,%s,%s",3,"ID EMPLEADO","NOMBRE","APELLIDO");

            for( i=0;i <arrayList->len(arrayList);i++ )
            {
                this = arrayList->get(arrayList,i);
                xlkSortPrintf(3,"%d,%s,%s",3,employee_getId(this), employee_getName(this), employee_getLastName(this));

                if( i == 125*pause)
                {
                    system("pause");
                    pause++;
                }
            }
}

void employee_add(Employee* this, ArrayList* arrayList)
{
    int i;
    char nombre[51], apellido[51];
    char confirma;

    if(this != NULL && arrayList != NULL)
    {
        for(i=0;i<=arrayList->len(arrayList);i++)
        {
            employee_setId(this, i+1);
        }

        employee_setIsEmpty(this,"true");

        printf("\nIngrese nombre del empleado: ");
        fflush(stdin);
        gets(nombre);
        employee_setName(this, nombre);

        printf("\nIngrese apellido del empleado: ");
        fflush(stdin);
        gets(apellido);
        employee_setLastName(this, apellido);

        do{
            printf("\nConfirma el alta de empleado? s/n: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
        }while(confirma != 's' && confirma != 'n');

        if(confirma == 's'){
            arrayList->add(arrayList, this);
            system("cls");
            printf("\nAlta realizada.\n\n");
        }
        else{
            system("cls");
            printf("\nAlta no realizada.\n\n");
        }
    }
}

void employee_remove(Employee* this, ArrayList* arrayList)
{
    int id;
    char confirma;

    if(this != NULL && arrayList != NULL)
    {
        getInt(&id, "Ingresar id del empleado a eliminar: ", "\nError. Reingrese id: ", 1, arrayList->len(arrayList));

        do{
            printf("\nConfirma baja? s/n: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
        }while(confirma != 's' && confirma != 'n');

        if(confirma == 's'){
            this = (Employee*) arrayList->pop(arrayList, id-1);
            printf("\nEmpleado eliminado: %s", employee_getName(this));
            printf("\nBaja realizada.\n\n");
        }
        else{
            printf("\nBaja cancelada.\n\n");
        }
    }
}

int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int indice = 0;

    printf("%s",message);
    scanf("%d",input);

    while( *input < lowLimit || *input >hiLimit)
    {
        printf("%s", eMessage);
        scanf("%d",input);
    }

    if(*input >lowLimit || *input <hiLimit){
        return indice;
    }
    else{
        indice = -1;
        return indice;
    }
}

void employee_subList(Employee* this, ArrayList* arrayList)
{
    int desde, hasta, i;
    ArrayList* arrayList2 = al_newArrayList();

    if(this != NULL && arrayList != NULL)
    {
        getInt(&desde,"Ingrese el id desde donde quiere listar: ","\nError. Reingrese id:",0,arrayList->len(arrayList)-1);
        getInt(&hasta,"\nIngrese el id hasta donde quiere listar: ","\nError. Reingrese id:",desde+1,arrayList->len(arrayList));

        arrayList2 = arrayList->subList(arrayList,desde-1,hasta);

        printf("\nEmpleados desde %d hasta %d\n",desde,hasta);
        xlkCenterPrintf("SUBLISTA DE EMPLEADOS",1);
        xlkSortPrintf(1,"%s,%s,%s",3,"ID EMPLEADO","NOMBRE","APELLIDO");

        for(i=0; i<arrayList2->len(arrayList2); i++)
        {
            if(arrayList->isEmpty(arrayList) == 0)
            {
             this = (Employee*)arrayList->get(arrayList2,i);
             one_employee_print(this);
            }
        }
    }
    else
    {
        printf("Error en sublista de empleados.\n");
        exit(1);
    }

}

int save_employees(ArrayList* arrayList)
{
    FILE* f;

    Employee* employee = employee_new();

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

                employee = arrayList->get(arrayList,i);

                    if(employee->isEmpty == 0)
                    {
                        strcpy(estado,"false");
                    }
                    else if(employee->isEmpty == 1)
                    {
                       strcpy(estado,"true");
                    }

                fprintf(f,"%d,%s,%s,%s\n",employee_getId(employee),employee_getName(employee),employee_getLastName(employee),estado);

            }

             fclose(f);
            for(i=0;i<arrayList->len(arrayList);i++)
            {
                  employee = arrayList->get(arrayList,i);
                  free(employee);
            }

            arrayList->deleteArrayList(arrayList);
        }
        returnAux = 0;
    }

    return returnAux;

}

Employee* employee_new(void)
{
    Employee* this = (Employee*) malloc(sizeof(Employee));

    return this;

}

void employee_delete(Employee* this)
{
    free(this);
}

void employee_setId(Employee* this, int id)
{
    if(id > 0)
        this->id = id;
}

int employee_getId(Employee* this)
{
    return this->id;
}

void employee_setName(Employee* this, char* name)
{
    if(strlen(name)<=51)
        strcpy(this->name, name);
}

char* employee_getName(Employee* this)
{
    return this->name;
}

void employee_setLastName(Employee* this, char* lastName)
{
    if(strlen(lastName)<=51)
        strcpy(this->lastName, lastName);
}

char* employee_getLastName(Employee* this)
{
    return this->lastName;
}

void employee_setIsEmpty(Employee* this, char* isEmpty)
{
    if(strcmp(isEmpty, "true")==0){
        this->isEmpty = 1;
    }
    else if(strcmp(isEmpty, "false")==0){
        this->isEmpty = 0;
    }
}

int employee_getIsEmpty(Employee* this)
{
    return this->isEmpty;
}


