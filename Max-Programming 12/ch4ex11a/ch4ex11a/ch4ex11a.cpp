//Max Zhang - Oct. 17
#include<iostream>
#include<conio.h>

using namespace std;
int get_input()
{
	cout<<"Enter an integer: ";
	double num;
	cin>>num;
	while(num!=int(num)||num<1)
	{
		cout<<"Bad input!"<<endl;
		cout<<"Enter an integer: ";
		cin>>num;
	}
	return int(num);
}
int main()
{
	system("cls");
	while(true)
	{
		int num = get_input();
		bool flag = true;
		for(int i=2;i<=num;i++)
		{
			if(num%i==0 && num!=i)
			{
				cout<<"Not prime"<<endl;
				flag = false;
				break;
			}
		}
		if(flag) cout<<"Prime"<<endl;
	}
	return 0;
}