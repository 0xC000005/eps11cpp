//Max Zhang - Sept. 16th
#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	system("cls");
	cout<<"Enter the temperature in Fahrenheit: "<<endl;
	double f;
	cin>>f;
	double c=5(f-32)/9;
	cout<<"The temperature in Celsius is "<<c<<" degrees."<<endl;
	return 0;
}
