#include "monty.h"

/**
 * exit_err - this function handles the exit and error messages
 * @flag: a returned int that refers to an error msg
 * @lines: a Table of commands
 * @L: line number
 * @cmd: the command push, pall, ...
 * @nL: the number of lines
 */

void exit_err(int flag, char *lines[][3], unsigned int L, char *cmd, int nL)
{
	if (flag == 1)
		fprintf(stderr, "L%d: usage: push integer\n", L);
	else if (flag == 3)
		fprintf(stderr, "L%d: can't pint, stack empty\n", L);
	else if (flag == 4)
		fprintf(stderr, "L%d: can't pop an empty stack\n", L);
	else if (flag == 5)
		fprintf(stderr, "L%d: can't swap, stack too short\n", L);
	else if (flag == 6)
		fprintf(stderr, "L%d: can't add, stack too short\n", L);
	else if (flag == 7)
		fprintf(stderr, "L%d: can't sub, stack too short\n", L);
	else if (flag == 81)
		fprintf(stderr, "L%d: can't div, stack too short\n", L);
	else if (flag == 82)
		fprintf(stderr, "L%d: division by zero\n", L);
	else if (flag == 9)
		fprintf(stderr, "L%d: can't mul, stack too short\n", L);
	else if (flag == 101)
		fprintf(stderr, "L%d: can't mod, stack too short\n", L);
	else if (flag == 102)
		fprintf(stderr, "L%d: division by zero\n", L);
	else if (flag == 111)
		fprintf(stderr, "L%d: can't pchar, stack empty\n", L);
	else if (flag == 112)
		fprintf(stderr, "L%d: can't pchar, value out of range\n", L);

	else if (flag == 10)
		fprintf(stderr, "L%d: unknown instruction %s\n", L, cmd);
	else if (flag == 11)
		fprintf(stderr, "Error: malloc failed\n");

	if (head != NULL)
		free_dlistint(head);
	free_grid2(lines, nL);
	exit(EXIT_FAILURE);
}