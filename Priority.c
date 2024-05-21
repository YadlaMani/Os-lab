#include<stdio.h>
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
void findAvgTime(int process[],int priority[],int n,int bt[]){
    int wt[n],tat[n],total_tat=0,total_wt=0;
    for(int i=0;i<n;i++){
        int idx=i;
        for(int j=i+1;j<n;j++){
            if(priority[j]<priority[idx]){
                idx=j;
            }
        }
        int temp=process[i];
        process[i]=process[idx];
        process[idx]=temp;
        temp=bt[i];
        bt[i]=bt[idx];
        bt[idx]=temp;
        temp=priority[i];
        priority[i]=priority[idx];
        priority[idx]=temp;
    }
    findWaitingTime(process,n,bt,wt);
    findTurnAroundTime(process,n,bt,wt,tat);
    for(int i=0;i<n;i++){
        total_tat=total_tat+tat[i];
        total_wt=total_wt+wt[i];
    }
    printf("Process\tBurst Time\tTurn Around Time\tWaiting time\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d",process[i],bt[i],wt[i],tat[i]);
        printf("\n");
    }
    float s=(float)total_wt/(float)n;
    float t=(float)total_tat/(float)n;
    printf("Average waiting time=%f\n",s);
    printf("Average turn around time=%f\n",t);


}
int main(){
    int n;
    printf("Enter the no.of process:");
    scanf("%d",&n);
    int process[n],priority[n],bt[n];
    printf("Enter the burst time and priority of the process:");
    for(int i=0;i<n;i++){
        process[i]=i+1;
        scanf("%d",&bt[i]);
        scanf("%d",&priority[i]);
    }
    findAvgTime(process,priority,n,bt);
}