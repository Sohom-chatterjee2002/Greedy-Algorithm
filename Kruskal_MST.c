#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10
//n no. of vertices and ne is no. of edges
int n,ne=1;
int min,min_cost=0;
int cost[MAX][MAX];
int parent[MAX];  
int find_set(int i)
{
	while(parent[i])
		i=parent[i];
	return i;
}
int Union(int i, int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}
void Algorithm_Kruskal_MST()
{
	int i,j,a,b,u,v;
	printf("\nThe edges of Minimum Cost Spanning Tree are:\n");
	printf("-------------------------\n");
	printf("Edge no. (Sv,Dv) = cost\n");
	printf("------------------------\n");
	while(ne<n)
	{
		for(i=1,min=9999;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find_set(u);
		v=find_set(v);
		if(Union(u,v))
		{
			printf("%d edge (%c,%c) = %d\n",ne++,a+64,b+64,min);
			min_cost+=min;
		}
		cost[a][b]=cost[b][a]=9999;
	}
	printf("\nMinimum cost of the minimal spanning tree is: %d\n",min_cost);
}
int main()
{
	int i,j;
	printf("Implementation of Kruskal's Algorithm to find Minimum Spanning Tree\n");
	printf("--------------------------------------------------------------------\n");
	printf("\nEnter the no. of vertices: ");    
	scanf("%d",&n);                        //user input- no. of vertices
	printf("Enter the cost adjacency matrix: \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=9999;
		}
	}
	Algorithm_Kruskal_MST();
}
