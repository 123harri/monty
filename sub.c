#include "monty.h"

/**
 * sub_opcode - Subtracts the top element from
 * the second top element of the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the file
 */
void sub_opcode(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		cleanup_and_exit(*stack);
	}

	(*stack)->next->n -= (*stack)->n;
	pop_opcode(stack, line_number);
}
