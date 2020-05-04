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
  Pokemon * myPokemon[6];
  Item * myItem;
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

  ///@brief Add one item in the tab
  ///@param Item is the item you want to add
  void addItem(Item);
  ///@brief Add one pokemon in the tab
  ///@param Pokemon is the item you want to add
	void addPokemon(Pokemon*);

  ///@brief Destroy the pokemon when it is die
  ///@param I is the index of tab Pokemon
  void deletePokemon(unsigned short int i);
  ///@brief Destroy the object if the item is used
  ///@param I is the index of tab Item
	void deleteItem(unsigned short int i);

  ///@brief check if a pokemon is dead
  bool pokIsDead(Pokemon*);
  ///@brief check if the player is dead
  bool playerIsDead();

};
#endif
