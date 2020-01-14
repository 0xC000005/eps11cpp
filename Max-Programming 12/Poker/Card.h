//
// Created by m04.zhang on 2020-01-14.
//

#ifndef POKER_CARD_H
#define POKER_CARD_H

#include<iostream>
#include<string>
#include<utility>

using namespace std;

class Card {
private:
    string description;
    string suit;
    int value{};

public:
    Card() = default;

    Card(string const &_description, string const &_suit, int const &_value) {
        setDescription(_description);
        setSuit(_suit);
        setValue(_value);
    }

    void setDescription(string _description) {
        description = std::move(_description);
    }

    string getDescription() {
        return description;
    }

    void setSuit(string _suit) {
        suit = std::move(_suit);
    }

    string getSuit() {
        return suit;
    }

    void setValue(int _value) {
        value = _value;
    }

    int getValue() {
        return value;
    }

};


#endif //POKER_CARD_H
