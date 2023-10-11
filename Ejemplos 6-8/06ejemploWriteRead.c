#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ATENCIÓN: Este programa presupone la existencia de un fichero "texto.txt" vacío

void main ()
{
  char saludo[]="Un saludo!!!\n";
  char buffer[10];
  int fd, bytesleidos;

  fd=open("texto.txt",1);  //Se abre fichero para solo escritura

  if (fd==-1)
  {
    printf("ERROR AL ABRIR EL FICHERO...\n");
    exit(-1);
  }

  printf("Escribo el saludo...\n");
  write(fd, saludo, strlen(saludo));
  close(fd);    //Cierro el fichero

  fd=open("texto.txt", 0);   //El fichero se abre solo para lectura
  printf("Contenido del fichero: \n"); 
//leo bytes de uno en uno y lo guardo en buffer 
  bytesleidos = read(fd,buffer,1);
  while (bytesleidos !=0) {
  printf("%s", buffer); 
  bytesleidos = read(fd, buffer, 1);
 } 

  close (fd);
}
