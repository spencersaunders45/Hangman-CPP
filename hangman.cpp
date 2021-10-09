#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

void displayInstructions();

int promptDifficulty();

string selectWord(int difficulty);

string createGuessWord(int difficulty);

void displayHangMan(int wrongGuesses);

void displayGuessWord(string correctGuess, int difficulty);

char promptGuess();

bool checkGuess(char guess, string word, int difficulty);

void displayWinResult(bool winResult, string word);

bool checkIfCompleted(string word, int difficulty);

string updateGuess(char guess, string word, string guessWord, int difficulty);

bool gameLoop(int difficulty, string word, string guessWord);

void addSpace();




int main(){

   displayInstructions();

   int difficulty = promptDifficulty();

   string word = selectWord(difficulty);

   string guessWord = createGuessWord(difficulty);

   bool winResult = gameLoop(difficulty, word, guessWord);

   displayWinResult(winResult, word);

   return 0;
}




bool gameLoop(int difficulty, string word, string guessWord)
{
   bool gameOver = false;
   int wrongGuesses = 0;
   char guess;
   bool winResult;

   while(gameOver == false)
   {
      displayHangMan(wrongGuesses);
      displayGuessWord(guessWord, difficulty);
      guess = promptGuess();

      // Updates guessWord if guess is correct
      if (checkGuess(guess, word, difficulty) == true)
      {
         guessWord = updateGuess(guess, word, guessWord, difficulty);
      }
      else
      {
         wrongGuesses++;
      }

      // Ends game with loss
      if (wrongGuesses == 6)
      {
         gameOver = true;
         winResult = false;
      }

      // Checks if word is completed
      if (checkIfCompleted(guessWord, difficulty) == true)
      {
         gameOver = true;
         winResult = true;
      }

      addSpace();
   }

   return winResult;
}

/*************************************
*  Adds seperation between displays
*************************************/
void addSpace()
{
   cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
}




void displayInstructions()
{
   cout << "******************************************************\n";
   cout << "Welcome to Hang Man!\n";
   cout << "Guess the correct word and you win!\n";
   cout << "Guess incorrectly 6 times and you're dead!\n";
   cout << "******************************************************\n";
}




int promptDifficulty()
{
   string diffString;
   int diffInt;
   cout << "Please type your difficulty: \n";
   cout << "easy\n";
   cout << "medium\n";
   cout << "hard\n\n";
   cin >> diffString;
   cout << endl;

   // asks user until valid input is entered
   while (diffString != "easy" && diffString != "medium" && diffString != "hard")
   {
      cout << "Type either easy, medium, or hard\n";
      cin >> diffString;
   }

   if (diffString == "easy")
   {
      diffInt = 6;
   }
   else if (diffString == "medium")
   {
      diffInt = 8;
   }
   else if (diffString == "hard")
   {
      diffInt = 12;
   }

   return diffInt;
}




string selectWord(int difficulty)
{
   string word;
   srand(time(0));
   int num = rand() % 5 + 1;
   if (difficulty == 6)
   {
      if (num == 1)
      {
         word = "active";
      }
      else if (num == 2)
      {
         word = "battle";
      }
      else if (num == 3)
      {
         word = "carbon";
      }
      else if (num == 4)
      {
         word = "random";
      }
      else if (num == 5)
      {
         word = "yellow";
      }
   }
   else if (difficulty == 8)
   {
      if (num == 1)
      {
         word = "catching";
      }
      else if (num == 2)
      {
         word = "database";
      }
      else if (num == 3)
      {
         word = "eighteen";
      }
      else if (num == 4)
      {
         word = "pipeline";
      }
      else if (num == 5)
      {
         word = "turnover";
      }
   }
   else if (difficulty == 12)
   {
      if (num == 1)
      {
         word = "temperatures";
      }
      else if (num == 2)
      {
         word = "thoughtfully";
      }
      else if (num == 3)
      {
         word = "crosschecked";
      }
      else if (num == 4)
      {
         word = "extravaganza";
      }
      else if (num == 5)
      {
         word = "overstepping";
      }
   }

   return word;
}




