#include "Attack.h"
#include "Second.h"
#include <iostream>
#include <string>

using namespace std;

Second :: Second()
{
    name="Second";
    type = 2;
    power = 1;
    pp= 9;
    maxPP=9;
    gainAtk=7;
    gainDefense=11;
    impact=0;
}

string Second :: getName ()
{return name;}
