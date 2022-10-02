#include<stdio.h>
void main()
{
	int no_of_process;
	int time_quantum ;
	int swap_var;
	int i,j;
	int buffer_turnaroundtime;
	int flag=0;
		printf("\n\t\t\t\t\t Priority Based Round Robin Scheduling \n");
        printf("\t\t\t\t==================================================\n");;
		printf("\t\t\t\t--------------------------------------------------\n");
	printf("\n -----------------------------------------------------------------------------------------------\n");
	printf("Enter no of processes: ");
	scanf("%d",&no_of_process);
	int rp = no_of_process;
	printf("Enter time quantum for processes: ");
	scanf("%d",&time_quantum);
	int process_number[no_of_process];	
	int arrival_time[no_of_process];
	int burst_time[no_of_process];
	int priority[no_of_process];
	int process[no_of_process];
	int turnaround_time[no_of_process];
	int waiting_time[no_of_process];
	int buffer_burst_time[no_of_process];
	float average_wt=0;
	float average_tat=0;

	//Details of Processes..
	for(i=0;i<no_of_process;i++)
	{	
		process_number[i] = i+1;
		printf("\n |---------------------------------------------------------------------------|\n");
		printf("\nEnter Details for process P%d (Assuming all process arrived at 0.)\n",process_number[i]);
		arrival_time[i] = 0;
		printf("Enter Burst time : ");
		scanf("%d",&burst_time[i]);
		buffer_burst_time[i] = burst_time[i];
		printf("Enter Priority : ");
		scanf("%d",&priority[i]);
		waiting_time[i]=0;
		turnaround_time[i]=0;
		printf("\n |---------------------------------------------------------------------------|\n");

	}
	
	//Process deatils before sorting.
	
	printf("\nProcess deatils before sorting of process a/c priority");
	printf("\n -----------------------------------------------------------------------------------------------\n");
	printf("|    Process\t|\tAT\t|\tBT\t|\tWT\t|\tTAT\t|  Priority     |\n");
	printf(" -----------------------------------------------------------------------------------------------\n");
	for(i=0;i<no_of_process;i++)
	{
		printf("|\tP%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n",process_number[i],arrival_time[i],burst_time[i],waiting_time[i],turnaround_time[i],priority[i]);
	}
	printf(" -----------------------------------------------------------------------------------------------\n");

	
	//rearranging of processes a/c to priority.
	for(i=0;i<no_of_process-1;i++)
		{
		  for(j=i+1;j<no_of_process;j++)
		  {
			if(priority[i] < priority[j])
				{
					swap_var = priority[i];
					priority[i] = priority[j];
					priority[j] = swap_var;
					swap_var = burst_time[i];
					burst_time[i] = burst_time[j];
					burst_time[j] = swap_var;
					swap_var = buffer_burst_time[i];
					buffer_burst_time[i] = buffer_burst_time[j];
					buffer_burst_time[j] = swap_var;
					swap_var = arrival_time[i];
					arrival_time[i] = arrival_time[j];
					arrival_time[j] = swap_var;
					swap_var = process_number[i];
					process_number[i] = process_number[j];
					process_number[j] = swap_var;
				}
			}
		}
		
	//process details after sorting a/c to priority
	printf("\nProcess details after sorting of process a/c priority");
	printf("\n -----------------------------------------------------------------------------------------------\n");
	printf("|    Process\t|\tAT\t|\tBT\t|\tWT\t|\tTAT\t|  Priority     |\n");
	printf(" -----------------------------------------------------------------------------------------------\n");
	for(i=0;i<no_of_process;i++)
	{
		printf("|\tP%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n",process_number[i],arrival_time[i],burst_time[i],waiting_time[i],turnaround_time[i],priority[i]);
	}		
	printf(" -----------------------------------------------------------------------------------------------\n");

	
	
	//round robin logic	
	for(i=0;rp!=0;)
	{
	
		if(buffer_burst_time[i] <= time_quantum && buffer_burst_time[i] > 0)
		{
			buffer_turnaroundtime += buffer_burst_time[i];
			buffer_burst_time[i] = 0;
			flag = 1;			
		}
		
		else if(buffer_burst_time[i]>0){
            buffer_burst_time[i] -= time_quantum;
            buffer_turnaroundtime += time_quantum;
        }
		
	
		if(flag==1 && buffer_burst_time[i]==0)
		{
			turnaround_time[i] = buffer_turnaroundtime-arrival_time[i];
			waiting_time[i] = buffer_turnaroundtime-arrival_time[i]-burst_time[i];
			
			flag = 0;
			rp--;
		}
		
	
		if(i==no_of_process-1)
            i=0;
        else if(arrival_time[i+1]<=buffer_turnaroundtime){
            i++;
        }
        else
            i=0;
	}
	
	for(i=0;i<no_of_process;i++)
	{
		average_wt = (average_wt + waiting_time[i]);
		average_tat = (average_tat + turnaround_time[i]);	
	}

	
	//process details after scheduling
	printf("\nProcess deatils after scheduling");	
	printf("\n -----------------------------------------------------------------------------------------------\n");
	printf("|    Process\t|\tAT\t|\tBT\t|\tWT\t|\tTAT\t|  Priority     |\n");
	printf(" -----------------------------------------------------------------------------------------------\n");
	for(i=0;i<no_of_process;i++)
	{
		printf("|\tP%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n",process_number[i],arrival_time[i],burst_time[i],waiting_time[i],turnaround_time[i],priority[i]);
	}
	printf(" -----------------------------------------------------------------------------------------------\n");
			

	printf("Average Waiting Time --> %f\n",average_wt/no_of_process);
	printf("Average Turnaround Time --> %f",average_tat/no_of_process);
}