#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define tnum 5
long long array_g[tnum];
void * runner_1(void * varg){
	int i = * ((int *) varg);
	array_g[i] = ( long long ) pthread_self();
	printf("Printing from thread %lld\n",(long long)pthread_self());
	return NULL;
}
int main(  ) {
	pthread_t threads[tnum];
	for (int i = 0; i < tnum; i++){
		pthread_create(&threads[i],NULL,runner_1,&i);
	}
	printf("thread creation is done");
	for (int i = 0; i < tnum; i++){
		pthread_join(threads[i],NULL);
	}
	for (int i = 0; i < tnum; i++){
		printf("array index %d is %lld\n",i,array_g[i + 1]);
	}
	return 0;
}
