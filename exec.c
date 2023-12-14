#include "monty.h"
/**
 * execute_opcode - Executes the opcode
 * @line_content: Line content
 * @stack_head: Head of the linked list (stack)
 * @line_number: Line number
 * @monty_file: Pointer to the Monty file
 * Return: No return
 */
int execute_opcode(char *line_content, stack_t **stack_head,
		unsigned int line_number, FILE *monty_file)
{
	instruction_t opcodes[] = {
		{"push", push_opcode}, {"pall", pall_opcode},
		{NULL, NULL}
	};
	unsigned int index = 0;
	char *opcode;

	opcode = strtok(line_content, " \n\t");
	if (opcode == NULL || opcode[0] == '#')
		return (0);

	bus.argument = strtok(NULL, " \n\t");

	while (opcodes[index].opcode != NULL)
	{
		if (strcmp(opcode, opcodes[index].opcode) == 0)
		{
			opcodes[index].f(stack_head, line_number);
			return (0);
		}
		index++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	fclose(monty_file);
	free(line_content);
	free_stack(*stack_head);
	exit(EXIT_FAILURE);

	return (1);
}
