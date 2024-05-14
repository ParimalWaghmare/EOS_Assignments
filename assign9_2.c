#include<unistd.h>
#include<stdio.h>
#include<signal.h>

void sig_handler(int sig){
	printf("SIGINT caught: %d\n", sig);

}


int main(){
int i=1;

signal(SIGINT, sig_handler);

while(1){
	printf("running %d\n",i++);
	sleep(1);

}

return 0;
}

