#include "Pokemon.h"
#include "WildPok.h"

#include <iostream>
//#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;



WildPok:: WildPok () {

    id = 001;
    Hp = 100;
    name = "WildPok";
    type = rand()%3;
    lvl = 1;
    atk = 2; 
    sAtk = 2;
    def = 10 ;
    sDef = 2;
    speed = 9;
}

WildPok:: ~WildPok () {}



