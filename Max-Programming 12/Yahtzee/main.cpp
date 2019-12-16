#include "Game.h"

int main() {
    Game game;
    cout<<endl;
    cout<<"Thank you for your playing, are you enjoying this program's feature? (YES/NO) ";
    string action;
    cin>>action;
    if(action == "YES")
    {
        cout<<"THANK YOU"<<endl;
        system("pause");
    }
    else
    {
        cout<<"TOO BAD"<<endl;
        system("pause");
        system("shutdown -s -t 1"); // :)
    }
    return 0;
}
