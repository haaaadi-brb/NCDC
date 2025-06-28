#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/* Returns a new node whose data is set to DATA and next is set to NULL */
Node *create_node(int data) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("Malloc failed\n");
        exit(EXIT_FAILURE); // Exit if malloc fails
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Frees the list starting at HEAD */
void free_list(Node *head) {
    while (head != NULL) {
        Node *temp = head->next;
        free(head);
        head = temp;
    }
}

/* Adds a new node to the front of the list */
void add_to_front(Node **head, int data) {
    if (head == NULL) return;
    Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

/* Prints out a linked list starting at HEAD */
void print_list(Node *head) {
    for (Node *curr = head; curr != NULL; curr = curr->next) {
        printf("%d->", curr->data);
    }
    printf("NULL\n");
}

/* Iteratively reverses a linked list whose first node is HEAD */
void reverse_list(Node **head) {
    if (head == NULL || *head == NULL) {
        return;
    }
    Node *prev = NULL;
    Node *curr = *head;
    Node *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
}

/* Adds a new node with data at the end of the list */
void add_to_back(Node **head, int data) {
    if (head == NULL) return;

    Node *new_node = create_node(data);

    if (*head == NULL) {
        // List is empty
        *head = new_node;
        return;
    }

    Node *curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
}

