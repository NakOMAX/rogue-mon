#include "Pokemon.h"
#include "Bulbasaur.h"
#include "Attack.h"
#include "First.h"
#include "Second.h"

#include <iostream>
//#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;



Bulbasaur:: Bulbasaur () {
    id = 001;
    maxHp = 100;
    Hp = 100;
    name = "Bulbasaur";
    type = 2;// 2= Grass
    lvl = 1;
    atk = 3;
    sAtk = 2;
    def = 10 ;
    sDef = 2;
    speed = rand()%10-1;
    myAttacks[0]= new First;
    myAttacks[1]= new Second;
}

Bulbasaur:: ~Bulbasaur () {}
