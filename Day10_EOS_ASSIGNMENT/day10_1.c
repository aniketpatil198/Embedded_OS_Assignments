/*The child process send two numbers to the parent process via message queue. The parent process calculate the sum and return via same message queue.
The child process print the result and exit. The parent process wait for completion of the child and then exit.*/

#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MQ_KEY		0x1234

typedef struct msg {
	long type;
    int num1, num2, sum;
	
} msg_t;

int main() {
	int mqid, ret, s;
    printf("PARENT PROCESS STARTED ->\n");
    sleep(1);
	// create message queue
	mqid = msgget(MQ_KEY, IPC_CREAT | 0600);
	if(mqid < 0) {
		perror("msgget() failed");
		_exit(1);
	}

	ret = fork();
	if(ret == 0) {
		// child: initialize and send the message
		msg_t m1;
		m1.type = 1;
        printf("CHILD PROCESS STARTED \n");
		sleep(1);
		printf("CHILD\n\t enter first number ->\t ");
		scanf("%d", &m1.num1);
        printf("CHILD\n\t enter second number ->\t ");
		scanf("%d", &m1.num2);
		ret = msgsnd(mqid, &m1, sizeof(m1), 0);
        
		printf("CHILD\n\t DATA SENT , %d\n", ret);
        sleep(1);

        ret = msgrcv(mqid, &m1, sizeof(m1), 1, 0);
        printf("CHILD\n\t DATA RECEIVED , %d \n", ret);
        printf("CHILD\n\t SUM = %d \n", m1.sum);

		// destroy the message queue

        //	msgctl(mqid, IPC_RMID, NULL);

		// exit
        _exit(0);


	}
	else {
		// parent: receive the message and print it
		msg_t m2;
        
		ret = msgrcv(mqid, &m2, sizeof(m2), 1, 0);
        
		printf("PARENT\n\t DATA RECEIVED , %d \n", ret);

        m2.sum=m2.num1+m2.num2;
        ret = msgsnd(mqid, &m2, sizeof(m2), 0);

        printf("PARENT\n\t DATA SENT , %d\n", ret);

	
		// wait for child and clean it up
		waitpid(-1,&s,0);
        printf("child exit -> %d \n ", WEXITSTATUS(s));
        

   


		// destroy the message queue
	//	msgctl(mqid, IPC_RMID, NULL);
	}
	return 0;
}
