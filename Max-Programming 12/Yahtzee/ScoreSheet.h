//
// Created by heckn on 2019-12-14.
//

#ifndef YAHTZEE_SCORESHEET_H
#define YAHTZEE_SCORESHEET_H

#include <iostream>
#include <string>
#include <list>
#include <utility>
#include <vector>
#include <iterator>
#include <mem.h>
#include "Score.h"

using namespace std;

class ScoreSheet {
private:
    vector<Score> score_paper;
    string name;
    string DESCRIPTIONS[16];
    string default_color_theme[7];
    string custom_command;
    bool finished;
    int playerID{}; //for multi-player
    int counter[6]{};
public:
    ScoreSheet() = default;

    explicit ScoreSheet(int const &_playerID)//init var
    {
        setPlayerID(_playerID);
        DESCRIPTIONS[0] = "Ones";
        DESCRIPTIONS[1] = "Twos";
        DESCRIPTIONS[2] = "Threes";
        DESCRIPTIONS[3] = "Fours";
        DESCRIPTIONS[4] = "Fives";
        DESCRIPTIONS[5] = "Sixes";
        DESCRIPTIONS[6] = "Sum";
        DESCRIPTIONS[7] = "Bonus";
        DESCRIPTIONS[8] = "Three of a Kind";
        DESCRIPTIONS[9] = "Four of a Kind";
        DESCRIPTIONS[10] = "Full House";
        DESCRIPTIONS[11] = "Small Straight";
        DESCRIPTIONS[12] = "Large Straight";
        DESCRIPTIONS[13] = "Chance";
        DESCRIPTIONS[14] = "YAHTZEE";
        DESCRIPTIONS[15] = "TOTAL SCORE";
        //custom color theme
        default_color_theme[0] = "color";
        default_color_theme[1] = "color 02";
        default_color_theme[2] = "color 03";
        default_color_theme[3] = "color 06";
        default_color_theme[4] = "color 0B";
        default_color_theme[5] = "color 1F";
        default_color_theme[6] = "color F0";
        finished = false;
        init_counter();
        init();
    }

    void setPlayerID(int _playerID) {
        playerID = _playerID;
    }

    int getPlayerID() {
        return playerID;
    }

    void setCustom_command(string _custom_command) {
        string message = "NOTICE: custom command - '" + _custom_command + " has affected.";
        notice_message(message);
        custom_command = std::move(_custom_command);
    }

    void applyCustom_command() {
        char *command = strdup(custom_command.c_str());
        system(command);
        free(command);
    }

    void setColor_theme() {
        cout<< "Do you want to set the color of this player? Press enter to use the default color scheme, input 'help' for help: ";
        string color_theme;
        getline(cin, color_theme);
        if (color_theme == "help") {
            system("help");
            setColor_theme();
        }
        if (color_theme.empty()) {
            //set your own default color theme
            for (int i = 0; i < 5; i++) {
                setCustom_command(default_color_theme[i]);
            }
        } else {
            setCustom_command(color_theme);
        }
    }

    void display() {
        cout << name << "'s Score Sheet:" << endl << endl;
        cout << "STATUS |   DESCRIPTION   | SCORE " << endl;
        cout << "--------------------------------" << endl;
        for (auto item : score_paper) {
            if (item.getID() == -1) {
                if (item.getDescription() == "TOTAL SCORE" || item.getDescription() == "Sum")
                    cout << "--------------------------------" << endl;
                cout << "       | ";
                cout.setf(ios::left);
                cout.width(16);
                cout << item.getDescription();
                cout << "| " << item.getScore() << endl; // total score doesnt need markded sign
                if (item.getDescription() == "Bonus") cout << "--------------------------------" << endl;
                continue;
            } else {
                string marked;
                if (item.getUsed() == 1) {
                    //marked = "   ☑";
                    marked = "   x";
                    cout << marked << "   | ";
                    cout.setf(ios::left);
                    cout.width(16);
                    cout << item.getDescription();
                    cout << "| " << item.getScore() << endl;
                    continue;
                } else {
                    //marked = "   ☐";
                    marked = "   o";
                    cout << marked << "   | ";
                    cout.setf(ios::left);
                    cout.width(16);
                    cout << item.getDescription();
                    cout << "| " << calculator(item.getID()) << endl;
                }
            }
        }
    }

    void init() {
        setColor_theme();
        cout << "Please enter your name: ";
        cin >> name;
        bool bypass = false;//use to bypass Sum and Bouns at the first time
        int count = 0;//use count to replace swither(int type)
        for (const auto &i : DESCRIPTIONS) {
            Score temp = Score(i);//init temp with description
            if (((count == 6) || (count == 7)) && !bypass)//first time meet sum and bouns
                temp.setID(-1);//set ID=-1 for sum and bouns
            else if (count == 8 && !bypass) {
                count -= 2;
                bypass = true;
                temp.setID(count);
            } else if (count == 13) {
                temp.setID(-1);
            } else {
                temp.setID(count);
            }
            score_paper.push_back(temp);
            count++;
        }
    }

