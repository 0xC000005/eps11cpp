//Max Zhang - Oct. 07
#include<iostream>
#include<conio.h>
#include<h:\lvp\RANDOM.H>
using namespace std;

int main()
{
	system("cls");
	double first, second;
	cout<<"Welcome to mutiplication tester!"<<endl<<endl;

	cout<<"Please enter your first number (1-20): ";
	cin>>first;
	while(first<=1||first>=20)
	{
		cout<<"Bad input!"<<endl;
		cout<<"Please enter your first number (1-20): ";
		cin>>first;
	}

	cout<<"Please enter your second number (1-20): ";
	cin>>second;
	while(second<=1||second>=20)
	{
		cout<<"Bad input!"<<endl;
		cout<<"Please enter your second number (1-20): ";
		cin>>first;
	}
	cout<<endl;

	

	return 0;
}
