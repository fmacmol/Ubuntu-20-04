#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void main ()
{
    int  a = 6;
    printf("Valor inicial de la variable: %d\n", a);
    pid_t pid, Hijo_pid;
    pid=fork();

    if (pid==-1) //Ha ocurrido un error
    {
        printf("No se ha podido crear el proceso hijo...");
        exit(-1);
    }

    if (pid==0)  //Nos encontramos en proceso hijo
    {
        printf("Variable en Proceso Hijo: %d\n", a-5);
    }
    else         //Nos encontramos en el proceso padre
    {
        Hijo_pid = wait (NULL);  //Espera la finalización del proceso hijo
        printf("Variable en Proceso Hijo: %d\n", a+5);
    }
    exit(0);
}
