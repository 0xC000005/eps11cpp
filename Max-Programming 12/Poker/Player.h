//
// Created by heckn on 2020-01-15.
//

#ifndef POKER_PLAYER_H
#define POKER_PLAYER_H

#include <string>
#include <iostream>
#include <vector>
#include "Card.h"

using namespace std;

class Player {
private:
    string name;
    int money{}, bet{};
    vector<Card> playerCard;

public:
    Player() = default;

    explicit Player(string const &_name) {
        name = _name;
        money = 5;
    }

    int getBet() {
        return bet;
    }

};


#endif //POKER_PLAYER_H
