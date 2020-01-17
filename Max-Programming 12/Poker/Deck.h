//
// Created by m04.zhang on 2020-01-14.
//

#ifndef POKER_DECK_H
#define POKER_DECK_H

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include "Card.h"
#include "Player.h"

using namespace std;

class Deck {
private:
    vector<Card> deck;
    int SHUFFLE{};
    string SUITS[4];
    string DESC[13];
    int VALUE[13] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

public:
    vector<Player> playerList;
    vector<Card> deckCards;
    int highestBet{};
    bool check = true;

    Deck() {
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

    void addNewPlayer() {
        cout << "Please input the name for this player: ";
        string name = "\n";
        getline(cin, name);
        getline(cin, name);
        if (name.empty())getline(cin, name);
        Player temp;
        playerList.push_back(temp);
    }

    void shuffle() {
        int num1, num2;
        for (int x = 1; x <= SHUFFLE; x++) {
            do {
                num1 = rand() % 52;// number from 0-51
                num2 = rand() % 52;// 1 number less than value
            } while (num1 == num2);
            swap(deck[num1], deck[num2]);
        }
    }

    void loadDeck() {
        for (const auto &s : SUITS)
            for (int d = 0; d < 13; d++) {
                Card tempCard;
                tempCard.setSuit(s);
                tempCard.setDescription(DESC[d]);
                tempCard.setValue(VALUE[d]);
                deck.push_back(tempCard);
            }
    }

    void init() {
        loadDeck();
        shuffle();

    }

    Card take() {
        Card temp = deck[0];
        deck.erase(deck.begin());
        return temp;
    }

    Card takeCard() {
        if (deck.empty()) {
            cout << "ERROR:RUN OUT THE CARDS" << endl;
            cout << "Play again? (yes/no)";
            string temp;
            cout << temp;
            if (temp == "yes") {
                init();
            }
        }
        Card temp = take();
        return temp;
    }

    void assignCards() {
        for (int i = 0; i < 2; i++) {
            for (auto &element: playerList) {
                element.playerCard.push_back(takeCard());
            }
        }
    }

    void showDeck() {
        for (auto element : deck) {
            cout << element.getDescription() << " of " << element.getSuit() << endl;
        }
    }

    static int showPlayerCard(const Player &temp) {
        int count = 0;
        for (auto element : temp.playerCard) {
            count++;
            cout << count << ". " << element.getDescription() << " of " << element.getSuit() << endl;
        }
        return count;
    }

    void discard(int num) {
        system("cls");
        cout << "=================================DISCARD================================" << endl << endl;
        cout << playerList[num].getName() << "'s cards: " << endl;
        int range = showPlayerCard(playerList[num]);
        cout << "Input the number of the card that you want to discard, input 0 to exit: " << endl;
        int ID;
        cin >> ID;
        if (ID < 0 || ID > range) {
            cout << "ERROR: Can't find ID" << ID << endl;
            discard(num);
        } else if (ID) {
            Card newCard = takeCard();
            swap(playerList[num].playerCard[ID - 1], newCard);
        }
    }

    void setAnte() {
        int ante;
        bool allGood = false;
        cout << "Input Antes: " << endl;
        cin >> ante;
        for (auto element: playerList) {

            highestBet = ante;
        }


    }

    int transfer(Player element, int money) {
        if (element.getMoney() < money) {
            cout << element.getName() << " doesn't have enough money, " << element.getName() << " only have "
                 << element.getMoney() << "$." << endl;
            return -1;
        }

        if (money > highestBet) {
            highestBet = money;
            cout << "Now the new highest bet is " << highestBet << endl;
        }

        cout << element.getName() << " has paid ante. Now " << element.getName() << " only has "
             << element.getMoney() << "$" << endl;
        element.money -= money;
        element.bet = money;

    }


    void calling(Player &player) {
        cout << player.getName() << " called. " << endl << endl;
        if (transfer(player, highestBet) == -1) {
            calling(player);
        }
    }

    void raising(Player &player) {
        cout << player.getName() << " raised. " << endl << endl;
        cout << "The current bet is " << highestBet << endl;
        cout << "How much money do you want to raise to? ";
        int raise;
        cin >> raise;
        if (raise < highestBet || transfer(player, raise) == -1) {
            raising(player);
        }

    }

    static void folding(Player &player) {
        player.fold = true;
        cout << player.getName() << " has folded. " << endl << endl;
    }

    static void checking(Player player) {
        cout << player.getName() << " choose to check. " << endl << endl;
    }

    void betting(Player player) {
        system("cls");
        cout << "=================================BETTING================================" << endl << endl;
        cout << "Now " << player.getName() << " is betting, you only have " << player.money << endl;
        cout << "1. Calling" << endl;
        cout << "2. Raising" << endl;
        cout << "3. Fold" << endl;
        if (check) cout << "4. Check" << endl << endl;
        cout << "Input the option that you want ot select: ";
        int option;
        cin >> option;
        if (option == 1) {
            calling(player);
        }
        if (option == 2) {
            raising(player);
        }
        if (option == 3) {
            folding(player);
        }
        if (option == 4) {
            checking(player);
        }
        if (option < 4)check = false;


    }

    void getCardScore(vector<Card> &Cards) {
        bool straight = true, flush = true, fourOfAKind = false, threeOfAKind = false, onePairs = false, twoPairs = false;
        int values[13];
        for (int i = 0; i < Cards.size(); i++) {
            Card element = Cards[i];
            if (i != Cards.size() - 1) {
                if (element.getSuit() != element.getSuit())flush = false;
                if (element.getValue() != element.getValue())straight = false;
            }
            values[element.getValue()]++;
        }

        for (int i: values) {
            if (i == 4)fourOfAKind = true;
            if (i == 3)threeOfAKind = true;
            if (i == 2)onePairs = true;
            if (onePairs && i == 2) twoPairs = true;
        }
    }


    static int getCardPoints() {
        cout << "High card" << endl;

        cout << "One pair" << endl;
        cout << "Two pair" << endl;
        cout << "Three of a kind" << endl;
        cout << "Straight" << endl;
        cout << "Flush" << endl;
        cout << "Full house" << endl;
        cout << "Four of a Kind" << endl;
        cout << "Straight Flush" << endl;
        cout << "Royal Flush" << endl;
        cout << "Five of a kind " << endl;
        return 0;
    }

};


#endif //POKER_DECK_H