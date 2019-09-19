//Max Zhang - Sept. 19th
#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	system("cls");
	cout<<"Enter a two-digit number: ";
	int num;
	cin>>num;
	int first = num/10, second = num%10;
	cout<<"The first digit is "<<first<<endl;
	cout<<"The second digit is "<<second<<endl;

	return 0;
}

