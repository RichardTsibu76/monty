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
	int index_checker = 0;

	instruction_t call[] = {
		{"push", push},/*the various instruction*/
		{"pall", pall},/*we are writing interpreter for*/
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
	for (index_checker = 0; call[index_checker].opcode != NULL; index_checker++)
	{
		if (strcmp(call[index_checker].opcode, cmd) == 0)
		{
			call[index_checker].f(top, line);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line, cmd);
	exit(EXIT_FAILURE);
}
