/*
 ============================================================================
 Name        : TP2
 Author      : Regueiro Ignacio
 ============================================================================
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Funciones.h"
#include "Input.h"
#define LEN 5
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);



    int option;
    int subOption;
    int id;
    int totalEmployees;

    totalEmployees = 0;
    eEmployee employee [LEN];
    InitEmployees(employee, LEN);


    do
    {
        option = Menu();

        switch(option)
        {
            case 1:
            totalEmployees += AddEmployee(employee, LEN);

            break;

            case 2:
            if(totalEmployees > 0)
            {
                PrintEmployees(employee, LEN);
                id = GetInt("Ingrese el ID del empleado a dar de baja: \n ");
                totalEmployees += RemoveEmployee(employee, LEN, id);
            }
            else
            {
                printf("No se puede dar de baja un empleado porque no hay ninguno cargado.\n");
            }
            break;

            case 3:
            if(totalEmployees > 0)
            {
                PrintEmployees(employee, LEN);
                id = GetInt("Ingrese el ID del empleado a modificar: \n");
                ModifyEmployee(employee, LEN, id);
            }
            else
            {
                 printf("No se puede modificar un empleado porque no hay ninguno cargado. \n");
            }
            break;

            case 4:
            if(totalEmployees > 0)
            {
                do
                {
                    subOption = subMenu();
                    switch(subOption)
                    {
                        case 1:
                        SortEmployees(employee, LEN);
                        PrintEmployeesBySector(employee, LEN);
                        break;

                        case 2:
                        PrintSalaryData(employee, LEN, totalEmployees);
                        case 3:
                        break;

                        default:
                        printf("Opción inválida. \n");
                        break;
                    }
                }while(subOption != 3);
            break;

            default:
            printf("Opción inválida. \n");
            break;
            }
            else
            {
                 printf("No se pueden mostrar los informes porque no hay ningún empleado cargado. \n");
            }


        }



    }while(option != 5);

    return 0;
}


