//Max Zhang - Sept. 26
#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	system("cls");
	int numEggs, dozens, leftOver;
	double cpd, cpe, subTotal, total, gst;
	//-------------------------------------
	cout<<"How many eggs? ";
	cin>>numEggs;
	cout<<"Cost per dozen? ";
	cin>>cpd;
	cout<<"Cost per egg overage? ";
	cin>>cpe;
	//-------------------------------------
	dozens = numEggs/12;
	leftOver = numEggs%12;
	subTotal = (dozens*cpd+leftOver*cpe);
	gst = subTotal*0.07;
	total = subTotal+gst;
	cout<<endl;
	//-------------------------------------
	cout<<"There are "<<dozens<<" dozen eggs and "<<leftOver<<" left  over."<<endl;
	cout<<endl;

	cout.width(10);cout<<left<<"Subtotal:";
	cout.width(15);cout<<right<<"$"<<subTotal<<endl;
	
	
	cout.width(10);cout<<left<<"GST(7%):";
	cout.width(15);cout<<right<<"$"<<gst<<endl;

	cout<<"----------------------------"<<endl;

	cout.width(10);cout<<left<<"Total:";
	cout.width(15);cout<<right<<"$"<<<<endl;

	return 0;
}

/*
int num;
	double dozen, overage;
	cout<<"How many eggs? ";
	cin>>num;
	cout<<"Cost per dozen? ";
	cin>>dozen;
	cout<<"Cost per egg overage? ";
	cin>>overage;
	cout<<endl;
	cout<<"There are "<<num/12<<" dozen eggs and "<<num%12<<" left  over."<<endl;
	cout<<endl;
	double money =num/12*dozen + num%12*overage, tax = money*0.07;
	cout.width(12);cout<<left<<"Subtotal:";cout.width(15);cout<<right<<"$"<<money<<endl;
	cout.width(12);cout<<left<<"GST(7%):";cout.width(15);cout<<right<<"$"<<tax<<endl;
	cout<<"----------------------------"<<endl;
	cout.width(12);cout<<left<<"Total:";cout.width(15);cout<<right<<"$"<<money+tax<<endl;
	return 0;
}
*/
