#include "monty.h"

/**
 * add_opcode - Adds the top two elements of the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the file
 */
void add_opcode(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		cleanup_and_exit(*stack);
	}

	(*stack)->next->n += (*stack)->n;
	pop_opcode(stack, line_number);
}
