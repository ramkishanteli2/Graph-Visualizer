#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#include "GraphStructure.h"
struct Graph* createGraph(int v,int e)
{
    struct Graph*G=(struct Graph*)malloc(sizeof(struct Graph));
    G->v=v;
    G->e=e;
    G->adj=(int **)malloc(sizeof(int *)*v);
    for(int i=0;i<v;i++)
    {
        G->adj[i]=(int *)malloc(sizeof(int)*v);
        for(int j=0;j<v;j++)
            G->adj[i][j]=0;
    }
    printf("Enter details of edges: \n");
    for(int i=0;i<e;i++)
    {
        int u,v;
        printf("Enter vertex number for edge - %d\n",i+1);
        scanf("%d%d",&u,&v);
        G->adj[u-1][v-1]=1;
        G->adj[v-1][u-1]=1;
    }
    return G;
};
void draw_Graph(struct Graph * G)
{
    initwindow(500,500,"Graph");
    int arr[G->v][2];
    for(int i=0;i<G->v;i++)
    {
        srand(time(NULL));
        arr[i][0]=rand()%500;
        arr[i][1]=rand()%500;
    }
    for(int i=0;i<G->v;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(G->adj[i][j]==1)
            {
                circle(arr[i][0],arr[i][1],5);
                circle(arr[j][0],arr[j][1],5);
                line(arr[i][0],arr[i][1],arr[j][0],arr[j][1]);
            }
        }
    }
    getch();
}
void printAdjMatrix(struct Graph *G)
{
    for(int i=0;i<G->v;i++)
    {
        for(int j=0;j<G->v;j++)
            printf("%d ",G->adj[i][j]);
        printf("\n");
    }
}
int main()
{
    struct Graph *G=createGraph(6,5);
    printAdjMatrix(G);
    printf("\n");
    //draw_Graph(G);
    return 0;
}
