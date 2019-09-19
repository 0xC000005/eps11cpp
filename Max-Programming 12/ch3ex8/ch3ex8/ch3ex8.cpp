//Max Zhang - Sept. 18th
#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	system("cls");
	cout<<"Enter the number of minutes: ";
	int min;
	cin>>min;
	int hour = min / 60;
	min -= hour*60;
	int ten = min / 10, one = min % 10;
	
	cout<<"This is "<<hour<<":"<<ten<<one<<endl;
	return 0;
}

