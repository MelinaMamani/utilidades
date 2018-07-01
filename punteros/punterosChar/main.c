<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>

void mostrarCadena();

int main()
{
    char cad[]= "hola";
    mostrarCadena(cad);
    return 0;
}

void mostrarCadena(char* punteroCadena){
    while(*punteroCadena != '\0'){
        printf("%c",*punteroCadena);
        punteroCadena++;
    }
}
=======
#include <stdio.h>
#include <stdlib.h>

void mostrarCadena();

int main()
{
    char cad[]= "hola";
    mostrarCadena(cad);
    return 0;
}

void mostrarCadena(char* punteroCadena){
    while(*punteroCadena != '\0'){
        printf("%c",*punteroCadena);
        punteroCadena++;
    }
}
>>>>>>> dc315f8d53e2ea29ec110c49d056cc641bc9bbee
