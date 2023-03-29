#include "monty.h"

global_var global_variable;

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument value
 * Description: run the m file
 * Return: 0
 */
int main(int argc, char **argv)
{
	char line[80], *token, array[2][80];
	int i = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
	    exit(EXIT_FAILURE);
	}
	global_variable.file = fopen(argv[1], "r");

	if (!(global_variable.file))
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	global_variable.line_number = 1;
	global_variable.stack = NULL;
	global_variable.queue_ask = 0;
	while (fgets(line, sizeof(line), global_variable.file))
	{
		i = 0;
		memset(array[0], 0, 80);
		memset(array[1], 0, 80);
		token = strtok(line, " \n\t");
		if (token)
		{
			while (token != NULL)
			{
				strcpy(array[i], token);
				token = strtok(NULL, " \n\t");
				i++;
			}
			execOp(array);
		}
		global_variable.line_number++;
	}
	fclose(global_variable.file);
	free_list(global_variable.stack);
	return (0);
}
