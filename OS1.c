#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include<conio.h>
#include<windows.h>

/*
Arrival Time:       Time at which the process arrives in the ready queue.
Completion Time:    Time at which process completes its execution.
Burst Time:         Time required by a process for CPU execution.
Turn Around Time:   Time Difference between completion time and arrival time.          
     Turn Around Time = Completion Time - Arrival Time

Waiting Time(W.T): Time Difference between turn around time and burst time.
     Waiting Time = Turn Around Time - Burst Time
*/


int n=0,option=-1;

void gotoxy(long x, long y) 
      {
           COORD pos = {x, y};
           SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
      }

struct Process
{
	int P_ID,arrival_time,burst_time,completion_time,waiting_time,turnaround_time,flag;
};
/////////////////////////////////////////////////////////////////////////////////////
loading()
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	int i,a=100000*0.5,b=100000*0.25,c=100000*0.125,u;
	gotoxy(50,3);
	printf("LOADING");
	for(i=0;i<30;i++)
	{
	    if(i<10)
	    u=a;
	    else if(i<20)
	    u=b;
	    else
	    u=c;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i%13+1 );
		gotoxy(40+i,4);
		printf("%c",220);
		gotoxy(40+i,2);
		printf("%c",186);
		gotoxy(40+i,2);
		printf("|");
		usleep(u);
		gotoxy(40+i,2);
		printf("/");
		usleep(u);
		gotoxy(40+i,2);
		printf("%c",196);
		usleep(u);
		int count=0;
		gotoxy(40+i,2);
		printf("\\");
		usleep(u);
		
		gotoxy(40+i,2);
		if(count<5)
		printf("%c",176);
		if(count>=5<10)
		printf("%c",177);
		else
		printf("%c",177);
		count++;
	}
}
///////////////////////////////////////////////////////////////////////////////////////
homepage()
{
	system("cls");
	
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | BACKGROUND_GREEN |BACKGROUND_RED|BACKGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY  );
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED );
	int i;
	printf("\n\n\n");
	printf("\t    ****************************************************************************************\n");
	printf("\t   |\t\t                    LOVELY PROFESSIONAL UNIVERSITY                          |\n");
	printf("\t   |\t\t           Department Of Computer Science And Engineering                   |\n");
	printf("\t   |\t\t                                                                            |\n");
	printf("\t   |\t\t                       A MINI PROJECT ON                                    |\n");
	printf("\t   |\t\t                                                                            |\n");
	printf("\t   |\t\t                        Operating System                                    |\n");
	printf("\t   |\t\t                                                                            |\n");
	printf("\t   |\t\t        BY:                                         GUIDE:                  |\n");
	printf("\t   |\t\t     -------------                                -----------               |\n");
	printf("\t   |\t\t   VIKRANT CHAUDHARY                         Mrs        |\n");
	printf("\t   |\t\t   Reg No.-> 11703065                                                       |\n");
	printf("\t   |\t\t   Roll NO.->44                                                             |\n");
    printf("\t    ****************************************************************************************\n\n");
	
	for(i=0;i<13;i++)
	{
		gotoxy(11,i+3);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i );
		printf("%c",204);
		printf("%c",185);
		gotoxy(100,i+3);
		
		printf("%c",204);
		printf("%c",185);
	}
	int k;
	for(i=0;i<92;i++)
	{
		if(i>9)
		k=i%10;
		else
        k=i;
		gotoxy(10+i,3);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),k);
		printf("*");
		gotoxy(10+i,16);
		printf("*");
	
	}
}
////////////////////////////////////////////////////
void frame()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4 );
	int i;
	
	for(i=0;i<91;i++)
	{
		gotoxy(11+i,3);
		printf("%c",205);
		gotoxy(11+i,6);
		printf("%c",247);
		gotoxy(11+i,2*n+7);
		printf("%c",247);
	}
	////////////////
	gotoxy(15,4);
    printf("Process");
    gotoxy(15,5);
    printf("  ID");
    gotoxy(30,4);
    printf("Arrival");
    gotoxy(30,5);
    printf(" time");
    gotoxy(45,4);
    printf("Burst");
    gotoxy(45,5);
    printf("time");
    gotoxy(60,4);
    printf("Completion");
    gotoxy(60,5);
    printf("   time");
    gotoxy(75,4);
    printf("Waiting");
    gotoxy(75,5);
    printf(" time");
    gotoxy(89,4);
    printf("TurnAround");
    gotoxy(89,5);
    printf("   time");
	////////////////
    for(i=0;i<n*2+4;i++)
	{
		gotoxy(11,i+4);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2 );
		//printf("%c",186);
		printf("%c",179);
		printf("%c",177);
		
		gotoxy(100,i+4);
		printf("%c",177);
		printf("%c",179);
		//printf("||");
	}
}
/////////////////////////////////////////////////////////////////////////////
void display(struct Process P[n])
{
	//frame();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2 );
	int i,l=0,b=0;
	//n=7;
	for(i=0;i<n;i++)
    {
    l+=2;
	  //gotoxy(12,5+i);
	gotoxy(15,6+l);
	if(P[i].P_ID==-5)
    printf("   %c       %c",196,186);
    else
    {
    printf("           %c",186);
    gotoxy(15,6+l);
    printf("   P%d",P[i].P_ID);
    }
    
    gotoxy(30,6+l);
    if(P[i].arrival_time==-5)
    printf("   %c       %c",196,186);
    else{
    printf("           %c",186);
    gotoxy(30,6+l);
    printf("   %d",P[i].arrival_time);
    }
    gotoxy(45,6+l);
    if(P[i].burst_time==-5)
    printf("   %c       %c",196,186);
    else{
    printf("           %c",186);
    gotoxy(45,6+l);
    printf("   %d",P[i].burst_time);
    }
    gotoxy(60,6+l);
    if(P[i].completion_time==-5)
    printf("   %c       %c",196,186);
    else{
    printf("           %c",186);
    gotoxy(60,6+l);
    printf("   %d",P[i].completion_time);
    }
    gotoxy(75,6+l);
    if(P[i].waiting_time==-5)
    printf("   %c       %c",196,186);
    else{
    printf("           %c",186);
    gotoxy(75,6+l);
    printf("   %d",P[i].waiting_time);
    }
    gotoxy(89,6+l);
    if(P[i].turnaround_time==-5)
    printf("   %c       ",196);
    else{
    printf("           %c",186);
    gotoxy(89,6+l);
    printf("   %d",P[i].turnaround_time);
    }
    int j;
    for(j=0;j<87;j++)
    {
    gotoxy(13+j,6+l+1);
    if(j%15==13)
    printf("%c",206);
    else
    printf("%c",205);
	}
	}
	frame();
	
}
///////////////////////////////////////////////////////////////////////////////
int main()
{
	homepage();
	//sleep(3);
	getch();
	system("cls");
	loading();
	system("cls");
	int i,j,l=0,burst_count=0;
	for(i=0;i<50;i++)
	{
	gotoxy(30+i,5);
	printf("%c",177);
    }
	gotoxy(30,6);
	printf("Enter The number of Process to enter");
	gotoxy(30,7);
	scanf("%d",&n);
	system("cls");
	
    struct Process P[n];
    ///////initallizing the struct
    for(i=0;i<n;i++)
    {
    	P[i].arrival_time=-5,P[i].burst_time=-5,P[i].completion_time=-5,P[i].P_ID=-5;
    	P[i].turnaround_time=-5,P[i].waiting_time=-5;
	}
    for(i=0;i<n;i++)
    {
    	l+=2;
    	display(P);
    	gotoxy(41,2*n+12);
    	printf("Enter arrival time for process %d\n",i+1);
    	P[i].P_ID=i+1;
    	P[i].flag=0;
    	gotoxy(33,6+l);
	    scanf("%d",&P[i].arrival_time);
	    
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
	system("cls");
	gotoxy(40,2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	printf("Table After Sorting The Arrival Time");
   	display(P);
   	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
   	gotoxy(30,n*2+11);
   	printf("Scheduler selects the process with ");
   	gotoxy(33,n*2+12);
   	printf("Enter 1 For-> largest burst time");
   	gotoxy(33,n*2+13);
   	printf("Enter 2 For->Shortest Job First scheduling approach");
   	gotoxy(30,n*2+14);
   	printf("from the queue for the execution.");
	gotoxy(30,n*2+15);
	scanf("%d",&option);
   	//getch();
   	system("cls");
   	
   	gotoxy(40,2);
   	if(option==1)
	printf("Table According to Largest Burst Time\n");
	gotoxy(30,2);
	if(option==2)
	printf("Table According to Shortest Job First scheduling approach \n");
	///////////////////////////////////////////////////
	int time_t=P[0].arrival_time,count_n=0,temp_i=0,prev_temp_i=-3,temp_opt=-1;
    do
	{
		int max=0,min=99999;
		if(option==1)
		temp_opt=max;
		if(option==2)
		temp_opt=min;
		
		for(i=0;P[i].arrival_time<=time_t && i<n;i++)
		{
			//finding the biggest burst time at time time_t
	        //if P[i].flag=555 then it means this process is already done
	        	if(option==1 && P[i].burst_time>=temp_opt &&P[i].flag==0)
	        	{
	        	temp_opt=P[i].burst_time;
	        	temp_i=i;
	            }
	            
	            if(option==2 && P[i].burst_time<=temp_opt &&P[i].flag==0)
	        	{
	        	temp_opt=P[i].burst_time;
	        	temp_i=i;
	            }
        }
        if(prev_temp_i==temp_i)
        {
           time_t+=1;
		}
		else
		{
        printf("\n");
        P[temp_i].completion_time=time_t+temp_opt;
        P[temp_i].turnaround_time=P[temp_i].completion_time-P[temp_i].arrival_time;
        P[temp_i].waiting_time=P[temp_i].turnaround_time-P[temp_i].burst_time;
        
        display(P);
        getch();
		//printf("%d :  %d   :  %d======",P[temp_i].arrival_time,P[temp_i].burst_time,P[temp_i].flag);
        //printf("%d : %d\n",temp_i,max);
        P[temp_i].flag=555;
        time_t+=temp_opt;
        burst_count-=temp_opt;
        }
        prev_temp_i=temp_i;
        
	}while(burst_count>0);
	gotoxy(30,n*2+15);
}
