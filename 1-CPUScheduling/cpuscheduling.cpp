#include<iostream>
using namespace std;


void roundrobin(int bt[100],int n)
{
    int count,j,time,remain,flag=0,time_quantum; 
    int wait_time=0,turnaround_time=0,at[10],rt[10]; 
    cout<<"Enter the time quantum";
    cin>>time_quantum;

    for(count=0;count<n;count++) 
  { 
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1); 
    scanf("%d",&at[count]); 
    scanf("%d",&bt[count]); 
    rt[count]=bt[count]; 
  } 

  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,count=0;remain!=0;) 
  { 
    if(rt[count]<=time_quantum && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]); 
      wait_time+=time-at[count]-bt[count]; 
      turnaround_time+=time-at[count]; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(at[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
  
  }



void Merge(int *a, int low, int high, int mid)
{
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;

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

	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
 
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
 
 
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}
 
void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
 
		Merge(a, low, high, mid);
	}
}




void fcfs(int bt[20],int n)
{
    int tat[20],avwt=0,avtat=0, wt[20];
    int i,j;	
//calculating waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++){
            wt[i]+=bt[j];
	    cout<<wt[i]<<"\n";
 } 
}

 cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time"; //calculating turnaround time
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
       std::cout<<"\nP["<<i+1<<"]"<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
    }
 
    avwt/=i;
    avtat/=i;
    cout<<"\n\nAverage Waiting Time:"<<avwt;
    cout<<"\nAverage Turnaround Time:"<<avtat;
}

void sjf(int bt[100],int n)
{
	int wt[100],i,j,avwt=0,tat[100],avtat=0,total=0;
	int st[100];
// Copying burst time to a temperary array
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

}


/*void priorityschedule(int btp[100],int pt[100],int n)
{
	int i = 0;
	MergeSort(pt,0,n-1);
	
	for(i=1;i<n;i++)
	{
		bt[i] = 
			
}*/

int main()
{
    int n,bt[20],wt[20],ch,i,btp[30],pt[30];
    
    cout<<"Enter total number of processes(maximum 20):";
    cin>>n;
 
    cout<<"\nEnter Process Burst Time\n";
    for(i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]:";
        cin>>bt[i];
    }


    while(1)
    {
	cout<<"Enter the MENU\n";
	cout<<"\n1.FCFS\n";
	cout<<"\n2. SJF \n";
	cout<<"\n3. Round Robin \n";
	cin>>ch;

	switch(ch)
	{
	case 1:
		fcfs(bt,n);
		break;
	case 2: sjf(bt,n);
		break;
	case 3: roundrobin(bt,n);
		break;
}

    return 0;
}
}
