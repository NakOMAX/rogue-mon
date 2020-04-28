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

unsigned short int Attack::getImpact(){ return impact; }

unsigned short int Attack::getGainAtk(){ return gainAtk; }

unsigned short int Attack::getGainDefense(){ return gainDefense; }

void Attack :: usePP(){
  if(pp != 0){
    pp--;
  }
}

void Attack :: resetPP(){
  pp = maxPP;
}

void Attack::operator=(Attack atk)
{
  power=atk.power;
  type = atk.type;
  pp= atk.pp;
  maxPP= atk.maxPP;
  gainAtk = atk.gainAtk;
  gainDefense = atk.gainDefense;
  impact = atk.impact;
}