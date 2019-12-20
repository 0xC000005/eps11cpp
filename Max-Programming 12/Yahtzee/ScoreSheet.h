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
#include <windows.h>
#include "Score.h"

using namespace std;

class ScoreSheet {
private:
    vector<Score> score_paper;
    string name;
    string DESCRIPTIONS[16];
    bool finished;
    int playerID{}; //for multi-player
    int counter[6]{};
    HANDLE h;
public:
    ScoreSheet() = default;

    explicit ScoreSheet(int const &_playerID)//init var
    {
        h = GetStdHandle(STD_OUTPUT_HANDLE);
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

    void setColor(int _color) {
        //string message = "NOTICE: custom command - '" + to_string(_color) + "' has affected.";
        //notice_message(message);
        SetConsoleTextAttribute(h, _color);
    }

    void resetColor() {
        SetConsoleTextAttribute(h, 15);
    }

    void display() {
        cout << name << "'s Score Sheet:" << endl<<endl;
        cout << "HINT: ";
        setColor(10);
        cout << "GREEN indicate items that have noo-zero potential score"<<endl;
        setColor(4);
        cout << "      RED indicate items that have been selected";
        resetColor();
        cout << endl << endl;
        cout << " ID | STATUS |   DESCRIPTION   | SCORE " << endl;
        cout << "--------------------------------------" << endl;
        for (auto item : score_paper) {
            if (item.getID() == -1) {
                if (item.getDescription() == "TOTAL SCORE" || item.getDescription() == "Sum")
                    cout << "--------------------------------------" << endl;
                cout << "             | ";
                cout.setf(ios::left);
                cout.width(16);
                cout << item.getDescription();
                cout << "|  " << item.getScore() << endl; // total score doesnt need markded sign
                if (item.getDescription() == "Bonus") cout << "--------------------------------------" << endl;
                continue;
            } else {
                if (item.getUsed() == 1) {
                    //marked = "   ☑";
                    cout << " ";
                    cout.setf(ios::left);
                    cout.width(2);
                    cout << item.getID() + 1;
                    cout << " |    ";
                    setColor(4);
                    cout << "x";
                    resetColor();
                    cout << "   | ";
                    cout.setf(ios::left);
                    cout.width(16);
                    cout << item.getDescription();
                    cout << "|  " << item.getScore() << endl;
                    continue;
                } else {
                    //marked = "   ☐";
                    cout << " ";
                    cout.setf(ios::left);
                    cout.width(2);
                    if (calculator(item.getID()) == 0) {
                        cout << item.getID() + 1;
                    } else {
                        setColor(10);
                        cout << item.getID() + 1;
                        resetColor();
                    }
                    cout << " |    ";
                    cout << "o";
                    cout << "   | ";
                    cout.setf(ios::left);
                    cout.width(16);
                    cout << item.getDescription();
                    if (calculator(item.getID()) == 0)cout << "|  " << calculator(item.getID()) << endl;
                    else {
                        cout << "|  ";
                        setColor(10);
                        cout << calculator(item.getID());
                        resetColor();
                        cout << endl;
                    }
                }
            }
        }
    }

    void init() {
        cout << "Please enter your name: ";
        name = "\n";
        getline(cin, name);
        getline(cin, name);
        if (name.empty())getline(cin, name);
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
            sum =25;
            for (int i = 0; i < 5; ++i) {
                if (counter[i] == 2)two = true;
                if (counter[i] == 3)three = true;
            }
            if (!(two && three))sum = 0;
        }
        if (type == 9)//Small straight
        {
            sum=30;
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
            sum=40;
            for (int i = 0; i < 5; ++i) {
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

    void player_action(int action = 0) {
        if (!action) {
            cout << "Enter the ID of the option you want to mark this round: ";
            cin >> action;
        }
        action -= 1;
        for (auto &item : score_paper) {
            if (action == item.getID()) {
                if (item.getUsed()) {
                    error_message("ERROR: the item you just selected has marked.");
                    player_action();
                }
                /*
                if (action == -1) {
                    string message = "ERROR: you can't select item 'Sum'.";
                    error_message(message);
                    player_action();
                }*/
                item.setScore(calculator(item.getID()));
                item.setUsed(true);
                cout << endl << "the item '" << item.getDescription() << "' has marked as " << item.getScore() << endl;
                break;
            }
        }
        if (action > 12 || action < 0) {
            string message = "ERROR: can't find the selected ID '" + to_string(action + 1) + "' on score sheet.";
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
        setColor(79);
        cout << message << endl;
        resetColor(); //reset the color theme

    }

    void warning_message(const string &message) {
        setColor(111);
        cout << message << endl;
        resetColor();
    }

    void test_message(const string &message) {
        setColor(47);
        cout << message << endl;
        resetColor();
    }

    void notice_message(const string &message) {
        setColor(31);
        cout << message << endl;
        resetColor();
    }

};

#endif //YAHTZEE_SCORESHEET_H