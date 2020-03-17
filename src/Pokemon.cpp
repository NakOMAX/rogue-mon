#include "Pokemon.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

#define const unsigned short int HPmax=100


Pokemon :: Pokemon(unsigned short int type, unsigned short int lvlinit=1, unsigned short int atkinit=10, unsigned short int definit=10)
{
    HP = HPmax;
    atk = atkinit;
    sAtk = atk/2;
    def = definit;
    sDef =def/2;
    lvl = lvlinit;
    speed = rand()%10-1;
    name = prompt_name();

}
