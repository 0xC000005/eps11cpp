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

class ScoreSheet
{
	private: 
		vector<Score> score_paper;
		string name;
		string DESCRIPTIONS[17];
		bool gameFinished;
		int counter[6];
        int result;
	public:
		ScoreSheet(){}
		ScoreSheet()
		{
			DESCRIPTIONS[] = {"Ones", "Twos", "Threes", "Fours", "Fives", "Sixes", "Sum", "Bonus", "Three of a Kind", "Four of a Kind", "Full House", "Small Straight", "Large Straight", "Chance", "Yahtzee", "Total Score"};
			gameFinished=false;
			counter[6];
			result=0,sum=0;
			init();

		}
    
    void ScoreSheet::init()
    {
        cin<<"Please enter your name: ";
        cin>>name;
        bool bypass=false;
        int count=0;//use count to replace swicher(int type)
        for(int i=0;i<16;++i)
        {
            Score temp=Score(DESCRIPTIONS[i]);
            if(((count==6)||(count==7))&&bypass==false)//first time meet sum and bouns
            {
                temp.setNum(-1);
            }
            else if(count==8&&bypass==false)
            {
                count-=2;
                bypass=true;
                temp.setNum(count);
            }
            else
            {
                temp.setNum(count);
            }
            score_paper.add(temp);
            count++;
        }
        display(true);
    }
    
    void ScoreSheet::display(bool firstTime)
    {
        cout<<name<<"'s Score Sheet:";
        for(int i=0;i<score_paper.size();i++)
        {
			Score item=score_paper[i];
            if(item.getDescription()=="Total Score")cout<<item.getDescription()<<" "<<item.getScore()<<endl;
            else
            {
                string marked;
                if(item.getUsed()==1)
                {
                    marked="☑";
                    cout<<marked<<" "<<item.getDescription()<<" "<<item.getScore()<<endl;
                }
                else
                {
                    marked="☐";
                    if(firstTime)cout<<marked+" "<<item.getDescription()<<" "<<item.getScore()<<endl;
                    else
                    {
                        if(item.getNum()==-1)cout<<marked<<" "<<item.getDescription()<<" "<<item.getScore();
                        else
                        {
                            swicher(item.getNum());
                            cout<<marked<<" "<<item.getDescription()<<" "<<sum;
                        }
                    }
                }
            }
        }
    }
    
    bool ScoreSheet::game_finished()
    {
        gameFinished=true;
        for(int i; i<score_paper.size(); i++)
        {
			Score item=score_paper[i];
            if(item.getUsed()==0)gameFinished=false;
            break;
        }
        return gameFinished;
    }
    
    void ScoreSheet::counter(int dice[],int preserve[])
    {
        for(int i=0;i<5;++i)
        {
            if(dice[i]!=0)counter[dice[i]-1]++;
            if(preserve[i]!=0)counter[preserve[i]-1]++;
        }
    }
    
    void ScoreSheet::swicher(int type)
    {
        if(0<=type&&type<=5)sum=counter[type]*(type+1);//Ones~Sixes
        else if(type==6)//Three of a kind
        {
            for(int i=0;i<5;++i)
            {
                bool statment=false;
                sum+=counter[i]*(i+1);
                if(counter[i]==3)
                {
                    statment=true;
                    break;
                }
                if(!statment)sum=0;
            }
        }
        else if(type==7)//Four of a kind
        {
            for(int i=0;i<5;++i)
            {
                bool statment=false;
                sum+=counter[i]*(i+1);
                if(counter[i]==4)
                {
                    statment=true;
                    break;
                }
                if(!statment)sum=0;
            }
        }
        else if(type==8)//Full house
        {
            bool two=false,three=false;
            for(int i=0;i<5;++i)
            {
                sum+=counter[i]*(i+1);
                if(counter[i]==2)two=true;
                if(counter[i]==3)three=true;
            }
            if(!(two&&three))sum=0;
        }
        else if(type==9)//Small straight
        {
            for(int i=0;i<5;++i)sum+=counter[i]*(i+1);
            bool case1=true,case2=true,case3=true;
            for(int i=0;i<3;++i)
            {
                if(!(counter[i]>0&&counter[i+1]>0))case1=false;
                if(!(counter[i+1]>0&&counter[i+2]>0))case2=false;
                if(!(counter[i+2]>0&&counter[i+3]>0))case3=false;
            }
            if(!(case1||case2||case3))sum=0;
        }
        else if(type==10)//Large straight
        {
            bool statement=true;
            for(int i=0;i<5;++i)
            {
                sum+=counter[i]*(i+1);
                if(counter[i]!=1)statement=false;
            }
            if(!statement)sum=0;
        }
        else if(type==11)//Chance
        {
            for(int i=0;i<5;++i)
            {
                sum+=counter[i]*(i+1);
            }
        }
        else if(type==12)//YAHTZEE
        {
            for(int i=0;i<5;++i)
            {
                if(counter[i]==5)sum=50;
            }
            if(sum!=50)sum=0;
        }
    }
    
    int ScoreSheet::getSum()
    {
        return sum;
    }
    
    void ScoreSheet::player_action()
    {
        cout<<"Enter the option you want to mark this round: ";
        string action;
		cin>>action;
        for(int i=0; i<score_paper.size(); i++)
        {
			Score item=score_paper[i];
            if(action==item.getDescription())
            {
                swicher(item.getNum());
                item.setScore(sum);
                item.setUsed(item.getUsed()+1);
            }
        }
    }
}


int main()
{
	return 0;
}




