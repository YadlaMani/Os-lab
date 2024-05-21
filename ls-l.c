#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>
#include<grp.h>
#include<pwd.h>
int main(){
    struct stat st;
    struct passwd *pw;
    struct group *gr;
    if(stat("one.txt",&st)<0){
        printf("Stat error");
    }
    if(S_ISREG(st.st_mode)) printf("-");
    if(S_ISDIR(st.st_mode))  printf("d");
    if(S_IRUSR&&st.st_mode) printf("r");
    else printf("-");
    if(S_IWUSR&&st.st_mode) printf("w");
    else printf("-");
    if(S_IXUSR&&st.st_mode) printf("x");
    else printf("-");
    if(S_IRGRP&&st.st_mode) printf("r");
    else printf("-");
    if(S_IWGRP&&st.st_mode) printf("w");
    else printf("-");
    if(S_IXGRP&&st.st_mode) printf("x");
    else printf("-");
    if(S_IROTH&&st.st_mode) printf("r");
    else printf("-");
    if(S_IWOTH&&st.st_mode) printf("w");
    else printf("-");
    if(S_IXOTH&&st.st_mode) printf("x");
    else printf("-");
    printf("%ld",(long)st.st_nlink);
    pw=getpwuid(st.st_uid);
    gr=getgrgid(st.st_gid);
    printf("%s",pw->pw_name);
    printf("%s",gr->gr_name);
    printf("%s",ctime(&st.st_ctime));
    printf("\n");
}
