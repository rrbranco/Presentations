#include <sys/types.h>
#include <unistd.h>

main()
{
	int status;

	if ( fork() )
	{
		/* Pai */
		printf("\n codigo pai executando normalmente\n");
		wait(&status); // espera o filho terminar

		printf("\n continuando execucao apos termino do filho\n");

	}
	else
	{
		/* Filho */
		execve("/bin/bash", NULL, NULL);

		printf("\n nao devera executar\n");

	}

}
