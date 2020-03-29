#ifndef _PLAYER
#define _PLAYER
#include "Pokemon.h"
#include "Item.h"

#include <string>

class Player{

  protected:
  string name;
  Pokemon *myPokemon[];
  Item *myItem[];
  unsigned short int nbPokemon;
  unsigned short int nbItem;

  public:

  Player(){};

  ~Player(){};

	string getUserName();   ///@brief getter
  Pokemon* getPokemon(unsigned short int id);   ///@brief getter
	Item* getItem(unsigned short int id);   ///@brief getter

	void setPokemon();  ///@brief setter

  void addItem(Item *);
	void addPokemon(Pokemon*);

  void deletePokemon(unsigned short int i);
	void deleteItem(unsigned short int i);

	int isDie();
};
#endif
