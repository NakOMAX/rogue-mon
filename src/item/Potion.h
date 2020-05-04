#ifndef _POTION
#define _POTION

#include <string>
#include "Item.h"

/**@class Potion
  @brief a health potion*/
class Potion : public Item
{
Public :

 ///@brief class constructor
 Potion ();

 ///@brief class destructor
 ~Potion ();

    ///@brief action of this item
    //void action(Pokemon &Pok);
}
#endif
