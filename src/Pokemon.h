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
