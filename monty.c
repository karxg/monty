#include "monty.h"
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	bus_t bus __attribute__((unused)) = {NULL, NULL, NULL, 0};
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read = 1;
	stack_t *stack = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read > 0)
	{
		content = NULL;
		read = getline(&content, &size, file);
		bus.content = content;
		count++;
		if (read > 0)
		{
			exe(content, &stack, count, file);
		}
		free(content);
	}
	_free(stack);
	fclose(file);
return (0);
}
