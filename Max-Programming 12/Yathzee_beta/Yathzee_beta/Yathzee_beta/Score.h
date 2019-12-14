//Max Zhang - Nov. 28
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
    int used{};
    int score{};
    int num{};

public:
    Score() = default;

    explicit Score(string const &_name) //init with description
    {
        setDescription(_name);
        used = 0;
        score = 0;
    }

    void setDescription(string _description) {
        description = std::move(_description);
    }

    string getDescription() {
        return description;
    }

    void setUsed(int _used) {
        used = _used;
    }

    int getUsed() {
        return used;
    }

    void setScore(int _score) {
        score = _score;
    }

    int getScore() {
        return score;
    }

    void setNum(int _num) {
        num = _num;
    }

    int getNum() {
        return num;
    }
};