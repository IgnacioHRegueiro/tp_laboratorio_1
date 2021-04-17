#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"


// Función encargada del pedido de un número entero.
int GetInt (char mensaje [])
{
    int numeroIngresado;

    printf("%s",mensaje);
    scanf("%d", &numeroIngresado);

    return numeroIngresado;
}

// Función encargada del pedido de un operando.
int IngresarOperando (void)
{

    int operando;
    operando = GetInt("Ingrese su operando: ");


    return operando;
}

// Función encargada del cálculo de la suma de los operandos.
int CalcularSuma(int primerOperando , int segundoOperando)
{
    int resultado;
    resultado = primerOperando + segundoOperando;
    return resultado;
}

// Función encargada del cálculo de la resta entre operandos (A-B).
int CalcularResta(int primerOperando , int segundoOperando)
{

    int resultado;

    resultado = primerOperando - segundoOperando;
    return resultado;
}

// Función encargada de la división entre operandos (A/B).
float CalcularDivision (int primerOperando , int segundoOperando)
{
    float resultado;

    resultado = (float)primerOperando / segundoOperando;
    return resultado;
}

// Función encargada de la multiplicación entre los operandos.
int CalcularMultiplicacion (int primerOperando , int segundoOperando)
{
    int resultado;

    resultado = primerOperando * segundoOperando;
    return resultado;
}

// Función encargada de realizar el cálculo del factorial.
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













