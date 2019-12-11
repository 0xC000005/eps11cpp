#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<iterator> 
#include<conio.h>
#include"ScoreSheet.h"
using namespace std;

class Game
{
	private: 
		int dice[4];
		int preserve[4];
		int pickOut;
		ScoreSheet player;
    
	public: 
		Game() //init
		{
			clean_dice();
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
		for(int i=0;i<5;i++)
		{
			cout<<dice[i]<<" "; 
		}
		cout<<endl;
		cout<<"preserve: ";
		for(int i=0;i<5;i++)
		{
			cout<<preserve[i]<<" "; 
		}
		cout<<endl;
	}

	void Game::clean_dice()
	{
		cout<<"TEST_MESSAGE: overwrite the entire dice and preserve arraies. "<<endl;
		for(int i=0;i<5;i++)
		{
			dice[i]=0; 
		}
		
		for(int i=0;i<5;i++)
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
		cout<<"1preserve: ";
		for(int i=0;i<5;i++)
		{
			cout<<preserve[i]<<" "; 
		}
		cout<<endl;
		cout<<"Your dices:"<<endl;
		for(int i=0;i<number;i++)
		{	
			cout<<"2preserve: ";
			for(int i=0;i<5;i++)
			{
				cout<<preserve[i]<<" "; 
			}
			cout<<endl;
			dice[i]=rand()%6+1;
			cout<<dice[i]<<" ";
			cout<<"preserve: ";
			for(int i=0;i<5;i++)
			{
				cout<<preserve[i]<<" "; 
			}
			cout<<endl;
		}
		cout<<endl;
		cout<<"4preserve: ";
		for(int i=0;i<5;i++)
		{
			cout<<preserve[i]<<" "; 
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
						cout<<"TEST_MESSAGE: dice[i] ="<<dice[i]<<"  preserve["<<pickOut<<"] -> dice["<<i<<"]"<<endl;
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
			print_dice(5-pickOut);
			picking_out();
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

