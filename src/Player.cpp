#include "Player.h"
#include "Pokemon.h"
#include "Bulbasaur.h"
#include "Charmander.h"
#include "Squirtle.h"
#include "Item.h"
#include <iostream>
using namespace std;

Player:: Player(){ // je sais pas comment le faire en sdl :/
  cout << "Enter your name: "<<endl;
  cin >> name;
  myPokemon = new Pokemon[6];
  myItem = new Item[6];
  nbPokemon = 0;
  nbItem = 0;
  setPokemon();
}

Player:: ~Player(){
  delete myPokemon[];
  myPokemon[] = NULL;
  delete myItem[];
  myItem[] = NULL;
}


string getUserName(){
  return name;
}

Pokemon* Player :: getPokemon(unsigned short int i){
  return myPokemon[i];
}


unsigned short int Player :: getNbPokemon()
{
  return nbPokemon;
}

Item Player :: getItem(unsigned short int i){
  return myItem[i];
}

unsigned short int Player :: getNbItem() {
  return nbItem;
}

void Player::setPokemon(){
  myPokemon[0] = new Bulbasaur;
  myPokemon[1] = new Charmander;
  myPokemon[2] = new Bulbasaur;
  nbPokemon++;
}

void Player::addPokemon(Pokemon* newPokemon){
  if (nbPokemon < 6){
  myPokemon[nbPokemon] = new Pokemon;
  nbPokemon++;
  }
}

void Player::addItem(Item* newItem){
  nbItem++;
  myItem[nbItem] = newItem;
}

void Player::deletePokemon(unsigned short int i){
    delete myPokemon[i];
    myPokemon[i] = NULL;
}

void Player::deleteItem(unsigned short int i){
    delete myItem[i];
    myItem[i] = NULL;
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

bool Player :: pokIsdead(Pokemon* Pok)
{
  if ( Pokemon:: pok.pokIsdead())
  {
    nbPokemon--;
    return true;
  }
  else {return false;}
}

bool Player :: playerIsdead ()
{
  if (nbPokemon==0)  {return true;}
  else {return false;}
}


/*Item :: useItem(){//cet intitulé est bizarre
    amount--;
}*/

void Item :: action (Pokemon* Pok)
{
  amount--;
  if( amount<=0)
  {

  }
}

void Item :: operator= (Item copy)
{
  name=copy.name ;
  amount = copy.amount;
  id = copy.id;

}
