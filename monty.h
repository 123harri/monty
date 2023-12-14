#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - Structure to store shared data between functions
 * @file: File pointer to the Monty bytecode file
 * @content: Content of the Monty bytecode file
 * @argument: Argument passed to an opcode
 */
typedef struct bus_s
{
	FILE *file;
	char *content;
	char *argument;
} bus_t;

extern bus_t bus;

void push_opcode(stack_t **stack, unsigned int line_number);
void pall_opcode(stack_t **stack, unsigned int line_number);
void cleanup_and_exit(stack_t *stack);
void add_node_to_stack(stack_t **stack, int value);
void print_stack(stack_t *stack);
void free_stack(stack_t *stack);
int execute_opcode(char *line_content, stack_t **stack_head,
		unsigned int line_number, FILE *monty_file);
void pint_opcode(stack_t **stack, unsigned int line_number);
void pop_opcode(stack_t **stack, unsigned int line_number);
void swap_opcode(stack_t **stack, unsigned int line_number);
void add_opcode(stack_t **stack, unsigned int line_number);
void nop_opcode(stack_t **stack, unsigned int line_number);
void sub_opcode(stack_t **stack, unsigned int line_number);
void div_opcode(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
