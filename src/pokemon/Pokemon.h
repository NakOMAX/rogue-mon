#ifndef _POKEMON
#define _POKEMON

#include <string>


class Pokemon /**\class A Pokemon is describe by a its name, its HP, its attack and its defense
of course it also have a level. A Pokemon can be used during a fight and sometimes you should take care of it.*/
{

protected:

    unsigned short int id;
    std::string name;
    unsigned short int type; // 1 = Water, 2= Grass, 3= Fire
    unsigned short int Hp;
    unsigned short int atk;
    unsigned short int sAtk;
    unsigned short int def;
    unsigned short int sDef;
    unsigned short int speed;
    unsigned short int lvl;


    ///@brief class constructor
    Pokemon();

    ///@brief class copy constructor
    Pokemon(unsigned short int new_Id,std::string new_Name,unsigned short int new_Type,unsigned short int new_HP,
            unsigned short int new_Atk,unsigned short int new_sAtk, unsigned short int new_Def,
            unsigned short int new_sDef,unsigned short int new_speed, unsigned short int new_lvl);

    ///@brief class destructor
    ~Pokemon();

    ///@brief accessor
    unsigned short int getId () const ;
    ///@brief accessor
    std::string getName () const ;
    ///@brief accessor
    unsigned short int getType() const ;
    ///@brief accessor
    unsigned short int getHp () const ;
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

    ///@brief mutator
    void setHP(unsigned short int newHP );
    ///@brief mutator
    void setLvl (unsigned short int newLvl );
};

#endif
