#include <stdio.h>

int n;
int Q[5];

struct vertex{
	int col;
	int dis;
	int par;
};
struct vertex u[5];

int front=-1;
int rear=-1;

int dequeue();
void enqueue(int);

void bsf(int [][n],int);

int main()
{
	int adj_mat[5][5];
	int s=0;
	int size,i,j;

	printf("\nEnter the no of vertex \n");
	scanf("%d",&size);
	n=size;

	printf("\nEnter the edges of vertex in matrix form\n");
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			scanf("%d",&adj_mat[i][j]);
		}
	}

	bsf(adj_mat,s);
}

void bsf(int adjm[][n],int s)
{
	int i,m;
	struct vertex S;

	for(i=1;i<n;i++)
	{
		u->col='W';
		u->dis=9999;
		u->par=-1;
	}
	S.col='G';
	S.dis=0;
	S.par=-1;

	enqueue(s);

	while(front<=rear)
	{
		m=dequeue();

		for(i=1;i<n;i++)
		{
			if(adjm[m][i]==1)
			{
				if(u[i].col=='W')
				{
					u[i].col='G';
					u[i].dis=u[m].dis+1;
					u[i].par=m;
				}
			}
		}
		u->col='B';
	}
	for(i=1;i<n;i++)
	{
		printf("vertex: v%d\t ",i);
		printf("\n");
		printf("color: %c\t",u[i].col);
		printf("\n");
		printf("Distance: %d\t",u[i].dis);
		printf("\n");
		printf("Parent : %c\t",u[i].par)
	}
}

int dequeue()
{
	if(front==-1 || front>rear)
	{
		printf("\nQueue is empty \n");
	}
	else
	{
		return Q[front++];
	}
}

void enqueue(int ele)
{
	if(front==-1)
	{
		front=0;
	}
	else if(front==n)
	{
		printf("\nQueue overflow\n");
	}
	Q[++rear]=ele;
}
