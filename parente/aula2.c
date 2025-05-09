#include <stdio.h>
#include<pthread.h>
#define TAM_BUFFER 10

int buffer=0;

sem_t empty,full,mutex;

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	FUNCOES UTILS
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
//funcao de produzir produto
int produzir()
{
	return 2;
}
//funcao de inserir no buffer o produto
void inserir_produto(int produto)
{
	buffer=buffer+produto;
	return;
}

//funcao de retirar no buffer o produto
void retirar_produto()
{
	buffer=buffer-produto;
	return;
}

void print_buffer()
{
	printf("buffer: %d\n",buffer);
	return;
}


/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	FUNCOES PARA THREADS
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

//funcao da thread produtor
void *produtor()
{
	while(1){
	print_buffer();
	//produzindo...
	produto=produzir();

	//regiao crítica
	sem_wait(&empty);
	sem_wait(&mutex);
	inserir_produto(produto);
	sem_post(&full);
	sem_post(&mutex);
		
	}
}

//funcao da thread consumidor
void *consumidor()
{
	//regiao critica
	while(1){
	print_buffer();
	sem_wait(&full);
	sem_wait(&mutex);
	retirar_produto();
	sem_post(&empty);
	sem_post(&mutex);
	}
	
}


int main() {
	//alocando threads
	pthread_t				produtor,consumidor1,consumidor2;	

	sem_init(&empty,0,TAM_BUFFER); //inicializando semaforo empty
	sem_init(&full,0,0);	 				 //inicializando semaforo full
	sem_init(&mutex,0,1);					 //inicializando semaforo mutex

	pthread_create(&produtor,NULL,produtor,NULL);
	pthread_create(&consumidor1,NULL,produtor,NULL);
	pthread_create(&consumidor2,NULL,produtor,NULL);
