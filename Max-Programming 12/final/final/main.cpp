//Max Zhang - Jan.20
#include <iostream>
#include <string>
#include <conio.h>
#include <math.h> // use sqrtl() to find the square root of a number ie. sqrtl(25) is 5
#include <h:\lvp\random.h>

using namespace std;

//----------------------------------------------------------------
void GetGuess(int &Row, int &Col)
/* Obtains values between 1 and 10 for each argument from the user */
{
	
	if((Row>10 || Row<0 )||(Col>10 || Col<0))
	{
		cout<<"Error!  Must give values between 1 and 10!"<<endl;
		cout<<"Enter Guess:"<<endl;
		cout<<"        Row: ";
		int Row_guess;
		cin>>Row_guess;
		cout<<"        Col: ";
		int Col_guess;
		cin>>Col_guess;
		GetGuess(Row_guess,Col_guess);
	}
}
//----------------------------------------------------------------
double Distance(int Row1, int Col1, int Row2, int Col2)
/* Returns the distance between Row1,Col1 and Row2, col2 using the
	Pythagorean Theorem */
{
	double Row_distance = abs(Row1 - Row2), Col_distance = abs(Col1 - Col2), dis;
	dis = sqrt(Row_distance*Row_distance + Col_distance*Col_distance);
	return dis;
}
//----------------------------------------------------------------



int main()
{
	randomize();
	const int MaxGuesses = 5;
	int NumGuesses = 0;
	int Row, Col;
	const int Row_prize = random(10) + 1;
	const int Col_prize = random(10) + 1;
	//cout<<Row_prize<<" "<<Col_prize<<endl;
	cout<<"You have 5 guesses"<<endl;
	for(int i=0;i<MaxGuesses;i++)
	{
		cout<<"This is your "<<i+1<<" guess."<<endl;
		cout<<"Enter Guess:"<<endl;
		cout<<"        Row: ";
		int Row_guess;
		cin>>Row_guess;
		cout<<"        Col: ";
		int Col_guess;
		cin>>Col_guess;
		GetGuess(Row_guess, Col_guess);
		double distance = Distance(Row_guess,Col_guess,Row_prize,Col_prize);
		
		if(!distance)
		{
			cout<<"You got it!"<<endl;
			return 0;
		}

		cout<<"You are "<<distance<<" units away"<<endl;
	}
	cout<<"You've had 5 guess. It was at "<<Row_prize<<" "<<Col_prize<<endl;
	return 0 ;
}