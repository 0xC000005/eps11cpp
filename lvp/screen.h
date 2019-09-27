// Header file:  screen.h
// This header file will create functions similar to those
// in the Turbo C++ conio.h header file, which are now not
// available in MS Visual C++.
// Using this header file will eliminate having to include
// the function definitions each time you wish to use
// these items.  It will also allow these functions to be
// easily accessed by beginning programmers, unfamiliar 
// with the use of functions.
 
//#include &lt;windows.h&gt;   
//#include &lt;time.h&gt;     
#include <conio.h>
     
// --------------------------------------------------------
// delay( ) -- Allow the screen to be "paused" for the
// number of seconds determined by the programmer.  Unlike 
// the system("PAUSE");, no message is displayed on the 
// screen.  (5000 = 5 seconds, approximately)
// --------------------------------------------------------
// Function for delay( )
void delay(long seconds) 
{
	clock_t time1 = clock();  // use clock time
   	clock_t time2 = time1 + seconds;
  	while(time1 &lt; time2)
    	time1 = clock();
  	return;
}

// --------------------------------------------------------
// gotoxy( , ) -- Move the cursor to any location on the
// screen.  The upper left corner of the screen will be set
// to the coordinates (1,1) for easier counting of spaces.
// --------------------------------------------------------
// Function for gotoxy( , )
void gotoxy(int x, int y)
{  
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD point;
   	point.X = x-1;
	point.Y = y-1;     
   	SetConsoleCursorPosition(hConsole, point);
   	return;
}

// --------------------------------------------------------
// getch( ) -- Waits for user to hit a key, returns
// this response, and goes on.  You will not see the
// user's response on the screen (no echo).
// --------------------------------------------------------
// Function for getch( ) 
int getch(void)
{ 
	int response;
	cout &lt;&lt; flush;
  	response = _getch();
  	HANDLE hConsole = GetStdHandle(STD_INPUT_HANDLE);
  	FlushConsoleInputBuffer(hConsole);
  	return response;
}

// --------------------------------------------------------
// getche( ) -- Waits for user to hit a key, returns
// this response, and goes on.  You will see the user's
// response on the screen (echo).
// --------------------------------------------------------
// Function for getche( )
int getche(void)
{
	int response;
    response = _getche();
  	HANDLE hConsole = GetStdHandle(STD_INPUT_HANDLE);
  	FlushConsoleInputBuffer(hConsole);
  	return response;
}



</PRE></BODY></HTML>
