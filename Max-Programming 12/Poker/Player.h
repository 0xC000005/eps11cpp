//
// Created by heckn on 2020-01-15.
//

#ifndef POKER_PLAYER_H
#define POKER_PLAYER_H

#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include "Result.h"
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
    Result playerResult;

    void setName(string _name) {
        name = std::move(_name);
    }


    void setResult(vector<int> _result, const string &description) {
        playerResult.setSum(_result[0]);
        playerResult.setLevel(_result[1]);
        playerResult.setResultWithWeight();
        playerResult.setDescription(description);
    }

    string getName() {
        return name;
    }

    int getMoney() {
        return money;
    }


};


#endif //POKER_PLAYER_H
