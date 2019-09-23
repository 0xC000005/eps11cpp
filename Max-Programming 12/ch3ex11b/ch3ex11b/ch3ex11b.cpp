//Max Zhang - Sept. 19th
#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	system("cls");
	cout<<"Enter the number of flower pots to ship: ";
	int pots;
	cin>>pots;
	int very_big_box = pots / 9;
	pots -= very_big_box * 9;
	int big_box = pots / 4;
	pots -= big_box * 4;
	int small_box = pots;
	cout<<"We will ship:"<<endl;
	cout<<"  "<<very_big_box<<" very big box(s)"<<endl;
	cout<<"  "<<big_box<<" big box(s)"<<endl;
	cout<<"  "<<small_box<<" small box(s)"<<endl;
	return 0;
}