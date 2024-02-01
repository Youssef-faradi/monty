#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @stack: the node / head
 * @line_number: the line number
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = head;
	(void) stack; /**stack is not used in this function **/
	(void) line_number;

	(head->next)->n = head->n + (head->next)->n;
	head = head->next;
	free(tmp);
}

/**
 * _sub - subtracts the top element of the stack
 *	from the second top element of the stack
 * @stack: the node / head
 * @line_number: the line number
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = head;
	(void) stack; /**stack is not used in this function **/
	(void) line_number;

	(head->next)->n = (head->next)->n - head->n;
	head = head->next;
	free(tmp);
}

/**
 * _div - divides the second top element of the
 *	stack by the top element of the stack
 * @stack: the node / head
 * @line_number: the line number
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = head;
	(void) stack; /**stack is not used in this function **/
	(void) line_number;

	(head->next)->n = (head->next)->n / head->n;
	head = head->next;
	free(tmp);
}

/**
 * _mul - multiplies the second top element of the stack
 *	with the top element of the stack
 * @stack: the node / head
 * @line_number: the line number
 */

void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = head;
	(void) stack; /**stack is not used in this function **/
	(void) line_number;

	(head->next)->n = (head->next)->n * head->n;
	head = head->next;
	free(tmp);
}

/**
 * _mod - computes the rest of the division of the second top
 *	element of the stack by the top element of the stack
 * @stack: the node / head
 * @line_number: the line number
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = head;
	(void) stack; /**stack is not used in this function **/
	(void) line_number;

	(head->next)->n = (head->next)->n % head->n;
	head = head->next;
	free(tmp);
}