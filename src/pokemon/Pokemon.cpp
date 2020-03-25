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
      // il faut generer l'ID
}

// constructeur par copie
Pokemon::Pokemon(unsigned short int new_Id, string new_Name,unsigned short int new_Type,unsigned short int new_HP,
                 unsigned short int new_Atk,unsigned short int new_sAtk, unsigned short int new_Def,
                 unsigned short int new_sDef,unsigned short int new_speed, unsigned short int new_lvl)
{
  id = new_Id;
  name = new_Name;
  type = new_Type;
  HP = new_HP;
  atk = new_Atk;
  sAtk = new_sAtk;
  def = new_Def;
  sDef = new_sDef;
  speed = new_speed;
  lvl = new_lvl;
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

unsigned short int Pokemon :: getHP ()const
{
    return HP;
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
{
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
    if (newHP>0 && newHP<HPMAX)
    {HP=newHP;}
    else
    {cout<< "HP invalide";}
}

void Pokemon :: setLvl (unsigned short int newLvl)
{
    if (newLvl>0)
    {lvl=newLvl;}
    else
    {cout<< "niveau du Pokémon négatif";}
}
