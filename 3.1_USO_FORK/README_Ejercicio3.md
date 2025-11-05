# Uso de fork - Ejercicio 3

El programa permite observar la ejecución concurrente de un proceso **padre** y un proceso **hijo** mediante la llamada al sistema `fork()`.  
Cada proceso imprime su **PID** (identificador de proceso) y su comportamiento demuestra la creación de un nuevo proceso independiente.  
El proceso padre utiliza `waitpid()` para esperar a que el hijo termine antes de finalizar, garantizando un cierre ordenado.

---

## Funcionalidad

### Proceso hijo
- Imprime su **PID** y el **PPID** (PID del proceso padre).  
- Muestra un mensaje de finalización.  
- Termina con un código de salida `0`.

### Proceso padre
- Imprime su **PID** y el **PID del hijo**.  
- Emplea `waitpid()` (o `wait(0)`) para **esperar** al hijo antes de finalizar.  
- Imprime el código de salida del hijo y su propio mensaje de finalización.  

---

## Compilación y ejecución

```bash
# Ir a la carpeta donde está el archivo
cd ~/Documents




# Compilar el programa
gcc -std=c11 -Wall fork_ejercicio3.c -o fork_ejercicio3

# Ejecutar
./fork_ejercicio3


```
 
## Captura de Ejecucion
<img width="1920" height="1020" alt="image" src="https://github.com/user-attachments/assets/2926e7c1-8170-441b-b79c-0be667cb6db3" />
