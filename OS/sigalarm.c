/*
*  Ideia para fazer um scheduler em modo usuario
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


/* Handler do sinal */
void hookalarm(int sinal) {

        printf("\n Sinal Recebido \n");

        /* Agenda um novo sinal */
        alarm(5);

        return ;
}

int main(int argc, char **argv) 
{
        /* Adiciona o handler */
        if (signal(SIGALRM, hookalarm) < 0) {
                perror("handler");
                return -1;
        }

        /* Schedula um sinal para daqui 5 segundos */
        alarm(5);

        while(1) {

                printf("loop\r");

        }

        /* Nunca chegara aqui */

        return 1;
}
