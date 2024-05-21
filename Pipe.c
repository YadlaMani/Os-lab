#include<stdio.h>
#include<unistd.h>
#define MSGSIZE 16
char *msg1="Mani";
char *msg2="Naidu";
int main(){
    char intbuf[MSGSIZE];
    int p[2],i;
    if(pipe(p)<0){
        exit(1);
    }
    write(p[1],msg1,MSGSIZE);
    write(p[1],msg2,MSGSIZE);
    for(int i=0;i<2;i++){
        read(p[0],intbuf,MSGSIZE);
        printf("%s\n",intbuf);
    }
    return 0;


}