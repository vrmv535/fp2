#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define LEFT (ph_num+4)%N
#define RIGHT (ph_num+1)%N

int state[N];
int phil_num[N]={0,1,2,3,4};

sem_t mutex;
sem_t S[N];

void *philosopher(void *num);
void take_fork(int);
void put_fork(int);
void test(int);

int main()
{
	pthread_t thread_id[N];

	sem_init(&mutex,0,1);

	int i;
	for(i=0;i<N;i++)
	{
		sem_init(&S[i],0,0);
	}

	for(i=0;i<N;i++)
	{

	pthread_create(&thread_id[i],NULL,philosopher,&phil_num[i]); 
	printf("philosopher %d is thinking\n",i+1);      //pthread_id[i],NULL,philosopher,phil_num[i]
    }

    for(i=0;i<N;i++)
	{

	pthread_join(thread_id[i],NULL); 
    }

}




void *philosopher(void *num)
{
	int *i =num;
	sleep(1);
	take_fork(*i);
	sleep(0);
	put_fork(*i);
}


void take_fork(int ph_num)
{
	sem_wait(&mutex);   //lock recpources

	state[ph_num]=HUNGRY;

	printf("the %d philosopher is hungry\n",ph_num+1);

	test(ph_num);

	sem_post(&mutex);

	sem_wait(&S[ph_num]);

	sleep(1);
}

void test(int ph_num)
{
	if(state[ph_num]==HUNGRY &&  state[LEFT] != EATING && state[RIGHT] != EATING)
	{
		state[ph_num]==EATING;

		printf("the %d philosopher lifts the %d and %d fork\n",ph_num+1,LEFT,ph_num+1);
		printf("the %d philosopher is eating\n",ph_num+1);

		sem_post(&S[ph_num]);
	}
}


void put_fork(int ph_num)
{
	sem_wait(&mutex);   //lock recpources

	state[ph_num]=THINKING;

	printf("the %d philosopher putting fork %d and %d fork down\n",ph_num+1,LEFT,ph_num+1);
	printf("the %d philosopher is thinking\n",ph_num+1);

	test(LEFT);
	test(RIGHT);

	sem_post(&mutex);  //release the recource
}
