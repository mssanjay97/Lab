#include<semaphore.h>
#include<pthread.h>
#include<stdio.h>
#include<string.h>
int think=0,hungry=1,eat=2;
int state[5];
int numberofphilosopher[5];
sem_t mutex,self[5];
void test(int philosopher)
{
    if (state[philosopher] == hungry && state[(philosopher+4)%5] != eat && state[(philosopher+1)%5] != eat)
    {
        state[philosopher] = eat;

        printf("Philosopher %d takes fork %d and %d\n",philosopher+1,(philosopher+4)%5+1,philosopher+1);
        printf("Philosopher %d is eat\n",philosopher+1);
        sem_post(&self[philosopher]);
    }
}

void putdown(int philosopher)
{
    sem_wait(&mutex);
    state[philosopher] = think;
    printf("Philosopher %d is currently thinking\n",philosopher+1);
    test((philosopher+4)%5);
    test((philosopher+1)%5);
    sem_post(&mutex);
}

void *philospherPROCESS(void *num)
{
    while(1)
    {
        int *i = num;

        pickup(*i);

        putdown(*i);
    }
}

void pickup(int philosopher)
{
    sem_wait(&mutex);
    state[philosopher] = hungry;
    printf("Philosopher %d is currently hungry\n",philosopher+1);
    test(philosopher);
    sem_post(&mutex);
    if(state[philosopher]!=eat)
    sem_wait(&self[philosopher]);
}

int main()
{
    int i;
for(i=0;i<5;i++)
numberofphilosopher[i]=i;
    pthread_t thread_id[5];
    sem_init(&mutex,0,1);
    for(i=0;i<5;i++)
        sem_init(&self[i],0,0);
    for(i=0;i<5;i++)
    {
        pthread_create(&thread_id[i],NULL,philospherPROCESS,&numberofphilosopher[i]);
        printf("Philosopher %d is currently thinking\n",i+1);
    }
    for(i=0;i<5;i++)
        pthread_join(thread_id[i],NULL);
}

