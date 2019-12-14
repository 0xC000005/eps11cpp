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
        clean_dice();
        clean_preserve();
        pickOut = 0;
        init();
        while (!player.game_finished()) {
            round();
        }
    }

    void check_dice() {
        cout << "TEST_MESSAGE: starting the test func. check_dice. " << endl;
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

    void clean_dice() {
        for (int &i : dice) {
            i = 0;
        }
    }

    void clean_preserve() {
        for (int &i : preserve) {
            i = 0;
        }
    }

    static void init() {
        cout << "TEST_MESSAGE: class 'Game' init." << endl;
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

    static void pressAnyKeyToContinue() {
        cout << "Press Enter key to continue..." << endl;
        getchar();
    }

    void picking_out() {
        cout << "TEST_MESSAGE: starting func. picking_out." << endl;
        cout << "Enter a number to select a dice you want to save." << endl;
        cout << "Enter 0 to end the pick_out operation when you finished." << endl;
        int pick = -1;
        while (pick != 0) {
            cout << "Input:";
            cin >> pick;
            if (pick != 0) {
                for (int i = 0; i < 5; i++) {
                    if (dice[i] ==
                        pick)//find the first right dice in the dice sequence, and store into preserve sequence with index = pickOut
                    {
                        preserve[pickOut] = dice[i];
                        cout << "TEST_MESSAGE: dice[i] =" << dice[i] << "  dice[" << i << "] -> preserve[" << pickOut
                             << "] " << endl;
                        dice[i] = 0;
                        pickOut++;
                        break;

                        /*

                            can also add a dice check here

                        */
                    }
                }
            }
        }
    }

    void round() {
        cout << "TEST_MESSAGE: new 'round' event start." << endl;
        bool finished = false;//after player_action(); return 0
        for (int i = 1; i <= 3; ++i)//each round has 3 tern
        {
            //system("cls");//clear
            player.check_counter();
            player.init_counter();
            player.check_counter();
            clean_dice();
            player.display(false); //display new sheet
            cout << "This is your " << i << " round." << endl;
            print_dice(5 - pickOut);
            check_dice();
            picking_out();
            player.counting(dice, preserve);
            //system("cls");
            player.display(false);
            if (i < 3) {
                cout << "Do you want to use the score paper now? (0/1)";
                int statement = 0;
                cin >> statement;
                if (statement == 1) {
                    player.player_action();
                    break;
                }
            } else if (i == 3) {
                player.player_action();
            }
            player.display(false);
        }
    }

    void check_pickOut() {
        cout << "pickOut = " << pickOut << endl;
    }

};

