//Max Zhang - Oct. 02
#include<iostream>
#include<conio.h>
#include <fstream>
#include <iomanip>

using namespace std;
const double aveage = 74.5;
int main()
{
	system("cls");
	int total_num, per_group;
	double mark;
	cout<<"How many students are in Mr. Tsang's class? ";
	cin>>total_num;
	cout<<"How many students per group? ";
	cin>>per_group;
	cout<<"What would you're group like for a mark? ";
	cin>>mark;
	int groups = total_num/per_group, left_out = total_num%per_group;
	cout<<endl<<"There are "<<groups<<" groups and the remaining "<<left<<" are judges."<<endl<<endl;

	cout<<"Your desired group mark is"; cout.width(5); cout<<mark;cout<<endl; 
	cout<<"The normal average grade is"; cout.width(6); cout<<aveage;cout<<"%"<<endl<<endl;
	cout<<"The difference is";cout.width(17);cout<<fixed<<setprecision(2)<<mark-aveage;cout<<"%."<<endl;
	return 0;
}
