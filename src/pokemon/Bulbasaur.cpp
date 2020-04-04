#include "Pokemon.h"
#include "Bulbasaur.h"

#include <iostream>
//#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;



Bulbasaur:: Bulbasaur () {

    id = 001;
    Hp = 100;
    name = "Bulbasaur";
    type = 2;// 2= Grass
    lvl = 1;
    atk = 10; // j'y connais pas grand chose il faut peut etre modifier ces valeurs avec def
    sAtk = 2;
    def = 10 ;
    sDef = 2;
    speed = rand()%10-1;
}

Bulbasaur:: ~Bulbasaur () {}
