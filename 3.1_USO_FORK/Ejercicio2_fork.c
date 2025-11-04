#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
int main(){
	int pid;
	int i;
	int valor=0;
	FILE *f;
	pid = fork();
	switch (pid)
	{
		case -1: //Si el pid es -1, hubo un error
			printf("No se ha podido crear el proceso hijo\n");
			break;
		case 0: //pid = 0, es el proceso hijo
			for(i=1;i<=10;i++){
				f = fopen("valores.txt", "a");
				fprintf(f,"%d Soy el hijo con PID: %d \n",i,getpid());
				fclose(f);
			}
				break;
		default: //Cuanto es distinto de cero, es el padre
			 for(i=1;i<=10;i++){
				 valor +=10;
				 printf("%d Soy el padre con PID: %d | Valor actual: %d\n ",i,getpid(),valor);
			 }
			 //la funcion wait detiene el proceso padre y se queda esperando a que termine el hijo
			 wait(0);
			 break;
	
	}

}

