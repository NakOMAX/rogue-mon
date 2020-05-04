#ifndef ITEM_H
#define ITEM_H
#include <string>
#include "Pokemon.h"
using namespace std;
class Item
{
protected :

    string name ;
    unsigned short int amount;
    unsigned short int id;

public :

    ///@brief class constructor
    Item ();
    ///@brief class copy constructor
    Item ( unsigned int newId, std :: string newName, unsigned short int newAmount);
    ///@brief class destructor
    ~Item();

    ///@brief accessor
    unsigned short int getId();
    ///@brief accessor
    std :: string getName ();
    ///@brief accessor
    Item operator= (Item copy);
    ///@brief action of an item
    ///@param Pokemon is a pointer to the Current Pokemon
    void actionItem(Pokemon*);
};
#endif
