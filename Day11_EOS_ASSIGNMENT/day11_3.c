#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int arr[2];

void sigint_handler(int sig) {
	printf("\nPipe buffer full \n");
	close(arr[1]);
	close(arr[0]);
	_exit(0);
}

int main(){
	int ret;
	char ch='A';
	ret = pipe(arr);
	struct sigaction sa;
	memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_handler = sigint_handler;
	ret = sigaction(SIGINT, &sa, NULL);
	int count=0;

	while(1){
		write(arr[1],&ch,1);
		count++;
		printf("data written on pipe buffer -> %d\n",count);
	}

		return 0;

}
