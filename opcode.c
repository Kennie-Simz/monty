#include "monty.h"

/**
 * _opcode - compares functions to tokens and executes them
 * @token: cmmand received
 * @stark: given stack
 * @line_num: line number
 * Return: void
 *
 **/

void _opcode(char *token, stack_t **stark, unsigned int line_num)
{
	int a = 0;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};

	if (strcmp(token, "stack") == 0)
	{
		variables.check = 0;
		return;
	}

	while (op[a].opcode != NULL)
	{
		if (strcmp(token, op[a].opcode) == 0)
		{
			op[a].f(stark, line_num);
			return;
		}
		a++;
	}
	printf("L%d: unknown instruction %s\n", line_num, token);
	free_stark(stark, line_num);
	exit(EXIT_FAILURE);
}

/**
 * nop - function to do nothing
 * @stark: the given stack
 * @line_num: line number
 * Return: void
 *
 **/

void nop(stack_t **stark, unsigned int line_num)
{
	(void)stark;
	(void)line_num;
}
