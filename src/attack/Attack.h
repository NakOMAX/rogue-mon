#ifndef _ATTACK_H
#define _ATTACK_H

#include <string>




class Attack{
  protected:
	std :: string name;
	unsigned short int power;
  unsigned short int type;
	unsigned short int pp;
	unsigned short int maxPP;
  unsigned short int gainAtk;
  unsigned short int gainDefense;
  unsigned short int impact;

  public:
  ///@brief constructor
  Attack();
  ///@brief destructor
  ~Attack();
  ///@brief accessor
  std :: string getName();
  ///@brief accessor : return the name
  unsigned short int getPower();
  ///@brief accessor : return the attack power
  unsigned short int getType();
  ///@brief accessor : return the type of Pokemon
  unsigned short int getPP();
  ///@brief accessor : return the number of times 1 attack can be used
  unsigned short int getImpact();
  ///@brief accessor
  unsigned short int getGainDefense();
  ///@brief accessor
  unsigned short int getGainAtk();

  ///@brief decrease pp after every attack
  void usePP();
  ///@brief reset number of times an attack can be used
  void resetPP(); 
  ///@brief operator =
  void operator=(Attack atk);

};

#endif
