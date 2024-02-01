#include "monty.h"

void T(void);

/**
 * _launcher - searches for the OPcode
 * @lines: the parser instructions
 * @numLines: the number of lines
 */

void _launcher(char *lines[][3], int numLines)
{
	int i, j, ret, mode = STACK;
	unsigned int line_number = 0;
	instruction_t data[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr}
	};

	for (i = 0; i < numLines; i++)
	{
		line_number++;
		if (!lines[i][0])
			continue;
		if (is_comment(lines[i][0]))
			continue;
		if (strcmp(lines[i][0], "queue") == 0)
		{
			mode = QUEUE;
			continue;
		}
		if (strcmp(lines[i][0], "stack") == 0)
		{
			mode = STACK;
			continue;
		}

		if (strcmp(lines[i][0], "nop") == 0)
			continue;

		for (j = 0; j < 14; j++)
		{
			if (strcmp(lines[i][0], data[j].opcode) == 0)
			{
				ret = func(data[j], lines[i], line_number, mode);
				if (ret != 0)
					exit_err(ret, lines, line_number, lines[i][0], numLines);
				break;
			}
		}
		if (j == 14)
		{
			exit_err(INSTRCT_EXIST, lines, line_number, lines[i][0], numLines);
		}
	}
}

/**
 * is_num - this function checks if str in a number or empty
 * @Str: the string
 *
 * Return: return 1 if the string is a number or 0 if else
 */

int is_num(char *Str)
{
	int i = 0;

	if (!Str)
		return (0);

	if (Str[i] == '-')
		i++;

	while (Str[i])
	{
		if (isdigit(Str[i]) == 0)
			return (0);
		i++;
	}

	return (1);
}

/**
 * func - executes the OPcode
 * @data: the opcode and its function
 * @toks: the command in tokens
 * @line_number: the line number of the command
 * @mode: the mode of opcode stack / queue
 *
 * Return: 0 if the command executes with no errors
 *	else return an int that refers to an error
 */

int func(instruction_t data, char **toks, unsigned int line_number, int mode)
{
	stack_t *new_node;

	if (strcmp(data.opcode, "push") == 0)
	{
		if (is_num(toks[1]))
			new_node = create_node(toks[1]);
		else
			return (1);
		if (new_node == NULL)
			return (11);
	}
	else if (strcmp(data.opcode, "pint") == 0 && head == NULL)
		return (3);
	else if (strcmp(data.opcode, "pop") == 0 && head == NULL)
		return (4);
	else if (strcmp(data.opcode, "swap") == 0)
	{
		if (head == NULL || head->next == NULL)
			return (5);
	}
	else if (strcmp(data.opcode, "add") == 0)
	{
		if (head == NULL || head->next == NULL)
			return (6);
	}
	else if (strcmp(data.opcode, "sub") == 0)
	{
		if (head == NULL || head->next == NULL)
			return (7);
	}
	else if (strcmp(data.opcode, "div") == 0)
	{
		if (head == NULL || head->next == NULL)
			return (81);
		else if (head->n == 0)
			return (82);
	}
	else if (strcmp(data.opcode, "mul") == 0)
	{
		if (head == NULL || head->next == NULL)
			return (9);
	}
	else if (strcmp(data.opcode, "mod") == 0)
	{
		if (head == NULL || head->next == NULL)
			return (101);
		else if (head->n == 0)
			return (102);
	}
	else if (strcmp(data.opcode, "pchar") == 0)
	{
		if (head == NULL)
			return (111);
		else if (head->n > 126 || head->n < 32)
			return (112);
	}
	if (strcmp(data.opcode, "push") == 0 && mode == QUEUE)
		_push_queue(&new_node, line_number);
	else
		data.f(&new_node, line_number);

	return (0);
}