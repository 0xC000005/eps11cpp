#include "Deck.h"
#include <vector>
int main() {
    /*int num;
    cin>>num;
    vector <Deck> playerList;
    for(int i=0; i<num; ++i)
    {
        Deck temp;
        playerList.push_back(temp);
    }*/
    Deck player1;
    player1.init();
    player1.Play();
    return 0;
}