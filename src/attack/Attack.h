#ifndef _ATTACK
#define _ATTACK

#include <string>
using namespace std;

// Faut-il associer les attaques à chaque Pokemon ?

class Attack{
  protected:
	string name;
	unsigned short int power; // je comprends pas cette valeur 
  unsigned short int type;// 1 fait perdre des pdv, 2 fait gagner en def et att
	unsigned short int pp;//nombre d'utilisation d'une attaque
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
  ///@brief accessor
  unsigned short int getPower();
  ///@brief accessor
  unsigned short int getType();
  ///@brief accessor
  unsigned short int getPP();
  ///@brief accessor
  unsigned short int getImpact();
  ///@brief accessor
  unsigned short int getGainDefense();
  ///@brief accessor
  unsigned short int getGainAtk();

  void usePP();

  void resetPP();

};

#endif
