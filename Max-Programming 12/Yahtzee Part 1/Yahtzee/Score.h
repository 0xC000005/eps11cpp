//Max Zhang - Nov. 28
#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<iterator> 
#include<conio.h>
using namespace std;
class Score
{
	private: 
		string description;
        int used;
        int score;
        int num;
    
	public: 
		Score(){}
		Score(string const  &_name)
		{
			setDescription(_name);
			used=0;
			score=0;
		}
    
    void Score::setDescription(string _description)
    {
        description=_description;
    }
    string Score::getDescription()
    {
        return description;
    }
    
    void Score::setUsed(int _used)
    {
        used=_used;
    }
    int Score::getUsed()
    {
        return used;
    }
    
    void Score::setScore(int _score)
    {
        score=_score;
    }
    int Score::getScore()
    {
        return score;
    }
    
    void Score::setNum(int _num)
    {
        num=_num;
    }
    int Score::getNum()
    {
        return num;
    }
};