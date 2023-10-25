#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int fp;
	char saludo[] = "Un saludo!!! por tuberías....\n";
	fp = open("FIFO1", 1); //Abro el FIFO (que ya debe estar creado) en modo escritura

	if (fp == -1) {
		printf("Error al abrir el FIFO\n");
		exit(-1);
	}

	printf("Enviando información al FIFO...\n");
	write(fp, saludo, strlen(saludo));
	close(fp);
	return (0);
}
