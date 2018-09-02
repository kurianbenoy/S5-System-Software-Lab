#include<iostream>
using namespace std;

int main()
{
        int n,bt[100],wt[100],tat[100],avwt=0,avtat=0,i,j;
        int total,quantum;
        cout<<"Enter the no of processes\n";
        cin>>n;
	cout<<"Enter the quantum\n";
	cin>>quantum;

        for(i=0;i<n;i++)
        {
        cout<<"Enter the burst time of process P["<<i+1<<"]";
        cin>>bt[i];
        }

	/* Calculate the waiting time*/
	wt[0] =  0;
	for(i=1;i<n;i++)
	{
		wt[i] = 0;
		for(j=0;j<n;j++)
		{
			wt[i]+=bt[j];
			if(wt[i]>quantum)
				{
				wt[i]+= quantum;
				cout<<wt[i]<<"\n";
				}
		}
		cout<<"\n";
		total += wt[i];
		cout<<total;
	}


} 
