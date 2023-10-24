#include "sort.h"

/**
 * swap - swap 2 element
 * @head: head
 * @a: node a
 * @b: node b
 */
void swap(listint_t *a, listint_t *b, listint_t **head)
{
	listint_t *ax = NULL, *ax2 = NULL;

	if (a == NULL || b == NULL)
		return;
	ax = a->prev;
	ax2 = b->next;
	if (ax)
		ax->next = b;
	if (ax2)
		ax2->prev = a;
	a->next = ax2;
	a->prev = b;
	b->next = a;
	b->prev = ax;
	if (ax == NULL)
		*head = b;
}
/**
 * insertion_sort_list  - insertion sort list
 * @list: doubly liked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *prev;
	int vl;

	if (list == NULL || (*list)->next == NULL || (*list) == NULL)
	{
		return;
	}
	head = *list;
	while (head)
	{
		prev = head->prev;
				vl = head->n;

		while (prev && prev->n > vl)
		{
			swap(prev, head, list);
			print_list(*list);
			prev = head->prev;
		}
		head = head->next;
	}
}
