/*
 * Input.h
 *
 *  Created on: 13 may. 2021
 *      Author: Ignacio Regueiro
 */

#include <stdlib.h>
#include <string.h>



#ifndef INPUT_H_
#define INPUT_H_

int GetInt(char *);
void GetString(char *, char *);
float GetFloat(char *);
int ValidateRange(char *, int, int, int);


#endif /* FUNCIONES_H_ */
