#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
/*-------------------------------------------*/
/* gestión de señales en proceso padre       */
void gestion_padre( int segnal )
{
    printf("Padre recibe señal..%d", segnal);
}
/*-------------------------------------------*/
int main()
{
    int contador = 0;
    int pid_padre, pid_hijo;

    pid_padre = getpid();
    pid_hijo = fork(); //creamos hijo

    switch(pid_hijo)
    {
        case -1:
            printf( "Error al crear el proceso hijo...\n");
            exit( -1 );
        case 0:   //HIJO
            //tratamiento de la señal en proceso hijo
            sleep(1);
            kill(pid_padre, SIGUSR1);//ENVIA SEÑAL AL PADRE
            sleep(1);
            kill(pid_padre, SIGUSR1);//ENVIA SEÑAL AL PADRE
            sleep(1);
            kill(pid_padre, SIGUSR1);//ENVIA SEÑAL AL PADRE
            while(contador<3) { //bucle 3 veces
                contador--;
                sleep(1);
                kill(pid_padre, SIGUSR1);//ENVIA SEÑAL AL PADRE
            }
            sleep(1);
            printf( "Proceso Padre a Terminado..");
            kill(pid_padre, SIGKILL);//TERMINA EL PROCESO PADRE
            break;
        default: //PADRE
            //tratamiento de la señal en proceso padre
            signal( SIGUSR1, gestion_padre );
            while (contador<=3){ //bucle 3 veces
                sleep(1);
                if(contador<3&&contador>0){
                    printf( "\n");
                }
                contador++;
            }
            break;
    }
    return 0;
}
/*
administrador@ubuntu1:~$ ps -fe | grep sincronizar
1000      1678  1549  0 22:20 pts/0    00:00:00 ./sincronizar
1000      1679  1678  0 22:20 pts/0    00:00:00 ./sincronizar
1000      1687  1572  0 22:21 pts/1    00:00:00 grep --color=auto sincronizar
administrador@ubuntu1:~$ kill 1679
   el padre queda a la espera
Padre recibe señal..10
administrador@ubuntu1:~$ kill 1678
Termina el proceso

Terminado

administrador@ubuntu1:~$

*/




