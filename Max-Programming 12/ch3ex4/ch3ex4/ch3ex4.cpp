//Max Zhang - Sept. 17th
#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	system("cls");
	cout<<"Enter the average speed: ";
	double speed;
	cin>>speed;
    double ans = (32/speed)*60;
	cout.precision(3);
	cout<<"The trip to school will take "<<ans<<" minutes."<<endl;
	return 0;
}
