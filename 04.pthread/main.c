#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
void *thread_fun1(void * arg){
	int i=*((int *) arg);
	printf("\nthread1\n");
	printf("%d cube is %d\n", i,(i*i*i));
	return ;
}
void *thread_fun2(){
	printf("\nthread2\n");
	int n;
	printf("\nenter the number to be squared\n");
	scanf("%d",&n);
	printf("the Square of %d is %d\n",n,n*n);
}
int main()
{
	pthread_t pid1,pid2;
	int i=6;
	void *status;
	pthread_create(&pid1,NULL,thread_fun1,(void *)&i);
	pthread_join(pid1,&status);
	pthread_create(&pid2,NULL,thread_fun2,NULL);
	pthread_join(pid2,&status);
	return 0;
}