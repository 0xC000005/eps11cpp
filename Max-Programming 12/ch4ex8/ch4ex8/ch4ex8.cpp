//Max Zhang - Oct. 11
#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	system("cls");
	while(true)
	{
		int num,digits=1,sum=0;
		cout<<"Enter an integer: ";
		cin>>num;
		while(num%(digits*10)!=num)digits*=10;
		while(true)
		{
			sum+=num/digits;
			num%=digits;
			if(digits!=1)digits/=10;
			else break;
		}
		cout<<"Sum of digits is "<<sum<<endl<<endl;
	}
	return 0;
}



