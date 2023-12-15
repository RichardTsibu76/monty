#include "monty.h"
/**
 * check_malloc - Checks for memory allocation using malloc
 * Return: Nothing, its a void keyword
 */
void check_malloc(void)
{
/* the fprint is used to write to the stderr*/
	fprintf(stderr, "Error: malloc failed\n");
/* it exits with this exit failure*/
	exit(EXIT_FAILURE);
}
