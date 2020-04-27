#include "Pokemon.h"
#include "Bulbasaur.h"
#include "attack.h"

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
    myattacks[0]= new First; // je pense que ca ne fonctionne pas comme ca pour mettre une classe fille à la place de la mère
    myattacks[1]= Second second 
}

Bulbasaur:: ~Bulbasaur () {}
