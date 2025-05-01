#include <stdio.h>
#include <pthread.h>


void print_num1(void)
{
	int x=10;
	while (x>0){
		printf("print 1\n");
		x--;
	}
	return;
}

void print_num2(void)
{
	int x=10;
	while (x>0){
		printf("print 2\n");
		x--;
	}
	return;
}


int main() {

	pthread_t thread1;   	
	pthread_t thread2;   	
	
	int y=10;

	print_num1();
	print_num2();
	printf("--------------\n");
	pthread_create(&thread1,NULL,(void *)print_num1,NULL);
	pthread_create(&thread2,NULL,(void *)print_num2,NULL);

	pthread_join(thread1,NULL);	
	pthread_join(thread2,NULL);	

	return 0;
 
}

