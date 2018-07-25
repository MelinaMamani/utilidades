#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

//INFORMACION IMPORTANTE: En la consola CMD entran 90 caracteres o digitos.

//Generadores de menus completos:


//XL1-1
/** \brief Genera un menu con la cantidad de opciones y texto a eleccion.
 *
 * \param head: Encabezado del menu.
 * \param totalOptions: se coloca un entero que indica la cantidad de opciones a generar
 * \param Se agregan parametros con string para las opciones, segun la cantidad elegida.
 *
 */

void xlkIndexGenerator(char head[],int totalOptions,...)
{
    system("cls");
    int i;
    va_list arguments;
    va_start(arguments,totalOptions);
    printf("#*---*---*---*---*---*---*---*---*---*----*---*---*---*---*---*---*---*---*---*#\n");
    printf("  *%s\n                                                                           ",head);
    printf("\n#*---*---*---*---*---*---*---*---*---*----*---*---*---*---*---*---*---*---*---*#\n");
    printf("###########____________________________________________________________________#\n"    );
    printf("   MENU:\n\n"                                                                          );
    printf("###########____________________________________________________________________#\n"  );
    for(i = 0; i < totalOptions; i++)
    {
        printf("-  %s\n",va_arg(arguments,char*));
    }
    printf("\n############___________________________________________________________________#\n");
    va_end(arguments);
}



//Generadores de fragmentos de menu:


//XL1-2
/** \brief Recuadra un texto con un diseño agradable para utilizarlo como encabezado destacado.
 *
 * \param mode:[distinto de 0] genera un encabezado con una linea debajo del mismo. mode:[0] no genera la linea.
 * \param text: texto a encuadrar.
 * \return
 *
 */
void xlkHeadGenerator(int mode, char text[])
{
    system("cls");
    printf("\\/  \\/   \\/  \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/\n");
    printf(" ** %s\n\n",text);
    printf("/\\  /\\   /\\  /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\\n");
    if(mode)
    {
        printf("________________________________________________________________________________\n");
    }

}


//XL1-3
/** \brief Genera un listado de opciones de cantidad variable sin encabezado.
 *
 * \param mode:[distinto de 0] genera un cuerpo de menu con una linea arriba del mismo. mode:[0] no genera la linea.
 * \param totalOptions: cantidad de opciones del listado.
 * \param ... Se colocan tantos argumentos como cantidad de opciones con texto a mostrar.
 * \return
 *
 */
void xlkIndexBodyGenerator(int mode,int totalOptions,...)
{
    va_list arguments;
    va_start(arguments,totalOptions);
    if(mode)
    {
        printf("________________________________________________________________________________\n");
    }
    for(int i=0; i < totalOptions; i++)
    {
        printf(" * %s\n",va_arg(arguments,char*));
    }
    printf("________________________________________________________________________________\n\n");
    va_end(arguments);
}


//XL1-4
/** \brief Muestra un mensaje al usuario segun el modo elegido.
 *
 * \param message : Mensaje a mostrar.
 * \param mode :[1] Limpia la pantalla y muestra el mensaje.
 * \param mode :[2] Limpia la pantalla, muestra el mensaje y hace una pausa.
 * \param mode :[3] Limpia la pantalla, muestra el mensaje, hace una pausa y sale del programa.
 * \param mode :[4] Muestra el mensaje y hace una pausa.
 * \param mode :[5] Muestra el mensaje, hace una pausa y sale del programa.
 * \param mode :[6] Muestra el mensaje con un '\n' delante.
 * \param mode :[7] Muestra el mensaje con dos '\n'.
 * \param mode :[ menor que 1 o mayor a 7] Muestra el mensaje.
 * \return
 *
 */

void xlkShowMessage(char* message, int mode)
{
    switch(mode)
    {
    case 1:
        system("cls");
        printf(message);
        break;
    case 2:
        system("cls");
        printf("%s\n\n",message);
        system("pause");
        break;
    case 3:
        system("cls");
        printf("%s\n\n",message);
        system("pause");
        exit(1);
        break;
    case 4:
        printf("%s\n\n",message);
        system("pause");
        break;
    case 5:
        printf("%s\n\n",message);
        system("pause");
        exit(1);
        break;
    case 6:
        printf("\n%s",message);
        break;
    case 7:
        printf("%s\n\n",message);
        break;
    default :
        printf(message);
        break;
    }
}


