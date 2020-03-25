#include "Pokemon.h"
#include <iostream>
//#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//à mettre dans la classe fille : #define const unsigned short int HPMAX=100


Pokemon :: Pokemon()
 //Concernant le tas ou la pile je sais pas si il faut faire un choix plus judicieux
{
  id = 0;
  name = NULL;
  type = 0;
  Hp = 0;
  atk = 0;
  sAtk = 0;
  def = 0;
  sDef = 0;
  speed = 0;
  lvl = 0;
}

// constructeur par copie
Pokemon::Pokemon(unsigned short int new_Id, string new_Name,unsigned short int new_Type,unsigned short int new_HP,
                 unsigned short int new_Atk,unsigned short int new_sAtk, unsigned short int new_Def,
                 unsigned short int new_sDef,unsigned short int new_speed, unsigned short int new_lvl)
{
  id = newId;
  name = newName;
  type = newType;
  Hp = newHP;
  atk = newAtk;
  sAtk = newSatk;
  def = newDef;
  sDef = newSdef;
  speed = newSpeed;
  lvl = newLvl;
}

Pokemon :: ~Pokemon() {} // destructor

unsigned short int Pokemon :: getId ()const
{
    return id;
}

string Pokemon :: getName ()const
{
    return name;

}

unsigned short int Pokemon :: getType ()const
{
    return type;
}

unsigned short int Pokemon :: getHp ()const
{// impossible car unsigned short int = int entre 0 et 65 535
    return Hp;
}

unsigned short int Pokemon :: getAtk ()const
{
    return atk;


unsigned short int Pokemon :: getSAtk ()const
{
    return sAtk;
}

unsigned short int Pokemon :: getDef ()const
{
    return def;
}

unsigned short int Pokemon :: getId ()const
{// impossible car unsigned short int = int entre 0 et 65 535
    return Id;
}


unsigned short int Pokemon :: getSDef ()const
{
    return sDef;
}

unsigned short int Pokemon :: getSpeed ()const
{
    return speed;
}

unsigned short int Pokemon :: getLvl ()const
{
    return lvl;
}

void Pokemon :: setHP (unsigned short int newHP)
{
    Hp = newHP;
    /* // impossible car unsigned short int = int entre 0 et 65 535
    if (newHP>0 && newHP<HPMAX){}
    else
    {cout<< "HP invalide";}
    */
}

void Pokemon :: setLvl (unsigned short int newLvl)
{
    lvl = newLvl;
    /* // impossible car unsigned short int = int entre 0 et 65 535
    if (newLvl>0){}
    else
    {cout<< "niveau du Pokémon négatif";}
    */
}
