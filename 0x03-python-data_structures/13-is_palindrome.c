#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/* Definition of a node in the linked list */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* Function to check if a singly linked list is a palindrome */
int is_palindrome(Node** head) {
    Node* slow = *head;
    Node* fast = *head;
    Node* prev = NULL;
    Node* temp;

    // Find the middle node of the linked list
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        temp = slow;
        slow = slow->next;
        temp->next = prev;
        prev = temp;
    }

    // If the linked list has odd number of nodes,
    // move the slow pointer one step further
    if (fast != NULL)
        slow = slow->next;

    // Compare the first half with the second half of the linked list
    while (prev != NULL && slow != NULL) {
        if (prev->data != slow->data)
            return 0;
        prev = prev->next;
        slow = slow->next;
    }

    return 1;
}

/* Utility function to create a new node */
Node* new_node(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

/* Utility function to print a linked list */
void print_list(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Test the is_palindrome function */
int main() {
    Node* head = new_node(1);
    head->next = new_node(2);
    head->next->next = new_node(3);
    head->next->next->next = new_node(2);
    head->next->next->next->next = new_node(1);

    printf("Linked list: ");
    print_list(head);

    int result = is_palindrome(&head);
    if (result)
        printf("The linked list is a palindrome.\n");
    else
        printf("The linked list is not a palindrome.\n");

    return 0;
}
