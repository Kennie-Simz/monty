#include "monty.h"

/**
 * rotr - rotates bottom to the top once
 * @stark: given stack
 * @line_num: line number, unused
 * Return: void
 *
 **/

void rotr(stack_t **stark, __attribute__((unused))unsigned int line_num)
{
	stack_t *reversed;

	if(stark == NULL || *stark == NULL || (*stark)->next == NULL)
		return;

	reversed = *stark;

	while (reversed->next != NULL)
		reversed = reversed->next;
	reversed->next = *stark;
	reversed->prev->next = NULL;
	reversed->prev = NULL;
	(*stark)->prev = reversed;
	*stark = reversed;
}

