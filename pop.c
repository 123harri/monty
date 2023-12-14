#include "monty.h"
/**
 * pop_opcode - Removes the top element of the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the file
 */
void pop_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		cleanup_and_exit(*stack);
	}

	*stack = top->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(top);
}
