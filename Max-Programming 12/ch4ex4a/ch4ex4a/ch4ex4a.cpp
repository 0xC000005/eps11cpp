//Max Zhang - Oct. 04
#include<iostream>
#include<conio.h>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	system("cls");
	double hours, rate, wage;
	cout<<"Enter hours worked: ";
	cin>>hours;
	cout<<"Enter hourly rate: ";
	cin>>rate;
	//----------------------------------------
	wage = hours*rate;
	cout<<endl<<endl<<"Gross wages = $ "<<fixed<<setprecision(2)<<wage<<endl;

	return 0;
}