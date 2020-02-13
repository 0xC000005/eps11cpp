#include <bits/stdc++.h>
using namespace std;
int x, y;
int matrix[201][201];

void find(int a,int b)
{
    if((a==x)&&(b==y))
    {
        cout<<"yes"<<endl;
        exit(0);
    }
    for(int c=1;c<=matrix[a][b];++c)
    {
        if(matrix[a][b]%c==0)
        {
            find(c,matrix[a][b]/c);
        }
    }

}

int main()
{
    cin>>x;
    cin>>y;
    for(int a=0;a<y;a++)
    {
        for(int b=0;b<x;b++)
        {
           cin>>matrix[a][b];
        }
    }
    find(0,0);
    cout<<"no"<<endl;
    return 0;
}

