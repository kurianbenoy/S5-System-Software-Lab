#include<stdio.h>
#include<stdlib.h>

# define LOW 0
# define HIGH 200

int main()
{
	int n,queue[100],head,i,j;
	int dloc,min,max;
	
	printf("\n Enter the no of disk location");
	scanf("%d",&n);
	
	printf("\n Enter the head position\n");
	scanf("%d",&head);
	for(i=0;i<n;i++)
	{
		printf("Enter the queue position Q[%d]",i);
		scanf("%d",&queue[i]);
	}

	queue[n] = head;

	void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

	void sort(int arr[],int n)
	{
	for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++)
		if(arr[j]>arr[j+1])
		{
		swap(&arr[j],&arr[j+1]);
		}
	}
	
	sort(queue,n+1);

	
	min = queue[0];
	max = queue[n];
	
	// locate head in queue
	
	dloc = 0;
	for(int i=0;i<n;i++) {
		if(queue[i]==head) 
		{
			dloc = i;
			break;	
			}
		}

	if(abs(head-LOW)<=abs(head-HIGH))
	{
		for(int j=dloc; j>=0; j--){
        printf("%d --> ",queue[j]);
      }
	  printf("%d -->",LOW);
      for(int j=dloc+1; j<n; j++){
        printf("%d --> ",queue[j]);
      }
	  printf("%d -->",HIGH);
	}


	int totals,avgs;

	totals =  head- min+max-queue[dloc+1];
	avgs = totals/n;
	
	printf("\n Total Seek time : \t %d",totals);
	printf("\n Average Seek time : \t%d",avgs);

	return 0;
}
