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
      }
	  printf("%d-->%d-->",LOW,HIGH);
      for(int j=n-1; j>=dloc+1; j--){
        printf("%d --> ",queue[j]);
      }
	}

	if(abs(queue[dloc+1])>=abs(queue[dloc-1]))
{
	for(int j=dloc+1;j<=n;j++)
		printf("%d -->",queue[j]);

	printf("%d -->%d -->",HIGH,LOW);
	
	for(int j=0;j<=dloc -1;j++)
	{
		printf("%d -->",queue[j]);
	}
}

	int totals, avgs;
	totals = head - LOW+ HIGH + max;
	avgs = totals/n;
	
	printf("\nTotal Seek time : %d \n",totals);
	printf("Avg seek time : %d \n",avgs);
}
