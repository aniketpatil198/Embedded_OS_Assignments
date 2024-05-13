#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	int ret1,ret2,ret3,ret4,ret5;
	int s1,s2,s3,s4,s5,i;
	ret1=fork();
	if(ret1==0)
	{
		ret2=fork();
		if(ret2==0)
		{
		
			ret3=fork();
			if(ret3==0)
			{
			ret4=fork();
			if(ret4==0)
			{
			ret5=fork();
			if(ret5==0)
			{
				for(i=1;i<=5;i++)
				{
						printf("ret5:%d\n",ret5);
						printf("r5 process=%d\n",getpid());
						sleep(1);
				}
				_exit(0);
			}

				for(i=1;i<=5;i++)
				{
						printf("ret4:%d\n",ret5);
						printf("r4 process=%d\n",getpid());
						sleep(1);
				//		waitpid(ret5,&s5,0);
				//		_exit(0);
				}
				waitpid(ret5,&s5,0);
				_exit(0);

			}

				for(i=1;i<=5;i++)
				{
						printf("ret3:%d\n",ret5);
						printf("r3 process=%d\n",getpid());
						sleep(1);
				//		waitpid(ret4,&s4,0);
				//		_exit(0);
				}
				waitpid(ret4,&s4,0);
				_exit(0);
			}

				for(i=1;i<=5;i++)
				{
						printf("ret2:%d\n",ret5);
						printf("r2 process=%d\n",getpid());
						sleep(1);
					//	waitpid(ret3,&s3,0);

					//	_exit(0);
				}
				waitpid(ret3,&s3,0);
				_exit(0);
			}

				for(i=1;i<=5;i++)
				{
						printf("ret1:%d\n",ret5);
						printf("r1 process=%d\n",getpid());
						sleep(1);
					//	waitpid(ret2,&s2,0);
					//	_exit(0);
				}
				waitpid(ret2,&s2,0);
				_exit(0);
			}

			
		waitpid(ret1,&s1,0);
		_exit(0);
		
	


	return 0;
}
