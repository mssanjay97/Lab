/*DONE BY M.S.SANJAY 15BCE0517*/
#include<pthread.h>
#include <stdio.h>
#include <semaphore.h>
int buffer[100];
sem_t mutex,full,empty;
void * producer()
{
int i=0,nextproduce,in=0;
for(i=0;i<50;i++)
{
sem_wait(&empty);
sem_wait(&mutex);
buffer[in]=i;
printf("\nproducer is producing item=%d",buffer[in]);
in=((in+1)%100);
  sem_post(&mutex);
sem_post(&full);
}
}
void * consumer()
{
int i,nextconsumed,out=0;
for(i=0;i<50;i++)
{
sem_wait(&full);
sem_wait(&mutex);
nextconsumed=buffer[out];
printf("\nconsumer is consuming item=%d",nextconsumed);
out=((out+1)%100);
sem_post(&mutex);
 sem_post(&empty);
}
}
int main()
{
pthread_t tid1;
pthread_t tid2;
sem_init(&mutex,0,1);
sem_init(&full,0,0);
sem_init(&empty,0,10);
pthread_create(&tid1,NULL,&producer,NULL);
pthread_create(&tid2,NULL,&consumer,NULL);
pthread_join(tid1, NULL);
pthread_join(tid2, NULL);
sem_destroy(&mutex);
sem_destroy(&full);
sem_destroy(&empty);
return 0;
}
