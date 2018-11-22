#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define UPPER 100
#define LOWER 1

int shared_variable[50];
char available = 0;
sem_t mutex;

void* producer(void* arg)
{
	int p, i = 0;

	while(1)
	{
		if(!available)
		{
			sem_wait(&mutex);

			p = rand();
			p = p%(UPPER - LOWER + 1) + LOWER;
			printf("Produced: %d\n", p);
			fflush(stdout);
			shared_variable[i] = p;
			i++;

			if(i >= 5)
			{
				available++;
			}

			sem_post(&mutex);
		}
		if(i >= 5)
			return NULL;
	}
}

void* consumer(void* arg)
{
	int c, i = 4;

	while(1)
	{
		if(available)
		{
			sem_wait(&mutex);
			c = shared_variable[i];
			printf("Consumed: %d\n", c);
			fflush(stdout);
			i--;

			if(i < 0)
			{
				available--;
//				i = 4;
			}

			sem_post(&mutex);
		}
		if(i < 0)
			return NULL;
	}
}

void main()
{


	pthread_t producert,consumert;
	sem_init(&mutex,0,1);
	pthread_create(&producert,NULL,producer,NULL);
	pthread_create(&consumert,NULL,consumer,NULL);

	pthread_join(producert,NULL);
	pthread_join(consumert,NULL);


}
