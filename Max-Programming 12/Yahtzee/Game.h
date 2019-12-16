//
// Created by heckn on 2019-12-14.
//

#ifndef YAHTZEE_GAME_H
#define YAHTZEE_GAME_H

#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<iterator>
#include <random>
#include"ScoreSheet.h"

using namespace std;

class Game {
private:
    int dice[5]{};
    int preserve[5]{};
    int pickOut;
    random_device rd;  //Will be used to obtain a seed for the random number engine
    ScoreSheet player;

public:
    Game() //init
    {
        while (!player.game_finished()) {
            pickOut = 0;
            round();
        }
        //game over
        player.display();
    }

    void check_dice() {
        cout << "dice: ";
        for (int i : dice) {
            cout << i << " ";
        }
        cout << endl;
        cout << "preserve: ";
        for (int i : preserve) {
            cout << i << " ";
        }
        cout << endl;
    }

    void init_dice() {
        for (int &i : dice) {
            i = 0;
        }
    }

    void init_preserve() {
        for (int &i : preserve) {
            i = 0;
        }
    }

    void print_dice(int number) {

        cout << "Your dices:" << endl;
        for (int i = 0; i < number; i++) {

            mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
            uniform_int_distribution<> dis(1, 6);
            dice[i] = dis(gen);
            cout << dice[i] << " ";

        }
        cout << endl;
    }

    void picking_out() {
        cout << "Enter a number to select a dice you want to save." << endl;
        cout << "Enter 0 to end the pick_out operation when you finished." << endl;
        int pick = 0;
        do {
            cout << "Input:";
            cin >> pick;
            if (pick == 0) {
                break;
            }
            bool finded = false;
            for (int &i : dice) {
                if (i == pick) {
                    preserve[pickOut] = i;
                    cout << "TEST_MESSAGE: dice[" << i << "] =" << dice[i] << "  dice[" << i << "] -> preserve["
                         << pickOut
                         << "] " << endl;
                    i = 0; //clean the transferred dice
                    pickOut++;
                    finded = true;
                    break;
                }
            }
            if (!finded) {
                cout << "ERROR: Can't find  this dice, check your number and retry. " << endl;
                continue;
            }
        } while (pick != 0);
    }

    static void pressAnyKeyToContinue() {
        system("pause");
    }

    void round() {
        bool finished = false;//after player_action(); return 0
        for (int i = 1; i <= 3; ++i)//each round has 3 tern
        {
            system("cls");//clear
            player.init_counter();
            init_dice();
            player.display(); //display new sheet
            cout << endl;
            cout << "This is your " << i << " round." << endl;
            cout << endl;
            print_dice(5 - pickOut);
            cout << endl;
            check_dice();
            cout << endl;
            picking_out();
            cout << endl;
            player.counting(dice, preserve);
            pressAnyKeyToContinue();
            system("cls");
            player.display();
            if (i < 3) {
                cout << "Do you want to use the score paper now? (0/1) ";
                int statement = 0;
                cin >> statement;
                if (statement == 1) {
                    player.player_action();
                    break;
                }
            } else if (i == 3) {
                player.player_action();
            }
        }
        system("cls");
        player.statistics();
        init_dice();
        init_preserve();
        player.display();
        pressAnyKeyToContinue();
    }
};


#endif //YAHTZEE_GAME_H
