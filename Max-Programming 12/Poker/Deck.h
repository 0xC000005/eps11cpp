//
// Created by m04.zhang on 2020-01-14.
//

#ifndef POKER_DECK_H
#define POKER_DECK_H

#include<iostream>
#include<string>
#include "Card.h"
#include<vector>

using namespace std;

class Deck {
private:
    int pTotal{}, dTotal{}, money{}, Check_Code{}, bet{}, p_aceCounter{}, d_aceCounter{};
    string hit, next_round, name;
    vector<Card> deck;
    vector<Card> playerCard;
    Card tempCard;

    int SHUFFLE{};
    string SUITS[4];
    string DESC[13];
    int VALUE[13] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

public:
    Deck() {
        money = 500;
        p_aceCounter = 0;
        d_aceCounter = 0;
        next_round = "yes";
        SHUFFLE = 1000;
        SUITS[0] = "Heart";
        SUITS[1] = "Diamonds";
        SUITS[2] = "Spades";
        SUITS[3] = "Clubs";
        DESC[0] = "Ace";
        DESC[1] = "Two";
        DESC[2] = "Three";
        DESC[3] = "Four";
        DESC[4] = "Five";
        DESC[5] = "Six";
        DESC[6] = "Seven";
        DESC[7] = "Eight";
        DESC[8] = "Nine";
        DESC[9] = "Ten";
        DESC[10] = "Jack";
        DESC[11] = "Queen";
        DESC[12] = "King";
        VALUE[0] = 1;
        VALUE[1] = 2;
        VALUE[2] = 3;
        VALUE[3] = 4;
        VALUE[4] = 5;
        VALUE[5] = 6;
        VALUE[6] = 7;
        VALUE[7] = 8;
        VALUE[8] = 9;
        VALUE[9] = 10;
        VALUE[10] = 11;
        VALUE[11] = 12;
        VALUE[12] = 13;
    }


    void addCard(int index1, const Card &cardToAdd) {
        deck.push_back(cardToAdd);
    }

    void card_swap(int num1, int num2) {
        deck[num1] = deck[num2];
        deck[num2] = tempCard;
    }

    void shuffle() {
        int num1, num2;
        for (int x = 1; x <= SHUFFLE; x++) {
            do {
                num1 = rand() % 52;// number from 0-51
                num2 = rand() % 52;// 1 number less than value
            } while (num1 == num2);
            card_swap(num1, num2);
        }
    }

    void loadDeck() {
        for (int s = 0; s < 4; s++)
            for (int d = 0; d < 13; d++) {
                tempCard.setSuit(SUITS[s]);
                tempCard.setDescription(DESC[d]);
                tempCard.setValue(VALUE[d]);
                addCard(13 * s + d, tempCard);
            }
    }

    void init() {
        loadDeck();
        shuffle();
        cout << "Please enter your name: ";
        name = "\n";
        getline(cin, name);
        getline(cin, name);
        if (name.empty())getline(cin, name);
    }


};


#endif //POKER_DECK_H
