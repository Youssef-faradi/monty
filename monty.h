#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

/* list of marcos */

#define MAX_BUF 32768
#define MAX_LINES 32768
#define MAX_TOKS 3 /* cuz we only need two token and the 3 tok is a NULL*/
#define NEW_LINE "\n"
#define SPACE " "
#define INSTRCT_EXIST 10 /* instruction does not exist */
#define STACK 1
#define QUEUE 2

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

extern stack_t *head; /** the head of the stack or queue as a global variable*/

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*** op codes ***/
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);
void _push_queue(stack_t **stack, unsigned int line_number);

/** file I / O */
char *read_textfile(const char *filename, size_t letters);

/*** parser ***/
int tokeniz(char **toks, char *L, char *d);
char *_liner(char *str);
int cmd_list(char *input, char *lines[][3]);
int is_comment(char *line);
int is_num(char *Str);


/*** list modification ***/
size_t print_dlistint(const stack_t *h);
stack_t *add_dnodeint(stack_t **stack, int n);
stack_t *create_node(char *str);
void free_dlistint(stack_t *head);
stack_t *add_nodeint_queue(stack_t **stack, int n);

/*** miscellaneous ***/
void _launcher(char *lines[][3], int numLines);
void free_grid2(char *grid[][3], int numTokens);
void free_grid(char *lines[][3]);

void exit_err(int flag, char *lines[][3], unsigned int L, char *cmd, int nL);
int func(instruction_t data, char **toks, unsigned int line_number, int mode);

#endif /* MONTY */