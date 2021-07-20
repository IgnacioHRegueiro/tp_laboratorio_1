#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

    int option = 0;
    int contadorEmpleados = 0;
    int maxId;
    int flagListaCargada;
    flagListaCargada = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	option = Menu();

        switch(option)
        {
            case 1:
            	if(flagListaCargada == 0)
            	{
                    controller_loadFromText("data.csv",listaEmpleados);
                    contadorEmpleados += ll_len(listaEmpleados);
                    flagListaCargada = 1;
            	}
                else
                {
                	printf("La lista ya está cargada \n");

                }
                break;
            case 2:

            	if(flagListaCargada == 0)
            	{
            		flagListaCargada = controller_loadFromBinary("data.bin", listaEmpleados);
					contadorEmpleados += ll_len(listaEmpleados);

            	}
            	else
            	{
            		printf("La lista ya está cargada \n ");

            	}
            	break;

 /* NOTA: Cargar un empleado antes de la lista LA PRIMERA VEZ que se ejecuta el programa es posible, sin errores en tiempo de ejecución, pero rompe el sistema de guardados de ID.
 Intenté evitar esto, pero cada solución generaba otro problema hasta que llegue a un punto en el que sencillamente no supe que hacer para seguir solucionando el problema.
 Si se carga primero la lista en la primera ejecución, el sistema de ID's funciona perfectamente.  */


            case 3:
            	maxId = GetMaxId("maxId.csv", listaEmpleados);
                contadorEmpleados += controller_addEmployee(listaEmpleados, maxId);
                maxId++;
                SaveMaxId("maxId.csv", maxId);
            	break;
            case 4:
                if(contadorEmpleados > 0)
                {
                	controller_editEmployee(listaEmpleados);
                }
            	else
            	{
            		printf("Error. Primero debe cargarse un empleado. \n");
            	}
            	break;
            case 5:
            	if(contadorEmpleados > 0)
            	{
            		contadorEmpleados += controller_removeEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("Error. Primero debe cargarse un empleado. \n");
            	}
            	break;
            case 6:
            	if(contadorEmpleados > 0)
            	{
            		controller_ListEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("Error. Primero debe cargarse un empleado. \n");
            	}
            	break;
            case 7:
            	if(contadorEmpleados > 0)
            	{
            		controller_sortEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("Error. Primero debe cargarse un empleado. \n");
            	}
            	break;
            case 8:
            	if(contadorEmpleados > 0)
            	{
            		controller_saveAsText("data.csv", listaEmpleados);

            	}
            	else
            	{
            		printf("Error. Primero debe cargarse un empleado. \n");
            	}
            	break;
            case 9:
            	if(contadorEmpleados > 0)
            	{
            		controller_saveAsBinary("data.bin", listaEmpleados);
            	}
            	else
            	{
            		printf("Error. Primero debe cargarse un empleado. \n");
            	}
            	break;
        }
    }while(option != 10);
    return 0;
}

