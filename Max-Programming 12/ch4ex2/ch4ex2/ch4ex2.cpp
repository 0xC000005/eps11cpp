//Max Zhang - Oct. 04
#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	system("cls");
	double weight,length,width, height;
	cout<<"Enter weight of package in kilograms: ";
	cin>>weight;
	cout<<"Enter length of package in meters: ";
	cin>>length;
	cout<<"Enter width of package in meters: ";
	cin>>width;
	cout<<"Enter height of package in meters: ";
	cin>>height;
	//--------------------------------------------
	if(weight>27)
		if(length*width*height>0.1)cout<<"Rejected: Too heavy and too large"<<endl;
		else cout<<"Rejected: Too heavy"<<endl;
	else if(length*width*height>0.1) cout<<"Rejected: Too large"<<endl;
	else cout<<"Accepted"<<endl;
	return 0;
}