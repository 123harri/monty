#include "monty.h"

/**
 * mul_opcode - Multiplies the second top element with
 * the top element of the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the file
 */
void mul_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *top1 = *stack;
	stack_t *top2 = top1->next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		cleanup_and_exit(*stack);
	}

	top2->n *= top1->n;
	*stack = top2;
	(*stack)->prev = NULL;

	free(top1);
}
