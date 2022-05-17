#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <limits>
#include <time.h>


#define LOG(msg) std::cout<<msg
//11435 words/lines in "Words.txt"

class table
{
private:
	int Board[5][5];
	
	
	std::string Guesses[5]; // Player Guesses
	std::string SecertWd; //Secert Word

    std::string PossibleWords[11435];
public:
	bool isWon = false;
	int Turn = 0;

	void initBoard();

	void PrintBoard();

	void PlMove(std::string PlayerWord); //Player move


};

void RunWordle();


/*void table::initBoard()
{   
    int Line = rand() % 11435 + 1;
    std::fstream myFile("Words.txt");

    GotoLine(myFile, Line);

    myFile >> SecertWd;

    //LOG(SecertWd);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            Board[j][i] = 0;
        }
    }
    
    for (int i = 0; i < 5; i++)
    {

        Guesses[i] = "";
    }
  */