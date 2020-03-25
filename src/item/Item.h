#ifndef _Item
#define _Item

include <string>
class Item
{
protected :

    string name ;
    unsigned short int amount;
    unsigned unsigned int id;

public :

    ///@brief class constructor
    Item ()
    ///@brief class copy constructor
    Item ( unsigned unsigned int newId, string newName, unsigned short int newAmount)
    ///@brief class destructor
    ~Item()

    ///@brief accessor
    unsigned short int getId();
    ///@brief accessor
    string getName ();
    ///@brief accessor
    unsigned short int getAmount();
    /**@brief The fonction use the caracteristic of the item*/
    Item useItem(unsigned short int amount, unsigned unsigned int id);
}
#endif
