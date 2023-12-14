#include "monty.h"

/**
 * stack_opcode - Sets the format of the data to a stack (LIFO)
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the file
 */
void stack_opcode(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}

/**
 * queue_opcode - Sets the format of the data to a queue (FIFO)
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the file
 */
void queue_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;
	stack_t *second_last = NULL;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}

	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}
