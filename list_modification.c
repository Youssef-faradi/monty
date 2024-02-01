#include "monty.h"

/**
 * create_node - creates a node
 * @str: the value of n
 * Return: the new node
 */
stack_t *create_node(char *str)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = atoi(str);
	new_node->next = NULL;
	new_node->prev = NULL;

	return (new_node);
}

/**
 * add_dnodeint - adds a new node at the
 *	beginning of a doubly linked list
 * @stack: the head of the list
 * @n: the value of the node
 * Return: the address of the new element
 *	or NULL if it failed
 */

stack_t *add_dnodeint(stack_t **stack, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n; /** n is the value of
			  *the new node that was passed
			  * as an argument
			  */

	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;

	return (new_node);
}

/**
 * print_dlistint - prints all elements of a
 *	doubly linked list
 * @h: the head
 * Return: the number of nodes
 */

size_t print_dlistint(const stack_t *h)
{
	size_t len = 0;
	const stack_t *current = h;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
		len++;
	}

	return (len);
}

/**
 * add_nodeint_queue - adds a new node at the end of linked list
 * @stack: the head of the list
 * @n: the value of the node
 * Return: the address of the new element
 *	or NULL if it failed
 */

stack_t *add_nodeint_queue(stack_t **stack, int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *tmp = *stack;

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	if (*stack == NULL)
		*stack = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;

		tmp->next = new;
		new->prev = tmp;
	}

	return (new);
}

/**
 * free_dlistint - frees a doubly linked list
 * @head: the head of the list
 */

void free_dlistint(stack_t *head)
{
	stack_t *current;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		current = head;
		head = current->next;
		current->prev = head;
		free(current);
	}
}