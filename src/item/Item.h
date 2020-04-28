#ifndef ITEM_H
#define ITEM_H
#include <string>
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
    void operator= (Item copy);
};
#endif
