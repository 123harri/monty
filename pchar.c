#include "monty.h"
/**
 * pchar_opcode - Prints the char at the top of the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the file
 */
void pchar_opcode(stack_t **stack, unsigned int line_number)
{
	int value = (*stack)->n;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		cleanup_and_exit(*stack);
	}

	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		cleanup_and_exit(*stack);
	}

	putchar(value);
	putchar('\n');
}
