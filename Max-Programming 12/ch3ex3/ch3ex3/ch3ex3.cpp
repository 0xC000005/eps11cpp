//Max Zhang - Sept. 17th
#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	system("cls");
	cout<<"Enter the size of the pizza: ";
	int size;
	cin>>size;
	double ans = 1.20 + size * size *0.05;
	cout<<"The cost is $"<<ans<<endl;
	return 0;
}