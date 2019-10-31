//Max Zhang - Oct. 11
#include<iostream>
#include<conio.h>

using namespace std;
int original_a,original_b;
int necklace(int a,int b)
{
	cout<<" "<<b;
	if(a==original_a && b==original_b)return 0;//border
	necklace(b,(a+b)%10);
}
int main()
{
	system("cls");
	cin>>original_a>>original_b;
	cout<<original_a<<" "<<original_b;
	necklace(original_b,original_a+original_b);
	return 0;
}