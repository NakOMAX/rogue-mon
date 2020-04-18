#include "Player.h"
#include "Pokemon.h"
#include "Item.h"
#include <iostream>
using namespace std;


Player :: Player(){ // je sais pas comment le faire en sdl :/
  cout << "Enter your name: "<<endl;
  cin >> name;
  myPokemon = new Pokemon[6];
  myItem = new Item[6];
  nbPokemon = 0;
  nbItem = 0;
  setPokemon();
}

Player :: ~Player(){
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

unsigned short int Player :: getNumberOfPokemons() {
  return nbPokemon;
}

Item* Player :: getItem(unsigned short int i){
  return myItem[i];
}

void Player::setPokemon(){
  //
  // ????
}

void Player::addPokemon(Pokemon* newPokemon){
  if (nbPokemon < 6){
  myPokemon[nbPokemon] = newPokemon;
  nbPokemon++;
  }
}

void Player::addItem(Item* newItem){
  myItem[i] = newItem;
  nbItem++;
}

void Player::deletePokemon(unsigned short int i){
    delete myPokemon[i];
    myPokemon[i] = NULL;
}

void Player::deleteItem(unsigned short int i){
    delete myItem[i];
    myItem[i] = NULL;
}

short int Player::isDie(){
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
}
