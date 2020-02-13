#include<iostream>
using namespace std;
int main()
{
	int P,N,R,count = 0, amount = 0;
	cin>>P;
	cin>>N;
	cin>>R;
	while(true)
	{
		count++;
		N = N*R;
		amount+=N;
		if(amount>=P)
		{
			cout<<count;
			return 0;
		}
	}
}
