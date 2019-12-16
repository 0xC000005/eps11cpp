//
// Created by heckn on 2019-12-14.
//

#ifndef YAHTZEE_SCORE_H
#define YAHTZEE_SCORE_H

#include<iostream>
#include<string>
#include<list>
#include <utility>
#include<vector>
#include<iterator>

using namespace std;

class Score {
private:
    string description;
    bool used{};
    int score{};
    int ID{};

public:
    Score() = default;

    explicit Score(string const &_name) //init with description
    {
        setDescription(_name);
        used = false;
        score = 0;
    }

    void setDescription(string _description) {
        description = std::move(_description);
    }

    string getDescription() {
        return description;
    }

    void setUsed(bool _used){
        used = _used;
    }

    bool getUsed() {
        return used;
    }

    void setScore(int _score) {
        score = _score;
    }

    int getScore() {
        return score;
    }

    void setID(int _num) {
        ID = _num;
    }

    int getID() {
        return ID;
    }
};

#endif //YAHTZEE_SCORE_H