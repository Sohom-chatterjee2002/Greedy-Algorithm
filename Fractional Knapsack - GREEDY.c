#include<stdio.h>
#include<stdlib.h>
void knapsack(int n, float weight[], float profit[], float capacity)
{
	float *x;     // solution vector array
	x=(float *)malloc(n*sizeof(float));
	float tp=0;
	int i,j,u;
	u=capacity;
	for(i=0;i<n;i++)
		x[i]=0.0;  //initialization solution vector to 0.0
	for(i=0;i<n;i++)
	{
		if(weight[i]>u)    //condition for fulfilled the knapsack capacity
			break;
		else
		{
			x[i]=1.0;    // take total weight of particular item
			tp=tp+profit[i];   //profit updation
			u=u-weight[i];    //weight updation
		}
	}
	if(i<n)
	{
		x[i]=u/weight[i];    //for take partially of a item 
	}
	tp=tp+(x[i]*profit[i]);
	
	printf("The result vector is: ");
	for(i=0;i<n;i++)
	{
		printf("%f\t",x[i]);
	}
	printf("Total Profit: %f",tp);
}
int main()
{
	float *weight,*profit,capacity;
	int n, i,j;
	float *ratio;
	float temp;
	printf("Enter the no. of items: ");
	scanf("%d",&n);
	weight=(float *)malloc(n*sizeof(float));
	profit=(float *)malloc(n*sizeof(float));
	ratio=(float *)malloc(n*sizeof(float));
	printf("Enter the profit and weights of each items: \n");
	for(i=0;i<n;i++)
	{
		scanf("%f %f",&profit[i],&weight[i]);
	}
	printf("Enter the capacity of knapsack: ");
	scanf("%f",&capacity);
	for(i=0;i<n;i++)
		ratio[i]=profit[i]/weight[i];       //calculate profit/weight ratio for each item
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(ratio[i]<ratio[j])
			{
				temp=ratio[j];
				ratio[j]=ratio[i];
				ratio[i]=temp;
				
				temp=weight[j];
				weight[j]=weight[i];
				weight[i]=temp;
				
				temp=profit[j];
				profit[j]=profit[i];
				profit[i]=temp;
			}
			
		}
	}
	knapsack(n,weight,profit,capacity);
	return 0;
}
