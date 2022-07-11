#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <lib.h>

typedef struct
{
    int src;
    int dest;
    int weight;
} EDGE;

// local function to sort the edges
static void sortEdges(EDGE *A, int n)
{
    if (n < 2)
        return;
    int i, l = 0, r = n - 1;
    EDGE t, pivot = A[0];
    while (l < r)
    {
        while ((A[l].weight <= pivot.weight) && (l < n))
            l++;
        while ((A[r].weight > pivot.weight) && (r > 0))
            r--;
        if (l < r)
        {
            t = A[l];
            A[l] = A[r];
            A[r] = t;
        }
    }
    for (i = 0; i < r; i++)
        A[i] = A[i + 1];
    A[i] = pivot;
    sortEdges(A, r);
    sortEdges(A + l, n - l);
}

// Reads the graph from the input file and creates a graph structure
GRAPH readGraph(char *FName)
{
    FILE *fptr;
    fptr = fopen(FName, "r");
    if (fptr == NULL)
    {
        printf("Error!\n");
        exit(1);
    }

    GRAPH G;
    fscanf(fptr, "%d", &G.nodes);
    fscanf(fptr, "%d", &G.edges);

    // allocate required memory to adjaceny matrix
    G.weight = (int **)malloc(G.nodes * sizeof(int *));
    for (int i = 0; i < G.nodes; i++)
    {
        G.weight[i] = (int *)malloc(G.nodes * sizeof(int));
        for (int j = 0; j < G.nodes; j++)
        {
            G.weight[i][j] = 0;
        }
    }

    // read edges
    int u, v, w;
    for (int i = 0; i < G.edges; i++)
    {
        fscanf(fptr, "%d%d%d", &u, &v, &w);
        G.weight[u][v] = G.weight[v][u] = w;
    }

    fclose(fptr);
    return G;
}
// Prints the graph in the format same as input
void printGraph(GRAPH G){
    printf("%d\n", G.nodes);
    printf("%d\n", G.edges);
    for(int i=0; i<G.nodes; i++){
        for(int j=0; j<G.nodes; j++){
            if(G.weight[i][j]!=INT_MAX) printf("%d %d %d\n", i, j, G.weight[i][j]);
        }
    }
}
// Utility function for DFS
static void DFSUtil(GRAPH G, int *visited, int root)
{
    STACK S = createStack();
    S = push(S, root);
    int u;

    while (!isEmptyStack(S))
    {
        S = pop(S, &u);
        if (!visited[u])
        {
            visited[u] = 1;
            printf("%d  ", u);
        }
        for (int v = 0; v < G.nodes; v++)
        {
            if (G.weight[u][v] != 0 && visited[v] == 0)
                S = push(S, v);
        }
    }
}

// DFS traversal
void DFS(GRAPH G)
{
    int *visited = (int *)malloc(G.nodes * sizeof(int));
    for (int i = 0; i < G.nodes; i++)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < G.nodes; i++)
    {
        if (visited[i] == 0)
            DFSUtil(G, visited, i);
    }
    printf("\n");
    free(visited);
}

// Utility function for BFS
static void BFSUtil(GRAPH G, int *visited, int root)
{
    QUEUE Q = createQueue();
    Q = enqueue(Q, root);
    int u;
    while (!isEmptyQueue(Q))
    {
        Q = dequeue(Q, &u);
        if (!visited[u])
        {
            visited[u] = 1;
            printf("%d  ", u);
        }
        for (int v = 0; v < G.nodes; v++)
        {
            if (G.weight[u][v] != 0 && visited[v] == 0)
                Q = enqueue(Q, v);
        }
    }
}

// BFS traversal
void BFS(GRAPH G)
{
    int *visited = (int *)malloc(G.nodes * sizeof(int));
    for (int i = 0; i < G.nodes; i++)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < G.nodes; i++)
    {
        if (visited[i] == 0)
            BFSUtil(G, visited, i);
    }
    printf("\n");
    free(visited);
}

// Minimum spanning tree
void MST(GRAPH G)
{
    EDGE *edges = (EDGE *)malloc(G.edges * sizeof(EDGE));
    int k = 0;
    for (int i = 0; i < G.nodes; i++)
    {
        for (int j = i; j < G.nodes; j++)
        {
            if (G.weight[i][j])
            {
                edges[k].src = i;
                edges[k].dest = j;
                edges[k].weight = G.weight[i][j];
                k++;
            }
        }
    }

    sortEdges(edges, G.edges);

    int count = 0, total_weight = 0;
    int *indexUF = (int *)malloc(G.nodes * sizeof(int));

    // make singleton set of each node
    UNION_FIND F = createUF(G.nodes);
    for (int i = 0; i < G.nodes; i++)
    {
        F = makeSetUF(F, i, indexUF + i);
    }

    // make Edges for adjacency matrix
    for (int i = 0; i < G.edges && count < G.edges - 1; i++)
    {
        if (findUF(F, indexUF[edges[i].src]) != findUF(F, indexUF[edges[i].dest]))
        {
            unionUF(F, indexUF[edges[i].src], indexUF[edges[i].dest]);
            count++;
            total_weight += edges[i].weight;
            printf("Edge: (%d -> %d), Weight: %d\n", edges[i].src, edges[i].dest, edges[i].weight);
        }
    }

    if (count == G.nodes - 1)
        printf("Weight of MST: %d\n", total_weight);
    else
        printf("NOT a connected graph. No MST found.\n");

    free(indexUF);
    free(edges);
}

int ShortestPath(GRAPH G, int source, int destination, int* distance, int toPrint){
    // if(source<0 || destination<0) exit(-1);
    int * isVisited = (int *) malloc(G.nodes * sizeof(int));
    int * parent = (int *) malloc(G.nodes * sizeof(int));
    for(int v=0; v<G.nodes; v++){
        distance[v]=INT_MAX;
        isVisited[v]=0;
        parent[v]=-1;
    }
    distance[source]=0;
    for(int i=0; i<G.nodes; i++){
        int nearest=-1;
        for(int v=0; v<G.nodes; v++){
            if(isVisited[v]==0 && (nearest==-1 || distance[nearest]>distance[v])) nearest=v;
        }
        if(distance[nearest]==INT_MAX) break;
        isVisited[nearest]=1;
        for(int v=0; v<G.nodes; v++){
            if(G.weight[nearest][v]!=INT_MAX){
                if(isVisited[v]==0 && distance[v]>distance[nearest]+G.weight[nearest][v]){
                    distance[v]=distance[nearest]+G.weight[nearest][v];
                    parent[v]=nearest;
                }
            }
        }
    }
    if(distance[destination]==INT_MAX) printf("No path found\n");
    else{
        int curr=destination;
        STACK S = createStack();
        while(curr!=-1){
            S = push(S, curr);
            curr = parent[curr];
        }
        S = pop(S, &curr);
        printf("Shortest Path: %d",curr);
        while(isEmptyStack(S)==0){
            S = pop(S, &curr);
            printf("->%d",curr);
        }
        printf("\n");
    }
    return distance[destination];
}
