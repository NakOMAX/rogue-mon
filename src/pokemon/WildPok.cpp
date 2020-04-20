#include "Pokemon.h"
#include "WildPok.h"

#include <iostream>
//#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;



WildPok:: WildPok () {

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
    myattacks[0]= First first // je pense que ca ne fonctionne pas comme ca pour mettre une classe fille à la place de la mère
    //myattacks[1]= Second second // faire quand on aura une attaque en plus.
}

WildPok:: ~WildPok () {}
