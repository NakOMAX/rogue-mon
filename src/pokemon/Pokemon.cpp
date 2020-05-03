#include "Pokemon.h"
#include <iostream>
#include "Attack.h"
//#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//à mettre dans la classe fille : #define const unsigned short int HPMAX=100


Pokemon:: Pokemon()
{
}

Pokemon :: Pokemon (const Pokemon & old){
  id = old.getId();
  name = old.getName();
  type = old.getType();
  maxHp = old.getMaxHp();
  Hp = old.getHp();
  atk = old.getAtk();
  sAtk = old.getSAtk();
  def = old.getDef();
  sDef = old.getSDef();
  speed = old.getSpeed();
  lvl = old.getLvl();
  myAttacks [0]= old.getMyAttacks(0);
  myAttacks [1]= old.getMyAttacks(1);
}

Pokemon:: ~Pokemon() {
  for (int i = 0; i<4; i++)
    delete myAttacks[i];
}

unsigned short int Pokemon:: getId ()const
{
    return id;
}

std::string Pokemon::getName () const
{
    return name;

}

unsigned short int Pokemon:: getType ()const
{
    return type;
}

unsigned short int Pokemon:: getHp ()const
{// impossible car unsigned short int = int entre 0 et 65 535
    return Hp;
}

unsigned short int Pokemon:: getMaxHp() const
{
  return maxHp;
}

unsigned short int Pokemon:: getAtk ()const
{
    return atk;

}
unsigned short int Pokemon:: getSAtk ()const
{
    return sAtk;
}

unsigned short int Pokemon:: getDef ()const
{
    return def;
}

unsigned short int Pokemon:: getSDef ()const
{
    return sDef;
}

unsigned short int Pokemon:: getSpeed ()const
{
    return speed;
}

unsigned short int Pokemon:: getLvl ()const
{
    return lvl;
}

Attack* Pokemon :: getMyAttacks (unsigned short int i) const
{
    return myAttacks[i];
}

void Pokemon:: setHp (unsigned short int newHP)
{
    Hp = newHP;
}

void Pokemon:: setLvl (unsigned short int newLvl)
{
    lvl = newLvl;
}

void Pokemon:: atkIncrease (unsigned short int newAtk)
{
    atk += newAtk;

}

void Pokemon:: defIncrease (unsigned short int newDef)
{
    def += newDef;
}


bool Pokemon :: pokIsDead()
{
    if (Hp == 0)
    {
        delete this;
        return true;
    }
    else {return false;}
}
