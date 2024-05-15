/*2. Improve your shell program so that it should not be terminated due to SIGINT (ctrl+C).*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

//step1: implement SIGINT handler
void sigint_handler(int sig) {
	printf("\nSIGINT caught: %d\n", sig);
    
}

int main()
{
	char cmd[512], *ptr, *args[32];
	int i, ret, err, s;
	printf("Welcome to minishell\n");
    
	while(1) {
        signal(SIGINT, sigint_handler);
		printf("cmd> ");
		gets(cmd);
		i=0;
		ptr = strtok(cmd, " ");
		args[i] = ptr;
		i++;
		//printf("first token: %s\n", ptr);
		do {
			ptr = strtok(NULL, " ");
			args[i] = ptr;
			i++;
			//printf("subseq token: %s\n", ptr);
		}while(ptr != NULL);

		//for(i=0; args[i]!=NULL; i++)
		//	puts(args[i]);

		if(strcmp(args[0], "exit") == 0)
			break;	// internal command 1 -- exit
		else if(strcmp(args[0], "cd") == 0)
			chdir(args[1]);	// internal command 2 -- cd
		else {
			// external commands
			ret = fork();
			if(ret == 0) {
				err = execvp(args[0], args);
				if(err < 0) {
					perror("bad command");
					_exit(1);
				}
			}
			else
				wait(&s);
		}
	}
	printf("bye!\n");
	return 0;
}

//input: ls -l -a /home
