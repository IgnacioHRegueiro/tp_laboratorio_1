#include "LinkedList.h"

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();

int employee_setId(Employee* employee,int id);
int employee_getId(Employee* employee,int* id);

int employee_setNombre(Employee* employee,char* nombre);
int employee_getNombre(Employee* employee,char* nombre);

int employee_setHorasTrabajadas(Employee* employee,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* employee,int* horasTrabajadas);

int employee_setSueldo(Employee* employee,int sueldo);
int employee_getSueldo(Employee* employee,int* sueldo);

int employee_sortByName(void* employee1, void* employee2);
int employee_getIndexById(LinkedList*, int);

int GetMaxId(char* path, LinkedList* pArrayEmployee);
void SaveMaxId(char* path, int maxId);



int Menu(void);
#endif // employee_H_INCLUDED
