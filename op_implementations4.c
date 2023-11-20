#include "monty.h"

/**
  *c_rotl - function rotates the stack to top
  *@stack: Pointer to top of stack
  *@line_num: line number of file
  */

void c_rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;
	int val;

	(void)line_num;

	tmp = *stack;
	if (tmp != NULL)
		val = tmp->n;
	while (tmp != NULL)
	{
		if (tmp->next != NULL)
		{
			tmp->n = tmp->next->n;
		}
		else
		{
			tmp->n = val;
		}
		tmp = tmp->next;
	}
}

/**
 * c_rotr - function that rotates the stack to the bottom
 * @stack: pointer to the stack
 * @line_num: line number in the file
 */
void c_rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *l_Node;

	(void)line_num;
	if (stack == NULL ||*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	l_Node = *stack;
	while (l_Node->next != NULL)
	{
		l_Node = l_Node->next;
	}
	l_Node->prev->next = NULL;
	l_Node->prev = NULL;
	l_Node->next = *stack;
	(*stack)->prev = l_Node;
	*stack = l_Node;
}
