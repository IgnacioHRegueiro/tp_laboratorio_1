#include "Funciones.h"

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

    int opcion;
    int primerOperando;
    int segundoOperando;
    int sumaOperandos;
    int restaOperandos;
    float divisionOperandos;
    int multiplicacionOperandos;
    unsigned long long int factorialPrimerOperando;
    unsigned long long int factorialSegundoOperando;
    int flagPrimerOperando;
    int flagSegundoOperando;
    int flagCalculoOperaciones;

    flagCalculoOperaciones = 0;
    flagSegundoOperando = 0;
    flagSegundoOperando = 0;

    primerOperando = 0;
    segundoOperando = 0;


    do
    {
        printf(" 1 - Ingresar primer operando (actualmente, %d). \n 2 - Ingresar segundo operando (actualmente, %d). \n 3 - Calcular todas las operaciones (Suma, resta, división, multiplicación y factorial). \n 4 - Mostrar los resultados de las operaciones. \n 5 - Salir. \n OPCIÓN: ", primerOperando, segundoOperando);
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:

            primerOperando = IngresarOperando();
            flagPrimerOperando = 1;
            break;

            case 2:

            segundoOperando = IngresarOperando();
            flagSegundoOperando = 1;
            break;

            case 3:

            if(flagPrimerOperando == 1 && flagSegundoOperando == 1)
            {
                sumaOperandos = CalcularSuma(primerOperando , segundoOperando);

                restaOperandos = CalcularResta(primerOperando , segundoOperando);

                divisionOperandos = CalcularDivision (primerOperando , segundoOperando);

                multiplicacionOperandos = CalcularMultiplicacion (primerOperando , segundoOperando);

                factorialPrimerOperando = CalcularFactorial(primerOperando);

                factorialSegundoOperando = CalcularFactorial(segundoOperando);

                flagCalculoOperaciones = 1;
                printf("Los cálculos se han realizado correctamente. \n");
            }
            else
            {

                printf("Debe ingresar ambos números antes de realizar las operaciones. Actualmente los numeros introducidos son A = %d y B = %d. \n", primerOperando, segundoOperando);
            }
            break;

            case 4:
            if(flagCalculoOperaciones == 1)
            {

                printf("El resultado de %d + %d es: %d\n" ,primerOperando, segundoOperando, sumaOperandos);
                printf("El resultado de %d - %d es: %d\n" ,primerOperando, segundoOperando, restaOperandos);
                if(segundoOperando == 0)
                {
                    printf("Dividir por 0 no es posible, por lo cual no se encontro ningun resultado\n");
                }
                else
                {
                    printf("El resultado de %d/%d es: %f\n" ,primerOperando, segundoOperando, divisionOperandos);
                }
            printf("El resultado de %d*%d es: %d\n" ,primerOperando, segundoOperando, multiplicacionOperandos);
            printf("El factorial de %d es: %d y el factorial de %d es: %d \n \n" ,primerOperando, factorialPrimerOperando, segundoOperando, factorialSegundoOperando) ;

            flagCalculoOperaciones = 0;
            }
            else
            {

                printf("No se pueden mostrar los resultados porque A: Aún no se han realizado los cálculos o B: Debe volver a realizar los cálculos. \n");
            }
            break;

            case 5:
            break;

            default:

            printf("La opción que ha ingresado es inválida. Por favor, reingrese la opción. \n");
            break;

        }

    }while(opcion != 5);

}