    bool game_finished() {
        finished = true;
        for (auto item : score_paper) {
            if (!item.getUsed()) {
                if (item.getDescription() == "Sum" || item.getDescription() == "Bonus" ||
                    item.getDescription() == "TOTAL SCORE")
                    continue;
                finished = false;
                break;
            }
        }
        return finished;
    }

    void counting(const int dice[], const int preserve[]) //make dices_list -> counter
    {
        for (int i = 0; i < 5; ++i) {
            if (dice[i] != 0) {
                counter[dice[i] - 1]++;
            }
            if (preserve[i] != 0) {
                counter[preserve[i] - 1]++;
            }
        }
    }

    void init_counter() {
        for (int &i : counter) {
            i = 0;
        }
    }

    int calculator(int type)//calculating the score for Score Sheet
    {
        int sum = 0;
        if (0 <= type && type <= 5)sum = counter[type] * (type + 1);//Ones~Sixes
        if (type == 6)//Three of a kind
        {
            for (int i = 0; i < 5; ++i) {
                bool statement = false;
                sum += counter[i] * (i + 1);
                if (counter[i] == 3) {
                    statement = true;
                    break;
                }
                if (!statement)sum = 0;
            }
        }
        if (type == 7)//Four of a kind
        {
            for (int i = 0; i < 5; ++i) {
                bool statement = false;
                sum += counter[i] * (i + 1);
                if (counter[i] == 4) {
                    statement = true;
                    break;
                }
                if (!statement)sum = 0;
            }
        }
        if (type == 8)//Full house
        {
            bool two = false, three = false;
            for (int i = 0; i < 5; ++i) {
                sum += counter[i] * (i + 1);
                if (counter[i] == 2)two = true;
                if (counter[i] == 3)three = true;
            }
            if (!(two && three))sum = 0;
        }
        if (type == 9)//Small straight
        {
            for (int i = 0; i < 5; ++i)sum += counter[i] * (i + 1);
            bool case1 = true, case2 = true, case3 = true;
            for (int i = 0; i < 3; ++i) {
                if (!(counter[i] > 0 && counter[i + 1] > 0))case1 = false;
                if (!(counter[i + 1] > 0 && counter[i + 2] > 0))case2 = false;
                if (!(counter[i + 2] > 0 && counter[i + 3] > 0))case3 = false;
            }
            if (!(case1 || case2 || case3))sum = 0;
        }
        if (type == 10)//Large straight
        {
            bool statement = true;
            for (int i = 0; i < 5; ++i) {
                sum += counter[i] * (i + 1);
                if (counter[i] != 1)statement = false;
            }
            if (!statement)sum = 0;
        }
        if (type == 11)//Chance
        {
            for (int i = 0; i < 5; ++i) {
                sum += counter[i] * (i + 1);
            }
        }
        if (type == 12)//YAHTZEE
        {
            for (int i = 0; i < 5; ++i) {
                if (counter[i] == 5)sum = 50;
            }
            if (sum != 50)sum = 0;
        }

        return sum;
    }

    void player_action() {
        cout << "Enter *full name* of the option you want to mark this round: ";
        string action;
        bool finded = false;
        getline(cin, action);
        if (action.empty()) {
            getline(cin, action);
        }
        for (auto &item : score_paper) {
            if (action == item.getDescription()) {
                if (item.getUsed()) {
                    error_message("ERROR: the item you just selected has marked.");
                    player_action();
                }
                if (action == "Sum" || action == "Bonus" || action == "TOTAL SCORE") {
                    string message = "ERROR: you can't select item '" + action + "'.";
                    error_message(message);
                    player_action();
                }
                finded = true;
                item.setScore(calculator(item.getID()));
                item.setUsed(true);
                cout << endl << "the item '" << item.getDescription() << "' has marked as " << item.getScore() << endl;
                break;
            }
        }
        if (!finded) {
            string message ="ERROR: can't find the selected item '" + action + "' on score sheet.";
            error_message(message);
            player_action();
        }
    }

    void statistics() {
        int sum = 0, total = 0;
        for (int i = 0; i < score_paper.size(); i++) {
            if (i < 6) sum += score_paper[i].getScore();
            if (i == 6)score_paper[i].setScore(sum);
            if (i == 7 && score_paper[i - 1].getScore() >= 56)score_paper[i].setScore(50);
            if (i >= 8 && i <= 14) total += score_paper[i].getScore();
            if (i == 15)score_paper[i].setScore(total + score_paper[6].getScore() + score_paper[7].getScore());
        }
    }

    string getName() {
        return name;
    }

    int getTotalScore() {
        return score_paper[15].getScore();
    }

    void error_message(const string &message) {
        system("color 4F");
        cout << message << endl;
        applyCustom_command(); //reset the color theme

    }

    void warning_message(const string &message) {
        system("color 60");
        cout << message << endl;
        applyCustom_command();
    }

    void test_message(const string &message) {
        system("color 0A");
        cout << message << endl;
        applyCustom_command();
    }

    void notice_message(const string &message) {
        system("color 09");
        cout << message << endl;
        applyCustom_command();
    }

};

#endif //YAHTZEE_SCORESHEET_H