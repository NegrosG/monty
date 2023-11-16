#include "monty.h"

/**
  *c_swap - pushes a new element onto the stack
  *@stack: A pointer to the top of the stack
  *@line_num: The line number in the Monty bytecode file
  *where the push operation is called
  */
void c_swap(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next)
	{
		temp->next->prev = *stack;
	}

	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;

	*stack = temp;
}

/**
  *c_add - pushes a new element onto the stack.
  *@stack: A pointer to the top of the stack.
  *@line_num: The line number in the monty Bytecode file
  *where the push operation is called.
  */

void c_add(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: cant't add, stack too short\n", line_num);
		exit(EXIT_FAILURE)
	}

	(*stack)->next->n += (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	free(temp);
}

/**
  *c_nop - Pushes a new element onto the stack
  *@stack: A pointer to the top of the stack.
  *@line_num: The line number in the Monty bytecode file
  *where the push operation is called
  */

void c_nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}
