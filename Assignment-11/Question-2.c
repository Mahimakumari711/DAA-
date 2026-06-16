#include <stdio.h>  
#include <stdlib.h> 
struct Edge {  
    int u, v, weight;  
}; 
struct Subset {  
    int parent; int rank;  
}; 
int find(struct Subset subsets[], int i) { 
     if (subsets[i].parent != i) 
             subsets[i].parent = find(subsets, subsets[i].parent); 
     return subsets[i].parent; 
 } 
void Union(struct Subset subsets[], int x, int y) {  
    int rootX = find(subsets, x); 
    int rootY = find(subsets, y); 
    if (subsets[rootX].rank < subsets[rootY].rank) 
    subsets[rootX].parent = rootY; 
    else if (subsets[rootX].rank > subsets[rootY].rank) 
        subsets[rootY].parent = rootX; 
    else { 
        subsets[rootY].parent = rootX; 
        subsets[rootX].rank++; 
    } 
} 
int compare(const void* a, const void* b) {  
    struct Edge* e1 = (struct Edge*)a;  
    struct Edge* e2 = (struct Edge*)b; return e1->weight - e2->weight; 
 } 
void kruskal(struct Edge edges[], int V, int E) {  
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset)); 
    for (int v = 0; v < V; v++) { 
        subsets[v].parent = v; 
        subsets[v].rank = 0; 
    } 
 
    qsort(edges, E, sizeof(struct Edge), compare); 
 
    int mstWeight = 0; 
    printf("\nEdges in Minimum Spanning Tree:\n"); 
 
    int count = 0;   
    for (int i = 0; i < E && count < V - 1; i++) { 
        int u = edges[i].u; 
        int v = edges[i].v; 
        int w = edges[i].weight; 
 
        int setU = find(subsets, u); 
        int setV = find(subsets, v); 
        if (setU != setV) { 
            printf("%d - %d    %d\n", u, v, w); 
            mstWeight += w; 
            Union(subsets, setU, setV); 
            count++; 
        } 
    } 
 
    printf("Total weight of MST: %d\n", mstWeight); 
 
    free(subsets); 
} 

int main() { 
    int V, E; 
    printf("Enter number of vertices: "); 
    scanf("%d", &V); 
 
    printf("Enter number of edges: "); 
    scanf("%d", &E); 
 
    struct Edge* edges = (struct Edge*)malloc(E * sizeof(struct Edge)); 
 
    printf("Enter edges (u v weight):\n"); 
    for (int i = 0; i < E; i++) { 
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight); 
    } 
 
    kruskal(edges, V, E); 
 
    free(edges); 
    return 0; 
} 


Output :  

Enter number of vertices: 5  
Enter number of edges: 13 
Enter edges (u v weight): 
0 1 2 
0 3 6 
1 2 3  
1 3 8 
1 4 5 
2 1 3 
2 4 7 
3 0 6  
3 1 8 
3 4 9  
4 1 5 
4 2 7 
4 3 9 
  
Edges in Minimum Spanning Tree: 
0 - 1    2 
1 - 2    3 
1 - 4    5 
0 - 3    6 
Total weight of MST: 16
