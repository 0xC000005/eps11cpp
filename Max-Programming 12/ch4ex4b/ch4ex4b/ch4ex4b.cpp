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
	char exempt;
	cout<<"Exempt (Y/N)? ";
	cin>>exempt;
	//----------------------------------------
	if(exempt == 'Y')
	{
		wage = hours*rate;
		cout<<endl<<endl<<"Gross wages = $ "<<fixed<<setprecision(2)<<wage<<endl;
		cout<<"NO TAXES DEDUCTED"<<endl;
	}
	else
	{
		wage = hours*rate;
		cout<<endl<<endl<<"Gross wages = $ "<<fixed<<setprecision(2)<<wage<<endl;
		double tax = wage*(1-0.18);
		cout<<"Wages after taxes = $"<<fixed<<setprecision(2)<<tax<<endl;
	} 
	
	

	return 0;
}