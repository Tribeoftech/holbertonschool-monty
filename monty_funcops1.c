#include "monty.h"

/**
 * swap - switch the top of the stack with second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: the number the line opcode occers on
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *switcher;
	int now;

	switcher = (*stack);
	if (!switcher || switcher->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_list(global_variable.stack);
		fclose(global_variable.file);
		exit(EXIT_FAILURE);
	}
	now = switcher->n;
	switcher->n = switcher->next->n;
	switcher->next->n = now;
}

/**
 * add - add top the top of stack with top of second stack
 * @stack: pointer to lists for monty stack
 * @line_number: number line opcode occurs on
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *now = *stack;
	int sum = 0, i = 0;

	if (now == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_list(global_variable.stack);
		fclose(global_variable.file);
		exit(EXIT_FAILURE);
	}

	while (now)
	{
		now = now->next;
		i++;
	}
	if (stack == NULL || (*stack)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	pop(stack, line_number);

	(*stack)->n = sum;
}


/**
 * nop - nop top of stack
 * @stack: pointer to list for monty stack
 * @line_number: number of line opcode occurs on
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
