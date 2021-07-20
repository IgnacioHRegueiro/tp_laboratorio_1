#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(char* path , LinkedList* pArrayListEmployee)
{
	int exito;
	exito = 0;

		if(path!=NULL && pArrayListEmployee != NULL)
		{

			char id[50];
			char nombre[128];
			char horasTrabajadas[50];
			char sueldo[50];


			FILE* pFile;
			Employee* employee;
			pFile = fopen(path,"r");

			 while(!feof(pFile))
			{
				fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",id, nombre, horasTrabajadas,sueldo);
				employee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
				ll_add(pArrayListEmployee, employee);
			}

			fclose(pFile);
			exito = 1;
		}

	return exito;

}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(char* path , LinkedList* pArrayListEmployee)
{

	int exito;
	exito = 0;

		if(path!=NULL && pArrayListEmployee != NULL)
		{

			FILE* pFile;
			Employee* employee;

			int i = 0;


			ll_clear(pArrayListEmployee);

			pFile = fopen(path,"rb");

			if(pFile != NULL)
			{
				while(!feof(pFile))
				{
					employee = employee_new();
					if(fread(employee,sizeof(Employee),1,pFile)==1)
					{
						ll_add(pArrayListEmployee, employee);
						i++;
					}

				}
				exito = 1;
			}

			else
			{
				printf("El archivo .bin no existe. \n");
			}
			fclose(pFile);

		}

		else
		{

		}

	return exito;

}
