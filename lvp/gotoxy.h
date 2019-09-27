#include "windows.h"
#include "iostream"
using namespace std;

void gotoxy(int x,int y)
{
  HANDLE hConsole;
  COORD cursorLoc;
  std::cout.flush();
  cursorLoc.X = x;
  cursorLoc.Y = y;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(hConsole, cursorLoc);
}