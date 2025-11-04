# Uso de fork - Ejercicio 2
El programa permite observar la ejecucion concurrente de un proceso padre y un proceso hijo, donde se realiza tareas diferentes y la informacion final se comparte a un archivo .txt.
# Funcionalidad
## Proceso hijo
* Se ejecuta 10 veces
* En el archivo valores.txt se guarda su numero de iteracion y PID.
* Uso de fopen en modo "a", para agregar información al archivo.

## Proceso padre: 
* Se jecuta 10 veces y por cada iteracion se suma 10 a una variable acumulativa.
* Se imprime por consola su num. de iteración, PID y valor acumulativo.
* Empleo de wait(0) para esperar a que el hijo termine antes de finalizar.

## Capturas de ejecución
* Visualización de terminal
<img width="754" height="205" alt="image" src="https://github.com/user-attachments/assets/5489f7ec-fa28-449e-858b-f3d9b609565c" />

* Visualización de valores.txt
<img width="477" height="195" alt="image" src="https://github.com/user-attachments/assets/13fc6482-2eb6-4576-b66a-10d1f72d99f9" />

