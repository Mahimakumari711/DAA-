#include <stdio.h> 
#define MAX 100 

int visited[MAX];
void dfs(int adj[MAX][MAX], int vCount, int start) { 
    visited[start] = 1; 
    printf("%d ", start); 
    for (int i = 0; i < vCount; ++i) { 
        if (adj[start][i] && !visited[i]) { 
            dfs(adj, vCount, i); 
        } 
    } 
} 
 
int main() { 
    int vCount, adj[MAX][MAX], start; 
 
    printf("Enter number of vertices: "); 
    scanf("%d", &vCount); 
 
    printf("Enter adjacency matrix:\n"); 
    for (int i = 0; i < vCount; ++i) { 
        for (int j = 0; j < vCount; ++j) { 
            scanf("%d", &adj[i][j]); 
        } 
    } 
 
    printf("Enter starting vertex (0-based index): "); 
    scanf("%d", &start); 
 
    for (int i = 0; i < vCount; ++i) 
        visited[i] = 0; 
 
    printf("DFS Traversal: "); 
    dfs(adj, vCount, start); 
    printf("\n"); 
    return 0; 
} 

Output : 

Enter number of vertices: 4 
Enter adjacency matrix: 
0 1 1 0 
0 0 1 0 
1 0 0 1 
0 0 0 1 
Enter starting vertex (0-based index): 2 
 
DFS Traversal: 2 0 1 3
