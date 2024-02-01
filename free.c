#include "monty.h"

/**
 * free_grid2 - frees a 2D array
 * @lines: the array
 * @numTokens: the number of the lines
 */

void free_grid2(char *lines[][3], int numTokens)
{
	int i, j;

	for (i = 0; i < numTokens ; i++)
	{
		for (j = 0; lines[i][j]; j++)
			free(lines[i][j]);
	}
}