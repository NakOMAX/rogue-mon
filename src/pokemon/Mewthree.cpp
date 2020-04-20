#include "Pokemon.h"
#include "Mewthree.h"

#include <iostream>
//#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;



Mewthree:: Mewthree () {

    id = 011;
    newHp = 100;
    Hp = 100;
    name = "Mewthree";
    type = 2;// 2= Grass
    lvl = 1;
    atk = 8;
    sAtk = 2;
    def = 20 ;
    sDef = 2;
    speed = 0;
    myattacks[0]= new First; // je pense que ca ne fonctionne pas comme ca pour mettre une classe fille à la place de la mère
    //myattacks[1]= Second second // faire quand on aura une attaque en plus.
}

Mewthree:: ~Mewthree () {}
