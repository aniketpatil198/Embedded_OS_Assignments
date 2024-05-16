#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

int main() {
		int num1, num2, n1, n2, sum, s, res;
		int arr1[4],arr2[4],ret;
		
		printf("Parent started...\n");
		sleep(1);

		ret = pipe(arr1);
		ret = pipe(arr2);
		printf("Parent process waiting for data...\n");

		ret = fork();
		if( ret == 0 ) {
				//child process started
				printf("\nCHILD PROCESS STARTED !\n\n");
				close(arr1[0]);
				close(arr2[1]);
				//scan two numbers
				printf("Enter Num1: \n");
				scanf("%d", &num1);

				printf("Enter Num2: \n");
				scanf("%d", &num2);

				printf("CHILD PROCESS\n\t writing to pipe...\n");

				write(arr1[1], &num1, sizeof(num1));
				write(arr1[1], &num2, sizeof(num2));

				printf("CHILD PROCESS\n\t write success !\n\n");

				read(arr2[0], &res, sizeof(res));
				printf("result: %d\n", res);

				close(arr1[0]);
				close(arr2[1]);

				printf("\nCHILD PROCESS COMPLETED !\n\n");
		}
		else {
				//parent
				close(arr1[1]);
				close(arr2[0]);
				
				read(arr1[0], &n1, sizeof(n1));
				read(arr1[0], &n2, sizeof(n2));
				
				printf("PARENT PROCESS\n\t reading from pipe...\n");
				sleep(1);

				res = n1 + n2;
				
				sleep(1);
				printf("PARENT PROCESS\n\t writing to pipe...\n");

				write(arr2[1], &res, sizeof(res));
				printf("PARENT PROCESS\n\t write success !\n\n");
				sleep(1);

				close(arr2[1]);
				close(arr1[0]);

				waitpid(-1, &s, 0);
				printf("Parent closed...\n");
				sleep(1);
		}
		return 0;
}
