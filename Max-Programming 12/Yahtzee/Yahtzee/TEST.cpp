

/*
#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<iterator> 
#include<conio.h>
#include"ScoreSheet.h"
using namespace std;


int dice[5];
int preserve[5];
int pickOut=0;
ScoreSheet player;

void print_dice(int number)
{
    cout<<"Your dices:"<<endl;
    for(int i=0;i<number;++i)
    {
			
        dice[i]=rand()%6+1;
        cout<<dice[i]+" "<<endl;
    }
    cout<<endl;
}

void pressAnyKeyToContinue()
{ 
    cout<<"Press Enter key to continue..."<<endl;
    getchar();
}

    
void pick_out()
{
    cout<<"Enter a number to select a dice you want to save."<<endl;
    cout<<"Enter 0 to end the pick_out operation when you finished."<<endl;
    int pick=-1;
    while(pick!=0)
    {
        cout<<"Input:";
        cin>>pick;
        if(pick!=0)
        {
            for(int i=0;i<5;++i)
            {
                if(dice[i]==pick)
                {
                    preserve[pickOut]=dice[i];
                    dice[i]=0;
                    pickOut++;
                    break;
                }
            }   
        }
    } 
}
    
void round()
{
    bool finished=false;//after player_action(); return 0
    for(int i=1;i<=3;++i)//each round has 3 tern
    {
        //system("cls");//clear
        player.display(false); //display new sheet
        print_dice(5-pickOut);
		pick_out();
        player.count(dice,preserve);
        //system("cls");
        player.display(false);
        if(i<3)
        {
           cout<<"Do you want to use the score paper now? (0/1)";
           int statment;
	       cin>>statment;
           if(statment==1)
           {
               player.player_action();
               break;
           }
        }
        else if(i==3)
        {
            player.player_action();
        }
        player.display(false);
    }
} 
    
int main()
{
   
     while(!player.game_finished())
    {
        round();
    }
   
}
*/