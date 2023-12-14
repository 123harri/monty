#include "monty.h"

/**
 * push_opcode - Pushes an element to the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the file
 */
void push_opcode(stack_t **stack, unsigned int line_number)
{
	int value, j = 0, flag = 0;

	if (!bus.argument)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		cleanup_and_exit(*stack);
	}

	if (bus.argument[0] == '-')
		j++;

	for (; bus.argument[j] != '\0'; j++)
	{
		if (bus.argument[j] < '0' || bus.argument[j] > '9')
		{
			flag = 1;
			break;
		}
	}

	if (flag == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		cleanup_and_exit(*stack);
	}

	value = atoi(bus.argument);
	if (bus.lifo == 0)
		add_node_to_stack(stack, value);
	else
		add_node_to_queue(stack, value);
}

/**
 * pall_opcode - Prints all values on the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Not used;
 */
void pall_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	(void)line_number;

	if (h == NULL)
		return;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * cleanup_and_exit - Clean up resources and exit
 * @stack: Pointer to the head of the stack
 */
void cleanup_and_exit(stack_t *stack)
{
	fclose(bus.file);
	free(bus.content);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * add_node_to_stack - Adds a new node to the stack
 * @stack: Pointer to the head of the stack
 * @value: Value to be added
 */
void add_node_to_stack(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		cleanup_and_exit(*stack);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * free_stack - Frees all nodes in the stack
 * @stack: Pointer to the head of the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{

		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
