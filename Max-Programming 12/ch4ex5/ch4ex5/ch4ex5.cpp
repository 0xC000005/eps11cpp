//Max Zhang - Oct. 04
#include<iostream>
#include<conio.h>

using namespace std;

bool is_in_array(int number)
{
	int defect[6] = {119,179,189,195,221,780};
	for(int i=0;i<6;i++)
		if(number == defect[i])	return true;
	return false;
}

int main()
{
	system("cls");
	while(true)
	{
		cout<<"Enter your model number (0 for done): ";
		int number;
		cin>>number;
		if(number==0)
		{
			cout<<"Program complete."<<endl;
			return 0;
		}
		else
		{
			if(is_in_array(number))
			{
				cout<<"Your car is defective. Please have it fixed."<<endl<<endl;
				continue;
			}
			else cout<<"Your car is OK."<<endl<<endl;
		}
	}
	return 0;
}