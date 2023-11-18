#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
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

void c_push(stack_t **stack, unsigned int line_number);
void c_pall(stack_t **stack, unsigned int line_number);
void c_pint(stack_t **stack, unsigned int line_num);
void c_pop(stack_t **stack, unsigned int line_num);
void c_swap(stack_t **stack, unsigned int line_num);
void c_add(stack_t **stack, unsigned int line_num);
void c_nop(stack_t **stack, unsigned int line_num);
int is_num(char *str);
void c_mod(stack_t **stack, unsigned int line_num);
void c_sub(stack_t **stack, unsigned int line_num);
void c_mul(stack_t **stack, unsigned int line_num);
void c_div(stack_t **stack, unsigned int line_num);
void c_pstr(stack_t **stack, unsigned int line_num);
void c_pchar(stack_t **stack, unsigned int line_num);

void process_file(FILE *fp);
void cleanup(FILE *fp, char *line, stack_t **stack);
void free_stack(stack_t **stack);
#endif
