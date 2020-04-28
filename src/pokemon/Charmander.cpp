#include "Pokemon.h"
#include "Charmander.h"

#include <iostream>
//#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;


Charmander  :: Charmander  () {

    id = 004;
    maxHp =
    Hp = 100;
    name = "Charmander";
    type = 3; // 3= Fire
    lvl = 1;
    atk = 10; // j'y connais pas grand chose il faut peut etre modifier ces valeurs avec def
    sAtk = 2;
    def = 10 ;
    sDef = 2;
    speed = rand()%10-1;
    myAttacks[0]= new Attack; // je pense que ca ne fonctionne pas comme ca pour mettre une classe fille à la place de la mère
    myAttacks[1]= new Attack;
}

Charmander  :: ~Charmander  () {}
