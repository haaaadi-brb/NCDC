#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* create_node(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void add_to_list(Node** head, int value) {
    Node* newNode = create_node(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list
void print_list(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free the linked list (Fixing Memory Leak)
void free_list(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp); // Free each node
    }
}

int main() {
    Node* head = NULL;

    // Adding elements to the list
    add_to_list(&head, 10);
    add_to_list(&head, 20);
    add_to_list(&head, 30);

    // Printing the list
    print_list(head);

    // Free allocated memory
    free_list(head);

    return 0;
}
