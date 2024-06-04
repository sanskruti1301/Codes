#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct AdjList
{
    struct Node* head;
};
struct Graph
{
    int V;
    struct AdjList* array;
};

struct Node* createNode(int data)
{
    struct Node* newnode= (struct Node*)malloc(sizeof(struct Node));
    newnode->data= data;
    newnode->next= NULL;
    return newnode;
}
struct Graph * createGraph(int V)
{
    struct Graph*graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->V=V;
    graph->array= (struct AdjList*)malloc(V*sizeof(struct AdjList));
    for(int i=0;i<V;++i)
    {
        graph->array[i].head=NULL;
    }
    return graph;
}
void addEdge(struct Graph*graph, int src, int dest)
{
    struct Node* newnode= createNode(dest);
    newnode->next= graph->array[src].head;
    graph->array[src].head= newnode;
    //directed so repeat with destination
    newnode=createNode(src);
    newnode->next= graph->array[dest].head;
    graph->array[dest].head= newnode;
}

void printGraph(struct Graph* graph)
{
    for(int i = 0; i < graph->V; ++i)
    {
        struct Node* current = graph->array[i].head;
        printf("Adjacency list of vertex %d: ", i);

        // Handle the case where the list is empty
        if (current == NULL) {
            printf("NULL");
        }
        else {
            while(current)
            {
                printf("%d -> ", current->data);
                current = current->next;
            }
            printf("NULL");
        }

        printf("\n");
    }
}


int main()
{ int V,x,y,n=0;
    printf("Enter number of vertices \n");
    scanf("%d",&V);
    struct Graph * graph= createGraph(V);
    printf("\nEnter the connection between vertices (from 0):\n");
    while (1)
    {
        if (n >= V * (V - 1) / 2)
        {
            printf("Maximum number of edges reached.\n");
            break;
        }

        scanf("%d",&x);
        scanf("%d",&y);
        addEdge(graph,x,y);
        n++;

        printf("\nIf you want to add more edges, press 1. Otherwise, press 0: ");
        int c;
        scanf("%d", &c);

        if (c != 1)
        {
            break;
        }
    }

    printGraph(graph);
    return 0;
}
