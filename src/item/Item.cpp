#include "Item.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>
using namespace std;

Item :: Item(){}

Item :: Item(unsigned int newId, string newName, unsigned short int newAmount=0)
{
  id = newId;
  name = newName;
  amount = newAmount;
}

Item :: ~Item(){}

unsigned short int Item::getId ()
{
    return id;
}

string Item::getName()
{
    return name;
}
