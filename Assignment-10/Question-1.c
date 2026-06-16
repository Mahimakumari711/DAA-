#include <stdio.h> 

int num; 
struct vertex 
{ 
 int par; 
 int dist; 
 int v_num; 
 int status; 
}; 

struct vertex vert [5]; 
void dijkstra (int [][5],int ); 
 
#define INF 9999 
#define NIL -1 
 
int main() 
{ 
 int i,j,n; 
 int G[5][5]; 
 int s; 
 
 printf("\nEnter the number of vertex \n"); 
 scanf("%d",&n); 
 num=n; 
 printf("\nEnter the adjacent matix of graph\n"); 
 for(i=0;i<n;i++) 
 { 
  for(j=0;j<n;j++) 
  { 
   scanf("%d",&G[i][j]); 
  } 
 } 
 printf("\nEnter the scource vertex \n"); 
 scanf("%d",&s); 
 
 dijkstra(G,s); 
} 
int extract_min(struct vertex Q[]) 
{ 
 int size=4; 
 int i=0,min=-1; 
 
 while(i<=size) 
 { 
  if(Q[i].status!=0) 
  { 
   min=i; 
   break; 
  } 
  i++; 
 } 
 Q[min].status=0; 
 return min; 
} 
 
void dijkstra(int G[][num],int s) 
{ 
 int i,u,v; 
 for(i=0;i<num;i++) 
 { 
  vert[i].dist=INF; 
  vert[i].par=NIL; 
  vert[i].v_num=i; 
 } 
 
 vert[s].dist=0; 
 
 struct vertex Q[num]; 
 
 for(i=0;i<num;i++) 
 { 
  Q[i].dist=vert[i].dist; 
  Q[i].par=vert[i].par; 
  Q[i].v_num=i; 
  Q[i].status=1; 
 } 
 
 Q[s].dist=0; 
  
 
 while((u=extract_min(Q))!=-1) 
 { 
  for(v=0;v<num;v++) 
  { 
   if(v==u) 
    continue; 
   if(G[u][v] !=0 && Q[v].dist >Q[u].dist+G[u][v]) 
   { 
    Q[v].dist=Q[u].dist+G[u][v]; 
    Q[v].par=u; 
   } 
  } 
  printf("The shortest distance from source to vertex %d is =%d\n",u,Q[u].dist); 
 } 
} 


Output :

Enter the number of vertex 
5 
 
Enter the adjacent matix of graph 
0 10 5 0 0 
0 0 2 0 1 
0 3 0 2 9 
7 0 0 0 6 
0 1 0 4 0 
 
Enter the source vertex 
0 
The shortest distance from source to vertex 0 is =0 
The shortest distance from source to vertex 1 is =10 
The shortest distance from source to vertex 2 is =5 
The shortest distance from source to vertex 3 is =7 
The shortest distance from source to vertex 4 is =11 
