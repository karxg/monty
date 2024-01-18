#include "monty.h"

/**
* _nop - Does nothing and serves as a placeholder operation.
*
* @head: Pointer to the head of the stack.
* @counter: Line number in the Monty file.
*
* Description:
* The _nop function does not perform any operation and is used as a
* placeholder in Monty code. It helps maintain line numbers in the
* Monty file while providing a function that has no impact on the stack.
*
* Return: No return value.
*/

void _nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}

/**
* _mul - Multiplies the top two elements of the stack.
*
* @head: Pointer to the head of the stack.
* @counter: Line number in the Monty file.
*
* Description:
* The _mul function multiplies the second element from the top of the
* stack with the top element, and replaces the top element with the result.
* If the stack contains less than two elements, an error message is
* printed, and the program exits with failure.
*
* Return: No return value.
*/

void _mul(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int len = 0, result;

	bus_t bus __attribute__((unused)) = {NULL, NULL, NULL, 0};

	current = *head;
	while (current)
	{
		current = current->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		_free(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	result = current->next->n * current->n;
	current->next->n = result;
	*head = current->next;
	free(current);
}

/**
* _free - Frees a doubly linked list.
*
* @head: Pointer to the head of the doubly linked list.
*
* This function frees the memory allocated for a doubly linked list,
* starting from the specified head. It iterates through the list and
* releases the memory for each node. The head pointer is set to NULL
* after the entire list is freed.
*
* Return: No return value.
*/

void _free(stack_t *head)
{
	stack_t *current_node, *next_node;

	current_node = head;

	while (current_node)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
}
