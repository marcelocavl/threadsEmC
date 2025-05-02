#include <stdio.h>
#include <pthread.h>


typedef struct nums
{
	int x;	//valor x para somar
	int y;	//valor y para somar
}t_nums;


void sum(void *arg)
{
	t_nums temp=*(t_nums *)arg;
	int soma=temp.x +temp.y;
	printf("%d\n",temp.x);
	printf("%d\n",temp.y);
	printf("%d\n",soma);
	
	return;
}

int main() {
	pthread_t thread1;
	t_nums numeros={45,46};

	pthread_create(&thread1,NULL,(void *)sum,(void *)&numeros);

	pthread_join(thread1,NULL);
	    
}

