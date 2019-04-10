#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
void *CatsChance();
void *MiceChance();
int NumCats,NumBowls,NumMice,t_c,t_b,t_m;
sem_t EatingTime;
int main()
{
	pthread_t thread,thread1;
	printf("Enter the number of Mice  - ");
	scanf("%d",&NumMice);
	printf("Enter the number of cats  - ");
	scanf("%d",&NumCats);
    printf("Enter the Number of Bowls - ");
    scanf("%d",&NumBowls);
    printf("\n\t\t\t\n");
    t_c=NumCats;
    t_b=NumBowls;
    t_m=NumMice;
    sem_init(&EatingTime,0,1);
    while((NumBowls>0) && (NumCats>0) || (NumMice>0))
    {
    	pthread_create(&thread,NULL,CatsChance,NULL);
    	pthread_create(&thread1,NULL,MiceChance,NULL);
	}
	while((NumBowls>0) && (NumCats>0) || (NumMice>0))
	{
		pthread_join(thread,NULL);
		pthread_join(thread1,NULL);
	}
	printf("\n-------------------------------\n");
	return 0;
}
void *CatsChance()
{
	if(NumCats<=t_c && NumBowls<=t_b && NumBowls>0 && NumCats>0)
	{
		sem_wait(&EatingTime);
		NumBowls--;
		NumCats--;
		printf("\nCat %d has eaten the Bowl  %d ",(t_c - NumCats),(t_b - NumBowls));
		sem_post(&EatingTime);
	}
	else return 0;
}
void *MiceChance()
{
	if(NumMice<=t_m && NumBowls<=t_b && NumBowls>0 && NumMice>0)
	{
		sem_wait(&EatingTime);
		NumBowls--;
		NumMice--;
		printf("\n Mice %d has eaten the Bowl %d",(t_m - NumMice),(t_b - NumBowls));
		sem_post(&EatingTime);
		
	}
    else return 0;
}
