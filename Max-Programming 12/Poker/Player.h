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

    int money = 100, bet;
    bool fold = false, dealer = false;
    vector<Card> playerCard;
    vector<int> result = {0, 0, 0};

    void setName(string _name) {
        name = std::move(_name);
    }

    void initResult() {
        for (auto &element:result) {
            element = 0;
        }
    }

    void setResult(vector<int> _result) {
        initResult();
        result = std::move(_result);
    }

    string getName() {
        return name;
    }

    int getMoney() {
        return money;
    }


};


#endif //POKER_PLAYER_H
