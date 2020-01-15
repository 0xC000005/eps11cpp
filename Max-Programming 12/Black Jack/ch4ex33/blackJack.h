#pragma once
class blackJack
{
public:
	blackJack(void);
	~blackJack(void);
	//Max Zhang - Nov. 04
#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<iterator> 
#include<conio.h>

using namespace std;

class Card 
{
	private:
		string description;
		string suit;
		int value;

	public:
		Card(){}
		Card(string const &_description,string const &_suit,int  const &_value)
		{
			setDescription( _description);
			setSuit(_suit);
			setValue(_value);
		}

		void Card::setDescription(string _description)
		{
			description=_description;
		}
		string Card::getDescription()
		{
			return description;
		}

		void Card::setSuit(string _suit)
		{
			suit=_suit;
		}
		string Card::getSuit()
		{
			return suit;
		}
    
		void Card::setValue(int _value)
		{
			value=_value;
		}
		int Card::getValue()
		{
			return value;
		}

};

bool blackjacked=false;
int pTotal,dTotal,money=500,Check_Code,bet,p_aceCounter=0,d_aceCounter=0;
string hit,next_round="yes";
vector<Card> CardList;
Card tempCard;

int SHUFFLE = 1000;
string SUITS[]={"Heart","Diamonds","Spades","Clubs"};
string DESC[]={"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
int VALUE[]={11,2,3,4,5,6,7,8,9,10,10,10,10};

void addCard(int index1, Card cardToAdd)
{
    CardList.push_back(cardToAdd);
}

void card_swap(int num1,int num2)
{
        Card tempCard=CardList[num1];
        CardList[num1]=CardList[num2];
        CardList[num2]=tempCard;
}


void shuffle()
{
    int num1,num2;     
    for (int x = 1; x<=SHUFFLE;x++)
	{
        do
		{
			num1 = rand() % 52;// number from 0-51
            num2 = rand() % 52;// 1 number less than value
        }while( num1 == num2);
        card_swap(num1,num2);
    }
}


int Betting()
{
        cout<<"==================================="<<endl;
        cout<<"Balance:"<<money<<endl;
        cout<<"Please enter your bet:";
        int bet;
		cin>>bet;
        cout<<"==================================="<<endl;
        if(bet>money)
        {
            cout<<"Now you only have "<<money<<"$, try other number!"<<endl;
            Betting();
        }
        return bet;
    }

void CheckOut()
{
    if(Check_Code==1)
    {
        money+=bet;
    }
    else if(Check_Code==0)
    {
        money-=bet;
    }
    else if(Check_Code==2)
    {
        money+=bet*2;
    }        
}

void loadDeck()
{
    for(int s=0;s<4;s++)
        for(int d=0;d<13;d++)
        {
            Card tempCard;
            tempCard.setSuit(SUITS[s]);
            tempCard.setDescription(DESC[d]);
            tempCard.setValue(VALUE[d]);
            addCard(13*s+d, tempCard);
		}
}

void init()
{
    loadDeck();
	shuffle();
}

Card take()
{
    Card temp=CardList[0];
    CardList.erase(CardList.begin());
    return temp;   
}



void takeCard()
{
    if(CardList.empty())
    {
        cout<<"------------ERROR:THERE_IS_NO_CARD_REMAIN------------"<<endl;
        cout<<"Play again? (yes/no)";
        string temp;
		cout<<temp;
        if(temp=="yes")
        {
            init();
			cout<<"Im too lazy to write a new identifier for this, gb :)"<<endl;
            //Play();
        }
    }
    else take();    
    }
    



void AceCheck(int i)
{
    if(tempCard.getValue()==11 && i==0) p_aceCounter++;
    if(tempCard.getValue()==11 && i==1) d_aceCounter++;
       
    if(i==0)
    {
        if((tempCard.getValue()+pTotal+10>21)&& p_aceCounter!=0)
        {
            pTotal-=10;
            p_aceCounter--;
        }
    }
    else
    {
		if((tempCard.getValue()+dTotal+10>21)&& d_aceCounter!=0)
		{
            dTotal-=10;  
            d_aceCounter--;
        }
    }
        
 }
    
 void Judge()
{
  //System.out.println("------------CHECK POINT:CHECK_OUT------------");
    if (pTotal > 21)
	{
        cout<<"YOU LOSE"<<endl;
        Check_Code=0;
    } 
	else if (dTotal > 21 || pTotal > dTotal)
	{
        cout<<"YOU WIN"<<endl;
        Check_Code=1;
    } 
	else if (pTotal == dTotal)
	{
        cout<<"PUSH"<<endl;
        Check_Code=3;
    } 
	else if (dTotal <= 21 && pTotal < 21 && pTotal < dTotal)
	{
        cout<<"YOU LOSE"<<endl;
        Check_Code=0;
        
	}
 }
    
void Black_Jack()
{
    int count=0,total=0,flag=0;
    count++;
    if(flag==0&&count==1)
    {
        if(tempCard.getSuit()=="Ace"||tempCard.getSuit()=="Jack")
        {
           flag++;
        }
    }
    if(flag==1&&count==2)
    {
        if(tempCard.getSuit()=="Ace"||tempCard.getSuit()=="Jack")
        {
            flag++;
        }
    }
    if(flag==2&&count==2)
    {
        cout<<"------------BLACK JACK------------"<<endl;
        cout<<"YOU WIN"<<endl;
        Check_Code=2; 
        blackjacked=true;
        money+=bet;
        }
        
}


    
void addCard(Card cardToAdd)
{
    CardList.push_back(cardToAdd);
}
    

    
void showDeck()
{   
	for(int i=0;i<CardList.size();i++)
	{
		Card element = CardList[i];
        cout<<element.getDescription()<<" of "<<element.getSuit()<<endl;
    }
}

void stand()
{
    while (dTotal < 17)
	{
        tempCard = CardList[0];
        cout<<tempCard.getDescription()<<" of "<<tempCard.getSuit()<<endl;
        AceCheck(1);
        dTotal+=tempCard.getValue();
        takeCard();
        cout<<"Dealer total= "<<dTotal<<endl;
    }
}

void Deal()
{
	cout<<"Dealer's hand:"<<endl;
    tempCard = CardList[0];
    cout<<"Down Card"<<endl;
    Card downCard = tempCard;
    takeCard();//up carrd
    tempCard = CardList[0];
    cout<<tempCard.getDescription()<<" of "<<tempCard.getSuit()<<endl;
    AceCheck(1);
    dTotal+=tempCard.getValue();
    cout<<"Dealer total= "<<dTotal<<endl;
    cout<<endl;
    cout<<"Your hand:"<<endl;
    tempCard = CardList[0];
    cout<<tempCard.getDescription()<<" of "<<tempCard.getSuit()<<endl;
    AceCheck(0);
    Black_Jack();
    pTotal+=tempCard.getValue();
    takeCard();
    tempCard = CardList[0];
    cout<<tempCard.getDescription()<<" of "<<tempCard.getSuit()<<endl;
    AceCheck(0);
    pTotal+=tempCard.getValue();
    takeCard();
    cout<<"Player total= "<<pTotal<<endl;
    Black_Jack();
    if(blackjacked==false)
    {
        cout<<"Would you like a hit? (yes/no)";
        cin>>hit;
        while (pTotal < 21 && hit=="yes")
		{
            tempCard = CardList[0];
            cout<<tempCard.getDescription()<<" of "<<tempCard.getSuit()<<endl;
            AceCheck(0);
            pTotal+=tempCard.getValue();
            takeCard();
            cout<<"Player total= "<<pTotal<<endl;
            if (pTotal < 21)
			{
                cout<<"Would you like a hit? (yes/no)";
                cin>>hit;
            }
        }
        
        if (pTotal < 21 && hit=="no")stand();
        
        if (pTotal >= 21){
            cout<<"Down Card: "<<downCard.getDescription()<<" of "<<downCard.getSuit();
            if(downCard.getValue()+10+dTotal<21)dTotal+=10;
            dTotal += downCard.getValue();
            cout<<"Dealer total= "<<dTotal<<endl;
            stand();
        }
        Judge();
    }
    // System.out.println("------------CHECK POINT:DEAL_FUNCTION_END------------");
    //if blackjack Check_Code=2;
    cout<<"------------------------"<<endl;
    cout<<"Would you like another round? (yes/no)";
    cin>>next_round;
    cout<<"------------------------"<<endl;
    pTotal=0;
    dTotal=0;
    blackjacked=false;
    p_aceCounter=0;
    d_aceCounter=0;
} 

void Play()
{
	cout<<"------------GAME START------------"<<endl;
    while(money>0 && next_round=="yes")
    {
       bet= Betting();
       Deal();  
       CheckOut();
    }
    if(money<=0) cout<<"You're out of money dumbass!"<<endl;
    cout<<"------------GAME OVER------------"<<endl;
}
};

