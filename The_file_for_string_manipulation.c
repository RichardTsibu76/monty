#include "monty.h"

/**
 * _strdup - This returns a newly allocated space in memory
 * @str: This is the formal parameter
 * Return: returns a pointer to duplicated string
 */

char *_strdup(char *str)
{
	int index = 0;
	char *dp;

	if (str == NULL)
	{
		dp = NULL;
		return (dp);
	}/*calling the malloc function to dynamically allocat mem*/
	dp = (char *) malloc((strlen(str) + 1) * sizeof(char));
	if (dp != NULL)
	{
		while (*str)
		{
			*(dp + index) = *(str);
			index++;
			str++;
		}
	}
	return (dp);
}

/**
 * free_all - Frees
 * @top: The top of stack
 * Return: Nothing its void
 */


void free_all(stack_t **top)
{
	stack_t *current_node = *top;
	stack_t *tmp = NULL;

	while (current_node)
	{
		tmp = current_node->next;
		free(current_node);
		current_node = tmp;
	}
}
