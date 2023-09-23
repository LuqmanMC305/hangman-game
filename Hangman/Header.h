#ifndef HANGMAN_
#define HANGMAN_
#include <string>
#include <iostream>
#include <cctype>
#include <fstream>
#include <time.h>

using namespace std;

class Hangman
{
    private:
      string word, hiddenWord, stringLine;
      int maxGuess, playerGuess, i, size;
      string* wordString;

    public:
      Hangman() : maxGuess(9), playerGuess(0), size(10), i(0)
      {

        wordString = new string[size];
        ifstream file("WordList.txt");

        if(!file.is_open())
        {
          std::cout << "Error opening file!" << std::endl;
        }

        while(std::getline(file, stringLine))
        {
          wordString[i] = stringLine;
          i++;
        }

        file.close();
        resetGame();

      }
      bool checkCondition(char userLetter);
      void printHangman(int playerGuess);
      bool isLoseGame();
      void resetGame();
      bool isWinGame();
      ~Hangman() {delete[] wordString;}

};

bool Hangman::checkCondition(char userLetter)
{
    bool foundLetter = false;
    userLetter = toupper(userLetter);

    for(int i=0; i<word.length(); i++)
    {
        if(word[i] == userLetter)
        {
           hiddenWord[i] = userLetter;
           foundLetter = true;
        }
    }

    if(foundLetter == false)
    {
       playerGuess++;

       if(playerGuess > maxGuess)
       {
           return isLoseGame();
       }
       else
       {
         cout << maxGuess - playerGuess << " guesses left!." << endl;
         printHangman(playerGuess);
       }  
    }

    cout << hiddenWord << endl;

    if(hiddenWord == word)
    {
        return isWinGame();
    }

    return false; 
}


void Hangman::printHangman(int playerGuess)
{


    switch(playerGuess)
    {
        case 1:
          cout << "_" << endl;
          break;

        case 2:
          cout << "|" << endl;
          cout << "_" << endl;
          break;

        case 3:
          cout << "|" << endl;
          cout << "|" << endl;
          cout << "_" << endl;
          break;

        case 4:
          cout << "|" << endl;
          cout << "|" << endl;
          cout << "|" << endl;
          cout << "_" << endl;
          break;

        case 5:
          cout << "-------------------------" << endl;
          cout << "|" << endl;
          cout << "|" << endl;
          cout << "|" << endl;
          cout << "_" << endl;
          break;

        case 6:
          cout << "-------------------------" << endl;
          cout << "|                        |" << endl;
          cout << "|" << endl;
          cout << "|" << endl;
          cout << "_" << endl;
          break;


         case 7:
          cout << "-------------------------" << endl;
          cout << "|                        |" << endl;
          cout << "|                        0" << endl;
          cout << "|" << endl;
          cout << "_" << endl;
          break;

         case 8:
          cout << "-------------------------" << endl;
          cout << "|                        |" << endl;
          cout << "|                        0" << endl;
          cout << "|                        |" << endl;
          cout << "_" << endl;
          break;

         case 9:
          cout << "-------------------------" << endl;
          cout << "|                        |" << endl;
          cout << "|                        0" << endl;
          cout << "|                        |" << endl;
          cout << "_                       - - " << endl;
          break;

    }

   

    

}

bool Hangman::isLoseGame()
{
    int playAgain;


    cout << "You lost!" << endl; 
    cout << "Do you want to play it again? (1/0)" << endl;
    cin >> playAgain;

   if(playAgain == 1)
   {
     resetGame();
     return false;
   }
   else
   {
     return true;
   }

    

}

bool Hangman::isWinGame()
{
    int playAgain;


    cout << "Player has won the game!" << endl;
    cout << "Do you want to play it again? (1/0)" << endl;
    cin >> playAgain;

   if(playAgain == 1)
   {
     resetGame();
     return false;
   }
   else
   {
     return true;
   }

    

}  


void Hangman::resetGame()
{
    srand(time(NULL));
    int randomNum = rand() % 10;
    playerGuess = 0;

    word = wordString[randomNum];
    hiddenWord = string(word.length(), '_');
}


#endif