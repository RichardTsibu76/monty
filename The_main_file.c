#include "monty.h"
/**
 * main - This functions cover the pro monty interpreter
 * @argc: The arguments passed
 * @argv: arguments vector
 * Return: EXIT_SUCCESS on 0, else failure
 */

int main(int argc, char **argv)
{
	ssize_t file_des, read_checkb, i, j, read_to_left;
	unsigned int line = 0;
	char *file_name, buffer[MAX_LENGTH], *copy_buffer, *comd;
	stack_t *top = NULL;

	file_des = intial_check(argc, argv);
	file_name = argv[1];
	read_checkb = read(file_des, buffer, MAX_LENGTH);
	if (read_checkb == -1)
	{
		fprintf(stderr, "Error: Can't read file %s\n", file_name);
		return (EXIT_FAILURE);
	}
	for (i = 0, j = 0; i < read_checkb; i++, j++)
	{
		if (buffer[i] == '\n')
		{
			copy_buffer = malloc((i + 1) * sizeof(char));
			if (copy_buffer == NULL)
			{
				fprintf(stderr, "Error: malloc failed\n");
				return (EXIT_FAILURE);
			}
			strncpy(copy_buffer, buffer, j);
			copy_buffer[j] = '\0';
			line++;
			comd = strtok(copy_buffer, " \t");/*The part of tokenization*/
			if (comd)
				cmd_caller(comd, line, &top);
			free(copy_buffer);/*freeing the buffer copy */
			read_to_left = read_checkb - (i + 1);
			read_checkb = read_to_left;
			memmove(buffer, buffer + i + 1, read_checkb);
			i = -1;
			j = -1;
		}
	}
	free_all(&top);
	close(file_des);
	return (EXIT_SUCCESS);
}
