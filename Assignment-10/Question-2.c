#include <stdio.h>  
#include <stdlib.h> 
 
#define INF 9999  
#define NIL –1 
 
struct vertex {  
int par ,dist, v_num, status;  
}; 
 struct Edge { 
     int v, weight; 
     struct Edge* next; 
 }; 
  
int num;  
struct vertex vert[50];  
struct Edge* adj[50]; 
 
void addEdge(int u, int v, int w) {  
    struct Edge* newNode = (struct Edge*) malloc(sizeof(struct Edge));  
    newNode->v = v; newNode->weight = w;  
    newNode->next = adj[u];  
    adj[u] = newNode; 
}  

int extract_min(struct vertex Q[]) {  
    int i, minIndex = -1; 
     int minValue = INF; 
     for(i = 0; i < num; i++) { 
         if(Q[i].status == 1 && Q[i].dist < minValue) { 
             minValue = Q[i].dist; 
             minIndex = i; 
         } 
     } 
     if(minIndex != -1) 
         Q[minIndex].status = 0; 
 
     return minIndex; 
     }  
     void dijkstra(int s) {  
          int i, u; 
                    for(i = 0; i < num; i++) { 
                        vert[i].dist = INF;                        
                        vert[i].par = NIL; 
                        vert[i].v_num = i; 
                        vert[i].status = 1; 
                    } 
                    vert[s].dist = 0; 
                    struct vertex Q[50]; 
                    for(i = 0; i < num; i++) { 
                    Q[i] = vert[i]; 
               } 
 
               while((u = extract_min(Q)) != -1) { 
               struct Edge* temp = adj[u]; 
 
               while(temp != NULL) { 
               int v = temp->v; 
               int weight = temp->weight; 
               if(Q[v].status == 1 && Q[v].dist > Q[u].dist + weight) { 
                   Q[v].dist = Q[u].dist + weight; 
                   Q[v].par = u; 
               } 
        temp = temp->next; 
    } 
      printf("Shortest distance from source to vertex %d = %d\n", u, Q[u].dist); 
   } 
} 
int main() {  
  int n, e, u, v, w, s; 
  printf("Enter number of vertices: "); 
  scanf("%d", &n); 
  num = n; 
  
  for(int i = 0; i < n; i++) 
    adj[i] = NULL; 
  printf("Enter number of edges: "); 
  scanf("%d", &e); 
  printf("Enter edges (u v w):\n"); 
  
  for(int i = 0; i < e; i++) { 
    scanf("%d %d %d", &u, &v, &w); 
    addEdge(u, v, w);    
  } 
  
  printf("Enter source vertex: "); 
  scanf("%d", &s); 
  dijkstra(s); 
  return 0; 
} 


Output : 

Enter number of vertices: 5  
Enter number of edges: 11 
Enter edges (u v w): 
0 1 10 
0 2 5 
1 2 2  
1 4 1 
2 1 3 
2 3 2 
2 4 9 
3 0 7  
3 4 6 
4 1 1  
4 3 4 
Enter source vertex: 0 
Shortest distance from source to vertex 0 = 0 
Shortest distance from source to vertex 2 = 5 
Shortest distance from source to vertex 3 = 7 
Shortest distance from source to vertex 1 = 8 
Shortest distance from source to vertex 4 = 9 
