/*
Matthew Lam
Pengo: mlam
Email: matthew.lam.93@icloud.com
Filename: Dictionary.cpp
Assignment 4 - Unfun
Description: function declarations for the class Dictionary
Code Status:
*/

#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "Dictionary.h"

using namespace std;

Dictionary::Dictionary(){
  ifstream file;
  string line;
  file.open("unfun-words.txt");
  while(getline(file, line)){
    wordList.push_back(line);
  }
  file.close();
}

void Dictionary::remove(int score, string guess){
  if(score==-1){
    int i=0;
    int length=wordList.size();
    while(i<=length-1){
      size_t pos = wordList[i].find(guess);
      if(pos!=string::npos){
	wordList.erase(wordList.begin()+i);
      }
      else{
       	i++;
      }
      length=wordList.size();
    }
    if(wordList.back().find(guess)!=string::npos){
      wordList.pop_back();
    }
  }
  else{
    for(int i=0; i<wordList.size(); i++){
       if(wordList[i].substr(score,1)!=guess){
	 wordList.erase(wordList.begin()+i);
       }
    }
  }
}

int Dictionary::score(string guess){
  int position[5] = {0,0,0,0,0};
  bool specialCase = false;
  for(int i=0; (i<wordList.size()) && (specialCase==false); i++){
     if(wordList[i].find(guess)!=string::npos){
       if(wordList[i].substr(0,1)==guess){
	 position[0]+=1;
       }
       if(wordList[i].substr(1,1)==guess){
	 position[1]+=1;
       }
       if(wordList[i].substr(2,1)==guess){
	 position[2]+=1;
       }
       if(wordList[i].substr(3,1)==guess){
	 position[3]+=1;
       }
       if(wordList[i].substr(4,1)==guess){
	 position[4]+=1;
       }
     }
     else{
       if(wordList[i].find(guess)==string::npos){
	 specialCase=true;
       }
     }
  }
  if(specialCase==true){
    return -1;
  }
  else{
    int score=0;
    for(int i=1; i<5; i++){
      if(position[i-1]<position[i]){
	score=i;
      }
    }
    return score;
  }
}

string Dictionary::printlist(){
  stringstream ss;

  for(int i=0; i<(wordList.size()-1); i++){
    ss << wordList[i] << ", ";
  }
  ss << wordList[wordList.size()-1];

  string list = ss.str();

  return list;
}

bool Dictionary::gameover(){
  if(wordList.size()==1){
    return true;
  }
  else{
    return false;
  }
}

