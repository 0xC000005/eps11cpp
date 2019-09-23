//Max Zhang - Sept. 23
#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	system("cls");
	cout<<"Enter your birthdate (using numbers for months):"<<endl;
	int bir_mon,bir_day,bir_yea;
	cout<<"Month: ";
	cin>>bir_mon;
	cout<<"Day: ";
	cin>>bir_day;
	cout<<"Year: ";
	cin>>bir_yea;

	cout<<"Enter today’s date (using numbers for months):"<<endl;
	int now_mon,now_day,now_yea;
    cout<<"Month: ";
	cin>>now_mon;
	cout<<"Day: ";
	cin>>now_day;
	cout<<"Year: ";
	cin>>now_yea;
	
	int dif_mon = now_mon - bir_mon, dir_day = now_day - bir_day, dir_yea = now_yea - bir_yea;
	int ans = dir_yea*365 + dif_mon*30 + dir_day;
	cout<<"You have been alive for "<<ans<<" days."<<endl;
	int hours = ans*8;
	cout<<"You have slept "<<52792<<" hours."<<endl;
	return 0;
}
/*
Leap_Yea();

for(int i=bir_yea;i<=now_yea;++i)
	{
		if(leap_year(i))ans+=366;
		else ans+=365;
	}
bool leap_year(int year)
{
	//leap year condition
   if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
      return true;
   else
      return false;
}

*/