#include<stdio.h>

//tp=Total processes
//qt=Quantum time / time slice
//count: Incrementing this value by 1 when one process execution completed
//time: works as time tracker
//bt=burst time
//cbt= Copied burst time
//wt= Waiting time
//tat= Turn around time

int main()
{
	//Getting total number of processes
	int tp , qt , count=0, time=0;
	printf("Enter total number of process: ");
	scanf("%d", &tp);
	
	//Declaring variables
	int bt[tp] ,cbt[tp], wt[tp] , tat[tp];
	float awt=0,atat=0;
	
	
	//Getting Burst Time for each process
	for (int i = 0; i < tp; i++)
	{
		printf("Enter burst time for process P%d: ", i);
		scanf("%d", &bt[i]);
		cbt[i]=bt[i];
		
	}
	
	//Getting quantum time
	printf("Enter Quantum Time of process: ");
	scanf("%d", &qt);
	
	//Round Robin Scheduling starts from here
	while(1){
		
		for (int x=0; x<tp ; x++){
			
			//Conditions for bt & qt 
			if(cbt[x]>qt){
				cbt[x]=cbt[x]-qt;
				time+=qt;
			}
			else{
				if(cbt[x]>0){
					time=time+cbt[x];
					tat[x]=time;
					cbt[x]=0;
					count+=1;
				}
			}
			//Process complete then continue loop
			if(cbt[x]==0){
				continue;
			}
		}
		//All processes execution completed 
		//Exiting while loop
		if(count==tp)
			break;
	}
	
	
	//Printing Results
	printf("\nProcesses\t Burst Time\t Turn AT \n Waiting time\n");
	
	for (int i=0;i<tp;i++){
		
		wt[i]=tat[i]-bt[i];
		awt=awt+wt[i];
		atat=atat+tat[i];
		printf("\nP%d\t %d \t %d\t %d\n",i,bt[i],tat[i],wt[i]);
		
	}
	
	printf("\nAverage waiting time: %f\n",awt/tp);
	printf("Average turn around time: %f\n",atat/tp);
	
	return 0;

}