#include "monty.h"
/**
 * read_textfile - reads a text file and prints
 *	it to POSIX Standard output
 * @filename: the name of the file
 * @letters: the number of letter it should read
 *	and print
 * Return: the number of letter is could read and
 *	print
 */

char *read_textfile(const char *filename, size_t letters)
{
	int fd, readed = -1;
	char *buff;

	if (filename == NULL)
		/** fprint error */
		exit(EXIT_FAILURE); /*exit failure*/

	fd = open(filename, O_RDONLY);
	if (fd == -1) /** fprint error */
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE); /*exit failure*/
	}

	buff = malloc(letters);
	if (buff == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	readed = read(fd, buff, letters);

	if (readed == -1)
		return (0);
	buff[readed] = '\0';

	close(fd);
	return (buff);
}