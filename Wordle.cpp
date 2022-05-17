#include "Wordle.h"


void initRandom()
{
    srand(time(NULL));

}

std::fstream& GotoLine(std::fstream& file, unsigned int num) {
    file.seekg(std::ios::beg);
    for (unsigned int i = 0; i < num - 1; ++i) {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return file;
}

//class table method definitions 

void table::initBoard()
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
}


void table::PrintBoard()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            LOG("[" << Board[j][i] << "] ");
        }

        LOG(std::endl);
    }

    LOG(std::endl << "----------" << std::endl);

    for (int i = 0; i < 5; i++)
    {
        LOG(Guesses[i] << std::endl);

        if (i == 4 && Turn == 5)
        {
            LOG(std::endl << "The correct word was " << SecertWd << std::endl);
        }
    }

   
}

void table::PlMove(std::string PlayerWord)
{
    Guesses[Turn] = PlayerWord;
    for (int i = 0; i < 5; i++)
    {
        if (PlayerWord[i] == SecertWd[i])
        {
            Board[i][Turn] = 2;
        }
        else
        {
            for (int j = 0; j < 5; j++)
            {
                if (PlayerWord[i] == SecertWd[j])
                    Board[i][Turn] = 1;
                
            }
                
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (Board[i][Turn] == 2)
        {
            isWon = true;
        }
        else
        {
            isWon = false;
            break;
        }
    }
    Turn++;
}

void RunWordle()
{
    table Wordle;

    initRandom();

    Wordle.initBoard();

    Wordle.PrintBoard();
   
    std::string Guess;
    
    while (!Wordle.isWon && Wordle.Turn != 5)
    {
        LOG("Input a 5 letter guess: ");
        std::cin >> Guess;
        while (Guess.length() != 5)
        {
            LOG("Please input a 5 letter word: ");
            std::cin >> Guess;
        }

        Wordle.PlMove(Guess);
        Wordle.PrintBoard();
    }
    
    if (Wordle.isWon == true)
    {
        LOG("You won in " << Wordle.Turn << " Guesses \nGAME OVER");
    }
    else
    {
        LOG("You lost \nGAME OVER");
    }
    //LOG(std::endl<<"Game Over"<<std::endl);
    
}