#include "Pokemon.h"
#include "WildPok.h"
#include "First.h"
#include "Second.h"

#include <iostream>
//#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;



WildPok:: WildPok ()
{
    id = 013;
    maxHp = 100;
    Hp = 100;
    name = "WildPok";
    type = rand()%3;
    lvl = 1;
    atk = 2;
    sAtk = 2;
    def = 10 ;
    sDef = 2;
    speed = 10;
    First first;
    Second second;
    myAttacks[0]= first; // je pense que ca ne fonctionne pas comme ca pour mettre une classe fille à la place de la mère
    myAttacks[1]= second;}

WildPok:: ~WildPok () {}

bool WildPok :: wildIsDead()
{
    bool dead ;
    dead = false;
    if (Hp==0){dead= true;}
    return dead;
}
