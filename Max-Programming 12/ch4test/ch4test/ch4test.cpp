//Max Zhang - Dec.02
#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

int get_input(string init="Enter an integer: ",string help="Enter an integer: ")
{
	cout<<init;
	double num;
	cin>>num;
	while(num!=int(num)||num<0||num>10) //looping lock
	{
		cout<<"Bad input!"<<endl;
		cout<<help;
		cin>>num;
	}
	return int(num);
}


int main()
{
	system("cls");
	int num=get_input("How many flips to analyze? ", "How many flips to analyze? ");
	cout<<endl;
	double head=0, tail=0;
	for(int i=1;i<=num;i++)
	{
		cout<<"Flip coin and enter result (H or T) #"<<i<<": ";
		char result;
		cin>>result;
		if(result=='H' || result =='h')head++;
		else if(result=='T' || result=='t')tail++;
	}
	cout<<endl;
	cout<<"Results:"<<endl;
	cout<<"      "<<head<<" heads, or "<<head/(head+tail)*100<<"%"<<endl;
	cout<<"      "<<tail<<" tails, or "<<tail/(head+tail)*100<<"%"<<endl;
	return 0;
}

