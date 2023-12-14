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
		{"pint", pint_opcode}, {"pop", pop_opcode},
		{"swap", swap_opcode}, {"add", add_opcode},
		{"nop", nop_opcode}, {"sub", sub_opcode},
		{"div", div_opcode}, {"pchar", pchar_opcode},
		{"mul", mul_opcode}, {"mod", mod_opcode},
		{"pstr", pstr_opcode}, {"rotl", rotl_opcode},
		{"rotr", rotr_opcode}, {"stack", stack_opcode},
		{"queue", queue_opcode},
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
