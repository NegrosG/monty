#include "monty.h"

/**
 * main - main function
 * @ac: argument count
 * @av: argument vector
 * Return: 0 (success)
 */

int main(int ac, char *av[])
{
	FILE *fp;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	fp = fopen(av[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		return (EXIT_FAILURE);
	}

	process_file(fp);

	cleanup(fp, NULL, &stack);

	return (EXIT_SUCCESS);
}

/**
 * process_file - Function to process the contents of the file
 * @fp: file to process
 */

void process_file(FILE *fp)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *opcode;
	unsigned int line_num = 0;
	stack_t *stack = NULL;
	int x;

	instruction_t op_func[] = {
			{"push", c_push}, {"pall", c_pall}, {"pint", c_pint}, {"pop", c_pop},
			{NULL, NULL}
	};

	while ((read = getline(&line, &len, fp)) != -1)
	{
		line_num++;
		opcode = strtok(line, " \n\t");
		if (opcode == NULL || opcode[0] == '#')
			continue;

		for (x = 0; op_func[x].opcode; x++)
		{
			if (strcmp(opcode, op_func[x].opcode) == 0)
			{
				op_func[x].f(&stack, line_num);
				break;
			}
		}

		if (!op_func[x].opcode)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
			cleanup(fp, line, &stack);
			exit(EXIT_FAILURE);
		}
		free(line);
		line = NULL;
	}
	free(line);
}

void free_stack(stack_t **stack)
{
    stack_t *curr_node = *stack;
    stack_t *next_node;

    while (curr_node != NULL) {
        next_node = curr_node->next;
        free(curr_node);
        curr_node = next_node;
    }
    *stack = NULL;
}


/**
 * cleanup - Function to free allocated memory and close the file
 * @fp: Opened file
 * @line: Memory to be freed
 * @stack: doubly linked list
 */

void cleanup(FILE *fp, char *line, stack_t **stack)
{
	free(line);
	free_stack(stack);
	fclose(fp);
}
