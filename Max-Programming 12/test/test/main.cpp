// Jimmy Wang - Jan.20
/*

Write a complete C++ program to play a game of “hide and search.” In this
game, a prize is randomly placed on an imaginary 10 x 10 grid (rows from
1 to 10, columns from 1 to 10). The player gets five guesses to pick the
position of the prize. If the player finds the prize, or guesses unsuccessfully
five times, the game ends. On each unsuccessful guess, the program should tell
the player how far away the prize is. When run, the program may display output
similar to (user input is as follows):
---------------------------------------------------------------------------------
You have 5 guesses
Enter Guess:
	Row: 1
	Col: 4
You are 4.12311 units away
Enter Guess:
	Row: 33
	Col: 6
Error!  Must give values between 1 and 10!
Enter Guess:
	Row: 33
	Col: 6
You are 2.23607 units away
Enter Guess:
	Row: 5
	Col: 5
You got it!
//---------------------------------------------------------------------------------
	Recall that the expression  random(10)+1 will evaluate to a random number
	between 1 and 10 inclusive.  Your program must include each of the following:

•	A void function GetGuess() that allows the user to enter a guess of the
position of the prize in Row/Column format. GetGuess() should not accept any
guesses which are outside of the range 1..10 in either Row or Column. The values
should be returned as reference parameters.

•	A function Distance() that returns the distance between two locations on the
grid passed as arguments. The function should not itself read from or write to
the user console. Distance() should use the Pythagorean Theorem to calculate
the distance:
*/

// Jimmy Wang - Jan.20

#include <iostream>
#include <conio.h>
#include <math.h> // use sqrtl() to find the square root of a number ie. sqrtl(25) is 5
#include <h:\lvp\random.h>

using namespace std;

//----------------------------------------------------------------
void GetGuess(int &Row, int &Col)
/* Obtains values between 1 and 10 for each argument from the user */

{
	// Referencing the memory location of Row and Col so that
	// We dont need to return any values
	int tRow, tCol;
	cout << "Enter Guess: " << endl;
	cout << "	Row: ";
	cin >> tRow;
	cout << "	Col: ";
	cin >> tCol;
	
	if (tRow < 1 || tRow > 10 || tCol > 10 || tCol < 1)	{
		cout << "Error! Must give values between 1 and 10!" << endl;
		GetGuess(Row, Col);		// Simply recursion, while loop implementation below
	}
	else {
		Row = tRow;
		Col = tCol;
	}
	/*	(While loop implmentation of error check)
	while(tRow < 1 || tRow > 10 || tCol > 10 || tCol < 1)	{
		cout << "Error! Must give values between 1 and 10!" << endl;
		cout << "Enter Guess: " << endl;
		cout << "	Row: ";
		cin >> tRow;
		cout << "	Col: ";
		cin >> tCol;
	}
	Row = tRow;
	Col = tCol;
	*/
}
//----------------------------------------------------------------
double Distance(int Row1, int Col1, int Row2, int Col2)
/* Returns the distance between Row1,Col1 and Row2, col2 using the
	Pythagorean Theorem */
{
	int temp1 = abs(Row2 - Row1);
	int temp2 = abs(Col2 - Col1);
	double distance = sqrtl((temp1*temp1)+(temp2*temp2));
	return(distance);
}
//----------------------------------------------------------------
int main()
{
	randomize();
	const int MaxGuesses = 5;
	int NumGuesses = 0;
	int Row, Col;
	const int PrizeRow = random(10) + 1;
	const int PrizeCol = random(10) + 1;

	//int PrizeRow = 5;		// I used these test variables to easily debug my program
	//int PrizeCol = 5;

	cout << PrizeRow << " " << PrizeCol << endl;

	//Beginning of program
	cout << "Your have " << MaxGuesses << " guesses" << endl;
	// As long as NumGuesses is less than MaxGuesses the while loop will continue
	while(NumGuesses < MaxGuesses)	{
		++NumGuesses;	// Adds 1 to NumGuesses each loop
		GetGuess(Row, Col);		// Gets user input
		// If the input if not equal to PrizeRow and PrizeCol, we display distance (displacement)
		if (!(Row == PrizeRow && Col == PrizeCol))	{
			cout << "You are " << Distance(Row, Col, PrizeRow, PrizeCol) << " units away" << endl;
		}
		else {
			// Anything else (Row == PrizeRow && Col == PrizeCol)  then we break from loop
			break;
		}
	}

	// Two if statements to determine whether we have run out of guesses or got the correct coordinates.
	if ((NumGuesses == MaxGuesses) && (Row != PrizeRow && Col != PrizeRow))	{
		cout << "You have used up all " << MaxGuesses << " guesses. The prize location is row " << PrizeRow << " and col " << PrizeCol << endl;
	}
	else if (Row == PrizeRow && Col == PrizeCol)	{
		cout << "You got it!" << endl;
	}
	
	_getch();	// Prevent console window from immediatly closing after the code finishes
	return 0 ;
}
