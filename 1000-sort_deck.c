#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "deck.h"

int card_value_to_int(const char *card_value);
void arrange_deck(deck_node_t **deck);

/**
 * compare_cards - Comparison function for playing cards for use with qsort
 * @card_left: left card
 * @card_right: right card
 *
 * Return: 1 if `card_left` is greater than `card_right`, -1 if `card_right` is
 * greater than `card_left`, 0 if they are equal.
 */
int compare_cards(const void *card_left, const void *card_right)
{
	const deck_node_t *left_card = *(const deck_node_t **)card_left;
	const deck_node_t *right_card = *(const deck_node_t **)card_right;
	int left_value, right_value;

	if (left_card->card->kind > right_card->card->kind)
		return (1);
	if (left_card->card->kind < right_card->card->kind)
		return (-1);
	left_value = card_value_to_int(left_card->card->value);
	right_value = card_value_to_int(right_card->card->value);
	if (left_value > right_value)
		return (1);
	if (left_value < right_value)
		return (-1);
	return (0);
}

/**
 * card_value_to_int - convert card value to integer for comparison
 * @card_value: string representation of card value
 *
 * Return: integer representation of `card_value`.
 */
int card_value_to_int(const char *card_value)
{
	if (strcmp(card_value, "Ace") == 0)
		return (1);
	if (strcmp(card_value, "Jack") == 0)
		return (11);
	if (strcmp(card_value, "Queen") == 0)
		return (12);
	if (strcmp(card_value, "King") == 0)
		return (13);
	return (atoi(card_value));
}

/**
 * sort_deck - function to sort deck of cards in order of suit and value
 * @deck: pointer to head of linked list of 52 card deck
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *deck_in_array[54], *node_head;
	size_t index;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;
	node_head = *deck;
	deck_in_array[0] = NULL;
	for (index = 1; index < 53 && node_head != NULL; index++)
	{
		deck_in_array[index] = node_head;
		node_head = node_head->next;
	}
	deck_in_array[index] = NULL;
	qsort(deck_in_array + 1, 52, sizeof(deck_in_array[1]), compare_cards);
	for (index = 1; index < 53; index++)
	{
		deck_in_array[index]->prev = deck_in_array[index - 1];
		deck_in_array[index]->next = deck_in_array[index + 1];
	}
	*deck = deck_in_array[1];
}
