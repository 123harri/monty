#define _POSIX_C_SOURCE 200809L
#include "monty.h"

bus_t bus = {NULL, NULL, NULL};

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	char *line_content;
	FILE *monty_file;
	size_t buffer_size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	bus_t bus = {NULL, NULL, NULL};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	monty_file = fopen(argv[1], "r");
	bus.file = monty_file;

	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read_line > 0)
	{
		line_content = NULL;
		read_line = getline(&line_content, &buffer_size, monty_file);
		bus.content = line_content;
		line_number++;

		if (read_line > 0)
		{
			execute_opcode(bus.content, &stack, line_number, monty_file);
		}

		free(line_content);
	}
	free_stack(stack);
	fclose(monty_file);
	return (0);
}
