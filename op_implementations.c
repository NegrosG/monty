#include "monty.h"

/**
 * c_push - Pushes a new element onto the stack.
 * @stack: A pointer to the top of the stack.
 * @line_num: The line number in the Monty bytecode file
 * where the push operation is called.
 */

void c_push(stack_t **stack, unsigned int line_num)
{
	char *arg = strtok(NULL, " \n\t");
	int n;
	stack_t *new_node;

	if (arg == NULL || !is_num(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	n = atoi(arg);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * is_num - Function to check if a string is a number
 * @str: string to check
 * Return: 0 if it's not a number and 1 if it's a number
 */

int is_num(char *str)
{
	int x;

	for (x = 0; str[x]; x++)
	{
		if (str[x] == ' ' || str[x] == '\n')
			continue;
		if (!isdigit(str[x]))
			return (0);
	}
	return (1);
}

/**
 * c_pall - Pushes a new element onto the stack.
 * @stack: A pointer to the top of the stack.
 * @line_num: The line number in the Monty bytecode file
 * where the push operation is called.
 */

void c_pall(stack_t **stack, unsigned int line_num)
{
	stack_t *curr_node;

	(void) line_num;
	curr_node = *stack;

	while (curr_node)
	{
		printf("%d\n", curr_node->n);
		curr_node = curr_node->next;
	}
}

/**
 * c_pint - Pushes a new element onto the stack.
 * @stack: A pointer to the top of the stack.
 * @line_num: The line number in the Monty bytecode file
 * where the push operation is called.
 */

void c_pint(stack_t **stack, unsigned int line_num)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * c_pop - Pushes a new element onto the stack.
 * @stack: A pointer to the top of the stack.
 * @line_num: The line number in the Monty bytecode file
 * where the push operation is called.
 */

void c_pop(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack)
	{
		(*stack)->prev = NULL;
	}

	free(temp);
}

