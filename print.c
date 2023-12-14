#include "monty.h"

/**
 * print_stack - Prints all elements in the stack
 * @stack: Pointer to the head of the stack
 */
void print_stack(stack_t *stack)
{
	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}
