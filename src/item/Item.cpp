#include "Item.h"
#include "Pokemon.h"
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

Item Item :: operator= (Item copy)
{
  Item It
  it.name=copy.name ;
  it.amount = copy.amount;
  it.id = copy.id;
  return it

}

/*Item :: useItem(){//cet intitulé est bizarre
    amount--;
}*/
void Player :: actionItem (Pokemon* Pok)
{

  nbItem--;
  if( nbItem<=0)
  {

  }
