#include<bits/stdc++.h>
using namespace std;

int main()
{
	int Avail[10];
	int Max[100][100],Alloc[100][100],Need[100][100];
	int m,n,i,j;

	cout<<"Enter the no of Processes";
	cin>>m;

	cout<<"Enter the no of Resources";
	cin>>n;

	cout<<"Enter Maximum resources for each Process";
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<"Enter resources for process P[ "<<i<<"]";
			cin>>Max[i][j];
		}
		cout<<"\n";
	}

	cout<<"Enter Allocated resources for each Process";
	for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
			cout<<"Enter resources for process P[ "<<i<<"]";
			cin>>Alloc[i][j];
			Need[i][j] = Max[i][j] - Alloc[i][j];
			}
		cout<<"\n";
		}

	cout<<"Enter the total available resources in System";
		for(i=0;i<m;i++)
		{
			cin>>Avail[i];
		}

	
	   cout<<"ALLOCATION  | MAXIMUM  | NEED \n";
       for(i=0;i<m;i++)
	   {
		   for(j=0;j<n;j++)
		   {
			 cout<<Alloc[i][j]<<"\t"<<Max[i][j]<<"\t"<<Need[i][j]<<"\t";
		   }
		   cout<<endl;
	   }


		
		// Calculate the Available and check if each state is safe or not

/*	  for(i=0;i<n;i++)
	  {
			for(j=0;j<n;j++)
			{
				if(Need[i][j]<Avail[j])
					Avail[j] = Avail[j] + Alloc[i][j];
			cout<<Avail[j]<<"\n";
			}
		  }*/

/*	void search(int i)
	{
		for(j=0;j<n;j++)
		  if(Need[i][j]<Avail[j])
			  return 0;
		  return -1;
	}` */
	return 0;
}

