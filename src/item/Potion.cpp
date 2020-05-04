
#include "Pokemon.h"
#include "Potion.h"

#include <iostream>
//#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;



Potion :: Potion () {

    id = 001;
    amount =0;
    name = "Potion";
}

Potion :: ~Potion () {}

/*void Potion :: action(Pokemon &Pok)
{
    Pok.Hp=100;
    Item:: action();
}*/