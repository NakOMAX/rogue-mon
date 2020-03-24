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

unsigned short int Pokemon :: getId ()const 
{
    return Id;
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
