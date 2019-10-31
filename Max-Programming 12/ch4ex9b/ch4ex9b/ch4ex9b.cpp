//Max Zhang - Oct. 11
#include<iostream>
#include<conio.h>

using namespace std;

int get_cube(int num)
{
	int digits=1,sum=0;
	while(num%(digits*10)!=num)digits*=10;
	while(true)
	{
		sum+=(num/digits)*(num/digits)*(num/digits);
		num%=digits;
		if(digits!=1)digits/=10;
		else break;
	}
	return sum;
}

int main()
{
	system("cls");
	for(int i=10;i<10000;++i)//all integers of two, three, or four digits 
	{
		if(i==get_cube(i))cout<<i<<endl;
	}
	
	return 0;
}
