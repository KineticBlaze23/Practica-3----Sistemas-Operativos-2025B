# 🚀 Uso de la función `system()` en C

Este programa demuestra cómo **ejecutar un comando del sistema** (`ls -l`) de forma simple, utilizando la función de alto nivel `system()`.
Forma parte del tema **"Creación y reemplazo de procesos"** en sistemas operativos tipo Unix/Linux.

---

## 1. Descripción general

En la biblioteca estándar de C (`<stdlib.h>`), la función `system()` es un **envoltorio de alto nivel** que permite ejecutar un comando de *shell* (`/bin/sh` o similar) directamente desde un programa en C.

Internamente, `system()` realiza la secuencia de llamadas a bajo nivel: **`fork()`**, una variante de **`exec()`** (para el *shell*) y **`wait()`**.

---

## 2. Funcionamiento del programa

### 1. **El Proceso Padre (Principal)**:
- Define el comando completo a ejecutar como una cadena de texto: `ls -l`.
- Llama a `system(comando)`.
- El proceso padre **se bloquea** en la llamada a `system()` y **espera** a que el comando (ejecutado por el proceso hijo) finalice.
- Una vez que `system()` retorna, el padre verifica el estado de salida para confirmar si la ejecución fue exitosa (`0`).
- Imprime un mensaje final y termina.

### 2. **El Proceso Hijo (Interno a `system()`)**:
- `system()` llama a `fork()` para crear un proceso hijo.
- El proceso hijo llama a `exec()` para ejecutar el *shell* (`/bin/sh`) con el comando provisto.
- El *shell* se encarga de interpretar y ejecutar `ls -l`.
- Cuando `ls -l` termina, el *shell* termina, y el proceso hijo finaliza.
- El estado de salida se devuelve al padre a través de `system()`.

> **Diferencia Clave:** A diferencia de `fork()` y `execl()`, el programador **no tiene control directo** sobre el proceso hijo ni sobre la llamada a `wait()`, ya que todo se gestiona automáticamente.

---

## 3. Código principal

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Aunque no es estrictamente necesario, se incluye por contexto

int main() {
    int estado_salida;
    char *comando = "ls -l"; 

    fprintf(stdout, "--> Proceso Padre (PID %d): Iniciando ejecución.\n", getpid());
    fprintf(stdout, "--> Proceso Padre: Ejecutando comando hijo (via system): '%s'\n", comando);

    // system() ejecuta el comando y espera su finalización
    estado_salida = system(comando);

    fprintf(stdout, "\n--> Proceso Padre: La ejecución del comando ha finalizado.\n");

    if (estado_salida == 0) {
        fprintf(stdout, "--> Proceso Padre: El comando se ejecutó con éxito.\n");
    } else {
        fprintf(stderr, "--> Proceso Padre: Error al ejecutar el comando. Código de salida: %d\n", estado_salida);
        return EXIT_FAILURE; 
    }

    return EXIT_SUCCESS;
}


Resultado

--> Proceso Padre (PID 41581): Iniciando ejecución.
--> Proceso Padre: Ejecutando comando hijo (via system): 'ls -l'
total 4
-rw-r--r-- 1 user group 1204 Nov 4 21:10 system_app.c

--> Proceso Padre: La ejecución del comando ha finalizado.
--> Proceso Padre: El comando se ejecutó con éxito.
