#ifndef _PLAYER
#define _PLAYER
#include "Pokemon.h"
#include "Item.h"

#include <string>

class Player{

  protected:
  std::string name;
  Pokemon *myPokemon;
  Item *myItem;
  unsigned short int nbPokemon;
  unsigned short int nbItem;

  public:

  Player(){};

  ~Player(){};

	std::string getUserName();   ///@brief accessor
  Pokemon* getPokemon(unsigned short int id);   ///@brief accessor
  unsigned short int getNbPokemon(); ///@brief accessor
	Item* getItem(unsigned short int id);   ///@brief accessor
  unsigned short int getNbItem(); ///@brief accessor

	void setPokemon();  ///@brief mutatorme.myitem

  void addItem(Item *);
	void addPokemon(Pokemon*);

  void deletePokemon(unsigned short int i);
	void deleteItem(unsigned short int i);

	short int isDie();
};
#endif
