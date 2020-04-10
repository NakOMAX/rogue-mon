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
  unsigned short int gainPower; 
  unsigned short int gaindefense;
  unsigned short int impact;

  public:
  Attack();

  ~Attack();

  string getName();

  unsigned short int getPower();

  unsigned short int getType();

  unsigned short int getPP();

  void usePP();

  void resetPP();

};

#endif
