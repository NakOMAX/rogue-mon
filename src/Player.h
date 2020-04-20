#ifndef _PLAYER
#define _PLAYER
#include "Pokemon.h"
#include "Item.h"

#include <string>

class Player{

  protected:
  string name;
  Pokemon *myPokemon[];// on ne defini pas comme ca un vector...
  Item *myItem[];
  unsigned short int nbPokemon;
  unsigned short int nbItem;

  public:

  Player(){};

  ~Player(){};

	string getUserName();   ///@brief accessor
  Pokemon* getPokemon(unsigned short int id);   ///@brief accessor
	Item* getItem(unsigned short int id);   ///@brief accessor
  unsigned short int getNbPokemon(); ///@brief accessor

	void setPokemon();  ///@brief mutatorme.myitem

  void addItem(Item *);
	void addPokemon(Pokemon*);

  void deletePokemon(unsigned short int i);
	void deleteItem(unsigned short int i);

	unsigned short int isDie();
};
#endif
