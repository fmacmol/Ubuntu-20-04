#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main ()
{
  int tuberia[2];
  pid_t pid;
  char saludoPadre[]="Buenos dí­as, hijo....";
  char buffer[80];

  pipe(tuberia); //Se crea el pipe y se generan los descriptores de ficheros en tuberia[0] (lectura) y tuberia[1] (escritura)
  pid=fork();  //Se crea el proceso hijo

  switch(pid)
  {
    case -1: //error
             printf("No se ha podido crear el proceso hijo...");
             exit(-1);
             break;
    case 0:  //proceso hijo recibe
             close(tuberia[1]);  //Cierra el descriptor de entrada de la tuberí­a
             read(tuberia[0], buffer, sizeof(buffer));  //leo el pipe
             printf("\tEl hijo recibe algo por el pipe: %s\n", buffer);
             break;
    default: //proceso padre enví­a
             close(tuberia[0]);  //Cierra el descriptor de salida de la tuberí­a
             write(tuberia[1], saludoPadre, strlen(saludoPadre));  //Escribe en el pipe
             wait (NULL);  //Espera a que finalice el proceso hijo
             break;
  }
  exit(0);
}
