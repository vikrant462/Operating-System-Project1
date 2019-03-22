#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

struct Process
{
    int arrival_time,burst_time,waiting_time,turnaround_time,flag;
};

int main()
{
	int n,i,j,burst_count=0;
	printf("Enter The number of Process to enter\n");
	scanf("%d",&n);
	//n=8;
    struct Process P[n];
    for(i=0;i<n;i++)
    {
    	printf("Enter arrival time for %d process\n",i+1);
	    scanf("%d",&P[i].arrival_time);
	    
	    printf("Enter burst time for %d process\n",i+1);
	    scanf("%d",&P[i].burst_time);
	    burst_count+=P[i].burst_time;
	}
	
	//for sorting according to arrival time
	for(j=0;j<n-1;j++)
	{
		for(i=0;i<n-j-1;i++)
		{
			if(P[i].arrival_time>P[i+1].arrival_time)
			{
			printf("check");	
			struct Process t=P[i];
			P[i]=P[i+1];
			P[i+1]=t;
         	}
	    }
	}
	/////////////////////////////////////////////////
	for(i=0;i<n;i++)
    {
	    printf("%d  :  %d\n",P[i].arrival_time,P[i].burst_time);
	}
	///////////////////////////////////////////////////
	int time_t=P[0].arrival_time,count_n=0;
    do
	{
		int max=0,temp_i,temp_change=0;
		for(i=0;P[i].arrival_time<=time_t;i++)
		{
			//finding the biggest burst time at time time_t
	        //if(P[i].burst_time<=time_t && P[i].flag!=555)
	        //{
	        	if(P[i].burst_time>=max && P[i].flag!=555)
	        	{
	        		//printf("Hello");
	        	max=P[i].burst_time;
	        	temp_i=i;
	        	temp_change=1;
	        	//count_n++;
	            }
	            //printf("world");
			//}
			//time_t=max;
        }
        
        if(temp_change==1)
		{
		printf("%d :  %d ======",P[temp_i].arrival_time,P[temp_i].burst_time);
        printf("%d : %d\n",burst_count,max);
        P[temp_i].flag=555;
        time_t+=max;
        burst_count-=max;
        }
        
	}while(burst_count>0);
}
