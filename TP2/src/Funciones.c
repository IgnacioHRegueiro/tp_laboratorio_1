/*
 * Funciones.c
 *
 *  Created on: 13 may. 2021
 *      Author: Ignacio Regueiro
 */


#include "Input.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}eEmployee;

int Menu(void)
{
    int option;
    printf("1. ALTA\n");
    printf("2. BAJA\n");
    printf("3. MODIFICACION\n");
    printf("4. INFORMAR\n");
    printf("5. SALIR\n");
    printf("Ingrese su opcion: \n");
    scanf("%d", &option);

    return option;
}

int subMenu(void)
{
    int option;
    printf("1. LISTADO DE EMPLEADOS \n");
    printf("2. TOTAL/PROMEDIO DE SALARIOS \n");
    printf("3. VOLVER AL MENU PRINCIPAL\n");
    scanf("%d", &option);

    return option;
}


void InitEmployees(eEmployee *employee, int len)
{
    int i;

    for(i=0;i<len;i++)
    {
        (employee+i)->isEmpty = 0;
    }
}

int SearchFree(eEmployee *employee, int len)
{
    int index;
    int i;

    index = -1;

    for(i=0;i<len;i++)
    {
        if((employee+i)->isEmpty == 0)
        {
            index = i;
        }
    }

    return index;
}

eEmployee GetEmployee(eEmployee *oldEmployee, int len)
{
    eEmployee employee;
    int i;

    employee.id = 0;

    for(i=0;i<len;i++)
    {
        if(employee.id == (oldEmployee+i)->id )
        {
            employee.id = employee.id + 1;
        }
    }

    GetString("Ingrese el nombre del empleado: \n", employee.name);

    GetString("Ingrese el apellido del empleado: \n", employee.lastName);

    employee.salary = GetFloat("Ingrese el salario del empleado: \n");

    employee.sector = GetInt("Ingrese el sector del empleado (1-10): \n");
    employee.sector = ValidateRange("Error : Reingrese el sector del empleado (1-10): \n", 10, 1, employee.sector);

    return employee;

}


int AddEmployee(eEmployee *employee, int len)
{
    int index;

    index = SearchFree(employee, len);

    if(index != -1)
    {
        *(employee+index) = GetEmployee(employee, len);
        (employee+index)->isEmpty = 1;
    }
    else
    {
        printf("No hay espacio disponible: \n");
    }


    return 1;
}



int FindEmployeeById(eEmployee *employee, int len, int id)
{
    int i;
    int index;

    index = -1;

    for(i=0;i<len;i++)
    {
        if(id == employee[i].id)
        {
            index = i;
        }
    }

    return index;
}

int RemoveEmployee(eEmployee *employee, int len, int id)
{
    int index;
    int control = 0;

    index = FindEmployeeById(employee, len, id);

    if(index != -1)
    {
        (employee+index)->isEmpty = 0;
        printf("Se ha dado de baja correctamente. \n");
        control = -1;
    }
    else
    {
        printf("Error. ID Inválido.\n");
    }

    return control;
}

void ModifyEmployee(eEmployee *employee, int len, int id)
{
    int index;
    int option;

    index = FindEmployeeById(employee, len, id);
    if(index != -1)
    {
        option = GetInt("Ingrese el campo a modificar: 1. NOMBRE, 2. APELLIDO, 3. SALARIO, 4. SECTOR: \n");
        option = ValidateRange("Opción inválida. Reingrese el campo a modificar: 1. NOMBRE, 2. APELLIDO, 3. SALARIO, 4. SECTOR: \n", 4, 1, option);


        switch(option)
        {
            case 1:
            GetString("Ingrese el nombre actualizado del empleado: \n", (employee+index)->name);
            printf("Modifación exitosa.");
            break;

            case 2:
            GetString("Ingrese el apellido actualizado del empleado: \n", (employee+index)->lastName);
            printf("Modifación exitosa.");
            break;

            case 3:
            (employee+index)->salary = GetFloat("Ingrese el salario actualizado del empleado: \n");
            printf("Modifación exitosa.");
            break;

            case 4:
            (employee+index)->sector = GetInt("Ingrese el sector actualizado del empleado (1-10): \n");
            printf("Modifación exitosa.");
            break;
        }
    }
    else
    {
        printf("Ha ingresado un ID inválido. \n");
    }


}

void SortEmployees(eEmployee *employee, int len)
{
    int i;
    int j;
    eEmployee aux;

    for (i=0; i<len - 1; i++)
	{
		for (j = i+1; j<len; j++)
		{
			if ((employee+i)->sector > (employee+j)->sector)
			{
				aux = employee[i];
				employee[i] = employee[j];
				employee[j] = aux;
			}
		}
	}
}

void PrintEmployees(eEmployee *employee, int len)
{
    int i;
    printf("LISTADO DE EMPLEADOS \n");
    for(i = 0; i<len; i++)
    {
        if((employee+i)->isEmpty != 0)
        {
            printf("ID: %d; NOMBRE: %s; APELLIDO: %s; SALARIO: %f; SECTOR: %d \n", (employee+i)->id, (employee+i)->name, (employee+i)->lastName, (employee+i)->salary, (employee+i)->sector);
        }
    }
}

void PrintEmployeesBySector(eEmployee *employee, int len)
{
    int i;
    int j;

    int validate;

    validate = 1;

    for(i=0;i<len;i++)
    {
        if((employee+i)->isEmpty == 1 && (employee+i)->sector != (employee+validate)->sector)
        {
            printf("Sector : %d\n", (employee+i)->sector);
            for(j=0;j<len;j++)
            {
                if((employee+i)->sector == (employee+j)->sector)
                {
                   printf("%s\n", (employee+j)->lastName);

                }

            }
        }

        validate++;
    }
}

float TotalSalaries(eEmployee *employee, int len)
{
    int i;
    float accSalaries;
    accSalaries = 0;

    for (i = 0; i<len; i++)
    {
        if((employee+i)->isEmpty != 0)
        {
            accSalaries += (employee+i)->salary;
        }
    }

    return accSalaries;
}


float AverageSalary(eEmployee *employee, int len, int totalEmployees)
{
    float accSalaries;
    float averageSalary;

    accSalaries = TotalSalaries(employee, len);

    averageSalary = accSalaries / totalEmployees;

    return averageSalary;
}

int EmployeesAboveAverage(eEmployee *employee, int len, int totalEmployees)
{
    int i;
    int totalAboveAverage;
    float averageSalary;

    averageSalary=AverageSalary(employee, len, totalEmployees);

    totalAboveAverage = 0;

    for (i=0; i<len; i++)
    {
        if((employee+i)->salary > averageSalary && (employee+i)-> isEmpty != 0)
        {
            totalAboveAverage++;
        }
    }

    return totalAboveAverage;
}



void PrintSalaryData(eEmployee *employee, int len, int TotalEmployees)
{

    float accSalaries;
    float averageSalary;
    int employeesAboveAverage;

    accSalaries = TotalSalaries(employee, len);
    averageSalary = AverageSalary(employee, len, TotalEmployees);
    employeesAboveAverage = EmployeesAboveAverage(employee, len, TotalEmployees);

    printf("El total entre todos los salarios de los empleados es: %f \n", accSalaries);
    printf("El salario promedio entre los empleados es de %f: \n", averageSalary);
    printf("La cantidad de empleados con un salario por encima del promedio es:  %d \n", employeesAboveAverage);
}







