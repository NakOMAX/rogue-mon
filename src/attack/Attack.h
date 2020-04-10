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
	unsigned short int pp;//nombre d'utilisation d'une attaque
	unsigned short int maxPP;

  public:
  Attack(string& newName, unsigned short int& newType, unsigned short int& newPower, unsigned short int& newPP);

  ~Attack();

  string getName();

  unsigned short int getPower();

  unsigned short int getType();

  unsigned short int getPP();

  void usePP();

  void resetPP();

};

#endif
