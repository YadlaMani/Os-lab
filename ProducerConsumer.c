#include<stdlib.h>
#include<stdio.h>
int mutext=1,full=0,empty=3,x=0;
int main(){
    int n;
    void producer();
    void consumer();
    int wait(int);
    int signal(int);
    printf("\n1.Producer\n2.Consumer\n3.Exit");
    while(1){
        printf("\nEnter your choice:");
        scanf("%d",&n);
        switch(n){
            case 1:if((mutext==1)&&empty!=0) producer();
            else printf("Buffer is full!!");
            break;
            case 2:if((mutext==1)&&full!=0) consumer();
            else printf("Buffer is empty!!");
            break;
            case 3:exit(0);
            break;

        }
    }
    return 0;
}
int wait(int s){
    if(s<=0);
    else return --s;
}
int signal(int s){
    return ++s;
}
void producer(){
    mutext=wait(mutext);
    full=signal(full);
    empty=wait(empty);
    x++;
    printf("\nProducer produces the item %d",x);
    mutext=signal(mutext);
}
void consumer(){
    mutext=wait(mutext);
    full=wait(full);
    empty=signal(empty);
    printf("\nConsumer consumes item %d",x);
    x--;
    mutext=signal(mutext);
}