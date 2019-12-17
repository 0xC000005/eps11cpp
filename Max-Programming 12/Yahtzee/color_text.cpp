#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 200; i++)	
	{
		SetConsoleTextAttribute(h, i);
		cout << i << " ";
	}
	SetConsoleTextAttribute(h, 15);
	return 0;
}
