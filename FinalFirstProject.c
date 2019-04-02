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
	printf("\n\n");
	printf("-------------First come first serve---------------\n");
	printf("Process Burst Time Waiting time TurnArroundTime\n");
	for(i=0;i<n;i++)
	{
		total_wt=total_wt+wt[i];
		total_tat=total_tat+tat[i];
		printf("P%d",i+1);
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
void sjf(int Process[],int Burst_time[], int n)
{
	int wt[n],tat[n],i,j,temp,total=0,pos;
	float avg_wt,avg_tat;
	 //sorting burst time in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(Burst_time[j]<Burst_time[pos])
                pos=j;
        }
 
        temp=Burst_time[i];
        Burst_time[i]=Burst_time[pos];
        Burst_time[pos]=temp;
 
        temp=Process[i];
        Process[i]=Process[pos];
        Process[pos]=temp;
    }
 
    wt[0]=0;            //waiting time for first process will be zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=Burst_time[j];
 
        total+=wt[i];
    }
 
    avg_wt=(float)total/n;      //average waiting time
    total=0;
    printf("\n\n");
    printf("-------------------Shortest Job First-------------------------");
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=Burst_time[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\nP%d\t\t  %d\t\t    %d\t\t\t%d",Process[i],Burst_time[i],wt[i],tat[i]);
    }
 
    avg_tat=(float)total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
	
}
void idle_condition(int Process[],int bt[],int n)
{
	int wt[n],tat[n],i,j,temp,total=0,pos;
	float avg_wt,avg_tat;
	 //sorting burst time in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=Process[i];
        Process[i]=Process[pos];
        Process[pos]=temp;
    }
 
    wt[0]=1;            //waiting time for first process is one due to idle condition
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=1;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=(float)total/n;      //average waiting time
    total=0;
    printf("\n\n");
    printf("-------------Cpu is in Idle Condition  for 1 unit-------------");
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\nP%d\t\t  %d\t\t    %d\t\t\t%d",Process[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=(float)total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}

int main()
{
   int Process[20],Burst_time[20],n,i;
   printf("Enter the total number of Process : \n");
   scanf("%d",&n);
   printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("P%d:",i+1);
        scanf("%d",&Burst_time[i]);
        Process[i]=i+1;         //contains process number
    }
   fcfs(Process,n,Burst_time);
   sjf(Process,Burst_time,n);
   idle_condition(Process,Burst_time,n);
}
