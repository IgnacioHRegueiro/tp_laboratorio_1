/*
 * Input.c
 *
 *  Created on: 13 may. 2021
 *      Author: Ignacio Regueiro
 */

#include "Input.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int GetInt(char *message)
{
    int number;
    printf("%s" , message);
    scanf("%d", &number);

    return number;
}

void GetString(char *message, char *string)
{
    printf("%s", message);
    fflush(stdin);
    scanf("%s", string);
}

float GetFloat(char *message)
{
    int number;
    printf("%s" , message);
    scanf("%d", &number);

    return number;
}

int ValidateRange(char *message, int max, int min, int number)
{
    while(number > max || number < min)
    {
        number = GetInt(message);
    }

    return number;
}

int getStringLetras(char string[])
{
    int i;
    int flag = 0;
    int esEspacio = 0;
    int tam = strlen(string);
    for(i=0; i<tam; i++)
    {
        if(string[i] != '\0')
        {
            if ((string[i]<'a' || string[i]>'z') && (string[i]<'A'||string[i]>'Z') && string[i]!=' ')
            {
                flag = -1;
            }
            if(string[i]!=' ')
            {
                esEspacio = -1;
            }
        }
    }
    if(esEspacio == 0)
    {
        flag = -1;
    }
    return flag;
}
int getStringNumeros(char string[])
{
    int i;
    int flag = 0;
    int tam = strlen(string);
    for(i=0; i<tam; i++)
    {
        if(string[i] != '\0')
        {
            if ((string[i]<'0' || string[i]>'9') && string[i]!=' ')
            {
                flag = -1;
            }

        }
    }
    return flag;
}
void GetStringSoloLetras (char mensaje[], char string[])
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", string);
    while(getStringLetras(string)== -1)
    {
        printf("Error. Solo se permiten letras, no se permite dejar el espacio en blanco! \n");
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%[^\n]", string);
    }
}
void GetStringSoloNumeros (char mensaje[], char string[])
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", string);
    while(getStringNumeros(string)== -1)
    {
        printf("Error. Solo se permiten números positivos, no se puede dejar el espacio en blanco! \n");
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%[^\n]", string);
    }
}


