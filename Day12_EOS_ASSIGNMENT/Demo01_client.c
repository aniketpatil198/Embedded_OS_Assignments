/*
The client process send two numbers to the server process via one ﬁfo. The server process calculate the sum and return via another ﬁfo. The client
process print the result.
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main() {
	int fdw,fdr, a, b, sum;

	fdw = open("/home/superuser/desd_client", O_WRONLY);

		printf("Enter number for addition\n");
		printf("A->");
		scanf("%d", &a);

		printf("B->");
		scanf("%d", &b);

			write(fdw, &a, sizeof(int));
			write(fdw, &b, sizeof(int));

		fdr = open("/home/superuser/desd_server", O_RDONLY);
			printf("\n waiting for data...\n");

			read(fdr, &sum, sizeof(int));;
			printf("SUM-> %d\n", sum);

		close(fdw);
		close(fdr);
		return 0;

}
