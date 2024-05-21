
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
    int fh_desr=0,fh_desw=0,sizer=0;
    char buff[30];
    fh_desr=open("one.txt",O_RDONLY);
    if(fh_desr<0){
        printf("Source file doesn't open");
        return 0;
    }
    fh_desw=open("two.txt",O_CREAT|O_WRONLY,0777);
    if(fh_desw<0){
        printf("Destination file doesn't open");
        return 0;
    }
    while((sizer=read(fh_desr,buff,20))>0){
        write(fh_desw,buff,sizer);
    }
    return 0;
}