#include<iostream>
using namespace std;


// A function to merge the two half into a sorted data.
void Merge(int *a, int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;

	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
 
	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
 
 
	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}
 
// A function to split array into two parts.
void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		// Split the data into two half.
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
 
		// Merge them to get sorted output.
		Merge(a, low, high, mid);
	}
}


/* Main loop*/

int main()
{
	int n,bt[100],wt[100],tat[100],avwt=0,avtat=0,i,j;
	int total;
	cout<<"Enter the no of processes\n";
	cin>>n;

	for(i=0;i<n;i++)
	{
        cout<<"Enter the burst time of process P["<<i+1<<"]";
        cin>>bt[i];
	}

	int st[100];
// Copying burst time to a temperoary array
	for(i=0;i<n;i++)
	{
        	st[i] = bt[i];
	}


	MergeSort(bt,0,n-1);
	
	/* Checking merge sort program
	for(i=0;i<n;i++)
	{
		cout<<st[i];
	}*/

/* Calculating the waiting time*/
	wt[0] = 0;
	for(i=1;i<n;i++)
	 {
		wt[i] = 0;
		for(j=0;j<i;j++)
		{
			wt[i]+=bt[j];
//			cout<<wt[i]<<"\n";
		}
		total += wt[i];
	}
	
	avwt = total/n;

	 cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
 
    //calculating turnaround time
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        
        avtat+=tat[i];
        cout<<"\nP["<<i+1<<"]"<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
    }

    avtat/=i;
    cout<<"\n\nAverage Waiting Time:"<<avwt;
    cout<<"\nAverage Turnaround Time:"<<avtat;

	return 0;
}
