#include <bits/stdc++.h>
using namespace std;

void showdeque(deque<char> s)
{
    while (!s.empty())
    {
        cout<<s.front();
        s.pop_front();
    }
    cout<<endl;
}

string tostring(deque<char> s)
{
    string output_string(s.begin(), s.end());
    return output_string;
}

void found(string a, string b)
{
    string::size_type idx;

    idx=a.find(b);
    if(idx != string::npos )
    {
        cout <<"yes"<<endl;
        exit(0);
    }
}

int main ()
{
    string a;
    cin>>a;
    string b;
    cin>>b;
    char str[1001];
    strcpy(str, b.c_str());
    deque<char> rearrange;
    for (int i = 0; i < strlen(str); i++) {
        rearrange.push_back(str[i]);
    }
    //showdeque(rearrange);
    found(a,tostring(rearrange));

    for (int i = 1; i < strlen(str); i++) {
        char temp = rearrange.back();
        rearrange.pop_back();
        rearrange.push_front(temp);
        //showdeque(rearrange);
        found(a,tostring(rearrange));
    }
    cout<<"no"<<endl;
    return 0;
}
