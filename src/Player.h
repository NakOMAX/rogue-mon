#ifndef _PLAYER
#define _PLAYER
#include "Pokemon.h"
#include "Item.h"

#include <string>
using namespace std;
class Player{

  protected:
  string name;
  Pokemon *myPokemon;
  Item *myItem;
  unsigned short int nbPokemon;
  unsigned short int nbItem;

  public:

  Player(){};

  ~Player(){};

	std::string getUserName();   ///@brief accessor
  Pokemon getPokemon(unsigned short int id);   ///@brief accessor
  unsigned short int getNbPokemon(); ///@brief accessor
	Item getItem(unsigned short int id);   ///@brief accessor
  unsigned short int getNbItem(); ///@brief accessor

	void setPokemon();  ///@brief mutator
  //me.myitem

  void addItem(Item*,int nbItem);
	void addPokemon(Pokemon*);

  void deletePokemon(unsigned short int i);
	void deleteItem(unsigned short int i);

	//unsigned short int isDie();

  ///@brief check if a pokemon is dead
  bool pokIsDead ();
  ///@brief check if the player is dead
  bool playerIsDead ();
  ///@brief action of an item
  void action(Pokemon* Pok);

  void operator= (Item copy);
};
#endif
