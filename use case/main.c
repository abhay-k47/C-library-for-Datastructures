#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

int main()
{   
    char *FName;
    FName = (char*) malloc(100*sizeof(char));
    printf("Enter file name: ");
    scanf("%s",FName);
    GRAPH G;
    G = readGraph(FName);
    printf("\nDFS traversal order: ");
    DFS(G);
    printf("\nBFS traversal order: ");
    BFS(G);
    printf("\nMST:\n");
    MST(G);
    return 0;
}