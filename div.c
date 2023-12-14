#include "monty.h"

/**
 * div_opcode - Divides the second top element
 * by the top element of the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the file
 */
void div_opcode(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		cleanup_and_exit(*stack);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		cleanup_and_exit(*stack);
	}

	(*stack)->next->n /= (*stack)->n;
	pop_opcode(stack, line_number);
}
