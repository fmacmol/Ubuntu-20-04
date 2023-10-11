#include <stdio.h>
#include <unistd.h>

void main()
{
  pid_t id_pactual, id_padre;

  id_pactual = getpid();
  id_padre = getppid();

  printf ("PID de este proceso: %d\n", id_pactual);
  printf ("PID del proceso padre de este: %d\n", id_padre);
}
