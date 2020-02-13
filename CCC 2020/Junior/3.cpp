#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int row_min = 101, row_max = -1, vol_min = 101, vol_max = -1;
	for(int i=0;i<n;i++)
	{
		int row_temp, vol_temp;
		scanf("%d,%d",&row_temp,&vol_temp);
		//cout<<i<<" row:"<<row_temp<<" vol:"<<vol_temp<<endl;
		if(row_min>row_temp)row_min = row_temp;
		if(row_max<row_temp)row_max = row_temp;
		if(vol_min>vol_temp)vol_min = vol_temp;
		if(vol_max<vol_temp)vol_max = vol_temp;
	}
	cout<<row_min-1<<","<<vol_min-1<<endl;
	cout<<row_max+1<<","<<vol_max+1<<endl;
	return 0;
}
