#include<unistd.h>
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int sig_num, pid;
		printf("Enter signal number\n");
		scanf("%d",&sig_num);
		
		printf("Enter pid \n");
		scanf("%d",&pid);

		if(kill(pid, sig_num)==0)
		{
			printf("Process executed\n");
		}
		else
		{
			perror("kill");
			//printf("Terminated");
			_exit(1);
		}
	return 0;
}
