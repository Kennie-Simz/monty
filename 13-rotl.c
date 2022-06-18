#include "monty.h"

/**
 * rotl - rotates stack from top to bottom once
 * @stark: given stack
 * @line_num: line number, unused
 * Return: void
 *
 **/

void rotl(stack_t **stark, __attribute__((unused))unsigned int linenum)
{
	stack_t *new;

	if (stark == NULL || *stark == NULL || (*stark)->next == NULL)
		return;
	new = *stark;

	while (new->next != NULL)
		new = new->next;

	new->next = *stark;
	(*stark)->prev = new;
	*stark = (*stark)->next;
	(*stark)->prev = NULL;
	new->next->next = NULL;
}
		
