//Max Zhang - Oct. 22
#include<iostream>
#include<conio.h>
#include<string>
#include<cmath>

using namespace std;

const int MAX=2147483647; //preset
int range=MAX;
int secret;

int get_input(string init="Enter an integer: ",string help="Enter an integer: ")
{
	cout<<init;
	double num;
	cin>>num;
	while(num!=int(num)) //looping lock
	{
		cout<<"Bad input!"<<endl;
		cout<<help;
		cin>>num;
	}
	return int(num);
}

bool check_range(int guess, int secret)//one-way lock
{
	cout<<"000001 abs(guess-secret) - "<<guess<<"-"<<secret<<"="<<abs(guess-secret)<<endl;
	cout<<"000003 Range - "<<range<<endl;
	if((abs(guess-secret))<range)
	{
		range=abs(guess-secret);
		cout<<"000004 - abs(guess-secret))<range =T,  range=abs(guess-secret) "<<range<<endl;
		return false;
	}
	cout<<"000004 - abs(guess-secret))<range =F, range=abs(guess-secret) = "<<range<<endl;
	return true;
}

int get_guess(int guess, int min, int max)
{
	int flag=0;//I can't ......
	cout<<guess<<"(l, h, c): ";
	bool lock=false;
	char result;
	cin>>result;
	//Binary decrement
	if(result=='l')flag=1;	
	else if(result=='h')flag=2;	
	else if(result=='c')flag=3;//pass
	cout<<"000000 - Guess = "<<guess<<endl;;

	if(check_range(guess,secret)) //recursion lock
	{
		cout<<"Bad input!"<<endl;
		get_guess(guess,min,max);
	}
	//new guess found
	return flag;
}

int main()
{
	system("cls");
	cout<<"Welcome to the magic guesser!"<<endl;
	int min = get_input("Enter the low value: "), max=get_input("Enter the high value: "), guess=(max-min)/2+min, count=0;
	//int *possible_value=new int[1+(max-min)]; dynamic array
	secret=get_input("Pick a secret number: ");
	cout<<endl;	
	do{
		cout<<"000008 - main func start. ------------------------------------------------"<<endl;
		cout<<"000006 - "<<"min: "<<min<<", max: "<<max<<endl;
		int flag = get_guess(guess, min, max);
		if(flag=1)
		{
			guess+=(max-guess)/2;
			min=guess;
		}
		else if(flag=2)
		{
			guess-=(guess-min)/2;
			max=guess;
		}
		else if(flag=3)
		{
			//pass
		}
		else 
		{
			//pass
		}
		cout<<"000007 - main func end.  ------------------------------------------------"<<endl;
	}while(check_range(guess,secret)==0);
	cout<<guess<<endl;
	return 0;
}