//XL1-5
/** \brief Separa una cadena a partir de un caracter especifico copiandose el resto de la cadena a otra y borrandose lo copiado desde la primera cadena.
 *
 * INFO ADICIONAL: Si hay espacios, la funcion hara la separacion desde el ultimo antes del caracter divisor.
 * \param splitterCharacter: numero de caracter a partir del cual el string1 finalizara y se copiaran los caracteres siguientes.
 * \param string1: Cadena a dividir a partir del caracter divisor(splitterCharacter).
 * \param string2: Cadena en la que se copiara el contenido que se encuentre despues del caracter divisor en string1.
 * \return
 *
 */

void stringSeparator(int splitterCharacter, char* string1, char* string2 )
{
    int i;
    int j;
    int flag = 0;
    int cutIndex = 0;
    int lastSpaceIndex = -1;
    for( i = 0, j = 0 ; string1[i] != '\0'; i++ )
    {
        if( string1[i] == ' ')
        {
            lastSpaceIndex = i;
        }
        if( i >= splitterCharacter )
        {
            if(flag == 0)
            {
                if( lastSpaceIndex != -1)
                {
                    cutIndex = lastSpaceIndex;
                    splitterCharacter = lastSpaceIndex;
                    i = lastSpaceIndex ;
                    flag++;
                    continue;
                }
                else
                {
                    cutIndex = i;
                    flag++;
                }

            }
            string2[j] = string1[i];
            j++;
        }
    }
    string1[cutIndex] = '\0';
    string2[j] = '\0';
}


//XL1-6
/** \brief Imprime de manera ordenada argumentos de cualquier tipo de dato.
 *
 * \param mode[3]: Imprime los datos con decoracion de linea punteada solo al final.
 * \param mode[2]: Imprime los datos con decoracion de linea recta.
 * \param mode[1]: Imprime los datos con decoracion de linea punteada.
 * \param mode[0]: Imprime los datos sin decoracion.
 * \param dataType: String con los especificadores de formato de cada argumento, en orden, sin espacios y separados por comas.
 * \param totalArguments: cantidad de argumentos a imprimir. El maximo es 6 por cuestiones visuales.
 * \return
 *
 */