void displayHangMan(int wrongGuesses)
{ 
   if (wrongGuesses == 0)
   {
      cout << "________________\n";
      cout << "|\n";
      cout << "|\n";
      cout << "|\n";
      cout << "|\n";
      cout << "|\n";
      cout << "|\n";
      cout << "|\n";
      cout << "_______________\n";
   }
   else if (wrongGuesses == 1)
   {
      cout << "________________\n";
      cout << "|" << setw(15) << "|\n";
      cout << "|" << setw(15) << "O\n";
      cout << "|\n";
      cout << "|\n";
      cout << "|\n";
      cout << "|\n";
      cout << "|\n";
      cout << "_______________\n";
   }
   else if (wrongGuesses == 2)
   {
      cout << "________________\n";
      cout << "|" << setw(15) << "|\n";
      cout << "|" << setw(15) << "O\n";
      cout << "|" << setw(15) << "|\n";
      cout << "|" << setw(15) << "|\n";
      cout << "|\n";
      cout << "|\n";
      cout << "|\n";
      cout << "_______________\n";
   }
   else if (wrongGuesses == 3)
   {
      cout << "________________\n";
      cout << "|" << setw(15) << "|\n";
      cout << "|" << setw(15) << "O\n";
      cout << "|" << setw(15) << "|\n";
      cout << "|" << setw(15) << "|\n";
      cout << "|" << setw(14) << "/\n";
      cout << "|\n";
      cout << "|\n";
      cout << "_______________\n";
   }
   else if (wrongGuesses == 4)
   {
      cout << "________________\n";
      cout << "|" << setw(15) << "|\n";
      cout << "|" << setw(15) << "O\n";
      cout << "|" << setw(15) << "|\n";
      cout << "|" << setw(15) << "|\n";
      cout << "|" << setw(13) << "/" << " \\" << endl;
      cout << "|\n";
      cout << "|\n";
      cout << "_______________\n";
   }
   else if (wrongGuesses == 5)
   {
      cout << "________________\n";
      cout << "|" << setw(15) << "|\n";
      cout << "|" << setw(15) << "O\n";
      cout << "|" << setw(15) << "--|\n";
      cout << "|" << setw(15) << "|\n";
      cout << "|" << setw(13) << "/" << " \\" << endl;
      cout << "|\n";
      cout << "|\n";
      cout << "_______________\n";
   }
   else if (wrongGuesses == 6)
   {
      cout << "________________\n";
      cout << "|" << setw(15) << "|\n";
      cout << "|" << setw(15) << "O\n";
      cout << "|" << setw(17) << "--|--\n";
      cout << "|" << setw(15) << "|\n";
      cout << "|" << setw(13) << "/" << " \\" << endl;
      cout << "|\n";
      cout << "|\n";
      cout << "_______________\n";
   }
}




string createGuessWord(int difficulty)
{
   string emptyWord;
   if (difficulty == 6)
   {
      emptyWord = "------";
   }
   else if (difficulty == 8)
   {
      emptyWord = "--------";
   }
   else if (difficulty == 12)
   {
      emptyWord = "------------";
   }
   
   return emptyWord;
}




char promptGuess()
{
   char guess;
   cout << "\tEnter letter: \n";
   cin >> guess;

   return guess;
}

/*************************************
*  Checks to see if guess was contained in the word
*************************************/
bool checkGuess(char guess, string word, int difficulty)
{
   bool correct = false;
   for (int i = 0; i < difficulty; i++)
   {
      if (guess == word[i])
      {
         correct = true;
         break;
      }
   }

   return correct;
}

/*************************************
*  Replaces "-" with correct letter
*************************************/
string updateGuess(char guess, string word, string guessWord, int difficulty)
{
   for (int i = 0; i < difficulty; i++)
   {
      if (guess == word[i])
      {
         guessWord[i] = guess;
      }
   }

   return guessWord;
}




void displayGuessWord(string guessWord, int difficulty)
{
   for (int i = 0; i < difficulty; i++)
   {
      cout << guessWord[i];
   }
   cout << endl;
}




bool checkIfCompleted(string guessWord, int difficulty)
{
   bool completed = true;
   for (int i = 0; i < difficulty; i++)
   {
      if (guessWord[i] == '-')
      {
         completed = false;
         break;
      }
   }

   return completed;
}




void displayWinResult(bool winResult, string word)
{
   if (winResult == true)
   {
      cout << word << endl;
      cout << "Winner winner chicken dinner!\n";
   }
   else
   {
      cout << "Sorry...you're done dead...\n";
   }
}
