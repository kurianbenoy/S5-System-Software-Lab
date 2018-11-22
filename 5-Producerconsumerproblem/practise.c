#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

int shared_variable[100];
int p,i;
sem_t mutex;
char available=0;

void *producer(void *arg)
{
    while(1)
    {
        if(!available)
        {
            sem_wait(&mutex);
            p = rand();
            p = p%100 + 1;
            printf("Produced : %d\n",p);
            fflush(stdout);
            shared_variable[i] = p;
            i++;
            if(i>=10)
                available++;
            
            sem_post(&mutex);
        }
        if(i >= 10)
			return NULL;
    }
}

void *consumers(void *arg)
{
    int c,i=9;
    while(1)
    {
        if(available!=0)
        {
            sem_wait(&mutex);
            c = shared_variable[i];
            printf("Consumed: %d",c);
            fflush(stdout);
            i--;
            if(i<0)
                available--;
            sem_post(&mutex);
        }
    }
}


int main()
{
    pthread_t ct,pt;
    sem_init(&mutex,0,1);
    pthread_create(&pt,NULL,producer,NULL);
    pthread_create(&ct,NULL,consumers,NULL);

    pthread_join(pt,NULL);
    pthread_join(ct,NULL);
}