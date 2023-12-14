#include "monty.h"
/**
 * swap_opcode - Swaps the top two elements of the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the file
 */
void swap_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *top1 = *stack;
	stack_t *top2 = top1->next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		cleanup_and_exit(*stack);
	}

	top1->next = top2->next;
	top2->prev = NULL;
	top2->next = top1;

	if (top1->next != NULL)
		top1->next->prev = top1;

	*stack = top2;
}
