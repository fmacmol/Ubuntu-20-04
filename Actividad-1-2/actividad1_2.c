#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>

int main ()
{
    pid_t pid;
    int fd1[2];
    char mensage[] = "Buenos días padre";
    char buffer[80]="";
    pipe(fd1);
    pid = fork(); //Soy el Padre
    switch(pid)
    {
        case -1: //error
            printf("No se ha podido crear el proceso hijo...");
            exit(-1);
            break;
        case 0:  //proceso hijo envia
            close(fd1[0]);  //Cierra el descriptor de salida de la tubería
            printf("\tEl HIJO envia algo por el pipe.\n");
            write(fd1[1], mensage, strlen(mensage));  //Escribe en el pipe
            wait (NULL);  //Espera a que finalice el proceso padre
            break;
        default: //proceso padre recibe

            close(fd1[1]);  //Cierra el descriptor de entrada de la tubería
            read(fd1[0], buffer, sizeof(buffer));  //leo el pipe
            printf("\tEl PADRE recibe algo por el pipe: %s\n", buffer);
            break;
    }
}
