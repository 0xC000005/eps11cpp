//Max Zhang - Sept. 18th
#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	system("cls");
	cout<<"Enter the amount of change in cents: ";
	int money;
	cin>>money;
	int quarters=0, dimes=0, nickels=0, pennies=0;
	quarters = money/25;
	money %= 25;
	dimes = money/10;
	money %= 10;
	nickels = money/5;
	money %= 5;
	pennies = money / 1;
	cout<<"Change:"<<endl;
	cout<<"  Quarters: "<<quarters<<endl;
	cout<<"  Dimes: "<<dimes<<endl;
	cout<<"  Nickels: "<<nickels<<endl;
	cout<<"  Pennies: "<<pennies<<endl;
	return 0;
}

