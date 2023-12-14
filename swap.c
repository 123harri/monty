#include "monty.h"

/**
 * swap_opcode - Swaps the top two elements of the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the file
 */
void swap_opcode(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		cleanup_and_exit(*stack);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
