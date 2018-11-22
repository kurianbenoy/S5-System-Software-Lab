#include<iostream>
#include<algorithm>

void fcfs(int bt[100],int n)
{
    int tat[100],wt[100];
    int avwt=0,avtat=0;
    std::cout<<"Waiting time\n";
    wt[0] = 0;
    for(int i=1;i<n;i++)
    {
        // std::cout<<wt[i]<<"\n";
        wt[i] = wt[i-1]+ bt[i-1];
        std::cout<<wt[i]<<"\n";
    }
    std::cout<<"Turnaround Time\n";
    for(int i=0;i<n;i++)
    {
        tat[i] = wt[i] + bt[i];
        std::cout<<tat[i]<<"\n";
        avwt += wt[i];
        avtat + tat[i];
    }
    std::cout<<"Average waiting time\n"<<avwt<<"\nAvg TAT\n"<<avtat;

}

void sjf(int bt[100],int n)
{
    int tat[100],wt[100];
    int avwt=0,avtat=0;

    std::sort(bt,bt+n);
    wt[0] = 0;
    std::cout<<"Waiting time\n";
    for(int i=1;i<n;i++)
    {
        std::cout<<"Bt Array"<<bt[i];
        wt[i] = wt[i-1]+ bt[i-1];
        std::cout<<wt[i]<<"\n";
    }
    std::cout<<"Turnaround Time\n";
    for(int i=0;i<n;i++)
    {
        tat[i] = wt[i] + bt[i];
        std::cout<<tat[i]<<"\n";
        avwt += wt[i];
        avtat += tat[i];
    }
    std::cout<<"Average waiting time\n"<<avwt<<"\nAvg TAT\n"<<avtat;

}

void priority(int bt[100],int pr[100],int n)
{
    int P[100], wt[100],avwt,avtat,tat[100];
    // P = pr;
    for(int i=0;i<n;i++)
    {
        P[i] = pr[i];
    }
    std::sort(pr,pr+n);
    wt[0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(pr[i]==P[j])
            {
            wt[i+1] = wt[i] + bt[j];
            std::cout<<"wt\t"<<wt[i]<<"\tbt\t "<<bt[j]<<"\n";
            }
        }
    }

    std::cout<<"Turnaround time\n";
    for(int i=0;i<n;i++)
    {
        tat[i] = wt[i] + bt[i];
        std::cout<<tat[i]<<"\n";
        avwt += wt[i];
        avtat += tat[i];
    }
    std::cout<<"Average waiting time\n"<<avwt<<"\nAvg TAT\n"<<avtat;
}

void roundrobin(int bt[100],int quantum,int n)
{
    int wt[100],i,j,total;
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
				// std::cout<<wt[i]<<"\n";
            std::cout<<"WT["<<j<<"]"<<wt[j];

				}
		}
        // std::cout<<"WT["<<i<<"]"<<wt[i];
		std::cout<<"\n";
		total += wt[i];
		std::cout<<total/n;
	}
}

int main()
{
    int choice,quantum;
    int wt[100],bt[100],tat[100],no,pr[100];
    std::cout<<"MENU\n 1. FCFS\n 2. SJF \n3.Round Robin \n4.Priority queue \n";
    std::cin>>choice;
    std::cout<<"Enter size of bt \n Enter elements of burst time";
    std::cin>>no;
    for(int i=0;i<no;i++)
    {
        std::cin>>bt[i];
    }

    switch(choice)
    {
        case 1: fcfs(bt,no);
                break;
        case 2: sjf(bt,no);
                break;
        case 3: std::cout<<"Enter Time quantum\n";
                std::cin>>quantum;
                roundrobin(bt,quantum,no);
                break;
        case 4: std::cout<<"Enter priority of process nos\n";       
                for(int i=0;i<no;i++)
                {
                std::cin>>pr[i];
                }
                priority(bt,pr,no);
                break;
    }
}
