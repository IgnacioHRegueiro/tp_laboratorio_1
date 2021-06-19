


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


int Menu(void)
{
    int option;
    printf("1. Cargar datos de empleados desde el archivo data.csv (modo texto) \n");
    printf("2. Cargar datos de empleados desde el archivo data.csv (modo binario) \n");
    printf("3. Alta del empleado \n");
    printf("4. Modificar datos del empleado\n");
    printf("5. Baja de empleados \n");
    printf("6. Listar empleados \n");
    printf("7. Ordenar empleados \n");
    printf("8. Guardar datos de los empleados en el archivo data.csv (modo texto)\n");
    printf("9. Guardar datos de los empleados en el archivo data.csv (modo binario) \n");
    printf("10. SALIR \n");
    printf("Ingrese su opcion: \n");
    scanf("%d", &option);

    return option;
}

Employee* employee_new()
{
	Employee* pEmployee;
	pEmployee = (Employee*) malloc(sizeof(Employee));

	return pEmployee;

}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* pEmployee;

	pEmployee = employee_new();

	pEmployee->id = atoi(idStr);
	strcpy(pEmployee->nombre, nombreStr);
	pEmployee->horasTrabajadas = atoi(horasTrabajadasStr);
	pEmployee->sueldo = atoi(sueldoStr);


	return pEmployee;
}
void employee_delete()
{

}

int employee_setId(Employee* employee,int id)
{
	int exito;
	exito = 0;
	if(employee != NULL)
	{
		employee->id = id;
		exito = 1;
	}
	return exito;
}
int employee_getId(Employee* employee,int* id)
{
	int exito;
	exito = 0;
	if(employee!= NULL && id != NULL)
	{
		*id = employee->id;
		exito = 1;
	}
	return exito;
}

int employee_getIndexById(LinkedList* pArrayListEmployee, int searchId)
{
	int index;
	index = -1;
	if(pArrayListEmployee != NULL)
	{
		int len;
		Employee* aux;

		len = ll_len(pArrayListEmployee);

		for (int i = 0; i<len; i++)
			{
				aux = ll_get(pArrayListEmployee, i);
				if(aux->id == searchId)
				{
					index = i;
				}
			}
	}
	return index;
}



int employee_setNombre(Employee* employee ,char* nombre)
{
	int exito;
	exito = 0;
	if(employee != NULL)
	{
		strcpy(employee->nombre, nombre);
		exito = 1;
	}
	return exito;
}
int employee_getNombre(Employee* employee,char* nombre)
{
	int exito;
	exito = 0;
	if(employee!= NULL && nombre != NULL)
	{
		strcpy(nombre, employee->nombre);
		exito = 1;
	}
	return exito;
}

int employee_setHorasTrabajadas(Employee* employee,int horasTrabajadas)
{
	int exito;
	exito = 0;
	if(employee != NULL)
	{
		employee->horasTrabajadas = horasTrabajadas;
		printf("%d \n", horasTrabajadas);
		exito = 1;
	}
	return exito;
}
int employee_getHorasTrabajadas(Employee* employee,int* horasTrabajadas)
{
	int exito;
	exito = 0;
	if(employee!= NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = employee->horasTrabajadas;
		exito = 1;
	}
	return exito;
}

int employee_setSueldo(Employee* employee,int sueldo)
{
	int exito;
	exito = 0;
	if(employee != NULL)
	{
		employee->sueldo = sueldo;
		exito = 1;
		printf("%d \n",sueldo);
	}
	return exito;
}
int employee_getSueldo(Employee* employee,int* sueldo)
{
	int exito;
	exito = 0;
	if(employee!= NULL && sueldo != NULL)
	{
		*sueldo = employee->sueldo;
		exito = 1;
	}
	return exito;
}


int employee_sortByName(void* employee1, void* employee2)
{
	int compare;
	Employee* aux1;
	aux1 = (Employee*)malloc(sizeof(Employee*));
	Employee* aux2;
	aux2 = (Employee*)malloc(sizeof(Employee*));


	aux1 = (Employee*)employee1;
	aux2 = (Employee*)employee2;

	if(employee1 != NULL && employee2 != NULL)
	{
		compare = strcmp(aux1->nombre, aux2->nombre);
	}

	return compare;
}
