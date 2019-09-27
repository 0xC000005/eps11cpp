//Jimmy Wang - Sept. 20
#include<iostream>
#include<conio.h>

using namespace std;

bool debug = false;

int yearToDay(int sY, int sM, int sD, int eY, int eM, int eD);
int calcDays(int month, int year);

int main() {
	int bM,bD, bY, tM, tD, tY;
	int alive, sleep;
	//Input
	system("CLS");
	cout << "Enter your birthdate (using numbers for months): " << endl;
	cout << "  Month: ";
	cin >> bM;
	cout << "  Day: ";
	cin >> bD;
	cout << "  Year: ";
	cin >> bY;
	cout << "Enter today's date (using numbers for months): " << endl;
	cout << "  Month: ";
	cin >> tM;
	cout << "  Day: ";
	cin >> tD;
	cout << "  Year: ";
	cin >> tY;

	//Calculations
	int temp = yearToDay(bY, bM, bD, tY, tM, tD);
	alive = temp;
	sleep = temp * 8;

	//Output
	cout << "You have been alive for " << alive << " days." << endl;
	cout << "You have slept " << sleep << " hours." << endl;
	return 0;
}

int yearToDay(int sY, int sM, int sD, int eY,int eM,int eD) {
	int days = 0;
	int year = sY;
	int month = sM;
	int day = sD;
	while (year <= eY) {
		if (year == eY) {
			while (month <= eM) 
			{
				if (month == eM)
				{
					while (day <= eD)
					{
						if (debug) cout << year << "/" << month << "/" << day << endl;
						day++;
						days++;
					}
				}
				else
				{
					while (day <= calcDays(month, year))
					{
						if (debug) cout << year << "/" << month << "/" << day << endl;
						day++;
						days++;
					}
				}
				day = 1;
				month++;
			}
		month = 1;
		}
		else
		{
			while (month <= 12) {
				while (day <= calcDays(month, year)) 
				{
					if (debug) cout << year << "/" << month << "/" << day << endl;
					day++;
					days++;
				}
				day = 1;
				month++;
			}
		}
		month = 1;
		year++;
	}
	return days;
}

int calcDays(int month, int year) {
	//if month is 2, leap year condition
	if (month == 2)
	{
		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
			return 29;
		else
			return 28;
	}
	//months that has 31 days
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
		|| month == 10 || month == 12)
		return 31;
	else
		return 30;
}