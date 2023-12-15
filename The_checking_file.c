#include "monty.h"


/**
 * intial_check - A function that checks for the main thing.
 * @argc: counts of arguments
 * @argv: pointer array
 * Return: returns
 */


ssize_t intial_check(int argc, char **argv)
{
	char *name_for_the_file;
	ssize_t fdescriptor;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	name_for_the_file = argv[1];
	fdescriptor = open(name_for_the_file, O_RDONLY);
	if (fdescriptor == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", name_for_the_file);
		exit(EXIT_FAILURE);
	}
	return (fdescriptor);
}

/**
 * is_digit - Coverts to ints
 * @value: Value at check
 * Return: either true or false
 */

bool is_digit(const char *value)
{
	char *endptr;

	strtol(value, &endptr, 10);
	return (*endptr == '\0');
}
