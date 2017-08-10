/*PRIORITY SCHEDULING ALGORITHM IMPLEMENTED BY ABHRAJIT CHATTOPADHYAY*/
 
#include<stdio.h>
#include<stdlib.h>
int totalWaitingTime;
int totalTurnAroundTime;
 
typedef struct process_struct{
    int id;
    int start_flag; //Necessary only if arrival time is different
    int time_left; //How much work is left
    int waiting_time; //How much time the process is waiting while other processes are working
    int end_flag; // Unneccessary in this program
    int turn_around_time;// Burst time + Completion Time (If arrival times are 0 for all processes))
    int priority;
    int burst_time;// Time required to complete the process
}pro;
 
 
void changeWaitingTime(pro process[],int n,int i,int wt){
    /* This function changes the waiting time for all the processes except
       the one which is processing.
       Here i is the processing process, j is used to go through all the process
       wt is the value, waiting_time has to be increased by*/
   
    for(int j=0;j<n;j++){
        if(process[j].time_left!=0){//Put &&process[j].start_flag==1 to have different arrival time
            if(j!=i) //If it is not the processing process
                process[j].waiting_time+=wt;}}}
 
 
void priorityScheduling(pro process[],int n){
pro temp;
    for(int i =0;i<n;i++){
	for(int j=0;j<n;j++){
		if(process[i].priority==process[j].priority){
			if(process[i].id<process[j].id){
				temp = process[i];
			process[i] = process[j];
			process[j] = temp;}}
		if(process[i].priority>process[j].priority){
			temp = process[i];
			process[i] = process[j];
			process[j] = temp;}}}
       
	

    for(int i = 0;i<n;i++){
	
        //process[i].start_flag = 1;        Remove comment to have different arrival time
        changeWaitingTime(process,n,i,process[i].time_left);
       
        /*In First Come First Serve, the process are completed at once*/
       
        printf("Process[%d] worked on for %d second(s)\n",i,process[i].time_left); //So, all of time_left is used
        process[i].time_left = 0; //Since work is done, time_left is set to 0
        totalWaitingTime += process[i].waiting_time; //Used to calculate average waiting time later
        printf("Total Waiting time of process[%d] is %d\n",i,process[i].waiting_time); //Total waiting time of          current process
        }
       
        }
 
int main(){
    int n;
    printf("Enter number of process : ");
    scanf("%d",&n);
    pro *process = (pro*) calloc(n,sizeof(pro));
    printf("Enter process burst_times & priority : \n");
   
   
    /*Getting Burst values from the user */
   
    for(int i=0;i<n;i++){
        scanf("%d %d",&process[i].burst_time,&process[i].priority);
        process[i].time_left = process[i].burst_time; //Initally, both will be same
	process[i].id = i;
        }
	
           
    priorityScheduling(process,n);
   
   
    printf("Process\tBurstTime\tWaitingTime\tTurnAroundTime\tCompletionTime\n"); //Table printing
    for(int i =0;i<n;i++){
        process[i].turn_around_time = process[i].burst_time+process[i].waiting_time;
        totalTurnAroundTime+=process[i].turn_around_time;
        printf("p[%d]\t%d\t\t%d\t\t%d\t\t%d\n",process[i].id,process[i].burst_time,process[i].waiting_time,process[i].turn_around_time,process[i].turn_around_time);}
    printf("\nAverage waiting time is %f\n",((float)totalWaitingTime/n));
    printf("\nAverage turn around time is %f\n",((float)totalTurnAroundTime/n));
   
 
    return 0;}
