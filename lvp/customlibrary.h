/*

  Chris Tidder
  Block C
  Feb. 6, 2007

*/

#include<iostream.h>
#include<conio.h>
#include<h:\lvp\random.h>

//------------------------------------------------------------------------

void Pause()

/*

	Diplays a message and waits for the user to hit a key
	Post: Key pressed

*/

{
	cout<< "Press a key to continue..." << endl;
	getch(); 
}

//------------------------------------------------------------------------



//------------------------------------------------------------------------

int GetInt(int Lo, int Hi)

/*

	Obtains and returns an integer from the user in the range Lo -  Hi.
	Pre: Lo < Hi
	Post: An integer between Lo and Hi inclusive  returned

*/

{
	int Entry;
	cin>>Entry;
	while ( (Entry<Lo) || (Entry>Hi) ) {
		cout<< "Value must be between " << Lo << " and " << Hi << endl;
		cout<< "Please re-enter: ";
		cin>>Entry;
	}
	return(Entry);
}