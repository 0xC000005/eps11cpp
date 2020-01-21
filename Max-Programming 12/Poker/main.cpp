#include "Deck.h"
#include "Player.h"

int main() {
    Deck Game;
    Game.init();
    cout << "Welcome to five-cards draw!" << endl;
    cout << "Input the number of player:";
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        Game.addNewPlayer();
    }
    continueGame:
    Game.setAnte();
    Game.assignCards();
    for (auto &player:Game.playerList) {
        if (player.fold) {
            cout << player.getName() << " has folded, skip." << endl;
            system("pause");
            continue;
        }
        Game.betting(player);
    }
    for (auto &player:Game.playerList) {
        if (player.fold) {
            cout << player.getName() << " has folded, skip." << endl;
            system("pause");
            continue;
        }
        Game.discard(player);
    }
    for (auto &player:Game.playerList) {
        if (player.fold) {
            cout << player.getName() << " has folded, skip." << endl;
            system("pause");
            continue;
        }
        Game.setPlayerScore(player);
    }


    return 0;
}