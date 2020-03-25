#include "Item.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

Item :: Item(){
  id = 0;
  name = NULL;
  amount = 0;
}

Item :: Item(unsigned unsigned int newId, string newName, unsigned short int newAmount)
{
  id = newId
  name = newName;
  amount = newAmount
}

Item :: ~Item(){}

unsigned short int Pokemon :: getId ()const
{
    return id;
}

string Pokemon :: getName ()const
{
    return name;
}

Item useItem(){
    amount--;
}
