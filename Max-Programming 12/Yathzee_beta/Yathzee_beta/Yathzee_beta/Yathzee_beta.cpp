#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<iterator> 
#include<conio.h>
#include"ScoreSheet.h"
#include<H:/lvp/RANDOM.H>
using namespace std;

class Game
{
	private: 
		int dice[5];
		int preserve[5];
		int pickOut;
		ScoreSheet player;
    
	public: 
		Game() //init
		{
			clean_dice();
			check_dice();
			pickOut=0;
			init();
			while(!player.game_finished())
			{
				round();
			}
		}

	void Game::check_dice()
	{
		cout<<"TEST_MESSAGE: starting the test func. check_dice. "<<endl;
		cout<<"dice: ";
		for(int i=0;i<6;i++)
		{
			cout<<dice[i]<<" "; 
		}
		
		cout<<"preserve: ";
		for(int i=0;i<6;i++)
		{
			cout<<preserve[i]<<" "; 
		}
	}

	void Game::clean_dice()
	{
		cout<<"TEST_MESSGE: overwrite the entire dice and preserve arraies. "<<endl;
		for(int i=0;i<6;i++)
		{
			dice[i]=0; 
		}
		
		for(int i=0;i<6;i++)
		{
			preserve[i]=0; 
		}
	}

	void Game::init()
	{
		cout<<"TEST_MESSAGE: class 'Game' init."<<endl;
	}

    void Game::print_dice(int number)
	{
		cout<<"Your dices:"<<endl;
		cout<<number<<endl;
		for(int i=0;i<number;++i)
		{	
			dice[i]=rand()%6+1;
			cout<<dice[i]<<" ";
		}
		cout<<endl;
	}

	void Game::pressAnyKeyToContinue()
	{ 
		cout<<"Press Enter key to continue..."<<endl;
		getchar();
	}

	void Game::picking_out()
	{
		cout<<"TEST_MESSAGE: starting func. picking_out."<<endl;
		cout<<"Enter a number to select a dice you want to save."<<endl;
		cout<<"Enter 0 to end the pick_out operation when you finished."<<endl;
		int pick=-1;
		while(pick!=0)
		{
			cout<<"Input:";
			cin>>pick;
			if(pick!=0)
			{
				for(int i=0;i<5;i++)
				{
					if(dice[i]==pick)//find the first right dice in the dice sequence, and store into preserve sequence with index = pickOut 
					{
						preserve[pickOut]=dice[i];
						dice[i]=0;
						pickOut++;
						/*
							pickOut here acts as both counter for preserve and how many dice has picked out, 
							so the none-zore size for preserve will always equals to the pickOut.
						*/
						break;

						/*
						
							can also add a dice check here
						
						*/
					}
				}   
			}
		} 
	}
    
	void Game::round()
	{
		cout<<"TEST_MESSAGE: new 'round' event start."<<endl;
		bool finished=false;//after player_action(); return 0
		for(int i=1;i<=3;++i)//each round has 3 tern
		{
			//system("cls");//clear
			player.display(false); //display new sheet
			cout<<"This is your "<<i<<" round."<<endl;
			check_dice();
			cout<<"TEST_MESSAGE: pickOut = "<<pickOut<<endl;
			print_dice(5-pickOut);
			picking_out();
			check_dice();
			
			player.counting(dice,preserve);
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

	void Game::check_pickOut()
	{
		cout<<"pickOut = "<<pickOut<<endl;
	}
    
};

void main()
{
	Game A;
}

