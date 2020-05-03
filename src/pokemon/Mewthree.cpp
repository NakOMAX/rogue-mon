#include "Pokemon.h"
#include "Mewthree.h"
#include "Attack.h"
#include "First.h"
#include "Second.h"

#include <iostream>
//#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;



Mewthree:: Mewthree () {

    id = 11;
    Hp = 100;
    name = "Mewthree";
    type = 2;// 2= Grass
    lvl = 1;
    atk = 8;
    sAtk = 2;
    def = 20 ;
    sDef = 2;
    speed = 0;
    myAttacks[0]= new First;
    myAttacks[1]= new Second;
    }

Mewthree:: ~Mewthree () {}