void xlkSortPrintf(int mode,char* dataType, int totalArguments,...)
{
    va_list arguments;
    va_start(arguments,totalArguments);

    if(totalArguments < 7 )
    {
        char matrizArgumentos[totalArguments][1000];
        char auxiliar[1000];
        char format;
        int i ;
        int flag = 0;
        int j = -1;

        for(i = 0; i < totalArguments ; i++)
        {
            for(j++; dataType[j] != ',' && dataType[j] != '\0'; j++)
            {
                if( dataType[j] == '%' && dataType[j+1] == 's' )
                {
                    format = 's';
                }
                else if( dataType[j] == '%' && dataType[j+1] == 'c'  )
                {
                    format = 'c';
                }
                else if( dataType[j] == '%' && dataType[j+1] == 'd'  )
                {
                    format = 'd';
                }
                else if( (dataType[j] == '%' && dataType[j+1] == 'l' && dataType[j+2] == 'd') || (dataType[j] == '%' && dataType[j+1] == 'l' && dataType[j+2] == 'i'))
                {
                    format = 'l';
                }
                else if( (dataType[j] == '%' && dataType[j+1] == 'l' && dataType[j+2] == 'l' && dataType[j+3] == 'd') || (dataType[j] == '%' && dataType[j+1] == 'l' && dataType[j+2] == 'l' && dataType[j+3] == 'i')  )
                {
                    format = 'L';
                }
                else if( dataType[j] == '%' && dataType[j+1] == 'f' )
                {
                    format = 'f';
                }
            }
            switch(format)
            {
            case 's':
                sprintf(matrizArgumentos[i],"%s",va_arg(arguments, char*));
                break;
            case 'c':
                sprintf(matrizArgumentos[i],"%c",va_arg(arguments, int));
                break;
            case 'd':
                sprintf(matrizArgumentos[i],"%d",va_arg(arguments, int));
                break;
            case 'l':
                sprintf(matrizArgumentos[i],"%ld",va_arg(arguments, long ));
                break;
            case 'L':
                sprintf(matrizArgumentos[i],"%lld",va_arg(arguments, long long ));
                break;
            case 'f':
                sprintf(matrizArgumentos[i],"%.2f",va_arg(arguments, double));
                break;
            }
        }
        if(mode == 1)
        {
            printf("--------------------------------------------------------------------------------");
        }
        else if(mode == 2)
        {
            printf("________________________________________________________________________________\n");
        }
        printf(" ");
        for(i = 0; i < totalArguments; i++)
        {
            switch(totalArguments)
            {
            case 1:
                if( strlen(matrizArgumentos[i]) > 76)
                {
                    stringSeparator(76,matrizArgumentos[i],auxiliar);
                    printf("%-76s  ", matrizArgumentos[i]);
                    strcpy( matrizArgumentos[i], auxiliar);
                    flag=1;
                }
                else
                {
                    printf("%-76s  ", matrizArgumentos[i]);
                    matrizArgumentos[i][0] = '\0';
                }
                break;
            case 2:
                if( strlen(matrizArgumentos[i]) > 37)
                {
                    stringSeparator(37,matrizArgumentos[i],auxiliar);
                    printf("%-37s  ", matrizArgumentos[i]);
                    strcpy( matrizArgumentos[i], auxiliar);
                    flag=1;
                }
                else
                {
                    printf("%-37s  ", matrizArgumentos[i]);
                    matrizArgumentos[i][0] = '\0';
                }
                break;
            case 3:
                if( strlen(matrizArgumentos[i]) > 23)
                {
                    stringSeparator(23,matrizArgumentos[i],auxiliar);
                    printf("%-23s  ", matrizArgumentos[i]);
                    strcpy( matrizArgumentos[i], auxiliar);
                    flag=1;
                }
                else
                {
                    printf("%-23s  ", matrizArgumentos[i]);
                    matrizArgumentos[i][0] = '\0';
                }
                break;
            case 4:
                if( strlen(matrizArgumentos[i]) > 17)
                {
                    stringSeparator(17,matrizArgumentos[i],auxiliar);
                    printf("%-17s  ", matrizArgumentos[i]);
                    strcpy( matrizArgumentos[i], auxiliar);
                    flag=1;
                }
                else
                {
                    printf("%-17s  ", matrizArgumentos[i]);
                    matrizArgumentos[i][0] = '\0';
                }
                break;
            case 5:
                if( strlen(matrizArgumentos[i]) > 13)
                {
                    stringSeparator(13,matrizArgumentos[i],auxiliar);
                    printf("%-13s  ", matrizArgumentos[i]);
                    strcpy( matrizArgumentos[i], auxiliar);
                    flag=1;
                }
                else
                {
                    printf("%-13s  ", matrizArgumentos[i]);
                    matrizArgumentos[i][0] = '\0';
                }
                break;
            case 6:
                if( strlen(matrizArgumentos[i]) > 11)
                {
                    stringSeparator(11,matrizArgumentos[i],auxiliar);
                    printf("%-11s  ", matrizArgumentos[i]);
                    strcpy( matrizArgumentos[i], auxiliar);
                    flag=1;
                }
                else
                {
                    printf("%-11s  ", matrizArgumentos[i]);
                    matrizArgumentos[i][0] = '\0';
                }
                break;
            }

            if( flag == 1 && i == totalArguments -1 )
            {
                printf("\n ");
                i = -1;
                flag = 0;
            }
        }

    }
    printf("\n");
    if(mode == 1 || mode == 3)
    {
        printf("--------------------------------------------------------------------------------");
    }
    else if(mode == 2)
    {
        printf("________________________________________________________________________________");
    }
    va_end(arguments);
}


//XL1-7
/** \brief Imprime un string en el centro de la pantalla.
 *
 * \param word: String a imprimir centrado.
 * \param mode[2]: Centra el texto y lo imprime con decoracion.
 * \param mode[1]: Centra el texto y lo imprime solo con la decoracion superior.
 * \param mode[0]: Centra el texto y lo imprime.
 * \return
 *
 */

void xlkCenterPrintf(char* word, int mode)
{
    int screenCenter = 30;
    int wordRef = ((strlen(word) / 2) - 1) ;
    int start = screenCenter - (wordRef - 3);
    int i;

    if(mode)
    {
        printf("--------------------------------------------------------------------------------");
        for( i = 0 ; i < start ; i++)
        {
            printf(" ");
        }
        printf("<<< %s >>>\n",word);
        if(mode == 2)
        {
            printf("--------------------------------------------------------------------------------");
        }
    }
    else
    {
        for( i = 0 ; i < start+5 ; i++)
        {
            printf(" ");
        }
        printf("%s\n",word);
    }

}

