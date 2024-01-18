#include "monty.h"

/**
 * exe - Executes the opcode specified in the given content.
 *
 * @content: Line content from the Monty file.
 * @stack: Pointer to the head of the linked list (stack).
 * @counter: Line counter.
 * @file: Pointer to the Monty file.
 *
 * This function interprets and executes Monty opcodes based on the content
 * provided. It uses a list of opcode-function pairs to
 * determine the appropriate
 * action. If an unknown opcode is encountered, it prints an error message and
 * exits with failure.
 *
 * Return: No explicit return value.
 */
int exe(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", _push},
				{"pall", _pall},
				{"pint", _pint},
				{"pop", _pop},
				{"swap", _swap},
				{"add", _add},
				{"nop", _nop},
				{"div", _div},
				{"mul", _mul},
				{"pstr", _pstr},
				{"rotl", _rotl},
				{"rotr", _rotr},
				{"queue", _queue},
				{"stack", _stack},
				{NULL, NULL}
				};
	unsigned int opcode_index = 0;
	char *current_opcode;

	bus_t bus __attribute__((unused)) = {NULL, NULL, NULL, 0};
	current_opcode = strtok(content, " \n\t");
	if (current_opcode && current_opcode[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[opcode_index].opcode && current_opcode)
	{
		if (strcmp(current_opcode, opst[opcode_index].opcode) == 0)
		{	opst[opcode_index].f(stack, counter);
			return (0);
		}
		opcode_index++;
	}
	if (current_opcode && opst[opcode_index].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, current_opcode);
		fclose(file);
		free(content);
		_free(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
