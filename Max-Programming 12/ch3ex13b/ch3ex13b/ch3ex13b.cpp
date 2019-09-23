//Max Zhang - Sept. 19th
#include<iostream>
#include<conio.h>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	system("cls");
	cout<<"Enter the number of burgers: ";
	int burgers;
	cin>>burgers;
	cout<<"Enter the number of fries: ";
	int fries;
	cin>>fries;
	cout<<"Enter the number of sodas: ";
	int sodas;
	cin>>sodas;
	cout<<fixed<<setprecision(2)<<endl;
	double total = burgers * 1.49 + fries * 0.89 + sodas * 0.99; 
	cout<<"The total before tax is: $"<<total<<endl;
	double tax = total * 0.06;
	cout<<"The tax is $"<<tax<<endl;
	double grand = total + tax;
	cout<<"The grand total is $"<<grand<<endl;
	cout<<endl;
	cout<<"Enter amount tendered: ";
	double money;
	cin>>money;
	double change = money - grand;
    cout<<"The change is: $"<<change<<endl;
	return 0;
}
