#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	int ret1,ret2,ret3,ret4,ret5,i;
	int s1,s2,s3,s4,s5;
	ret1=fork();
	if(ret1==0)
	{
		for(i=1;i<=5;i++)
		{
			
			printf("count of ret1 %d\n",i);
			printf(" pid of ret1  %d\n",getpid());
			sleep(1);

		}

		_exit(0);

	}
	ret2=fork();
	if(ret2==0)
	{
		for(i=1;i<=5;i++)
		{
			printf("count of ret2 %d\n",i);
			printf("pid of ret2 %d\n",getpid());
			sleep(1);
		}
		_exit(0);
	
	}
	ret3=fork();
	if(ret3==0)
	{
		for(i=1;i<=5;i++)
		{

				printf("count of ret3 %d\n",i);
				printf("pid of ret3 %d\n",getpid());
				sleep(1);
		}
		
		_exit(0);
	}

	ret4=fork();
	if(ret4==0)
	{
		for(i=1;i<=5;i++)
		{

				printf("count of ret4 %d\n",i);
				printf("pid of ret4 %d\n",getpid());
				sleep(1);
		}
		
		_exit(0);
	}

	ret5=fork();
	if(ret5==0)
	{
		for(i=1;i<=5;i++)
		{

				printf("count of ret5 %d\n",i);
				printf("pid of ret5 %d\n",getpid());
				sleep(1);
		}
		
		_exit(0);
	}
	waitpid(ret1,&s1,0);
	waitpid(ret2,&s2,0);
	waitpid(ret3,&s3,0);
	waitpid(ret4,&s4,0);
	waitpid(ret5,&s5,0);
	return 0;
}
