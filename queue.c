#include "monty.h"

/**
 * add_node_to_queue - Adds a new node to the end of the queue
 * @stack: Pointer to the head of the queue
 * @value: Value to be added to the new node
 */
void add_node_to_queue(stack_t **stack, int value)
{
	stack_t *last = *stack;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		cleanup_and_exit(*stack);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*stack == NULL)
	{
		*stack = new_node;
		return;
	}

	while (last->next)
		last = last->next;

	last->next = new_node;
	new_node->prev = last;
}
