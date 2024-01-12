#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
*add_node - function that adds a new node at the beginnig of a list
*@head: pointer to pointer to struct
*@number: pointer to integer
*Return: new node created
**/

listint_t *insert_node(listint_t **head, int number) {
	listint_t *new_node = malloc(sizeof(listint_t));
	listint_t *current;

	if (new_node == NULL)
	return NULL;
	new_node->n = number;

	if (*head == NULL || (*head)->n >= new_node->n) {
        new_node->next = *head;
        *head = new_node;
    }

	else {
        current = *head;
        while (current->next != NULL && current->next->n < new_node->n) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
	return *head;
}
