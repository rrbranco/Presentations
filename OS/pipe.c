#include <unistd.h>

main()
{
	int childpid, mypid;
	int pipecom[2]; /* pipecom[0] para leitura e pipecom[1] para escrita */

	mypid=getpid();

	if ( pipe(pipecom) )
	{
		perror("\n Criando pipe\n");
		exit(-1);
	}

	if ( (childpid=fork()) )
	{
		/* Codigo pai  - executara primeiro */
		printf("\n Processo pai - Pid do filho: %d\n",childpid);
		char *escrever="Escrevi no pipe";
		int status;
		
		write(pipecom[1],escrever,strlen(escrever));

		wait(&status);

		printf("\n Processo pai - Filho terminou sua execucao\n");
		
	}
	else
	{
		/* Codigo filho */
		printf("\n Processo filho - Pid do pai: %d\n",mypid);
		char *ler;
		ler=(char *) malloc(sizeof(char) * 100);
		read(pipecom[0], ler, (sizeof(char) * 100));
		printf("\n Processo filho - Lido: %s\n",ler);
	
	}


}
