#ifndef _Item
#define _Item

#include <string>
#include "Pokemon.h"
class Item
{
protected :

    std ::string name ;
    unsigned short int amount;
    unsigned int id;

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
    unsigned short int getAmount();
    /**@brief The fonction use the caracteristic of the item*/
   /* Item useItem(unsigned short int amount, unsigned unsigned int id);*/
    ///@brief action of an item
    void action();

    void operator= (Item copy);
};
#endif
