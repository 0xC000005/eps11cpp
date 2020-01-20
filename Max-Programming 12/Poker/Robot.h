//
// Created by m04.zhang on 2020-01-16.
//

#ifndef POKER_ROBOT_H
#define POKER_ROBOT_H

#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include "Card.h"

class Robot {
private:
    string name;

public:
    Robot() = default;

    int money = 100;
    bool fold = false, dealer = false;
    vector<Card> playerCard;

    void setName(string _name) {
        name = std::move(_name);
    }

    string getName() {
        return name;
    }

    int getMoney() {
        return money;
    }

    vector<Card> allCombination(const vector<Card> &playerCard) {

        vector<Card> totalCard;
        for (const auto &element: playerCard) {
            totalCard.push_back(element);
        }
        for (const auto &element: deckCards) {
            totalCard.push_back(element);
        }

        do {
            for (auto element:totalCard) {

            }
            cout << endl;
        } while (next_permutation(totalCard.begin(), totalCard.end()));
        return vector<Card>();
    }
};


#endif //POKER_ROBOT_H
