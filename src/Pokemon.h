#ifndef _POKEMON
#define _POKEMON

#include <string>

class Pokemon 
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
    Pokemon ();
    ///@brief class destructor
    ~Pokemon();

    ///@brief accessor 
    unsigned int getId ();
    ///@brief accessor 
    string getName ();
    ///@brief accessor 
    unsigned int getType ();
    ///@brief accessor 
    unsigned int getHP ();
    ///@brief accessor 
    unsigned int getAtk ();
    ///@brief accessor 
    unsigned int getSAtk ();
    ///@brief accessor 
    unsigned int getDef ();
    ///@brief accessor 
    unsigned int getSDef ();
    ///@brief accessor 
    unsigned int getSpeed ();
    ///@brief accessor 
    unsigned int getLvl ();

    ///@brief mutator
    setHP(unsigned int );
    ///@brief mutator
    setLvl (unsigned int );

    
    
}
