#include <sys/types.h>
#include <unistd.h>


main()
{

	if  ( setuid(1001) )
	{
			perror("\n Mudando de usuario\n");
			exit(-1);
	}

	printf("\n UserID: %d\n",getuid());

	if ( chdir("/teste") )
	{
			perror("\n Mudando para o diretorio /teste\n");
			exit(-1);
	}

	printf("\n Tive permissoes\n");

}
