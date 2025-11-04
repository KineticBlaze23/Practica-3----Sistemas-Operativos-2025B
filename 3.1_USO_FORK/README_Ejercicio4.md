# Uso del fork - Ejercicio 4

El programa crea un proceso padre y tres hijos que realizan distintas tareas (contar, contar regresivamente y calcular cuadrados). El padre espera a que terminen y muestra un mensaje al finalizar, demostrando el uso de fork() y wait() para manejar procesos concurrentes.

## Funcionalidad:

### Proceso padre:

- Crea tres procesos hijos usando fork().
- Después de crear cada hijo, espera a que termine con wait(0) y muestra un mensaje indicando que el hijo correspondiente ha finalizado.

### Procesos hijos:

Cada hijo realiza una tarea distinta según su número:

- Hijo 1: cuenta del 1 al 10.
- Hijo 2: cuenta regresiva del 10 al 1.
- Hijo 3: calcula los cuadrados del 1 al 10.

## Ejecución:

