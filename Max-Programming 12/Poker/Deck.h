//
// Created by m04.zhang on 2020-01-14.
//

#ifndef POKER_DECK_H
#define POKER_DECK_H

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <random>
#include "Card.h"
#include "Player.h"
#include "Result.h"

using namespace std;

class Deck {
private:
    vector<Card> deck;
    int SHUFFLE{}, bet{};
    string SUITS[4];
    string DESC[13];
    int VALUE[13] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

public:
    vector<Player> playerList;
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
        string name;
        cin >> name;
        Player player;
        player.setName(name);
        playerList.push_back(player);
    }

    void shuffle() {
        random_device rd;  //Will be used to obtain a seed for the random number engine
        mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        uniform_int_distribution<> dis(1, 52);
        int num1, num2;
        for (int x = 1; x <= SHUFFLE; x++) {
            do {
                num1 = dis(gen);// number from 0-51
                num2 = dis(gen);// 1 number less than value
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
        for (int i = 0; i < 5; i++) {
            for (auto &element: playerList) {
                element.playerCard.push_back(takeCard());
            }
        }
    }

    static int displayPlayerCard(Player &player) {
        cout << player.getName() << "'s cards: " << endl;
        int count = 0;
        for (auto element : player.playerCard) {
            count++;
            cout << count << ". " << element.getDescription() << " of " << element.getSuit() << endl;
        }
        cout << endl;
        return count;
    }

    void discard(Player &player) {
        //system("cls");
        cout << "=================================DISCARD================================" << endl << endl;
        int range = displayPlayerCard(player);
        cout << "Input the number of the card that you want to discard, input 0 to exit: " << endl;
        while (true) {
            int ID;
            cin >> ID;
            if (!ID)break;
            if (ID < 0 || ID > range) {
                cout << "ERROR: Can't find ID" << ID << endl;
                discard(player);
            } else if (ID) {
                Card newCard = takeCard();
                swap(player.playerCard[ID - 1], newCard);
            }
        }
    }

    void setAnte() {
        int ante;
        cout << "Input Antes: ";
        cin >> ante;
        for (auto &player: playerList) {
            if (!transfer(player, ante)) {
                setAnte();
            }
        }
    }

    int transfer(Player &player, int playerBet) {
        if (player.getMoney() < playerBet) {
            cout << player.getName() << " doesn't have enough playerBet, " << player.getName() << " only have "
                 << player.getMoney() << "$." << endl;
            return 0;
        }

        if (playerBet > highestBet) {
            highestBet = playerBet;
            cout << "Now the new highest playerBet is " << highestBet << endl;
        }
        player.money -= playerBet;
        player.bet = playerBet;
        bet += playerBet;
        cout << player.getName() << " has paid ante. Now " << player.getName() << " only has "
             << player.getMoney() << "$" << endl;
        return 1;
    }

    void sorting() {
        vector<int> ranking;
        ranking.reserve(playerList.size());
        for (auto &player:playerList) {
            cout << player.playerResult.getSum() << endl;
            cout << player.playerResult.getLevel() << endl;
            cout << player.playerResult.getResultWithWeight() << endl;
            ranking.push_back(player.playerResult.getResultWithWeight());
        }
        int size = ranking.size();
        sort(ranking.begin(), ranking.end());

        cout << endl;

        for (int resultWithWeight:ranking) {
            for (int i = 0; i < playerList.size(); i++) {
                Player &player = playerList[i];
                if (resultWithWeight == player.playerResult.getResultWithWeight()) {
                    playerList.push_back(player);
                    playerList.erase(playerList.begin() + i);
                }
            }
        }
    }

    void displayPlayerScore() {
        for (auto player:playerList) {
            if (player.fold) {
                cout << player.getName() << " has folded. " << endl << endl;
                continue;
            }
            displayPlayerCard(player);
            cout << player.getName() << "'s cards: " << player.playerResult.getDescription() << " with "
                 << player.playerResult.getSum() << " points." << endl;
        }
    }

    void checkOut() {
        sorting();
        displayPlayerScore();
        for (int i = 0; i < playerList.size(); i++) {
            Player &player = playerList[i];
            if (i == playerList.size() - 1) {
                cout << player.getName() << " wins." << endl;
                player.money += bet;
            }
            player.reset();
        }
    }

    void calling(Player &player) {
        cout << player.getName() << " called. " << endl << endl;
        if (!transfer(player, highestBet)) {
            calling(player);
        }
    }

    void raising(Player &player) {
        cout << player.getName() << " raised. " << endl << endl;
        cout << "The current bet is " << highestBet << endl;
        cout << "How much money do you want to raise to? ";
        int raise;
        cin >> raise;
        if (raise < highestBet || !transfer(player, raise)) {
            raising(player);
        }

    }

    static void folding(Player &player) {
        player.fold = true;
        cout << player.getName() << " has folded. " << endl << endl;
    }

    static void checking(Player &player) {
        cout << player.getName() << " choose to check. " << endl << endl;
    }

    void betting(bool secondTime = false) {
        //system("cls");
        bool raised = false;
        for (auto &player:playerList) {
            if (player.fold)continue; //skip fold
            if (player.bet == highestBet && secondTime)continue;
            cout << "=================================BETTING================================" << endl << endl;
            cout << "Now " << player.getName() << " is betting, you only have " << player.money << "$" << endl;
            cout << "Current bet: " << highestBet << " , Total bet: " << bet << endl << endl;
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
                raised = true;
            }
            if (option == 3) {
                folding(player);
            }
            if (option == 4) {
                checking(player);
            }
            if (option < 4)check = false;
        }
        if (raised)betting(true);
    }

    static vector<int> getCardScore(vector<Card> &Cards) {
        bool fiveOfAKind = false, straightFlush = false, straight = true, flush = true, fourOfAKind = false, fullHouse = false, threeOfAKind = false, onePairs = false, twoPairs = false, highCard = false;
        int values[13];
        for (int &i:values)i = 0; //init
        for (int i = 0; i < Cards.size(); i++) {
            values[Cards[i].getValue() - 1]++;
            if (i != Cards.size() - 1) {
                if (Cards[i].getSuit() != Cards[i + 1].getSuit())flush = false;
            }
        }

        //for(int i:values) cout<<i;
        //cout<<endl;
        for (int i = 0; i < 13; i++) {
            if (values[i] == 5)fiveOfAKind = true;
            if (values[i] == 4)fourOfAKind = true;
            if (values[i] == 3)threeOfAKind = true;
            if (values[i] == 2)onePairs = true;
            if (onePairs && values[i] == 2) twoPairs = true;
            if (i < 13 && ((values[i] == 1) && (values[i + 1] != 1)))straight = false;
        }


        if (straight && flush) straightFlush = true;
        if (threeOfAKind && onePairs) fullHouse = true;

        int sum = 0;
        for (auto card:Cards) {
            sum += card.getValue();
        }

        int level = 1;
        if (straightFlush) level = 10;
        if (fiveOfAKind) level = 9;
        if (fourOfAKind) level = 8;
        if (fullHouse) level = 7;
        if (flush) level = 6;
        if (straight) level = 5;
        if (threeOfAKind) level = 4;
        if (twoPairs) level = 3;
        if (onePairs) level = 2;

        vector<int> result = {sum, level};
        return result;
    }


    static string getCardDescription(int level) {
        if (level == 1) {
            return "High card";
        }
        if (level == 2) {
            return "One pair";
        }
        if (level == 3) {
            return "Two pair";
        }
        if (level == 4) {
            return "Three of a kind";
        }
        if (level == 5) {
            return "Straight";
        }
        if (level == 6) {
            return "Flush";
        }
        if (level == 7) {
            return "Full house";
        }
        if (level == 8) {
            return "Four of a Kind";
        }
        if (level == 9) {
            return "Five of a kind ";
        }
        if (level == 10) {
            return "Straight Flush";
        }
        return std::__cxx11::string();
    }

    static void setPlayerScore(Player &player) {
        player.setResult(getCardScore(player.playerCard), getCardDescription(getCardScore(player.playerCard)[1]));
    }

};


#endif //POKER_DECK_H
