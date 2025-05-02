#include <stdio.h>
#include <pthread.h>


//funcao da primeira thread
void *tarefa(void* arg){
	printf("ola, sou a thread nova!\n");
	return NULL;
}


//thread principal (main)
int main() {

	pthread_t thread1;	//identificador da thread no sistema
	
	//cria nova thread
	//passamos o identificador da thread por referência pois quem vai inicializar essa variável é a funcao create
	//sendo argumento é os atributos da thread (tamanho da pilha da thread,prioridades,etc)(é um point)
	//
	if(pthread_create(&thread1,NULL,tarefa,NULL))	
		printf("deu erro\n");
  printf("passou\n"); 
}

