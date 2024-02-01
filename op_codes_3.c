#include "monty.h"

/**
 * _pchar - print the char at the top of the stack
 * @stack: the node / head
 * @line_number: the line number
 */

void _pchar(stack_t **stack, unsigned int line_number)
{
	(void) stack; /**stack is not used in this function **/
	(void) line_number;

	putchar(head->n);
	putchar('\n');
}

/**
 * _pstr - prints the string starting at the top
 *	of the stack, followed by a new line
 * @stack: the node / head
 * @line_number: the line number
 */

void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = head;
	(void) stack; /**stack is not used in this function **/
	(void) line_number;

	while (tmp && tmp->n != 0 && (tmp->n < 126 && tmp->n > 32))
	{
		putchar(tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
}

/**
 * _rotl - rotates the stack to the top
 * @stack: the node / head
 * @line_number: the line number
 */

void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = head, *current;
	(void) stack; /**stack is not used in this function **/
	(void) line_number;

	if (head == NULL || head->next == NULL)
		return;

	head = head->next;
	head->prev = NULL;

	current = head;
	while (current->next)
		current = current->next;

	current->next = tmp;
	tmp->next = NULL;
	tmp->prev = current;
}

/**
 * _rotr - rotates the stack to the bottom
 * @stack: the node / head
 * @line_number: the line number
 */

void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *current = head;
	(void) stack; /**stack is not used in this function **/
	(void) line_number;

	if (head == NULL || head->next == NULL)
		return;

	while (current->next)
		current = current->next;

	tmp = current;
	current = current->prev;

	current->next = NULL;

	tmp->next = head;
	tmp->prev = NULL;
	head->prev = tmp;

	head = head->prev;
}

/**
 * _push_queue - adds a node to the queue
 * @stack: the node / head
 * @line_number: the line number
 */

void _push_queue(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void) line_number;

	/** head is the global variable for the stack or queue*/
	add_nodeint_queue(&head, (*stack)->n);
	free(tmp);
}