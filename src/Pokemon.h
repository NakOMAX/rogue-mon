#ifndef _POKEMON
#define _POKEMON

#include <string>

class Pokemon /**\class A Pokemon is describe by a its name, its HP, its attack and its defense 
of course it also have a level. A Pokemon can be used during a fight and sometimes you should take care of it.*/ 
{
    
protected:

    unsigned short int idP;
    string name;
    unsigned short int type;
    unsigned short int HP;
    unsigned short int atk;
    unsigned short int sAtk;
    unsigned short int def;
    unsigned short int sDef;
    unsigned short int speed;
    unsigned short int lvl;


    ///@brief class constructor 
    Pokemon(
    unsigned short int type ///@param The Pokemon can be 1: water, 2: Fire, 3 : Grass
    unsigned short int lvlinit =1,  ///@param This is for a new Pokemon with a better lvl
    unsigned short int atkinit =10,  ///@param The Pokemon can be stronger 
    unsigned short int definit =10 ///@param The Pokemon can be stronger 
    )
    ///@brief class destructor
    ~Pokemon();

    ///@brief accessor 
    unsigned short int getId ();
    ///@brief accessor 
    string getName ();
    ///@brief accessor 
    unsigned short int getType ();
    ///@brief accessor 
    unsigned short int getHP ();
    ///@brief accessor 
    unsigned short int getAtk ();
    ///@brief accessor 
    unsigned short int getSAtk ();
    ///@brief accessor 
    unsigned short int getDef ();
    ///@brief accessor 
    unsigned short int getSDef ();
    ///@brief accessor 
    unsigned short int getSpeed ();
    ///@brief accessor 
    unsigned short int getLvl ();

    ///@brief mutator
    setHP(unsigned short int );
    ///@brief mutator
    setLvl (unsigned short int );

    
    
}

#endif
