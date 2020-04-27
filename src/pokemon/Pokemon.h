#ifndef _POKEMON
#define _POKEMON

#include <string>
#include "Attack.h"


class Pokemon /**\class Pokemon is describe by a its name, its HP, its attack and its defense
of course it also have a level. A Pokemon can be used during a fight and sometimes you should take care of it.*/
{

protected:

    unsigned short int id;
    std::string name;
    unsigned short int type; // 1 = Water, 2= Grass, 3= Fire
    unsigned short int maxHp;
    unsigned short int Hp;
    unsigned short int atk;
    unsigned short int sAtk;
    unsigned short int def;
    unsigned short int sDef;
    unsigned short int speed;
    unsigned short int lvl;
    Attack *myAttacks[2];

public:
    ///@brief class constructor
    Pokemon();

    ///@brief class copy constructor
    Pokemon(const Pokemon& old);

    ///@brief class destructor
    ~Pokemon();

    ///@brief accessor
    unsigned short int getId () const ;
    ///@brief accessor
    std::string getName () ;
    ///@brief accessor
    unsigned short int getType() const ;
    ///@brief accessor
    unsigned short int getHp () const ;
    ///@brief accessor
    unsigned short int getMaxHp () const ;
    ///@brief accessor
    unsigned short int getAtk () const ;
    ///@brief accessor
    unsigned short int getSAtk () const ;
    ///@brief accessor
    unsigned short int getDef () const ;
    ///@brief accessor
    unsigned short int getSDef () const ;
    ///@brief accessor
    unsigned short int getSpeed () const ;
    ///@brief accessor
    unsigned short int getLvl () const ;
    ///@brief accessor 
    ///@param i {the number in the array of the attack you want}
    Attack* getMyAttacks (unsigned short int i);

    ///@brief mutator
    ///@param newHP {the new value of Hp}
    void setHp(unsigned short int newHP );
    ///@brief mutator
    ///@param newLvl {the new value of lvl}
    void setLvl (unsigned short int newLvl );

    ///@brief addition atk with the param
    ///@param newAtk {the value you want to add to atk}
    void atkIncrease(unsigned short int newAtk );
    ///@brief addition def with the param
    ///@param newDef {the value you want to add to def}
    void defIncrease(unsigned short int newDef );

    bool pokIsDead();
};

#endif
