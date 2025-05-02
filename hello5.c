
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

//Saldo total do usuario
int saldo_total=1000;

sem_t sem;

//Funcao de saque de valor do saldo
void saque(void *arg)
{
	sem_wait(&sem);
	int conta=saldo_total;
	int x=1000000000;
	conta=conta-*(int *)arg;
	while(x>0){x--;}		//loop
	saldo_total=conta;
	sem_post(&sem);
	return;

}

//Funcao de depositar no valor do saldo
void deposito(void *arg)
{
	sem_wait(&sem);
	int conta=saldo_total;
	conta=conta+*(int *)arg;
	saldo_total=conta;
	sem_post(&sem);
	return;
}


int main() {
		//Indicadores de thread 
		pthread_t thread1,thread2;    
		sem_init(&sem,0,1);
		
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

