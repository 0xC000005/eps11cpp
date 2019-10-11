//Max Zhang - Oct. 11
#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	system("cls");
	int num,digits=1;
	cout<<"Enter an integer: ";
	cin>>num;
	while(num%(digits*10)!=num)digits*=10;
	while(true)
	{
		int digit=num/digits;
		cout<<digit<<endl;
		num%=digits;
		if(digits!=1)digits/=10;
		else break;
	}
	return 0;
}



