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
#include <unistd.h>
#include"ScoreSheet.h"

using namespace std;

class Game {
private:
    int dice[5]{};
    int preserve[5]{};
    int pickOut;
    int player_num;
    random_device rd;  //Will be used to obtain a seed for the random number engine
    vector<ScoreSheet> playerList;

public:
    Game() //init
    {
        player_num = 0;
        init_playerList();
        bool statues[player_num];
        while (!playerList[0].game_finished()) {
            //init table
            for (int i = 0; i < player_num; i++) {
                statues[i] = false;
            }
            table:
            system("cls");
            cout << "After all players have played in this round, the system will automatically enter the next round"
                 << endl << endl;
            cout << "STATUES |  PLAYER" << endl;
            cout << "-------------------" << endl;
            for (int i = 0; i < playerList.size(); i++) {
                if (statues[i])cout << "    x   |  player" << i << endl;
                else cout << "    o   |  player " << i << endl;
            }
            cout << "-------------------" << endl;
            cout << endl;
            cout << "Please select the number of player to operate:" << endl;
            int play = 0;
            cin >> play;
            /*if (play < player_num || play > player_num)//error check
            {
                cout << "WARNING: The number you inputed is not within the range retry." << endl;
                pressAnyKeyToContinue();
                goto table;
            }*/
            if (statues[play])//redundant
            {
                playerList[play].warning_message("WARNING: The player you selected has already played in this round, you can only choose players who have not played.");
                cout<< endl;
                pressAnyKeyToContinue();
                goto table;
            }

            pickOut = 0;
            playerList[play].applyCustom_command();
            round(playerList[play]);
            statues[play] = true;
            for (int i = 0; i < player_num; i++) {
                if (!statues[i])goto table;
            }
        }
        //game over
        cout << "NOTICE: GAME FINISHED" << endl;
        cout << "PLAYER | SCORE" << endl;
        for (int i = 0; i < player_num; i++) {
            cout << " " << i << " | " << playerList[i].getTotalScore() << endl;
        }
        cout << endl;
        for (auto item : playerList) {
            item.display();
            cout << endl;
        }
    }

    void init_playerList() {
        system("cls");
        cout << "Welcome to Yahtzee!" << endl;
        cout << endl;
        cout << "Loading features and Plugins";
        for (int i = 0; i < 6; i++) {
            cout << ".";
            sleep(1);

        }
        cout << endl;
        cout << "Feature 'Friend or foe identification system' now supports 7 players" << endl;
        cout << endl;
        cout << "Choose your Mode:" << endl;
        cout << "--------------------" << endl;
        cout << "Single player mode" << endl;
        cout << "Double player mode" << endl;
        cout << "Custom player number" << endl;
        cout << endl;
        cout << "Advanced Features:" << endl;
        cout << "--------------------" << endl;
        cout << "Load custom command set (now support Cygwin, MinGW and WSL)" << endl;
        cout << "Load customize plugin (see README.md on Github)" <<endl;
        cout << endl << endl;
        cout << "Choose your action: " << endl;
        string action;
        getline(cin, action);
        if (action.empty())getline(cin, action);
        bool success = false;
        //Here is the only hard code in the entire program!
        if (action == "Single player mode") {
            player_num = 1;
            success = true;
        }
        if (action == "Double player mode") {
            player_num = 2;
            success = true;
        }
        if (action == "Custom player number") {
            system("cls");
            cout << "input your custom player number: ";
            cin >> player_num;
            success = true;
        }
        if (action == "Load custom command set") {
            setCustom_command();
            success = true;
        }
        if(action == "Load customize plugin"){
            setCustom_command();
            success = true;
        }
        if (!success) {
            system("color 4F");
            cout << "ERROR: Can't find your action '" << action << "', please check and retry." << endl;
            system("color 0F");
            pressAnyKeyToContinue();
            init_playerList();
        }

        for (int i = 0; i < player_num; i++) {
            system("cls");
            cout << "initialize player" << i + 1 << endl;
            ScoreSheet player = ScoreSheet(i);
            playerList.push_back(player);
        }
    }

    void setCustom_command() {
        system("cls");
        cout << "input your custom command, input 'help' for help: ";
        string command;
        cin >> command;
        if (command == "help") {
            system("help");
            pressAnyKeyToContinue();
            setCustom_command();
        } else {
            system("systeminfo");
            cout << endl << endl;
            system("color 60");
            cout << "WARNING: It is detected that you are not running this program in Cygwin or UNIX system." << endl;
            cout
                    << "          The use of custom commands may result in an unstable state on the command line of your system: "
                    << endl;
            cout << "                 'Microsoft Windows 10 Pro 10.0.18363 N / A Build 18363'. " << endl;
            cout << "          Please go to UNIX Retry" << endl << endl;
            system("color 0F");
            pressAnyKeyToContinue();
        }
        init_playerList();
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

    void picking_out(ScoreSheet player) {
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
                    string message =  "TEST_MESSAGE: dice[" + to_string(i) + "] =" + to_string(dice[i]) + "  dice[" + to_string(i) + "] -> preserve[" + to_string(pickOut) + "] ";
                    player.test_message(message);
                    i = 0; //clean the transferred dice
                    pickOut++;
                    finded = true;
                    break;
                }
            }
            if (!finded) {
                player.error_message("ERROR: Can't find  this dice, check your number and retry. " );
                continue;
            }
        } while (pick != 0);
    }

    static void pressAnyKeyToContinue() {
        system("pause");
    }

    void round(ScoreSheet player) {
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
            picking_out(player);
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
