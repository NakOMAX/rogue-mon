#ifndef _ATTACK
#define _ATTACK

#include <string>
using namespace std;

// Faut-il associer les attaques à chaque Pokemon ?

class Attack{
  protected:
	string name;
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
  string getName();
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

  void usePP();  ///@brief decrease pp after every attack

  void resetPP(); ///@brief reset number of times an attack can be used

};

#endif
