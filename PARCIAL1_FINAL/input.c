#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    printf("%s\n",message);
    scanf("%d",input);
    while(*input<lowLimit || *input>hiLimit)
    {
        printf("Error.%s\n",eMessage);
        scanf("%d",input);
    }
    return 0;
}

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    printf("%s\n",message);
    scanf("%f",input);
    while(*input<lowLimit || *input>hiLimit)
    {
        printf("Error.%s\n",eMessage);
        scanf("%f",input);
    }
    return 0;
}


/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
{
    printf("%s\n",message);
    scanf("%c",input);
    *input = toupper(*input);
    while(*input<lowLimit || *input>hiLimit)
    {
        printf("Error.%s\n",eMessage);
        fflush(stdin);
        scanf("%c",input);
        *input = toupper(*input);
    }
    return 0;
}


/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int i;
    printf("%s\n",message);
    fflush(stdin);
    scanf("%s",input);
    for(i=0;i<strlen(input);i++)
    {
        input[i] = tolower(input[i]);
    }
    while(strlen(input)<lowLimit || strlen(input)>hiLimit)
    {
        printf("Error.%s. Reingrese:\n",eMessage);
        fflush(stdin);
        scanf("%s",input);
        for(i=0;i<strlen(input);i++)
        {
            input[i] = tolower(input[i]);
        }
    }
    //strcpy(input,"Sheldon");
    return 0;
}
