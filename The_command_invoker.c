#include "monty.h"

/**
 * cmd_caller - This is a funcptr that calls for cmd
 * @cmd: command to executes
 * @line: The line number
 * @top: first of data elements
 * Return: returns
 */
void cmd_caller(char *cmd, unsigned int line, stack_t **top)
{
	int idx = 0;

	instruction_t call[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (cmd[0] == '#')
		return;
	for (idx = 0; call[idx].opcode != NULL; idx++)
	{
		if (strcmp(call[idx].opcode, cmd) == 0)
		{
			call[idx].f(top, line);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line, cmd);
	exit(EXIT_FAILURE);
}
