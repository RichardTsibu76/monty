#include "monty.h"
/**
 * add - Adds the top two elements
 * @stack: This points to the stack
 * @line_number: number line
 * Return: Nothing, its void
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * nop - This is an operation code
 * @stack: pointer
 * @line_number: number line
 * Return: Nothing its void
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - This works the difference on the stack
 * @stack: pointer
 * @line_number: Line number
 * Return: Nothing, its void
 */
void sub(stack_t **stack, unsigned int line_number)
{

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
/*	result = ((*stack)->next->n - ((*stack)->n)) * -1; */
/*	(*stack)->next->n = result */
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}

/**
 * div - Operation code that divides the top elements
 * @stack: Pointer
 * @line_number: Line number
 * Return: Returns nothing its void keyword
 */

void div(stack_t **stack, unsigned int line_number)
{

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE); /*exit with is this*/
	}
/*still having acess to the nest*/
/*	result = ((*stack)->n / (*stack)->next->n);*/
/*	(*stack)->next->n = result; */
	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mul - Multiplies
 * @stack: This points to the stack
 * @line_number: line num
 * Return: Nothing
 */

void mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
