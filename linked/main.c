#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Wrong memory allocation");
        return NULL;
    } else {
        newnode->data = data;
        newnode->next = NULL;
        return newnode;
    }
}

void insertAtEnd(struct node** head, int data) {
    struct node* newnode = create(data);

    if (*head == NULL) {
        *head = newnode;
    } else {
        struct node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
    }
}

void display(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d \t", current->data);
        current = current->next;
    }
}

unsigned long long int calculateNumber(struct node* head) {
    unsigned long long int number = 0;
    struct node* current = head;

    while (current != NULL) {
        number = number * 10 + current->data;
        current = current->next;
    }

    return number;
}

struct node* reverseList(struct node* head) {
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

struct node* addTwoNumbers(struct node* h1, struct node* h2) {
    // Your implementation for adding two numbers represented by linked lists
    // You can add your code here if needed.
    return NULL;
}

int main() {
    struct node* h1 = NULL;
    struct node* h2 = NULL;
    int data;
    int data2;


    printf("Enter values for list one (in reverse order) or type 24 to stop:\n");

    while (scanf("%d", &data) == 1 && data != 24) {
        insertAtEnd(&h1, data);
    }

    printf("Enter values for list two (in reverse order) or type 24 to stop:\n");
    while (scanf("%d", &data2) == 1 && data2 != 24) {
        insertAtEnd(&h2, data2);
    }

    display(h1);
    printf("\n");
    display(h2);


    h1 = reverseList(h1);
    h2 = reverseList(h2);

    int n1= calculateNumber(h1);
    int n2=calculateNumber(h2);
    printf("%d \n", n1+n2);

    return 0;
}
