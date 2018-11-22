#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

#define N 5
#define LEFT (pno+4)%N
#define RIGHT (pno+1)%N

sem_t mutex;
sem_t S[N];
int state[N];
int phil[N] = {1,2,3,4,5};

void test(int pno)
{
    if(state[pno]==0&& state[LEFT] !=1 && state[RIGHT]!=1)
    {
        state[pno] = 1;
        sleep(2);
        printf("Philosopher %d takes fork %d and %d and is eating",pno,LEFT,pno);
    }
}

void take_fork(int pno)
{
    sem_wait(&mutex); 
    state[pno] = 1; 
    printf("Philosopher %d is Hungry\n", pno + 1); 
    test(pno); 
  
    sem_post(&mutex); 
    sem_wait(&S[pno]); 
    sleep(1); 
}

void put_fork(int pno)
{
    sem_wait(&mutex);
    state[pno] = 2;
    printf("Philosopher %d puts forks %d and %d down and thinks",pno,LEFT,pno);
    test(LEFT);
    test(RIGHT);
    sem_post(&mutex);
}


void *philosopher(void *num)
{
    while(1)
    {
        int *i = num;
        take_fork(*i);
        sleep(2);
        put_fork(*i);
        sleep(2);
    }
}

int main(int argc, char const *argv[])
{
    int i;
    pthread_t threads[N];
    sem_init(&mutex,0,1);

    for(i=0;i<N;i++)
        sem_init(&S[i],0,0);
    for(i=0;i<N;i++)
    {
        pthread_create(&threads[i],NULL,philosopher,&phil[i]);
        printf("Philosopher %d is thinking\n",i+1);
    }
    for(i=0;i<N;i++)
        pthread_join(threads[i],NULL);
    return 0;
}
