#include "Deck.h"
#include "Player.h"
#include <vector>

int main() {
    Deck Game;
    Game.init();
    cout<<"Welcome to five-cards draw!"<<endl;
    cout<<"Input the number of player:";
    int num;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        Game.addNewPlayer();
    }
    Game.setAnte();
    Game.assignCards();
    for(auto &player:Game.playerList)
    {

    }
    return 0;
}