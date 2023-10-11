#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Para mejorar este código habrá que cerrar la boca del pipe que no se usa en cada proceso (ver los siguientes ejemplos

int main ()
{
  int tuberia[2];
  char buffer[30];
  pid_t pid;

  pipe(tuberia); //Se crea el pipe y se generan los descriptores de ficheros en tuberia[0] (lectura) y tuberia[1] (escritura)

  pid=fork();  //Se crea el proceso hijo

  switch(pid)
  {
    case -1: //error
             printf("No se ha podido crear el proceso hijo...");
             exit(-1);
             break;
    case 0:  //proceso hijo
             printf("El hijo escribe en el pipe...\n");
             write(tuberia[1], "Hola papi", 10);
             break;
    default: //proceso padre
             wait (NULL);  //Espera a que finalice el proceso hijo
             printf("El padre lee del pipe...\n");
             read(tuberia[0], buffer, 10);
             printf("\tMensaje leí­do: %s\n", buffer);
             break;
  }
  exit(0);
}
