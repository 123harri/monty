#include "monty.h"

/**
 * rotl_opcode - Rotates the stack to the top
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the file
 */
void rotl_opcode(stack_t **stack, unsigned int line_number)
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

/**
 * rotr_opcode - Rotates the stack to the bottom
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the file
 */
void rotr_opcode(stack_t **stack, unsigned int line_number)
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
