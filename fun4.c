#include "monty.h"

/**
 * _swap - Swaps the top two elements of the stack.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number in the input file.
 *
 * Description:
 * This function swaps the values of the top two elements in the stack.
 * If the stack has fewer than two elements, an error message is printed
 * to standard error, the program is terminated, and resources are freed.
 *
 * Return: None
 */

void _swap(stack_t **head, unsigned int counter)
{
	bus_t bus __attribute__((unused)) = {NULL, NULL, NULL, 0};

	stack_t *current;
	int len = 0, aux;

	current = *head;

	while (current)
	{
		current = current->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		_free(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	aux = current->n;
	current->n = current->next->n;
	current->next->n = aux;
}

/**
 * _stack - Prints the top element of the stack.
 *
 * @head: Pointer to the head of the stack
 * @counter: Line number in the input file
 *
 * Description:
 * This function is intended to print the top element of the stack,
 * but the current implementation does not perform any meaningful action.
 * It sets the 'bus.lifi' variable to 0, and the parameters 'head' and
 * 'counter'
 * are not utilized. This function might be a placeholder or have a specific
 * purpose in the overall program logic.
 *
 * Return: Nothing.
 */

void _stack(stack_t **head, unsigned int counter)
{
	bus_t bus __attribute__((unused)) = {NULL, NULL, NULL, 0};

	(void)head;
	(void)counter;
	bus.lifi = 0;
}

/**
 * _rotr - Rotates the stack to move the top element to the bottom.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number in the input file (unused in this function).
 *
 * Description:
 * This function rotates the stack by moving the top element to the bottom.
 * If the stack is empty or contains only one element, the rotation no effect.
 * The circular rotation involves adjusting pointers to maintain doublelinked
 * list structure. The 'counter' parameter is not utilized in this function.
 *
 * Return: No return value.
 */

void _rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *last_element;

	last_element = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (last_element->next)
	{
		last_element = last_element->next;
	}
	last_element->next = *head;
	last_element->prev->next = NULL;
	last_element->prev = NULL;
	(*head)->prev = last_element;
	(*head) = last_element;
}

/**
 * _rotl - Rotates the stack to move the bottom element to the top.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number in the input file (unused in this function).
 *
 * Description:
 * This function rotates the stack by moving the bottom element to the top.
 * If the stack is empty or contains only one element, the rotation has no
 * effect.
 * The circular rotation involves adjusting pointers to maintain
 * the doubly linked
 * list structure. The 'counter' parameter is not utilized in this function.
 *
 * Return: No return value.
 */

void _rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *current_head = *head, *new_head;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	new_head = (*head)->next;
	new_head->prev = NULL;
	while (current_head->next != NULL)
	{
		current_head = current_head->next;
	}
	current_head->next = *head;
	(*head)->next = NULL;
	(*head)->prev = current_head;
	(*head) = new_head;
}
