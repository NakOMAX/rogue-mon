#ifndef _PLAYER_H
#define _PLAYER_H
#include "Pokemon.h"
#include "Item.h"
#include "Bulbasaur.h"
#include "Charmander.h"
#include "Squirtle.h"
#include <string>

class Player{

  protected:
  std::string name;
  Pokemon *myPokemon;
  Item *myItem;
  unsigned short int nbPokemon;
  unsigned short int nbItem;

  public:

  Player();

  ~Player();

	std::string getUserName();   ///@brief accessor
  Pokemon* getPokemon(unsigned short int id);   ///@brief accessor
  unsigned short int getNbPokemon(); ///@brief accessor
	Item * getItem(unsigned short int id);   ///@brief accessor
  unsigned short int getNbItem(); ///@brief accessor

	void setPokemon();  ///@brief mutator
  //me.myitem

  void addItem(Item);
	void addPokemon(Pokemon);

  void deletePokemon(unsigned short int i);
	void deleteItem(unsigned short int i);

  ///@brief check if a pokemon is dead
  bool pokIsDead(Pokemon*);
  ///@brief check if the player is dead
  bool playerIsDead();

};
#endif
