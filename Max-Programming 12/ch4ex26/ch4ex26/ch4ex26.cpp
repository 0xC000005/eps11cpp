//Max Zhang - Nov. 1
#include<iostream>
#include<conio.h>

using namespace std;

int get_input()
{
	cout<<"Enter an integer: ";
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
	int money=100;
	while(money>1)
	{
		cout<<"You have "<<money<<" tokens. Pull? ";
		char option;
		cin>>option;
		if(option=='Y'||option=='y')
		{
			int a=(rand()%9)+1, b=(rand()%9)+1, c=(rand()%9)+1;
			cout<<"["<<a<<"]"<<" ["<<b<<"]"<<" ["<<c<<"]"<<endl;
			if((a==b)&&(b==c)&&(c==a))
			{
				cout<<"You won "<<a+b+c<<" tokens! "<<endl;
			}
			else
			{
				money--;
				cout<<"You lost."<<endl;
			}
		}
		else break;
	}
	cout<<"Thanks for playing!"<<endl;

	return 0;
}

