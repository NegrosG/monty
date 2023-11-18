#include "monty.h"
/**
  *c_sub - this function subtracts the top element of the stack
  *@stack: pointer to top of the stack
  *@line_num: line number in the Monty bytecode file
  */

void c_sub(stack_t **stack, unsigned int line_num)
{
	int subtraction;

	if (stack == NULL || *stack == NULL || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	subtraction = (*stack)->next->n - (*stack)->n;
	c_pop(stack, line_num);
	(*stack)->n = subtraction;
}

/**
  *c_mul - function mulitplies the second top element and the
  *top element of the stack
  *@stack: Pointer to top of the stack
  *@line_num: Line number in the Monty bytecode
  */

void c_mul(stack_t **stack, unsigned int line_num)
{
	int prod;

	if (stack == NULL || *stack == NULL || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	prod = (*stack)->next->n * (*stack)->n;
	c_pop(stack, line_num);
	(*stack)->n = prod;
}

/**
  *c_div - function divides the second top element by the top
  *@stack: Pointer to top of the stack
  *@line_num: line number in the Monty bytecode
  */

void c_div(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	c_pop(stack, line_num);
}

/**
  *c_pstr - function print string starting at the top of stack
  *@stack: Pointer to top of the stack
  *@line_num: line number is the Monty bytecode
  */

void c_pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *str = *stack;

	(void)line_num;

	while (str != NULL && str->n > 0 && str->n < 128)
	{
		printf("%c", str->n);
		str = str->next;
	}
	printf("\n");
}

/**
 * c_pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: A pointer to the top of the stack.
 * @line_num: The line number in the Monty bytecode file
 * where the push operation is called.
 */

void c_pchar(stack_t **stack, unsigned int line_num)
{
	int ascii_val;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	ascii_val = (*stack)->n;

	if (ascii_val < 0 || ascii_val > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", ascii_val);
}

