//Max Zhang - Sept. 27
#include<iostream>
#include<conio.h>
#include<string>
#include<h:/lvp/string.h>
using namespace std;

int main()
{
	system("cls");
	int num1, ten;
	cout<<"Enter a number: ";
	cin>>num1;
	ten = num1%100/10;
	cin>>num1;
	cout<<"the number in the tens position is "<<ten<<endl;
	return 0;
}