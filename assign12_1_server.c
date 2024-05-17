#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main()
{
	int num1,num2,result;
	int serreq_fd,serres_fd;

	serreq_fd = open("/home/parimal/Desktop/Practice/EOS_Practice/fifo1",O_RDONLY);
	if(serreq_fd<0)
	{
		perror("open() failed");
		_exit(1);
	}
	read(serreq_fd,&num1,sizeof(num1));
	read(serreq_fd,&num2,sizeof(num2));
	close(serreq_fd);
	result=num1+num2;
	serres_fd = open("/home/parimal/Desktop/Practice/EOS_Practice/fifo2",O_WRONLY);
	if(serres_fd<0)
	{
		perror("open() failed");
		_exit(1);
	}
	write(serres_fd,&result,sizeof(result));
	close(serres_fd);
	return 0;}
