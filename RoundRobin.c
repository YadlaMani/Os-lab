#include<stdio.h>
#include<stdlib.h>

int main(){
    int c,y,n,quant,wt=0,tat=0,at[10],bt[10],temp[10],sum=0,i=0;
    float avg_tat,avg_wt;
    printf("Enter the no.of process:");
    scanf("%d",&n);
    y=n;
    printf("\nEnter the arrival time and burst time:");
    for(int i=0;i<n;i++){
        scanf("%d",&at[i]);
        scanf("%d",&bt[i]);
        temp[i]=bt[i];
    }
    printf("Enter the time quantum for the process:");
    scanf("%d",&quant);
    printf("\nProcess\tBurst Time\nTAT\nWT");
    for(sum=0,i=0;y!=0;){
        if(temp[i]<=quant&&temp[i]>0){
            sum+=temp[i];
            temp[i]=0;
            c=1;
        }
        else if(temp[i]>0){
            temp[i]=temp[i]-quant;
            sum=sum+quant;
        }
        if(temp[i]==0&&c==1){
            y--;
            printf("\nP[%d]\t%d\t%d\t%d\t",i+1,bt[i],sum-at[i],sum-at[i]-bt[i]);
            wt+=sum-at[i]-bt[i];
            tat+=sum-at[i];
            c=0;
        }
        if(i==n-1){
            i=0;
        }
        else if(at[i+1]<=sum){
            i++;
        }
        else{
            i=0;
        }

    }
    avg_wt=wt*1.0/n;
    avg_tat=tat*1.0/n;
    printf("\nAverage WT:%f",avg_wt);
    printf("\nAverage TAT:%f",avg_tat);

}