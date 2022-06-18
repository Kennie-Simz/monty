#include "monty.h"

/**
 * pstr - prints string
 * @stark: given stack
 * @line_num:line number, unused
 * Return: void
 *
 **/

void pstr(stack_t **stark, __attribute__((unused)) unsigned int linenum)
{
	stack_t *str;

	if (stark == NULL || *stark == NULL || variables.holder == 0)
	{
		printf("\n");
		return;
	}

	str = *stark;

	while (str != NULL && str->n != 0 && isascii( (str->n) ))
	{
		printf("%c", str->n);
		str = str->next;
	}
	printf("\n");
}
