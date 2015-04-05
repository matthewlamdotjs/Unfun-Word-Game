/*
Matthew Lam
Pengo: mlam
Email: matthew.lam.93@icloud.com
Filename: Unfun.h
Assignment 4 - Unfun
Description: Unfun class runs a word guessing game
*/

#ifndef UNFUN_H
#define UNFUN_H
#include "Dictionary.h"

class Unfun{
public:
  Unfun();
  void play();
private:
  Dictionary dict;
};

#endif
