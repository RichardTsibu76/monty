#include "monty.h"


/**
* push - This operation adds data elements to the stack
* @stack: This points to the stack
* @line_number: line number
* Return: Nothing its void
*/

void push(stack_t **stack, unsigned int line_number)
{
	int number;
	char *the_str;
	stack_t *new_node;

	the_str = strtok(NULL, " \t\n");
	if (the_str == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!is_digit(the_str))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	number = atoi(the_str); /*coverting str to int*/

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = number;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
* pall - This is prints all
* @stack: pointer
* @line_number: line number
* Return: Nothing its void
*/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node;

	(void)line_number;
	current_node = *stack;

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}

/**
* pint - top value prints
* @stack: pointer to the stack under consideration
* @line_number: line number
* Return: Does not return
*/

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
* pop - removes
* @stack: pointee
* @line_number: ln number
* Return: Does not return
*/

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_node = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp_node);
}

/**
* swap - swaps the top elements
* @stack: double pointer to the stack
* @line_number: The line number
* Return: Does not return
*/

void swap(stack_t **stack, unsigned int line_number)
{
	int temp_node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp_node = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp_node;
}
