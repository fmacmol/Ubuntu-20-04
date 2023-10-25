#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main (void) {
	int fp;
	int p, bytesleidos;
	char buffer[1];

	p=mknod("FIFO1", S_IFIFO|0666,0);  //Creamos un FIFO con permiso de lectura y escritura

	if (p==-1) {
		printf("Ha ocurrido un error creando el FIFO...\n");
		exit (-1);
	}

	while (1){
		fp = open("FIFO1", 0);    //Abrimos el FIFO en modo lectura
		bytesleidos = read (fp, buffer, 1);
		printf ("OBTENIENDO Información: ");
		while (bytesleidos!=0){
			printf("%c", buffer[0]);
			bytesleidos=read (fp, buffer, 1);
		}
		close (fp);
	}
	return(0);
}
