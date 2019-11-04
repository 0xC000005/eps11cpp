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

bool check_range(int flag, int max, int min, int guess, int secret, int range)
{
	int optionL=(max-guess)/2+guess, rangeL=abs(optionL-secret), optionH=(guess-min)/2+min, rangeH=abs(optionH-secret);
	//cout<<optionL<<" "<<rangeL<<endl;
	//cout<<optionH<<" "<<rangeH<<endl;
	if(rangeH==0 && rangeL==0)
	{
		cout<<"You lied! "<<endl;
		return false;
	}
	if(flag==1 && rangeH<rangeL)
	{
		cout<<"You lied! "<<endl;
		return false;
	}
	if(flag==2 && rangeH>rangeL)
	{
		cout<<"You lied! "<<endl;
		return false;
	}
	else
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
		//cout<<(max-guess)/2+guess<<endl;
		//cout<<(guess-min)/2+min<<endl;
		int flag;
		if(judge=='l')
		{
			flag=1;
			
		}
		else if(judge=='h')
		{
			flag=2;
		}
		else if(judge=='c')
		{
			flag=3;
			if(range==0) goto ans;
			else goto re1;
		}
		

		if(!check_range(flag, max, min, guess, secret, range)) goto re1;
		else
		{
			//cout<<"update status ......"<<endl;
			if(flag==1)min=guess;
			if(flag==2)max=guess;
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
