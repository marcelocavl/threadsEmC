#include <stdio.h>
#include<pthread.h>


void *tarefa(void *arg)
{
	int i,j,sum,contInt=1;
	char *nome=(char *)arg;
	while(1){
		sum=1;
		for (i=0;i<100;i++){
			for(j=0;j<800;j++){
				sum++;	
					
			}
		}
		printf("%s : iteração %d\n",nome,contInt);
		contInt++;
	}
}

int main() {
	pthread_t thread1,thread2,thread3,thread4;
	char *nome_thread1="thread1";
	char *nome_thread2="thread2";
	char *nome_thread3="thread3";
	char *nome_thread4="thread4";


	pthread_attr_t attr1, attr2,attr3,attr4;
  struct sched_param param1, param2,param3,param4;

	

  // Inicializa atributos
  pthread_attr_init(&attr1);
  pthread_attr_init(&attr2);
  pthread_attr_init(&attr3);
  pthread_attr_init(&attr4);


  // Define política de escalonamento como FIFO (ou RR)
  pthread_attr_setschedpolicy(&attr1, SCHED_FIFO);
  pthread_attr_setschedpolicy(&attr2, SCHED_FIFO);
  pthread_attr_setschedpolicy(&attr3, SCHED_FIFO);
  pthread_attr_setschedpolicy(&attr4, SCHED_FIFO);


  // Define prioridade
  param1.sched_priority = 3;
  param2.sched_priority = 3;
  param3.sched_priority = 3;
  param4.sched_priority = 4;


  pthread_attr_setschedparam(&attr1, &param1);
  pthread_attr_setschedparam(&attr2, &param2);
  pthread_attr_setschedparam(&attr3, &param3);
  pthread_attr_setschedparam(&attr4, &param4);


  // Habilita a utilização dos parâmetros definidos
  pthread_attr_setinheritsched(&attr1, PTHREAD_EXPLICIT_SCHED);
  pthread_attr_setinheritsched(&attr2, PTHREAD_EXPLICIT_SCHED);
  pthread_attr_setinheritsched(&attr3, PTHREAD_EXPLICIT_SCHED);
  pthread_attr_setinheritsched(&attr4, PTHREAD_EXPLICIT_SCHED);




	if(pthread_create(&thread1,&attr1,tarefa,(void *)nome_thread1)){
		printf("erro ao criar thread\n");
	}
	pthread_create(&thread2,&attr2,tarefa,(void *)nome_thread2);
	pthread_create(&thread3,&attr3,tarefa,(void *)nome_thread3);
	pthread_create(&thread4,&attr4,tarefa,(void *)nome_thread4);
		



	//pthread_setschedprio(thread1,10);
	//pthread_setschedprio(thread2,3);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_join(thread3,NULL);
	pthread_join(thread4,NULL);
				    			    
}

