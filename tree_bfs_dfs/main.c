#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* right;
    struct node* left;
};

struct node* newnode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void bfs(struct node* root) {
    if (root == NULL) {
        return;
    }
    struct node** queue = (struct node**)malloc(sizeof(struct node) * 100);
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct node* current = queue[front++];
        printf("\t %d \t", current->data);
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
    free(queue);
}

// Inorder DFS traversal
void dfs(struct node* root) {
    if (root == NULL) {
        return;
    }
    dfs(root->left);
    printf("%d ", root->data);
    dfs(root->right);
}

int main() {
    struct node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->left->left = newnode(6);
    root->right->right = newnode(5);
    root->left->right = newnode(7);

    printf("BFS traversal: ");
    bfs(root);
    printf("\n");

    printf("DFS traversal: ");
    dfs(root);
    printf("\n");

    return 0;
}
