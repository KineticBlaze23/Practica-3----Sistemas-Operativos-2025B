#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>
#define NUM_PROC 3
void hijoHasAlgo(int numero);
int main(){
	int i , pid;
	for(i=1;i<=NUM_PROC;i++)
	{
		pid = fork();
		switch(pid)
		{
			case -1: 
				fprintf(stderr, "Error al crear proceso\n");
				break;
			case 0:
			       	hijoHasAlgo(i);
				exit(0);
			default: 
				printf("Ejecutando padre\n");
				wait(0);
				printf("Mi hijo %d ha terminado. \n",i);
				break;
		}
	}

}

void hijoHasAlgo(int numero)
{
	int i,MAX=10;
	printf("Ejecutando el hijo %d: \n", numero);
	switch(numero)
	{
		case 1: 
			printf("Hijo 1: Contar del 1 al 10\n");
			for(i=1;i<= MAX; i++)
				printf("%d ",i);
			break;

		case 2: 
			printf("Hijo 2: Cuenta regresiva 10 al 1\n");
			for (i=MAX; i>=1; i--)
				printf("%d ", i);

			break;
		case 3:
			printf("Hijo 3: Cuadrados del 1 al 10\n");
			for(i=1; i<=MAX; i++)
				printf("%d ", i*i);
			break;
	}
	printf("\n");

}


