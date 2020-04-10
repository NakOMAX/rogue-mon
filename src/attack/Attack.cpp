#include "Attack.h"
#include <iostream>
#include <string>
using namespace std;

Attack :: Attack(string& newName, unsigned short int& newType, unsigned short int& newPower, unsigned short int& newPP){
  name = newName;
  type = newType;
  power = newPower;
  pp = newPP;
  maxPP = pp;
}

Attack :: ~Attack(){}

string Attack::getName(){ return name; }

unsigned short int Attack::getPower(){ return power; }

unsigned short int Attack::getType(){ return type; }

unsigned short int Attack::getPP(){ return pp; }

void Attack :: usePP(){
  if(pp != 0){
    pp--;
  }
}

void Attack :: resetPP(){
  pp = maxPP;
}
