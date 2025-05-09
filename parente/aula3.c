#include <stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t a,b;

void *thread_a()
{
	int i,j;
	while(1){
	for(i=0;i<1000;i++){
		for(j=0;j<2000;j++){
			sem_wait(&a);
			printf("A\n");
			sem_post(&b);

		}
	}		
	}
}

void *thread_b()
{
	int i,j;
	while(1){
	for(i=0;i<10000;i++){
		for(j=0;j<2000;j++){
			sem_wait(&b);
			printf("B\n");
			sem_post(&a);

		}
	}
}
}

int main() {
	pthread_t thread1,thread2;

	sem_init(&a,0,1);
	sem_init(&b,0,1);
		
	pthread_create(&thread1,NULL,thread_a,NULL);
	pthread_create(&thread2,NULL,thread_b,NULL);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
				    
}

