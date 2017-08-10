/*Round Robin Algorithm implemented by Abhrajit Chattopadhyay*/
#include<stdlib.h>
#include<stdio.h>
int totalWaitingTime;
int totalTurnAroundTime;
int quantum;
 
 
typedef struct process_struct{
    int start_flag;
    int time_left;
    int burst_time;
    int waiting_time;
    int end_flag;
    int completion_time;
    int turn_around_time;
}pro;
 
 
 
 
 
void changeWaitingTime(pro process[],int n,int i,int wt){
   
    for(int j=0;j<n;j++){
        if(process[j].time_left!=0){//remove && statement for same arrival time  &&process[j].start_flag==1
            if(j!=i)
                process[j].waiting_time+=wt;}}}
 
 
void roundRobin(pro process[],int n){
    int end_flag=0;
   
    while(1){
       
        for(int i =0;i<n;i++){
            process[i].start_flag=1;
            if(process[i].end_flag!=1){
                    if(process[i].time_left/quantum!=0){
                        printf("Process[%d], worked on for %d second(s)\n",i,quantum);
                        process[i].time_left-=quantum;
                        process[i].completion_time+=quantum;
                        changeWaitingTime(process,n,i,quantum);
                        }
                    else if(process[i].time_left%quantum!=0){
                        printf("Process[%d], worked on for %d second\n",i,process[i].time_left%quantum);
                        changeWaitingTime(process,n,i,process[i].time_left%quantum);
                        process[i].completion_time+=process[i].time_left%quantum;
                        process[i].time_left-=process[i].time_left%quantum;
                       
                        }
                    else{
                        printf("Process[%d] has ended!",i);
                        printf("\nTotal wating time for process[%d] is %d\n",i,process[i].waiting_time);
                        totalWaitingTime+=process[i].waiting_time;
                        process[i].end_flag=1;;
                        end_flag++;
                        }}
                       
                }
        if(end_flag>=n){
               
                break;}
               
                }
}
                       
               
 
int main(){    
    int n;
    printf("Enter number of processes : ");
    scanf("%d",&n);
    pro *process = (pro*) calloc(n,sizeof(pro));//used calloc to set default values of struct members as 0
    printf("Enter burst time : \n");
    for(int i=0;i<n;i++){
        scanf("%d",&process[i].burst_time);
        process[i].time_left = process[i].burst_time;
    }
    printf("\nEnter quantum time (Time given to each process) : ");
    scanf("%d",&quantum);  
    roundRobin(process,n);
    printf("Process\tBurstTime\tWaitingTime\tTurnAroundTime\tCompletionTime\n");
    for(int i =0;i<n;i++){
        process[i].turn_around_time = process[i].burst_time+process[i].waiting_time;
        totalTurnAroundTime+=process[i].turn_around_time;
        printf("p[%d]\t%d\t\t%d\t\t%d\t\t%d\n",i,process[i].burst_time,process[i].waiting_time,process[i].turn_around_time,process[i].turn_around_time);}
    printf("\nAverage waiting time is %f\n",((float)totalWaitingTime/n));
    printf("\nAverage turn around time is %f\n",((float)totalTurnAroundTime/n));
    return 0;}
