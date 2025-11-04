#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	int pid;
	pid = fork();
	if(pid>0)
	{
		printf("Soy el proceso padre (PID: %d ) y espero 60 segundos antes de terminar, de mi hijo no se nada. \n",getpid());
		printf("Mi hijo tiene PID: %d\n", pid);
		printf("Mi hijo quedara en estado zombie\n");
		sleep(60);
		printf("El padre termina\n");
	}
	else
	{
		exit(0);
	}
	return 0;


}
