#include "monty.h"

/**
 * tokeniz - tokenizes an input
 * @toks: the buffer where the result is stored
 * @L: the line to tokenize
 * @d: the delimiter
 *
 * Return: return the number of tokens
 */

int tokeniz(char **toks, char *L, char *d)
{
	char *tmp;
	int i = 0;

	tmp = strtok(L, d);
	for (i = 0; tmp && i < 2; i++)
	{
		toks[i] = strdup(tmp);
		tmp = strtok(NULL, d);
	}

	toks[i] = NULL;
	return (i);
}

/**
 * is_comment - checks if the instuction is a
 *	comment
 * @line: the parsed line
 * Return: 1 if it's a comment, 0 otherwise
 */

int is_comment(char *line)
{
	/* check for comment*/
	if (line[0] == '#')
		return (1); /* if the line is a comment */

	return (0);	/* if not */
}

/**
 * cmd_list - parses the input into a list
 *	of commands
 * @input: the input to parse
 * @lines: the buffer to where to store the rslt
 *
 * Return: return the number of lines
 */

int cmd_list(char *input, char *lines[][3])
{
	/*char *buf[MAX_LINES];*/
	FILE *fd;
	char *buf = NULL;
	int i = 0, num_lines = 0;
	size_t len;

	fd = fopen(input, "r");
	if (fd == NULL) /** fprint error */
	{
		fprintf(stderr, "Error: Can't open file %s\n", input);
		exit(EXIT_FAILURE); /*exit failure*/
	}

	for (num_lines = 1; getline(&buf, &len, fd) != -1; num_lines++)
		tokeniz(lines[i++], buf, "\n ");
	lines[num_lines][0] = NULL;

	free(buf);
	fclose(fd);
	return (num_lines - 1);
}

/**
 * _liner - removes whitespaces
 * @str: the str to handle
 * Return: the clean str
 */

char *_liner(char *str)
{
	char BUF[1024];
	int i = 0, k = 0;

	if (str != NULL)
	{
		while (str[i] == ' ')
			i++;

		for (; str[i]; i++)
		{
			if (str[i] != ' ')
				BUF[k++] = str[i];
			else if (str[i] == ' ' && str[i - 1] != ' ')
				BUF[k++] = str[i];
		}
	}
	if (BUF[k - 1] == ' ')
		BUF[k - 1] = '\0';
	else
		BUF[k] = '\0';

	return (strdup(BUF));
}