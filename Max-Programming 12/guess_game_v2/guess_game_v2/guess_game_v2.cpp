//Max Zhang - Oct. 228
#include<iostream>
#include<conio.h>
#include<string>
#include<cmath>
using namespace std;

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

bool check_range(int guess, int secret, int range)
{
	if(abs(guess-secret)>range)
	{
		cout<<"You lied! "<<endl;
		return false;
	}
	cout<<"This is true!"<<endl;
	return true;
}

int main()
{
	system("cls");
	cout<<"Welcome to the magic guesser!"<<endl;
	int min = get_input("Enter the low value: "), max=get_input("Enter the high value: "), guess=(max-min)/2+min, secret=get_input("Pick a secret number: "), range=abs(guess-secret), count=0;
	cout<<endl;
	
re1: //Recursive Lock
		
		//cout<<"range: "<<range<<endl;
		cout<<"Is the number "<<guess<<"? (l,h,c): ";
		char judge;
		cin>>judge;
		if(judge=='l')
		{
			min=guess;
		}
		else if(judge=='h')
		{
			max=guess;
		}
		else if(judge=='c')
		{
			if(range==0) goto ans;
			else goto re1;
		}
		if(!check_range((max-min)/2+min, secret, range)) goto re1;
		else
		{
			//cout<<"update status ......"<<endl;
			guess=(max-min)/2+min;
			range=abs(guess-secret);
			count++;
			goto re1;
		}
	
	cout<<endl;

	ans:
		cout<<"It took me "<<count<<" guesses."<<endl;

	return 0;
}
