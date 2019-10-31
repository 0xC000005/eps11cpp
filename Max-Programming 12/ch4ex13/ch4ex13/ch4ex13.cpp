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

int gcd(int a,int b)
{
	//Everything divides 0
	if(!a)return b;
	if(!b)return a;
	//base case
	if(a==b)return a;
	//a is greater
	if(a>b) return gcd(a-b,b);
	return gcd(a,b-a);
}

int main()
{
	system("cls");
	cout<<"The GCD is "<<gcd(get_input(),get_input())<<endl;
	return 0;
}

