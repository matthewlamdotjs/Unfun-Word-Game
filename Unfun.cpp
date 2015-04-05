/*
Matthew Lam
Pengo: mlam
Email: matthew.lam.93@icloud.com
Filename: Unfun.cpp
Assignment 4 - Unfun
Description: function declarations for the class Unfun
Code Status: Working/NotTested
*/

#include "Dictionary.h"
#include "Unfun.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Unfun::Unfun(){
}
 
void Unfun::play(){
  int numGuesses=1;
  bool cheat=false;
  bool gameover=false;
  bool end=false;
  string guesses="";
  string word="-----";

  cout << "CS19: Unfun!" << endl;
  cout << "I'm thinking of a five letter word," << endl;
  cout << "you guess letters until you have the whole word!" << endl;

  while(end==false){
    string guess;
    cout << "The word: " << word << "     previously guessed:" << guesses << endl;
    cout << "Guess #" << numGuesses <<  "? ";
    cin >> guess;

    if(guess=="-" || guess=="_"){
      cout << "possible words: " << dict.printlist() << endl;
			
      if(cheat==false){
	cheat=true;
      }
    }
    else if(guesses.find(guess)!=string::npos){
      cout << "You already guessed the letter " << guess << "." << endl;
    }
    else{
      int score = dict.score(guess);
      dict.remove(score, guess);

      if(score==-1){
	cout << "The word does not contain a(n) " << guess << "." << endl;
      }
      else{
	cout << "Yes, there is a(n) " << guess << "." << endl;
      	word.replace(score,1,guess);
      }
      stringstream ss1;
      ss1 << guesses << guess;
      guesses=ss1.str();
      numGuesses++;
    }
    if((gameover==true) && (word.find("-")==string::npos)){
      cout << "Correct! You got the word \"" << word << "\" in " << numGuesses-1 << " guesses." << endl;
      if(cheat==true){
       	cout << "(but you cheated)" << endl;
      }
      end=true;
    }
    if(dict.gameover()==true){
      gameover=true;

    }
  }
}

