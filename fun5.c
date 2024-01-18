#include "monty.h"

/**
 * _queue - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * _addqueue - Adds a new node to the tail of the stack in queue mode (FIFO).
 *
 * @head: Pointer to the head of the stack.
 * @n: Value for the new node.
 *
 * This function creates a new node with the given value and adds it to the
 * tail of the stack when operating in queue (First In, First Out) mode. It
 * updates the pointers to maintain the linked list structure. If memory
 * allocation fails, it prints an error message.
 *
 * Return: No explicit return value.
 */

void _addqueue(stack_t **head, int n)
{
	stack_t *new_node, *tail_node;

	tail_node = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (tail_node)
	{
		while (tail_node->next)
			tail_node = tail_node->next;
	}
	if (!tail_node)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		tail_node->next = new_node;
		new_node->prev = tail_node;
	}
}

/**
 * _push - Adds a new node with an integer value to the stack.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number in the Monty file.
 *
 * This function adds a new node with the specified integer value to the stack.
 * It performs input validation to ensure that the provided argument is a valid
 * integer. If the argument is not a valid integer or if it is missing, the
 * function prints an error message and exits with failure.
 * The mode of the stack
 * (LIFO or FIFO) is determined by the global 'bus' variable.
 *
 * Return: No explicit return value.
 */

void _push(stack_t **head, unsigned int counter)
{
	int val, index = 0, invalid_flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			index++;
		for (; bus.arg[index] != '\0'; index++)
		{
			if (bus.arg[index] > 57 || bus.arg[index] < 48)
				invalid_flag = 1; }
		if (invalid_flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			_free(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		_free(*head);
		exit(EXIT_FAILURE); }
	val = atoi(bus.arg);
	if (bus.lifi == 0)
		_addnode(head, val);
	else
		_addqueue(head, val);
}
