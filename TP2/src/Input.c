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
