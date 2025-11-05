#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int estado_salida;
    char *comando = "ls -l"; // Comando del shell a ejecutar

    printf("--> Proceso Padre (PID %d): Iniciando ejecucion.\n", getpid());
    printf("--> Proceso Padre: Llamando a system() para ejecutar el comando '%s'.\n", comando);

    // system() realiza fork(), exec() y espera (wait()) internamente.
    // El proceso padre se bloqueará aquí hasta que el comando termine.
    estado_salida = system(comando);

    printf("\n--> Proceso Padre: La ejecucion del comando ha finalizado.\n");

    // 0 es el valor de retorno estándar para una ejecución exitosa en el shell.
    if (estado_salida == 0) {
        printf("--> Proceso Padre: El comando se ejecuto con exito.\n");
    } else {
        fprintf(stderr, "--> Proceso Padre: Error al ejecutar el comando. Codigo de salida: %d\n", estado_salida);
        return EXIT_FAILURE; 
    }

    printf("--> Proceso Padre: Finalizando.\n");
    return EXIT_SUCCESS;
}
