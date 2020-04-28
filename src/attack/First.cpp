#include "Attack.h"
#include "First.h"
#include <iostream>
#include <string>
using namespace std;

First :: First()
{
    name="First";
    type = 1;
    power = 2;
    pp= 9;
    maxPP= 9;
    gainAtk=0;
    gainDefense=0;
    impact=50;
}

string First :: getName ()
{return name;}
