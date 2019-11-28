#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<iterator> 
#include<conio.h>
#include"Score.h"
using namespace std;
//disable TEST.cpp and Scoresheet.h before u run it
//this is just a demo for get and post method for class SCORE
int main()
{
	Score test;
	test.setDescription("test");
	cin>>test.getDescription();
	return 0;

}