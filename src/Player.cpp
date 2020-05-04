#include "Player.h"
#include "Pokemon.h"
#include "Bulbasaur.h"
#include "Charmander.h"
#include "Squirtle.h"
#include "Item.h"
#include <iostream>
using namespace std;

Player:: Player(){ // je sais pas comment le faire en sdl :/
  myItem = new Item[6];
  nbPokemon = 0;
  nbItem = 0;
  setPokemon();
}

Player:: ~Player(){
  for (int i = 0; i<6; i++)
  {
    delete myPokemon[i];
  }
}


string Player:: getUserName(){
  return name;
}

Pokemon* Player :: getPokemon(unsigned short int i){
  return myPokemon[i];
}

unsigned short int Player :: getNbPokemon()
{
  return nbPokemon;
}

Item* Player :: getItem(unsigned short int id){
  return &myItem[id];
}

unsigned short int Player :: getNbItem() {
  return nbItem;
}

void Player::setPokemon(){
  myPokemon[0] = new Bulbasaur;
  myPokemon[1] = new Charmander;
  nbPokemon = 2;
}

void Player::addPokemon(Pokemon * newPokemon){
  if (nbPokemon < 6){
    myPokemon[nbPokemon] = newPokemon;
    nbPokemon++;
  }
}

void Player::addItem(Item newItem){
  nbItem++;
  myItem[nbItem] = newItem;
}

void Player::deletePokemon(unsigned short int i){
    delete myPokemon[i];
    myPokemon[i] = NULL;
}

void Player::deleteItem(unsigned short int i){
    *myItem = myItem[i];
    delete myItem;
    myItem = NULL;
}

/*short int Player::isDie(){
  for(unsigned int i = 0; i<nbPokemon; i++){
      if(myPokemon[i].getHp() > 0 ){
        //cout << "Pokemon : "<<i<<" alive" <<endl;
        return 0;
      }
      else{
        cout << "Pokemon : "<<i<<" is dead" <<endl;
        return -1;
      }
  }
  cout << "player is defeated";
  return 1;
}*/

bool Player :: pokIsDead(Pokemon* Pok)
{
  if (Pok->pokIsDead())
  {
    nbPokemon--;
    return true;
  }
  else {return false;}
}

bool Player :: playerIsDead ()
{
  if (nbPokemon==0){return true;}
  else {return false;}
}
