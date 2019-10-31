//Max Zhang - Oct. 17
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
	cout<<"Enter starting number: ";
	int starting = get_input();
	cout<<"Enter ending number: ";
	int ending = get_input(),count=0;
	for(int num=starting; num<=ending; num++)
	{
		bool flag = true;
		for(int i=2;i<=num;i++)
		{
			if(num%i==0 && num!=i)
			{
				flag = false;
				break;
			}
		}
		if(flag) count++;
	}
	cout<<"Number of primes in range: "<<count<<endl;
	return 0;
}