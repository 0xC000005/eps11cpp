//
// Created by heckn on 2020-01-15.
//

#ifndef POKER_PLAYER_H
#define POKER_PLAYER_H

#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include "Card.h"

using namespace std;

class Player {
private:
    string name;


public:
    Player() = default;
    int money = 100;
    vector<Card> playerCard;

    void setName(string _name) {
        name = std::move(_name);
    }

    string getName() {
        return name;
    }

    int getMoney()
    {
        return money;
    }

};


#endif //POKER_PLAYER_H
