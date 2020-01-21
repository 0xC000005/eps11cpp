//
// Created by heckn on 2020-01-21.
//

#ifndef POKER_RESULT_H
#define POKER_RESULT_H

#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include "Card.h"

class Result {
private:
    int level = 0;
    int sum = 0;
    int resultWithWeight = 0;
public:
    Result() = default;

    void setLevel(int _level) {
        level = _level;
    }

    int getLevel() {
        return level;
    }

    void setSum(int _sum) {
        sum = _sum;

    }

    int getSum() {
        return sum;
    }

    void setResultWithWeight() {
        resultWithWeight = level * sum;
    }

    int getResultWithWeight() {
        setResultWithWeight();
        return resultWithWeight;
    }

};


#endif //POKER_RESULT_H
