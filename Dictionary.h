/*
Matthew Lam
Pengo: mlam
Email: matthew.lam.93@icloud.com
Filename: Dictionary.h
Assignment 4 - Unfun
Description: Dictionary class creates a dictionary from a word list in a file
*/

#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <vector>
#include <string>

class Dictionary{
public:
  Dictionary();
  void remove(int score, std::string guess);
  int score(std::string guess);
  std::string printlist();
  bool gameover();
private:
  std::vector<std::string> wordList;
};

#endif
