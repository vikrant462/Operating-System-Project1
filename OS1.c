#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
/*
Arrival Time:       Time at which the process arrives in the ready queue.
Completion Time:    Time at which process completes its execution.
Burst Time:         Time required by a process for CPU execution.
Turn Around Time:   Time Difference between completion time and arrival time.          
     Turn Around Time = Completion Time - Arrival Time

Waiting Time(W.T): Time Difference between turn around time and burst time.
     Waiting Time = Turn Around Time - Burst Time
*/
struct Process
{
    int P_ID,arrival_time,burst_time,completion_time,waiting_time,turnaround_time,flag;
}Process;

int main()
{
	int n,i,j,burst_count=0;
	printf("Enter The number of Process to enter\n");
	scanf("%d",&n);
	
    struct Process P[n];
    for(i=0;i<n;i++)
    {
    	P[i].P_ID=i+1;
    	printf("Enter arrival time for %d process\n",i+1);
	    scanf("%d",&P[i].arrival_time);
	    
	    //printf("Enter burst time for %d process\n",i+1);
	    //scanf("%d",&P[i].burst_time);
	    P[i].burst_time=2*P[i].arrival_time;
	    burst_count+=P[i].burst_time;
	}
	
	//for sorting according to arrival time
	for(j=0;j<n-1;j++)
	{
		for(i=0;i<n-j-1;i++)
		{
			if(P[i].arrival_time>P[i+1].arrival_time)
			{	
			struct Process t=P[i];
			P[i]=P[i+1];
			P[i+1]=t;
         	}
	    }
	}
	/////////////////////////////////////////////////
   /*	for(i=0;i<n;i++)
    {
	    printf("%d  :  %d\n",P[i].arrival_time,P[i].burst_time);
	}*/
	///////////////////////////////////////////////////
	int time_t=P[0].arrival_time,count_n=0;
    do
	{
		int max=0,temp_i;
		for(i=0;P[i].arrival_time<=time_t;i++)
		{
			//finding the biggest burst time at time time_t
	        //if P[i].flag=555 then it means this process is already done
	        	if(P[i].burst_time>=max && P[i].flag!=555)
	        	{
	        	max=P[i].burst_time;
	        	temp_i=i;
	            }
        }
        
		
        P[temp_i].flag=555;
        P[i].completion_time=time_t+max;
        P[i].turnaround_time=P[i].completion_time-P[i].arrival_time;
        P[i].waiting_time=P[i].turnaround_time-P[i].burst_time;
        
        printf("%d :  %d  :   %d======",P[temp_i].arrival_time,P[temp_i].burst_time,P[i].completion_time);
        printf("%d : %d\n",burst_count,max);
        time_t+=max;
        burst_count-=max;
        
	}while(burst_count>0);
}
