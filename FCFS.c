#include<stdio.h>
#include<stdlib.h>
void findWaitingTime(int process[],int n,int bt[],int wt[]){
    wt[0]=0;
    for(int i=1;i<n;i++){
        wt[i]=bt[i-1]+wt[i-1];
    }
}
void findTurnAroundTime(int process[],int n,int bt[],int wt[],int tat[]){
    for(int i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
    }
}
void findAvgTime(int process[],int n,int bt[]){
    int wt[n],tat[n],total_wt=0,total_tat=0;
    findWaitingTime(process,n,bt,wt);
    findTurnAroundTime(process,n,bt,wt,tat);
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnAround Time\n");
    for(int i=0;i<n;i++){
        total_wt=total_wt+wt[i];
        total_tat=total_tat+tat[i];
        printf("%d",(i+1));
        printf("\t%d",bt[i]);
        printf("\t%d",wt[i]);
        printf("\t%d\n",tat[i]);
    }
    float s=(float)total_wt/(float)n;
    float t=(float)total_tat/(float)n;
    printf("\nAverage waiting time=%f\n",s);
    printf("\nAverage turn around time=%f",t);
}
int main(){
    int n;
    printf("Enter the no.of process:");
    scanf("%d",&n);
    int process[n];
    for(int i=0;i<n;i++){
        process[i]=i+1;
    }
    int burst_time[n];
    printf("Enter the burst time:");
    for(int i=0;i<n;i++){
        scanf("%d",&burst_time[i]);

    }
    findAvgTime(process,n,burst_time);
    return 0;
}