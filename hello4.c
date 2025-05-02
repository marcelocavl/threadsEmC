/*
	ESSE PROGRAMA TEM UM CASO ENGRAÇADO ONDE O **saldo_total** NO FIM FICA IGUAL A 500
	HIPÓTESE:TALVEZ O PROGRAMA MAIN ACABA ANTES DO DEPOSITO
*/

#include <stdio.h>
#include <pthread.h>

//Saldo total do usuario
int saldo_total=1000;

//Funcao de saque de valor do saldo
void saque(void *arg)
{
	saldo_total=saldo_total-*(int *)arg;
	return;
}

//Funcao de depositar no valor do saldo
void deposito(void *arg)
{
	saldo_total=saldo_total+*(int *)arg;
	return;
}


int main() {
		//Indicadores de thread 
		pthread_t thread1,thread2;    
		
		int valor_do_saque=500;		 //Valor que iremos sacar da conta corrente
		int valor_do_deposito=400; //Valor que iremos depositar na conta corrente

		//inicializando as threads	
		pthread_create(&thread1,NULL,(void *)saque,(void *)&valor_do_saque);
		pthread_create(&thread2,NULL,(void *)deposito,(void *)&valor_do_deposito);
	
		//Thread main irá esperar as threads iniciadas finalizarem para poder finalizar	
		pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);

		printf("acabou as transações\n");
		printf("saldo final: %d\n",saldo_total);
    return 0;
}

