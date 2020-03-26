#include "attack.h"
#include <iostream>
#include <string>
using namespace std;

attack :: attack(string& newName, unsigned short int& newType, unsigned short int& newPower, unsigned short int& newPP){
  name = newName;
  type = newType;
  power = newPower;
  pp = mewPP;
  maxPP = pp;
}

attack :: ~attack(){}

string attack::getName(){ return name; }

unsigned short int attack::getPower(){ return power; }

unsigned short int attack::getType(){ return type; }

unsigned short int attack::getPP(){ return pp; }

void Attack :: usePP(){
  if(pp != 0){
    pp--;
  }
}

void attack :: resetPP(){
  pp = maxPP;
}
