#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>
sem_t readermutex,writermutex;
int rc=0;
void * writerprocess(void *arg)
{
printf("\nwriterprocess %d is trying to enter into file",(int)arg);
sem_wait(&writermutex);
printf("\nwriterprocess %d is writting into file",(int)arg);
printf("\nwriterprocess %d finished writing in file");
sem_post(&writermutex);
}
void *readerprocess(void *arg)
{
printf("\nreaderprocess %d is trying to read the file",(int)arg);
sem_wait(&readermutex);
rc++;
if(rc==1)
{
sem_wait(&writermutex);
printf("\nreaderprocess %d is currently reading file",(int)arg);
}
sem_post(&readermutex);
sem_wait(&readermutex);
rc--;
if(rc==0)
{
printf("\nreaderprocess %d finished reading file",(int)arg);
sem_post(&writermutex);
}
sem_post(&readermutex);
}

int main()
{
int i=0,numread=0,numwrite;
sem_init(&readermutex,0,1);
sem_init(&writermutex,0,1);
pthread_t readerprocesss_thr[100],writerprocess_thr[100];
printf("\nenter total no of threads for readerprocesss");
scanf("%d",&numread);
printf("\nenter total no of threads for writerprocesss");
scanf("%d",&numwrite);
for(i=0;i<numread;i++)
{
pthread_create(&readerprocesss_thr[i],NULL,readerprocess,(void *)i);
}


for(i=0;i<numwrite;i++)
{
pthread_create(&writerprocess_thr[i],NULL,writerprocess,(void *)i);
}
for(i=0;i<numwrite;i++)
{
pthread_join(writerprocess_thr[i],NULL);
}

for(i=0;i<numread;i++)
{
pthread_join(readerprocesss_thr[i],NULL);
}
sem_destroy(&writermutex);
sem_destroy(&readermutex);
return 0;
}
