/*
2. Create a server that accept multiple 
clients connected over UNIX sockets. 
Each client send two numbers, server do 
the addition and send the result back.
The client connection should be closed 
immediately after sending response.
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/un.h>
#include<sys/socket.h>
#include<signal.h>

#define SOCK_PATH "/tmp/desd_socket"

int serv_fd;

void sigint_handler(int sig) {
		shutdown(serv_fd, SHUT_RDWR);
		unlink(SOCK_PATH);
		_exit(1);
}

int main() {
		int cli_fd, ret, num1, num2, result;
		struct sockaddr_un serv_addr, cli_addr;
		socklen_t socklen;
		struct sigaction sa;

		memset(&sa, 0, sizeof(struct sigaction));
		sa.sa_handler = sigint_handler;
		ret = sigaction(SIGINT, &sa, NULL);
		if(ret < 0) {
				perror("sigaction() failed");
				_exit(2);
		}

		serv_fd = socket(AF_UNIX, SOCK_STREAM, 0);
		if(serv_fd < 0) {
				perror("socket() failed");
				_exit(3);
		}

		serv_addr.sun_family = AF_UNIX;
		strcpy(serv_addr.sun_path, SOCK_PATH);
		ret = bind(serv_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

		if(ret < 0) {
				perror("bind() failed");
				_exit(4);
		}

		listen(serv_fd, 5);

		while(1) {
				socklen = sizeof(cli_addr);
				cli_fd = accept(serv_fd, (struct sockaddr*)&cli_addr, &socklen);
				if(cli_fd < 0) {
						perror("accept() failed");
				}

		read(cli_fd, &num1, sizeof(int));
		read(cli_fd, &num2, sizeof(int));

		result = num1 + num2;
		printf("%d + %d = %d\n", num1, num2, result);
		
		write(cli_fd, &result, sizeof(int));
		close(cli_fd);
		}

	return 0;
}

























