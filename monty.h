#ifndef _MONTY_H_
#define _MONTY_H_

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

/**
 * struct var - global variable representation
 * @holder: unassigned memory holder
 * @check: checks for the element to be assigned
 *
 **/
typedef struct var
{
	int holder;
	char check;
} var_t;

extern var_t variables;
var_t variables;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 *
 **/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 *
 **/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int check_digit(char *token);
void _tokenize(char *string, stack_t **stark, unsigned int line_num);
void free_stark(stack_t **stark, unsigned int line_num);
void _opcode(char *token, stack_t **stark, unsigned int line_num);
void push(stack_t **stark, unsigned int line_num);
void pall(stack_t **stark, unsigned int line_num);

#endif /* MONTY */
