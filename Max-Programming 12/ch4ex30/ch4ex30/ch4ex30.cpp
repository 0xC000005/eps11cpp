//Max Zhang - Nov. 05
#include<iostream>
#include<conio.h>
#include<string>
#include<time.h>
#include <ctype.h>
#include<stdlib.h>
using namespace std;

int position(int pos, char horse)
{
	cout << horse << ": ";
	pos = pos + rand() % 2 + 1; /// this code will generate a random number between 1 and 2
	for(int b=0;b<=pos;b++)cout << " ";
	cout << "~n-n^";
	cout << endl << endl;
	return pos;
}

int main()
{
	cout<<"------- Welcome to The Horse Ride! -------"<<endl;
	int money=100;
	while(money>0)
	{
		int posA=0, posB=0, posC=0, posD=0,  posE=0,  posF=0;
		char horse,horsename,bethorse;
		int betcash=0;
		input:
			cout<<"You have "<<money<<" $ right now. How much money are you going to bet? ";
			cin>>betcash;
			if(money<betcash)
			{
				cout<<"Bad input!"<<endl;
				goto input;
			}
			
		cout<<"Which horse are you going to bet? A, B, C, D, E or F? ";
		cin>>bethorse;
		bethorse=toupper(bethorse);

		srand(time(NULL)); /// this line of code ensures that our program will generate a new random number each time we ask for it

		for(int a=0;a<=25;a++)
		{
			system("cls");
			horse='A';
			posA=position(posA,horse);
			horse='B';
			posB=position(posB,horse);
			horse='C';
			posC=position(posC,horse);
			horse='D';
			posD=position(posD,horse);
			horse='E';
			posE=position(posE,horse);
			horse='F';
			posF=position(posF,horse);
			for(int timer=0;timer<=100000000;timer++);
		}

		int highest=0;
		int winner[] = {posA, posB, posC, posD, posE, posF};
		for(int p=0;p<=5;p++)
		{
			cout<<winner[p] << endl;
			if(winner[p]>winner[highest])highest=p;
		}
	
		switch(highest)
		{
			case 0:
			horsename='A';
			break;
			case 1:
			horsename='B';
			break;
			case 2:
			horsename='C';
			break;
			case 3:
			horsename='D';
			break;
			case 4:
			horsename='E';
			break;
			case 5:
			horsename='F';
			break;
		}

		cout<<"Winning Horse: Horse "<<horsename<<endl;
		if(horsename==bethorse)
		{
			cout<<"You Won! You Get triple times the money you paid."<<endl;
			money+=betcash*3;
		}
		else
		{
			money-=betcash;
			cout<<"You Lost! "<<endl;
		}
		cout<<"Do you want to continue? (Y/N)";
		char option;
		cin>>option;
		if(option=='N')break;
		}
	if(money<=0)cout<<"You ran out the money!"<<endl;
	cout<<"------- Program Ends -------"<<endl;
	return 0;
}