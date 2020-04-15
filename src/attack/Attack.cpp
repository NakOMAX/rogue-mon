#include "Attack.h"
#include <iostream>
#include <string>
using namespace std;

Attack :: Attack(){} // j'ai fait l'initialisation dans la classe fille

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
