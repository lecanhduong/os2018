
#include<stdio.h> 
#include<unistd.h>

int main(){ 
        printf("Before fork:\n")
        int pid = fork;
        if (ptd == 0){
                int ptd2 = fork();
                if (ptd2 == 0){
                        printf("child is printing...")
                        char* args[] = {"/bin/ps ", "-ef", NULL};
                        execvp("/bin/ps", args)
                }else {
                        printf("child free!");
                        char* args[] = {"free", "-h", NULL};
                        execvp("free", args)
        }
}


