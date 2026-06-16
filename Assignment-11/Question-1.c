#include <stdio.h> 
 
#define MAX 9999 
#define INF 99999 
#define V 5  
 
int minKey(int key[],int mstSet[]) 
{ 
 int min=MAX,min_index; 
 
 for(int v=0;v<V;v++) 
 { 
  if(mstSet[v]==0 && key[v]) 
  { 
   min=key[v]; 
   min_index=v; 
  } 
 } 
 return min_index; 
} 
void printMST(int parent[],int graph [V][V]) 
{ 
 printf("Edge \t Weight \n"); 
 for(int i=1;i<V;i++) 
 { 
  printf("%d - %d \t%d\n",parent[i],i,graph [i][parent[i]]); 
 } 
} 
 
void primMST(int graph[V][V]) 
{ 
 int parent[V]; 
 int key[V]; 
 int mstSet[V]; 
 
 for(int i=0;i<V;i++) 
 { 
  key[i]=INF; 
  parent[i]=0; 
  mstSet[i]=-1; 
 } 
 key[0]=0; 
 parent[0]=-1; 
 
 for(int count=0;count<V-1;count++) 
 { 
  int u=minKey(key,mstSet); 
  mstSet[u]=1; 
 
  for(int v=0;v<V;v++) 
  { 
   if(graph[u][v] && mstSet[v] == 0 && graph[u][v]<key[v]) 
   { 
    parent[v]=u; 
    key[v]=graph[u][v]; 
   } 
  } 
 } 
 printMST(parent,graph); 
} 
 
int main() 
{ 
 int i,j,v,r; 
 int g[V][V]; 
 
 printf("Enter the number of vertex \n"); 
 scanf("%d",&v); 
 
 printf("\nEnter the graph value with weight in adjacency matrix form \n"); 
 for(i=0;i<v;i++) 
 { 
  for(j=0;j<v;j++) 
  { 
   scanf("%d",&g[i][j]); 
  } 
 } 
  primMST(g); 
}


Output :

Enter the number of vertex 
5 
 
Enter the graph value with weight in adjacency matrix form 
0 2 0 6 0 
2 0 3 8 5 
0 3 0 0 7 
6 8 0 0 9 
5 0 7 9 0 
Edge     Weight 
0 - 1   2 
0 - 2   0 
0 - 3   6 
0 - 4   5 
