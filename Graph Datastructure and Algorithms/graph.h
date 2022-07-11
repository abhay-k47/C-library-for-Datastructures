#ifndef GRAPH_H
#define GRAPH_H

typedef struct
{
    int nodes;
    int edges;
    int **weight;
} GRAPH;

GRAPH readGraph(char *FName);
void printGraph(GRAPH G);
void DFS(GRAPH G);
void BFS(GRAPH G);
void MST(GRAPH G);
int ShortestPath(GRAPH G, int source, int destination, int* distance, int toPrint);

#endif
