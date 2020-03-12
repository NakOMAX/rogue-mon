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
    getId ();
    ///@brief accessor 
    getName ();
    ///@brief accessor 
    getType ();
    ///@brief accessor 
    getHP ();
    ///@brief accessor 
    getAtk ();
    ///@brief accessor 
    getSAtk ();
    ///@brief accessor 
    getDef ();
    ///@brief accessor 
    getSDef ();
    ///@brief accessor 
    getSpeed ();
    ///@brief accessor 
    getLvl ();



    
    
}
