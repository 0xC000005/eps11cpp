//ch3ex5
#include<iostream>
#include<conio.h>
#include<cmath>

using namespace std;

int main()
{
	system("cls");
	const double C = 3*pow(10.0,8);
	const int LIGHT_BULB = 360000;
	long double mass,energy,time;
	cout<<"Enter the mass in kg: ";
	cin>>mass;
	energy = mass*C*C;
	cout<<"This mass could produce "<<energy<<" Joules of energy."<<endl;
	time = energy/LIGHT_BULB;
	cout<<"It could power "<<time<<" 100-watt light bulbs for an hour."<<endl;
	return 0;
}