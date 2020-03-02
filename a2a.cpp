// Assignment 2a: written by Melinda Sterne 

/*
  This program genreates a random number to represent the users guess and then the program asks the user if the guess was correct, if the number is higher, or if the number is lower.  The program operates by implementing a hand coded binary search

  INPUT: User inputs if the computer guessed the number correctly, if the number the computer guessed was too high or too low, and if the user wants to play again
  OUTPUT: Program outputs midpoint guess from the range and option prompts for the user
  VALIDATION:  This program does not require validation
*/

#include <iostream>
#include <cstdlib> //Needed to use functions srand and rand
#include <ctime>  //Needed to use function time for a random number generator

using namespace std;

int main()
{
  //declare variables
  char answer = 'y';
  int high = 100, low = 1, guess = 50, randomNumber = 0;
  //enter Random number Generator
  unsigned int seed = time(0);

  //use the time function to get a seed value for srand
  srand(seed);

  //prompt user to think of a number between 1 and 100
  cout << "Think of a number between 1 and 100. " << endl;
 
  //Generate a random number between 1 and 100
  randomNumber = rand()%(1+100);
  //output number to guess
  cout << "(The number to guess is: " << randomNumber << ")" << endl;
  //do while loop to guess number 
  do 
  {
    //output guess to console and prompt user to enter input to verify if guess was correct or to update the guessing range
    cout << "My guess is " << guess << ". Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: ";
    cin >> answer;
    if(answer == 'l')
    {
      high = guess;
      guess = (low + high)/2; 
    }
    else if(answer == 'h')
    {
      low = guess;
      guess = (low + high)/2;
    }
    else
    {
      //output to prompt user if they would like to play again
      cout << "Great! Do you want to play again (y/n)? ";
      cin >> answer;
      //if user wants to play again reset variables
      if(answer == 'y')
      {
        high = 100;
        low = 1;
        guess = 50;
        randomNumber = rand()%(1+100);
        cout << "(The number to guess is: " << randomNumber << ")" << endl;
      }
      //if user does not want to play again change answer to c to exit loop
      else
        answer = 'c';
    }
  }while(answer != 'c');
  return 0;
}
