#include "Deck.h"
#include "Player.h"

int main() {
    newGame:
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
    Game.betting();


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
        Deck::setPlayerScore(player);
    }
    Game.sorting();
    Game.displayPlayerScore();
    Game.checkOut();
    cout << endl << endl;
    cout << "1. Continue this game." << endl;
    cout << "2. Load a new game" << endl;
    cout << "3. Exit" << endl;
    int option;
    cin >> option;
    if (option == 1) {
        goto continueGame;
    }
    if (option == 2) {
        goto newGame;
    }
    if (option == 3) {
        exit(0);
    }


    return 0;
}