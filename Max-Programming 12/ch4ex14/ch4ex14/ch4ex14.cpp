//Max Zhang - Oct. 17
#include<iostream>
#include<conio.h>

using namespace std;

int get_input()
{
	cout<<"How many boxes? ";
	double num;
	cin>>num;
	while(num!=int(num)||num<1)
	{
		cout<<"Bad input!"<<endl;
		cout<<"Enter an integer: ";
		cin>>num;
	}
	return int(num);
}


int main()
{
	system("cls");
	int box=get_input();
	for(int i=1;i<=box;i++)
	{
		cout<<"  AMY’S GARDEN EMPORIUM"<<endl; 
		cout<<"  SUNTAN, IOWA 12345"<<endl; 
		cout<<"  BOX NUMBER "<<i<<" OF "<<box<<endl<<endl;

	}

	return 0;
}
