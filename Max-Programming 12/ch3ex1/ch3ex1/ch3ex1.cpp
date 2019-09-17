//Max Zhang - Sept. 16th
#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	system("cls");
	int t;
	cout<<"Enter the time: ";
	cin>>t;
	double  h=100-4.9*(t*t);
	cout<<"The object is at "<<h<<" meters"<<endl;
	return 0;
}
