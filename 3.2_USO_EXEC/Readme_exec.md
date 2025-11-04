#  Uso de la función `execl()` en C

Este programa demuestra cómo **crear un proceso hijo** que ejecuta un comando del sistema (en este caso `ls -l`) usando la función `execl()`.  
Forma parte del tema **"Creación y reemplazo de procesos"** en sistemas operativos tipo Unix/Linux.

---

##  1. Descripción general

En C, la función `fork()` crea un nuevo proceso (llamado **proceso hijo**), y `execl()` permite **reemplazar la imagen del proceso hijo** con un nuevo programa.

Este mecanismo se usa para que un proceso ejecute otro programa distinto.

---

## 2. Funcionamiento del programa

### 1. **El proceso padre**:
- Llama a `ejecutarNuevoProc()`.
- Espera que el proceso hijo termine con `wait(NULL)`.
- Luego imprime un mensaje indicando que el hijo ha terminado.

### 2. **La función `ejecutarNuevoProc()`**:
- Llama a `fork()` para crear un proceso hijo.
- Si `fork()` falla → muestra un mensaje de error y finaliza.
- Si `fork()` retorna 0 → el código se está ejecutando en el **hijo**.
- El hijo llama a `execl("/bin/ls", "ls", "-l", NULL)` para ejecutar el comando `ls -l`.

> Si `execl()` tiene éxito, **no retorna nunca**, porque el proceso actual se reemplaza por el nuevo programa (`ls`).

- Si `execl()` falla, imprime un mensaje de error y termina el proceso.
- El **padre** simplemente recibe el `pid` del hijo y lo devuelve al `main`.

---

##  3. Código principal

```c
int main() {
    char *programa = "/bin/ls";
    char *arg1 = "ls";
    char *arg2 = "-l";

    int pid = ejecutarNuevoProc(programa, arg1, arg2);
    wait(NULL);

    fprintf(stdout, "El proceso hijo con PID %d ha terminado.\n", pid);
    return 0;
}
```
## 4. Resultado 

total 0
El proceso hijo con PID 41580 ha terminado.
