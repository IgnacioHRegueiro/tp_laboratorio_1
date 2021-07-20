#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "input.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{


	int exito;
	exito = 0;



	if(path != NULL && pArrayListEmployee != NULL)
	{
		if(parser_EmployeeFromText(path, pArrayListEmployee) == 1)
		{
			printf("Se han cargado los datos con éxito \n");
			exito = 1;
		}
		else
		{
			printf("No se han podidos cargar los datos \n");
		}
	}
	else
	{
		printf("No se han podido cargar los datos \n");
	}

	return exito;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int exito = 0;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		if(parser_EmployeeFromBinary(path, pArrayListEmployee) == 1)
		{
			printf("Se han cargado los datos con éxito \n");
			exito = 1;
		}
		else
		{
			printf("No se han podidos cargar los datos \n");
		}
	}
	else
	{
		printf("No se han podido cargar los datos \n");
	}

	return exito;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int maxId)
{
	int exito = 0;
	if(pArrayListEmployee != NULL)
	{
		Employee* employee;
		char temp [50];
		employee = employee_new();




		employee->id = maxId+1;

		GetStringSoloLetras("Ingrese el nombre del empleado \n", employee->nombre);

		employee->nombre[0] = toupper(employee->nombre[0]);

		GetStringSoloNumeros("Ingrese las horas trabajadas del empleado: \n", temp);
		employee_setHorasTrabajadas(employee, atoi(temp));

		GetStringSoloNumeros("Ingrese el sueldo del empleado: \n ", temp);
		employee_setSueldo(employee, atoi(temp));

		ll_add(pArrayListEmployee, employee);
		exito = 1;
	}





    return exito;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int exito = 0;
	if(pArrayListEmployee != NULL)
	{
		int opcion;
		int searchId;
		int indice;
		char temp[25];

		Employee* modifiedEmployee;
		modifiedEmployee = employee_new();

		searchId = GetInt("Ingrese el id del empleado a modificar: \n");
		indice = employee_getIndexById(pArrayListEmployee, searchId);

		if(indice != -1)
		{
			printf("Se ha encontrado al empleado \n");
			exito = 1;

			modifiedEmployee = ll_get(pArrayListEmployee, indice);
			do
			{
			opcion = GetInt("¿Qué dato desea modificar? (1 para NOMBRE, 2 para HORAS TRABAJADAS, 3 para SUELDO, 4 para TERMINADO: \n");
			switch(opcion)
				{
					case 1:
						GetStringSoloLetras("Ingrese el nombre modificado del empleado \n", temp);
						employee_setNombre(modifiedEmployee, temp);
					break;
					case 2:
						GetStringSoloNumeros("Ingrese las horas trabajadas modificadas del empleado: \n", temp);
						employee_setHorasTrabajadas(modifiedEmployee, atoi(temp));
					break;
					case 3:
						GetStringSoloNumeros("Ingrese el sueldo modificado del empleado: \n ", temp);
						employee_setSueldo(modifiedEmployee, atoi(temp));
					break;
					case 4:

						ll_set(pArrayListEmployee, indice, modifiedEmployee);
						break;
					default:
						printf("Opción inválida \n");
					break;
				}
			}while(opcion != 4);
		}
		else
		{
			printf("Ha ingresado un ID inválido");
		}
	}
	return exito;
}



/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int exito = 0;
	if(pArrayListEmployee != NULL)
	{
		int searchId;
		int indice;


		searchId = GetInt("Ingrese el id del empleado a eliminar: \n");
		indice = employee_getIndexById(pArrayListEmployee, searchId);

		if(indice != -1)
		{
			ll_remove(pArrayListEmployee, indice);
			exito = -1;
		}
		else
		{
			printf("Ha ingresado un ID inválido. \n");
		}
	}

    return exito;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int exito = 0;
	if(pArrayListEmployee != NULL)
	{
		int len;
		Employee* aux;
		aux = (Employee*) malloc(sizeof(Employee));
		len = ll_len(pArrayListEmployee);

		for(int i = 0; i<len; i++)
		{
			aux = (Employee*) ll_get(pArrayListEmployee, i);
			printf("ID: %d, NOMBRE: %s, HORAS TRABAJADAS: %d, SUELDO: %d \n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
		}
		exito = 1;
	}

    return exito;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int exito = 0;
	if(pArrayListEmployee != NULL)
	{
		exito = 1;
		ll_sort(pArrayListEmployee, employee_sortByName, 1);
	}
    return exito;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int exito = 0;

	if(path != NULL && pArrayListEmployee!=NULL)
	{
		FILE* pFile;
		int len;
		Employee* aux;
		len = ll_len(pArrayListEmployee);

		pFile = fopen(path, "w");

		for(int i = 0; i<len; i++)
		{
			aux = (Employee*)ll_get(pArrayListEmployee, i);
			fprintf(pFile, "%d,%s,%d,%d \n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
		}

		fclose(pFile);

		exito = 1;
	}
    return exito;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int exito = 0;
	if(path != NULL && pArrayListEmployee)
	{

		FILE* pFile;
		Employee* employee;
		employee = (Employee*)malloc(sizeof(Employee*));
		int len;

		len = ll_len(pArrayListEmployee);

		pFile = fopen(path, "wb");

		for (int i = 0; i<len; i++)
		{
			employee = (Employee*)ll_get(pArrayListEmployee, i);
			fwrite(employee,sizeof(Employee),1,pFile);
		}

		exito = 1;
		fclose(pFile);

	}

    return exito;
}

