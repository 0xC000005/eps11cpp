#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<iterator> 
#include<conio.h>
#include"Score.h"

using namespace std;
class ScoreSheet
{
	public:
		vector<Score> score_paper;
		string name;
		string DESCRIPTIONS[16];
		bool gameFinished;
		int counter[6];
        int result,sum;
		ScoreSheet()
		{
			DESCRIPTIONS[1]="Ones";
			DESCRIPTIONS[2]="Twos";
			DESCRIPTIONS[3]="Threes";
			DESCRIPTIONS[4]="Fours";
			DESCRIPTIONS[5]="Fives";
			DESCRIPTIONS[6]="Sixes";
			DESCRIPTIONS[7]="Sum";
			DESCRIPTIONS[8]="Bonus";
			DESCRIPTIONS[9]="Three of a Kind";
			DESCRIPTIONS[10]="Four of a Kind";
			DESCRIPTIONS[11]="Full House";
			DESCRIPTIONS[12]="Small Straight";
			DESCRIPTIONS[13]="Large Straight";
			DESCRIPTIONS[14]="Chance";
			DESCRIPTIONS[15]="Yahtzee";
			DESCRIPTIONS[16]="Total Score";
			gameFinished=false;
			result=0,sum=0;
			init();
		}   

    void ScoreSheet::init()
    {	
		
        cout<<"Please enter your name: ";
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
            score_paper.push_back(temp);
            count++;
        }
        display(true);
    }
    
    void ScoreSheet::display(bool firstTime)
    {
        cout<<name<<"'s Score Sheet:";
        for(size_t i=0;i<score_paper.size();i++)
        {
			Score item=score_paper[i];
            if(item.getDescription()=="Total Score")
			{
				cout<<item.getDescription()<<" "<<item.getScore()<<endl;
			}
            else
            {
                string marked;
                if(item.getUsed()==1)
                {
                    //marked="☑";
					marked="x";
                    cout<<marked<<" "<<item.getDescription()<<" "<<item.getScore()<<endl;
                }
                else
                {
                    //marked="☐";
                    marked="o";
					if(firstTime)
					{
						cout<<marked+" "<<item.getDescription()<<" "<<item.getScore()<<endl;					
					}
                    else
                    {
                        if(item.getNum()==-1)
						{
							cout<<marked<<" "<<item.getDescription()<<" "<<item.getScore()<<endl;						
						}
                        else
                        {
                            swicher(item.getNum());
                            cout<<marked<<" "<<item.getDescription()<<" "<<sum<<endl;
                        }
                    }
                }
            }
        }
    }
    
    bool ScoreSheet::game_finished()
    {
        gameFinished=true;
        for(size_t i=0; i<score_paper.size(); i++)
        {
			Score item=score_paper[i];
            if(item.getUsed()==0)
			{
				gameFinished=false;
			}
            break;
        }
        return gameFinished;
    }
    
    void ScoreSheet::count(int dice[],int preserve[])
    {
        for(int i=0;i<5;++i)
        {
            if(dice[i]!=0)
			{
				counter[dice[i]-1]++;
			}
            if(preserve[i]!=0)
			{
				counter[preserve[i]-1]++;
			}
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
        for(size_t i=0; i<score_paper.size(); i++)
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
};
