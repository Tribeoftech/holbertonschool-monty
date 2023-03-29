#include "monty.h"

/*global_var global_variable;*/

/**
 * free_list - free dll
 * @stack: head of the dll
 * Return: 0 or 1
 *
 */
void free_list(stack_t *stack)
{
	stack_t *new = stack;

	if (stack == NULL)
		return;
	while (new)
	{
		stack = stack->next;
		free(new);
		new = stack;
	}
	stack = NULL;
}
