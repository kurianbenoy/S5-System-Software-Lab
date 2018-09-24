#include<stdio.h>
#include<stdlib.h>

# define LOW 0

int main()
{
	int n,queue[100],head,i,j;
	int dloc,min,max,high,totals,avg;
	
	printf("\n Enter the maximum \n");
	scanf("%d",&high);

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

	for(int i=0;i<n;i++){
		if(head == queue[i])
		{
			dloc = i;
			break;
			}
		}
	
	if(abs(queue[dloc-1])>=abs(queue[dloc+1]))
	{
		for(int j=dloc; j>=0; j--){
        printf("%d --> ",queue[j]);
		totals += abs(queue[j]-head);
		head = queue[j];
      }
	  printf("%d-->%d-->",LOW,high);
      for(int j=n-1; j>=dloc+1; j--){
        printf("%d --> ",queue[j]);
		totals += abs(queue[j]-head);
		head = queue[j];
      }
	}

	if(abs(queue[dloc+1])>=abs(queue[dloc-1]))
{
	for(int j=dloc+1;j<=n;j++)
	{
		printf("%d -->",queue[j]);
		totals += abs(queue[j]-head);
		head = queue[j];
	}

	printf("%d -->%d -->",high,LOW);
	
	for(int j=0;j<=dloc -1;j++)
	{
		printf("%d -->",queue[j]);
		totals += abs(queue[j]-head);
		head = queue[j];
	}
}

	printf("\nTotal Seek time : %d \n",totals);
	avgs = totals/n;
	printf("Avg seek time : %d \n",avgs);
}

