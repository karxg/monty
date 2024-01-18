#include "monty.h"

/**
 * _pstr - Prints the string starting at the top of the stack.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number in the Monty file.
 *
 * Description:
 * The _pstr function interprets the integers on the stack as ASCII
 * values and prints the corresponding characters until it encounters
 * a non-printable ASCII character (outside the range 1 to 127) or a zero.
 * The function prints a newline character after the string is printed.
 *
 * Return: No return value.
 */

void _pstr(stack_t **head, unsigned int counter)
{
	stack_t *current;
	(void)counter;

	current = *head;
	while (current)
	{
		if (current->n > 127 || current->n <= 0)
		{
			break;
		}
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}

/**
 * _pop - Removes the top element of the stack.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number in the Monty file.
 *
 * Description:
 * The _pop function removes the top element of the stack. If the stack
 * is empty, an error message is printed, and the program exits with failure.
 *
 *
 * Return: No return value.
 */

void _pop(stack_t **head, unsigned int counter)
{
	stack_t *top_element;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		_free(*head);
		exit(EXIT_FAILURE);
	}
	top_element = *head;
	*head = top_element->next;
	free(top_element);
}

/**
 * _pint - Prints the value of the top element of the stack.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number in the Monty file.
 *
 * Description:
 * The _pint function prints the integer value of the
 * top element of the stack.
 * If the stack is empty, an error message is printed, and the program exits
 * with failure.
 *
 * Return: No return value.
 */

void _pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u : can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		_free(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * _pall - Prints all elements in the stack.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number in the Monty file (not used).
 *
 * Description:
 * The _pall function prints all elements in the stack, starting from the
 * top element. If the stack is empty, no output is produced.

 * Return: No return value.
 */

void _pall(stack_t **head, unsigned int counter)
{
	stack_t *current;
	(void)counter;

	current = *head;
	if (current == NULL)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

