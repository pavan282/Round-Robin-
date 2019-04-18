#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
	//at[100]------>arrival time
	//bt[100]------>burst time
	//qt----------->Quantam time
	//n------------>no of process
	//wt_avg------->average of waiting time
	//tat_avg------>average of turn around time
	//temp--------->temporary variable to hold value
	//wt_sum------->sum of waiting time
	//tat_sum------>sum of turn around time
	//tat_time----->turn around time
	//wait_time---->waiting time
	//p[10]-------->array of processors
	//i,j --------->interger variables
	//n------------>no of processors
	//count-------->for counting purpose
	//limit-------->Holds the value of n
	
	
	int i,j,n,total,qt,count,temp1[10],p[10]={1,2,3,4,5,6,7,8,9,10},at[10],bt[10],wt[10],tat[10],temp,tat_time=0,wait_time=0;
	float wt_avg=0,tat_avg=0;
	printf("\t\t\t\t***************ROUND ROBIN SHEDULING*************\n\n");
	printf("Enter no of process :\t");                                          //prints no of process
	scanf("%d",&n);
	int limit=n;
	if(n!=0)                                                                    //prints no of process is not equal to zero the executes the program
	{
	printf("----------------------------------------------------------\n");
	for(i=0;i<n;i++)
	{
		printf("| p[%d]\n",i+1);
		printf("| Enter Arrival time : ");                                      //prints Arrival time
		scanf(" %d",&at[i]);                                   
		printf("| Enter Burst time   : ");                                      //prints Brust time
		scanf("%d",&bt[i]);
		temp1[i]=bt[i];
		printf("| \n");
	}
	printf("| Enter Quantum time : \t");                                         //prints Quantum time 
	scanf("%d",&qt);
	printf("----------------------------------------------------------\n");
	sleep(1);
	printf("Please wait...\n");
	sleep(2);
	printf("While we are loading......");
	sleep(2);
	system("CLS");
	printf("Performing Sheduling............");
	sleep(2);
	printf("\nGetting Result:-\n");
	sleep(2);
	printf("\n\tQuantum time is: %d\n",qt);                                           //prints quantum time
	sleep(1);         
	printf("\tProcess Table:\n");                                                     //prints process table
	sleep(2);
	printf("\t-------------------------------------------------------------------------------------------\n");
	printf("\t| process_id\t| Arrival time\t  | Burst time\t  |  Waiting time     | Turn Around Time  |\n");     //prints the value of arrival time,burst time,waiting time,turn around time
	printf("\t-------------------------------------------------------------------------------------------\n");
	sleep(2);
	for(total=0,i=0;limit!=0;)
	{
		if(temp1[i]<=qt && temp1[i]>0)
		{
			total=total+temp1[i];                                                   //calculates total value of all process to calculate turn around time and waiting time
			temp1[i]=0;
			count=1;
		}
		else if(temp1[i]>0)
		{
			temp1[i]=temp1[i]-qt;
			total+=qt;
		}
		if(temp1[i]==0 && count==1)
		{
			limit--;
			wt[i]=total-at[i]-bt[i];                                                   //applying formula to calculate waiting time
			tat[i]=total-at[i];                                                        //applying formula to calculate turn around time
			printf("\t|  p[%d]\t\t|    %d\t\t  |  \t%d\t  |    %d\t      |    %d\t\t  |\n",i+1,at[i],bt[i],wt[i],tat[i]);
			wait_time=wait_time+total-(at[i]+bt[i]);
			tat_time=tat_time+total-at[i];
			count=0;
			sleep(2);
				
		}
		if(i==n-1)                                                                    //increases the value of i upto n process
		{
			i=0;
		}
		else if(at[i+1]<=total)
		{
			i++;
		}
		else
		{
			i=0;
		}
	}
	printf("\t-------------------------------------------------------------------------------------------\n");
	sleep(2);
	printf("\tCalculating Average.............\n");                                                 
	sleep(2); 
	wt_avg=(float)wait_time/n;                                                         //calculates average of waiting time
	printf("\n\tAverage Waiting time is: %f",wt_avg);
	sleep(2);
	tat_avg=(float)tat_time/n;                                                        //calculates average of turn around time
	printf("\n\tAverage Turn Around Time is: %f\n",tat_avg);
	sleep(2);
	printf("\n\t\t\t\t***End of the sheduling***\n");
	
}
	else
	{   printf("\n----------------------------------------------------");
	    printf("\n| Error !! \n");
		printf("| Scheduling can't be done without any process :(:(:(\n");            // prints error message if 0 process
		printf("| Please enter no of process and try again \n");
		printf("| :):):)\n");
	}
	return 0;
}

