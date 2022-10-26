// C program for Dijkstra's single 
// source shortest path algorithm.
// The program is for adjacency matrix
// representation of the graph.
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 5
int minDistance(int dist[],bool sptSet[])
{

    int min = INT_MAX, min_index;
   
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
   
    return min_index;
}

void printPath(int parent[], int j,int dist[])
{

    if (parent[j] == - 1)
        return;
   
    printPath(parent, parent[j] ,dist);
   
    printf("-->%d(%d)", j,dist[j]);
}
   
int printSolution(int dist[], int n, 
                      int parent[])
{
    int src = 0;
    printf("0-->0(0)\n\n");

    for (int i = 1; i < V; i++)
    {
        printf("%d",src);
        printPath(parent, i,dist);
        printf("\n\n");
    }
}
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; 
    bool sptSet[V];
    int parent[V];
   
    for (int i = 0; i < V; i++)
    {
        parent[0] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {

        int u = minDistance(dist, sptSet);

        sptSet[u] = true;
 
        for (int v = 0; v < V; v++)
   
            if (!sptSet[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            } 
    }

    printSolution(dist, V, parent);
}

int main()
{
    int graph[V][V] = { {0, 10, 0,5, 0},
                        {0, 0, 1, 2, 0},
                        {0, 0, 0, 0, 4},
                        {0, 3, 9, 0, 2},
                        {0, 0, 6, 0, 0}
                    };
    dijkstra(graph, 0);
    printf("Following is the name convention followed for the nodes:-\n");
    printf("s denotes 0'th node in the graph\n");
    printf("t denotes 1'th node in the graph\n");
    printf("x denotes 2'nd node in the graph\n");
    printf("y denotes 3'rd node in the graph\n");
    printf("z denotes 4'th node in the graph\n");
    return 0;
}
