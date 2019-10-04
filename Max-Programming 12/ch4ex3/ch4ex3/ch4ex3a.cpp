//Max Zhang - Oct. 03
#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	system("cls");
	cout.setf(ios::fixed);
	cout.precision(2);
	int numeggs, numdoz, leftover;
	double cpd,cpe,bill;
	cout<<"Enther number of eggs: ";//126
	cin>>numeggs;
	//---------------------------------
	numdoz = numeggs/12;//10
	if(numdoz>=0&&numdoz<4)cpd=0.50;
	else if (numdoz>=4&&numdoz<6)cpd=0.45;
	else if(numdoz>=6&&numdoz<11)cpd=0.40;
	else cpd=0.35;
	//bill = numeggs * cpe;
	cpe=cpd/12;
	leftover=numeggs%12;
	bill = numdoz*cpd+leftover*cpe;
	//----------------------------------
	cout<<"Yourt cost is $"<<cpd<<" per dozen or ";
	cout.precision(3);
	cout<<cpe<<" per egg."<<endl;
	cout.precision(2);
	cout<<"Your bill comes to $"<<bill<<endl;

	return 0;
}