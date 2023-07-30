#include "sort.h"

void swapWithNextNode(
	listint_t **head,
	listint_t **tailEnd,
	listint_t **currentNode);
void swapWithPreviousNode(
	listint_t **head,
	listint_t **tailEnd,
	listint_t **currentNode);
void cocktail_sort_list(listint_t **head);

/**
 * swapWithNextNode - Swap a node in a listint_t doubly-linked list
 *                   of integers with the node ahead of it.
 * @head: A pointer to the head of a doubly-linked list of integers.
 * @tailEnd: A pointer to the tail of the doubly-linked list.
 * @currentNode: A pointer to the current swapping node of the cocktail shaker
 * algorithm.
 */
void swapWithNextNode(
	listint_t **head,
	listint_t **tailEnd,
	listint_t **currentNode)
{
	listint_t *nextNode = (*currentNode)->next;

	if ((*currentNode)->prev != NULL)
		(*currentNode)->prev->next = nextNode;
	else
		*head = nextNode;
	nextNode->prev = (*currentNode)->prev;
	(*currentNode)->next = nextNode->next;
	if (nextNode->next != NULL)
		nextNode->next->prev = *currentNode;
	else
		*tailEnd = *currentNode;
	(*currentNode)->prev = nextNode;
	nextNode->next = *currentNode;
	*currentNode = nextNode;
}

/**
 * swapWithPreviousNode - Swap a node in a listint_t doubly-linked
 *                        list of integers with the node behind it.
 * @head: A pointer to the head of a doubly-linked list of integers.
 * @tailEnd: A pointer to the tail of the doubly-linked list.
 * @currentNode: A pointer to the current swapping node of the cocktail shaker
 * algorithm.
 */
void swapWithPreviousNode(
	listint_t **head,
	listint_t **tailEnd,
	listint_t **currentNode)
{
	listint_t *previousNode = (*currentNode)->prev;

	if ((*currentNode)->next != NULL)
		(*currentNode)->next->prev = previousNode;
	else
		*tailEnd = previousNode;
	previousNode->next = (*currentNode)->next;
	(*currentNode)->prev = previousNode->prev;
	if (previousNode->prev != NULL)
		previousNode->prev->next = *currentNode;
	else
		*head = *currentNode;
	(*currentNode)->next = previousNode;
	previousNode->prev = *currentNode;
	*currentNode = previousNode;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @head: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **head)
{
	listint_t *tailEnd, *nodePointer;
	bool isSorted = false;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;

	for (tailEnd = *head; tailEnd->next != NULL;)
		tailEnd = tailEnd->next;

	while (isSorted == false)
	{
		isSorted = true;
		for (nodePointer = *head; nodePointer != tailEnd;
			 nodePointer = nodePointer->next)
		{
			if (nodePointer->n > nodePointer->next->n)
			{
				swapWithNextNode(head, &tailEnd, &nodePointer);
				print_list((const listint_t *)*head);
				isSorted = false;
			}
		}
		for (nodePointer = nodePointer->prev; nodePointer != *head;
			 nodePointer = nodePointer->prev)
		{
			if (nodePointer->n < nodePointer->prev->n)
			{
				swapWithPreviousNode(head, &tailEnd, &nodePointer);
				print_list((const listint_t *)*head);
				isSorted = false;
			}
		}
	}
}
