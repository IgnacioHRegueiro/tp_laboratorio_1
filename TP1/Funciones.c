#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"


// Funci�n encargada del pedido de un n�mero entero.
int GetInt (char mensaje [])
{
    int numeroIngresado;

    printf("%s",mensaje);
    scanf("%d", &numeroIngresado);

    return numeroIngresado;
}

// Funci�n encargada del pedido de un operando.
int IngresarOperando (void)
{

    int operando;
    operando = GetInt("Ingrese su operando: ");


    return operando;
}

// Funci�n encargada del c�lculo de la suma de los operandos.
int CalcularSuma(int primerOperando , int segundoOperando)
{
    int resultado;
    resultado = primerOperando + segundoOperando;
    return resultado;
}

// Funci�n encargada del c�lculo de la resta entre operandos (A-B).
int CalcularResta(int primerOperando , int segundoOperando)
{

    int resultado;

    resultado = primerOperando - segundoOperando;
    return resultado;
}

// Funci�n encargada de la divisi�n entre operandos (A/B).
float CalcularDivision (int primerOperando , int segundoOperando)
{
    float resultado;

    resultado = (float)primerOperando / segundoOperando;
    return resultado;
}

// Funci�n encargada de la multiplicaci�n entre los operandos.
int CalcularMultiplicacion (int primerOperando , int segundoOperando)
{
    int resultado;

    resultado = primerOperando * segundoOperando;
    return resultado;
}

// Funci�n encargada de realizar el c�lculo del factorial.
unsigned long long int CalcularFactorial (int Operando)
{
    unsigned long long int factorial;

    factorial = 1;

    for (int i = Operando; i > 1; i--)
    {
        factorial = factorial * i;
    }

    return factorial;
}













