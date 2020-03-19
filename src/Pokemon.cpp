#include "Pokemon.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

#define const unsigned short int HPMAX=100


Pokemon :: Pokemon(unsigned short int ntype, unsigned short int lvlinit=1, unsigned short int atkinit=10, unsigned short int definit=10)
// c'est une idée de constructeur mais il faut que les classe soient heritées donc, je pense qu'il ne ser pas comme ca au final. 
//Et concernant le tas ou la pile je sais pas si il faut faire un choix plus judicieux
{
    HP = HPmax;
    type = ntype;
    atk = atkinit;
    sAtk = atk/2;
    def = definit;
    sDef =def/2;
    lvl = lvlinit;
    speed = rand()%10-1;
    name = /* je sais pas faire */
    // il faut aussi generer l'ID

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
