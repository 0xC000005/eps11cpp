//Max Zhang - Sept. 25
#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

int main()
{
	system("cls");
	int can1NY, can1NJ, can1CON, can2NY, can2NJ, can2CON;
	string candidate1 = "Awbrey", candidate2 = "Berlin";
	int can1Total, can2Total, total;
	double can1perc, can2perc;

	//--------------------------------------------------------

	cout<<"Enter New York votes for "<<candidate1<<":";
	cin>>can1NY;
	cout<<"Enter New York votes for "<<candidate2<<":";
	cin>>can2NY;
	cout<<"Enter New Jersey votes for "<<candidate1<<":";
	cin>>can1NJ;
	cout<<"Enter New Jersey votes for "<<candidate2<<":";
	cin>>can2NJ;
	cout<<"Enter Connecticut votes for "<<candidate1<<":";
	cin>>can1CON;
	cout<<"Enter Connecticut votes for "<<candidate2<<":";
	cin>>can2CON;

	//--------------------------------------------------------

	can1Total = can1NY+can1NY+can1CON;
	can2Total = can2NY+can2NY+can2CON;
	total = can2Total+can2Total;
	can1perc = double(can1Total)/total*100;
	can2perc = double(can2Total)/total*100;

	//--------------------------------------------------------
	cout.setf(ios::left);
	cout<<"Candiates   Votes   Percent"<<endl;
	cout.width(12);cout<<candidate1<<" "<<can1Total<<" "<<can1perc<<endl;
	cout.width(10);cout<<candidate2<<" "<<can2Total<<" "<<can2perc<<endl;
	cout.width(7);cout<<can1perc<<endl;
	return 0;
}
