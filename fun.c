#include "monty.h"
/**
 * _add - Adds the top two elements of the stack.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number in the Monty file.
 *
 * This function retrieves the top two elements from the stack and adds them.
 * If the stack has fewer than two elements, it prints an error message and
 * exits with failure. The result is stored in the second element, and the
 * original top element is removed from the stack.
 *
 * Return: No return value.
 */

void _add(stack_t **head, unsigned int counter)
{
	stack_t *stack_ptr;
	int stack_len = 0, sum;

	stack_ptr = *head;
	while (stack_ptr)
	{
		stack_ptr = stack_ptr->next;
		stack_len++;
	}
	if (stack_len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		_free(*head);
		exit(EXIT_FAILURE);
	}
	stack_ptr = *head;
	sum = stack_ptr->n + stack_ptr->next->n;
	stack_ptr->next->n = sum;
	*head = stack_ptr->next;
	free(stack_ptr);
}

/**
 * _addnode - Adds a new node to the head of the stack.
 *
 * @head: Pointer to the head of the stack.
 * @n: Value for the new node.
 *
 * This function creates a new node with the given value and adds it to the
 * head of the stack. It properly updates the pointers to maintain the linked
 * list structure. If memory allocation fails, the function prints an error
 * message and exits with failure.
 *
 * Return: No return value.
 */

void _addnode(stack_t **head, int n)
{

	stack_t *new_node, *current_top;

	current_top = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (current_top)
		current_top->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

/**
 * _div - Divides the second element from the top by the top
 * element in the stack.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number in the Monty file.
 *
 * This function divides the value of the top element by the value of the
 * second element from the top in the stack. If the stack has fewer than two
 * elements, it prints an error message and exits with failure. Additionally,
 * if the top element is zero, it prints a division by zero error and exits.
 *
 * Return: No return value.
 */

void _div(stack_t **head, unsigned int counter)
{
	stack_t *stack_ptr;
	int stack_len = 0, quotient;

	stack_ptr = *head;
	while (stack_ptr)
	{
		stack_ptr = stack_ptr->next;
		stack_len++;
	}
	if (stack_len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		_free(*head);
		exit(EXIT_FAILURE);
	}
	stack_ptr = *head;
	if (stack_ptr->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		_free(*head);
		exit(EXIT_FAILURE);
	}
	quotient = stack_ptr->next->n / stack_ptr->n;
	stack_ptr->next->n = quotient;
	*head = stack_ptr->next;
	free(stack_ptr);
}
