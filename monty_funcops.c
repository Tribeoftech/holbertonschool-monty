#include "monty.h"

/**
 * push - Adds values to the top of the stack
 * @stack: Head of the stack
 * fix on github
 * @line_number: Line number of monty file
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *top = NULL;

	(void)line_number;
	top = (*stack);
	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_list(global_variable.stack);
		fclose(global_variable.file);
		exit(EXIT_FAILURE);
	}

	top->n = atoi(global_variable.number);
	top->next = *stack;
	top->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = top;
	*stack = top;

}


/**
 * pall - print all function
 * @stack: pointer to linked list stack
 * @line_number: number a line opcode occurs on
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *printem;

	printem = (*stack);
	(void) line_number;
	while (printem != NULL)
	{
		printf("%d\n", printem->n);
		printem = printem->next;
	}
}


/**
 * pop - remvove element a list
 * @stack: pointer to first node
 * @line_number: integer
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *c_ya = NULL;

	(void) line_number;
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_list(global_variable.stack);
		fclose(global_variable.file);
		exit(EXIT_FAILURE);
	}
	while (c_ya->prev != NULL)
	{
		c_ya = c_ya->prev;
	if (c_ya->next != NULL)
	{
		c_ya->next->prev = NULL;
	}
	if (c_ya == *stack)
	{
		if ((*stack)->next != NULL)
		{
			(*stack) = (*stack)->next;
		}
		else
		{
			(*stack) = NULL;
		}
	}
	free(c_ya);
	}
}

/**
 * pint - Prints value at the top of the stack + newline
 * @stack: Struct stack_s as stack_t **ptr
 * @line_number: File line number
 * Return: Nothing (void)
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	if (stack == NULL || (*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_list(global_variable.stack);
		fclose(global_variable.file);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*stack)->n);
}
