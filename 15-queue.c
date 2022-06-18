#include "monty.h"

/**
 * _queue - FIFO
 * @stark: given stack
 * @line_num: line number
 * @Return: void
 *
 **/
void _queue(stack_t **stark, unsigned int line_num)
{
	stack_t *new = NULL;
	stack_t *old = NULL;

	if (stark == NULL)
		exit(EXIT_FAILURE);
	
	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		free_stark(stark, line_num);
		exit(EXIT_FAILURE);
	}
	new->n = variables.holder;
	new->next = NULL;

	if (*stark == NULL)
	{
		new->prev = NULL;
		*stark = new;
		return;
	}

	old = *stark;

	while (old->next != NULL)
		old = old->next;

	old->next = new;
	new->prev = old;
	variables.holder = (*stark)->n;
}
