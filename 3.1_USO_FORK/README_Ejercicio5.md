
# Uso del fork - Ejercicio 5
## Uso del fork – Proceso Zombie

El programa crea un **proceso padre** y un **proceso hijo** para demostrar cómo se genera un **proceso zombie** en un sistema operativo Linux.  
El hijo termina su ejecución inmediatamente, mientras que el padre continúa activo durante 60 segundos sin recoger el estado del hijo, provocando que este quede en estado **zombie** temporalmente.

---

##  Funcionalidad:

### Proceso padre:

- Crea un proceso hijo usando `fork()`.  
- Muestra su propio **PID** y el **PID del proceso hijo**.  
- Indica que el hijo quedará en estado **zombie** porque no usará `wait()` para esperarlo.  
- Duerme durante **60 segundos** (`sleep(60)`), manteniendo vivo al padre mientras el hijo ya ha terminado.  
- Una vez transcurrido ese tiempo, el padre termina su ejecución y el sistema limpia al proceso hijo zombie.

---

### Proceso hijo:

- Finaliza de inmediato con `exit(0)`.  
- Como el padre no ejecuta `wait()`, el proceso hijo queda en la tabla de procesos con estado **Z (Zombie)**.  
- Permanece en ese estado hasta que el proceso padre finaliza.

---

## 💻 Ejecución del programa:
<img width="1245" height="100" alt="image" src="https://github.com/user-attachments/assets/79e54e0d-229c-4730-b121-5c8597e7d678" />




