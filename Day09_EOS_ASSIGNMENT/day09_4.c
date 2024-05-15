//4. Write a program that compiles above multi-ﬁle project. It runs commands "gcc -c circle.c", "gcc -c square.c", "gcc -c rectangle.c", "gcc -c main.c"
//concurrently.

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{   int ret ,r2,r3,err, i , s;
    for(i=0;i<4;i++)
    {   ret=fork();
        if(ret==0)
        {    
            while(i==0)
            {
                err = execlp("gcc", "gcc", "-c", "circle.c",NULL);
                break;

            }
            while(i==1)
            {
                err = execlp("gcc", "gcc", "-c", "square.c",NULL);
                break;
            }
            while(i==2)
            {
                err = execlp("gcc", "gcc", "-c", "rectangle.c",NULL);
                break;
            }
            while(i==3)
            {
                err = execlp("gcc", "gcc", "-c", "main.c",NULL);
                break;
            }
        
            
            _exit(0);
        }
        }
	
     // wait for all child processes to complete
     for(i=0;i<4;i++)
     {   waitpid(-1,&s,0);
            printf("child exit -> %d \n ", WEXITSTATUS(s));
            }

        if(WEXITSTATUS(s)==0)
        { r2=fork();
            if(r2==0){
            err = execlp("gcc", "gcc", "-o","program.out","circle.o", "square.o", "rectangle.o", "main.o",NULL);
            if(err==-1)
            {
                
                printf("error in compiling");
            }
            _exit(0);
        }
        }
        
        waitpid(-1,&s,0);
            printf("child exit -> %d \n ", WEXITSTATUS(s));

        if(WEXITSTATUS(s)==0)
        { r3=fork();
            if(r3==0){
                
            err = execlp("./program.out", "./program.out",NULL);
            if(err==-1)
            {
                
                printf("error in compiling");
            }
            _exit(0);
            }
        }

        waitpid(-1,&s,0);
            printf("child exit -> %d \n ", WEXITSTATUS(s));

         
            return 0;


}
