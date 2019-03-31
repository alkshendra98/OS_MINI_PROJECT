#include<stdio.h>
void findwt(int Process[],int n,int Burst_time[],int wt[])
{
	wt[0]=0;
	int i;
	for(i = 1;i<n;i++)
	{
		wt[i]=Burst_time[i-1]+wt[i-1];
	}
}
void findtat(int Process[],int n, int Burst_time[],int wt[],int tat[])
{
	int i;
	for(i=0;i<n;i++)
	{
		tat[i]=Burst_time[i]+wt[i];
	}
}

void fcfs(int Process[],int n,int Burst_time[])
{
	int wt[n], total_wt=0; int tat[n], total_tat=0;
	findwt(Process,n,Burst_time,wt);
	findtat(Process,n,Burst_time,wt,tat);
	int i;
	printf("Process Burst Time Waiting time TurnArroundTime\n");
	for(i=0;i<n;i++)
	{
		total_wt=total_wt+wt[i];
		total_tat=total_tat+tat[i];
		printf("   %d",i+1);
		printf("        %d",Burst_time[i]);
		printf("        %d",wt[i]);
		printf("              %d",tat[i]);
		printf("\n");
	}
	int a=(float)total_wt/(float)n;
	int b=(float)total_tat/(float)n;
	printf("Average Waiting time is : %d ",a);
    printf("\nAverage Turn Around Time is : %d ",b);
	
}

int main()
{
   int Process[]={1,2,3};
   int Burst_time[]={8,4,1};
   int n=sizeof Process/sizeof Process[0];
   fcfs(Process,n,Burst_time);
}
