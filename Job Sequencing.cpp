#include<iostream>
#include<algorithm>
using namespace std;
struct Job 
{
	char id;      //job id
	int deadline;  // deadline of job
	int profit;    // profit if job is overc befone or on deadline
};
bool comparison(Job a , Job b)  //sort all jobs according to their profits
{
	return (a.profit>b.profit);
}
void job_schedule(Job arr[], int n)   //job_sccheduling algorithm using greddy approach
{
	sort(arr,arr+n,comparison);  //sort all jobs according to decreasing order of profit
	int result[n];    // to store result(sequence of jobs)
	bool slot[n];     // keep track of free time slots
	for(int i=0;i<n;i++)   //initialize all slots to be free
	{
		slot[i]=false;
	}
	for(int i=0;i<n;i++)     //iterate through all given jobs
	{
		for(int j=min(n,arr[i].deadline)-1;j>=0;j--)     //find a free slot for this job(note that we start from the last possible slot)
		{
			//free slot found
			if(slot[j]==false)
			{
				result[j]=i;    // add this job to result
				slot[j]=true;    // mark the slot occupied
				break;
			}
		}
	}
	//print the result
	for(int i=0;i<n;i++)
	{
		if(slot[i])
			cout<<arr[result[i]].id<<" ";
	}
}
int main()
{
	Job arr[]={{'A',5,200},{'B',3,180},{'C',3,190},{'D',2,300},{'E',4,120},{'F',2,100}};
	//Job arr[]={{'a',2,100},{'b',1,19},{'c',2,27},{'d',1,25},{'e',3,15}};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<"Following is the schedule:"<<endl;
	job_schedule(arr,n);
	return 0;
}

