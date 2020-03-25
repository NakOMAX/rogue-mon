#include "Pokemon.h"
#include "Charmander .h"

#include <iostream>
//#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define const unsigned short int HPMAX=100

Charmander  :: Charmander  () {

    id = 004;
    Hp = HPMAX;
    name = "Charmander";
    type = 3; // 3= Fire
    lvl = 1;
    atk = 10; // j'y connais pas grand chose il faut peut etre modifier ces valeurs avec def
    sAtk = 2;
    def = 10 ;
    sDef = 2;
    speed = rand()%10-1;
}

Charmander  :: ~Charmander  () {}
