
#include "Pokemon.h"
#include "Potion.h"

#include <iostream>
//#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define const unsigned short int HPMAX=100


Potion :: Potion () {

    id = 001;
    amount =0;
    name = "Potion";
}

Potion :: ~Potion () {}
