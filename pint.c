#include "monty.h"

/**
 * pint_opcode - Prints the value at the top of the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the file
 */
void pint_opcode(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		cleanup_and_exit(*stack);
	}

	printf("%d\n", (*stack)->n);
}
