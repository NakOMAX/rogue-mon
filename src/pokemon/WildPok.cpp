#include "Pokemon.h"
#include "WildPok.h"
#include "Attack.h"
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
    myAttacks[0]= new First;
    myAttacks[1]= new Second;
}

WildPok:: ~WildPok () {}

bool WildPok:: wildIsDead()
{
    bool dead;
    dead = false;
    if (Hp==0){dead= true;}
    return dead;
}
