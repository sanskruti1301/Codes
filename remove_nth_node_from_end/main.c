#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void delete_node(struct node **head, int c);
void printlist(struct node *head);
struct node *create(int data);
void insert_end(struct node **head, int data);
int count(struct node *head);
void Remove(struct node **head, int n);

void delete_node(struct node **head, int c) {
    int k = 1;
    struct node *p, *q;

    if (*head == NULL) {
        return;
    }
    p = *head;

    if (c == 1) {
        *head = (*head)->next;
        free(p);
        return;
    } else {
        while ((p != NULL) && k < c) {
            k++;
            q = p;
            p = p->next;
        }

        if (p == NULL) {
            printf("Position does not exist \n");
            return;
        } else {
            q->next = p->next;
            free(p);
        }
        return;
    }
}

void printlist(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

struct node *create(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\n Wrong memory allocation \n");
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insert_end(struct node **head, int data) {
    struct node *newnode = create(data);
    if (*head == NULL) {
        *head = newnode;
    } else {
        struct node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
    }
}

int count(struct node *head) {
    struct node *current = head;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void Remove(struct node **head, int n) {
    int totalNodes = count(*head);
    int c = totalNodes - n + 1;  // Position to delete
    delete_node(head, c);
}

int main() {
    struct node *head = NULL;
    insert_end(&head, 1);
    insert_end(&head, 2);
    insert_end(&head, 3);
    insert_end(&head, 4);
    insert_end(&head, 5);
    int n;
    printf("Enter n \n");
    scanf("%d", &n);
    Remove(&head, n);
    printlist(head);
    return 0;
}
