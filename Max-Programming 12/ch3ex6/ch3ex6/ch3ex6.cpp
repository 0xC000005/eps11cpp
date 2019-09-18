//Max Zhang - Sept. 18th
#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	system("cls");
	int first, second;
	cout<<"Enter first integer: ";
	cin>>first;
	cout<<"Enter second integer: ";
	cin>>second;
	cout<<first<<" / "<<second<<" = "<<first/second<<endl;
	cout<<first<<" % "<<second<<" = "<<first%second<<endl;
	cout<<second<<" / "<<first<<" = "<<second/first<<endl;
	cout<<second<<" % "<<first<<" = "<<second%first<<endl;
	return 0;
}