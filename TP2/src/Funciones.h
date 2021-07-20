/*
 * Funciones.h
 *
 *  Created on: 13 may. 2021
 *      Author: Ignacio Regueiro
 */


#include <stdlib.h>
#include <string.h>



#ifndef FUNCIONES_H_
#define FUNCIONES_H_

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}eEmployee;

// Main menu
int Menu(void);

// 4th's option subMenu
int subMenu(void);

//Initializes "Empty" flag at zero.
void InitEmployees(eEmployee*, int);

//Searchs for a free index.
int SearchFree(eEmployee*, int);

//Requests the employee's data.
eEmployee GetEmployee(eEmployee*, int);

//Adds an employee to the list.
int AddEmployee(eEmployee*, int);



//Returns an employee's data searching it via ID.
int FindEmployeeById(eEmployee*, int, int);

// Removes an employee from the list by changing it's "Empty" flag to zero again.
int RemoveEmployee(eEmployee*, int, int);

// Modifies any camp (besides ID) of a selected employee.
void ModifyEmployee(eEmployee*, int, int);

//Sorts employees by sector.
void SortEmployees(eEmployee*, int);

// Prints the employee list.
void PrintEmployees(eEmployee*, int);

// Prints the employee list divided in sectors and sorted by lastname.
void PrintEmployeesBySector(eEmployee*, int);

// Returns the accumulated salary of all employees.
float TotalSalaries(eEmployee*, int);

// Returns the average salary between all employees.
float AverageSalary(eEmployee*, int, int);

// Returns how many employees have an above average salary.
int EmployeesAboveAverage(eEmployee*, int, int);

// Prints the accumulated and average salary of all employees, and how many of them have an above average salary.
void PrintSalaryData(eEmployee*, int, int);

#endif /* FUNCIONES_H_ */

