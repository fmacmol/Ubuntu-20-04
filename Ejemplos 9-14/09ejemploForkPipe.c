#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//ABUELO-HIJO-NIETO

int main ()
{
  pid_t pid, Hijo_pid, pid2, Hijo2_pid;


  int tuberia1[2];
  int tuberia2[2];

  char saludoAbuelo[]="Saludos del abuelo....";
  char saludoPadre[]="Saludos del padre....";
  char saludoHijo[]="Saludos del hijo....";
  char saludoNieto[]="Saludos del nieto....";

  char buffer[80];

  pipe(tuberia1);
  pipe(tuberia2); //Se crean los pipes y se generan los descriptores de ficheros en tuberia[0] (lectura) y tuberia[1] (escritura)

  pid=fork();  //El abuelo crea a su hijo

  switch(pid)
  {
    case -1: //error
             printf("No se ha podido crear el proceso hijo...");
             exit(-1);
             break;
    case 0:  //proceso hijo
             pid2= fork();   //El hijo crea al nieto
             switch(pid2)
             {
               case -1: //error
                        printf("No se ha podido crear el proceso nieto en el hijo...");
                        exit(-1);
                        break;
               case 0:  //proceso nieto
                        //NIETO RECIBE
                        close(tuberia2[1]);
                        read(tuberia2[0], buffer, sizeof(buffer));
                        printf("\t\tEl nieto recibe el mensaje de su padre: %s\n", buffer);

                        // NIETO ENVÃA
                        printf("\t\tNieto envía mensaje a su padre...\n");
                        close(tuberia1[0]);
                        write(tuberia1[1], saludoNieto, strlen(saludoNieto));
                        break;
               default: //proceso padre (HIJO)
                        //HIJO RECIBE de abuelo
                        close(tuberia1[1]);
                        read(tuberia1[0], buffer, sizeof(buffer));
                        printf("\tEl hijo recibe el mensaje del abuelo: %s\n", buffer);

                        // HIJO ENVÍAA a nieto
                        printf("\tHijo envÃ­a mensaje al nieto...\n");
                        close(tuberia2[0]);
                        write(tuberia2[1], saludoPadre, strlen(saludoPadre));
                        Hijo2_pid = wait(NULL);

                        //HIJO RECIBE de nieto
                        close(tuberia1[1]);
                        read(tuberia1[0], buffer, sizeof(buffer));
                        printf("\tEl hijo recibe el mensaje del nieto: %s\n", buffer);

                        // HIJO ENVÍAA a abuelo
                        printf("\tHijo enví­a mensaje al abuelo...\n");
                        close(tuberia2[0]);
                        write(tuberia2[1], saludoHijo, strlen(saludoHijo));
                        Hijo_pid = wait(NULL);
                        break;
             }
             break;
    default: //proceso abuelo
             // ABUELO ENVÍAA
             printf("Abuelo enví­a mensaje al hijo...\n");
             close(tuberia1[0]);
             write(tuberia1[1], saludoAbuelo, strlen(saludoAbuelo));
             Hijo_pid = wait(NULL);

             //ABUELO RECIBE
             close(tuberia2[1]);
             read(tuberia2[0], buffer, sizeof(buffer));
             printf("El abuelo recibe el mensaje del hijo: %s\n", buffer);
             break;
  }
  exit(0);
}
