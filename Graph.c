#include <stdio.h>
#include <stdlib.h>

typedef struct Graph
{
    int info;
    struct Graph *next;
} g;

void addEdge(int, int);
g *ptr[100];

int main()
{
    int i = 0;
    int src = 0, dst = 0;
    int ch;
    g *t = NULL;

    for (i = 0; i < 100; i++)
        ptr[i] = NULL;

    do
    {
        printf("\n\n");
        printf("Enter src and dest: ");
        scanf("%d %d", &src, &dst);
        addEdge(src, dst);
        printf("\nDo you want to continue y(1)/n(0)?");
        scanf("%d", &ch);
    } while (ch);

    return 0;
}

void addEdge(int src, int dst)
{

    g *p = NULL;
    g *t = NULL;
    p = (g *)malloc(sizeof(g));

    if (ptr[src] == NULL)
    {
        p->info = src;
        ptr[src] = p;
        p = (g *)malloc(sizeof(g));
        ptr[src]->next = p;
        p->info = dst;
        p->next = NULL;
    }

    p->info = dst;
    p->next = ptr[src]->next;
    ptr[src]->next = p;
}