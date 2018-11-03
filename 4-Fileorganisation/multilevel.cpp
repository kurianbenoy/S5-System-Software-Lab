#include <iostream>
#include<string.h>

using namespace std;

struct Dir {
	char dname[10],filename[10][10];
	int fno;
}file[100]; 

int main()
{
	//Dir file;
	int i,ch;
	char fsearch[100];
	cout<<"ENTER name of directory \n";
	cin>>file.dname;
//	cout<<"Enter the no of files\n";
//	cin>>file.fno;

	while(1)
	{
	cout<<"Enter the FILE OPERATION TO PERFORM \n 1. INSERT A FILE \n 2. DELETE A FILE \n 3. DISPLAY FILES \n 4. END\n 5. SEARCH A FILE";
    cin>>ch;
	switch(ch)
	{
		case 1 : cout<<"Enter file to be inserted";
				 cin>> file.filename[file.fno];
				 file.fno++;
				 break;

		case 2: cout<<"Enter file to be Deleted \n";
				cin>>fsearch;
				for(i=0;i<10;i++)
				{
					if(strcmp(fsearch,file.filename[i])==0)
					{
						
						strcpy(file.filename[i],file.filename[i-1]);
						cout<<"File to be deleted is"<<fsearch;
						break;
					}
				}
				break;

		case 3: cout<<"Files to be displayed are \n";
				cout<<"File contents are \n";
				for(i=0;i<file.fno;i++)
				{
					cout<<file.filename[i];
				}
				break;

		case 4: exit(0);
		case 5: cout<<"Enter file to ";
				cin>>fsearch;
				for(i=0;i<10;i++)
				{
					if(strcmp(fsearch,file.filename[i])==0)
					{
						cout<<"file"<<file.filename[i]<<"  found at :"<<i;
	
					}}
			}
	}
	return 0;

}

