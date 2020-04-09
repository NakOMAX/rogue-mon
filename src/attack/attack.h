#ifndef _ATTACK
#define _ATTACK

#include <string>

class attack{
  protected:
	string name;
	unsigned short int power;
  unsigned short int type;
	unsigned short int pp;//nombre d'utilisation d'une attaque
	unsigned short int maxPP;

  public:
  attack(string&, unsigned short int&, unsigned short int&, unsigned short int&, unsigned short int&);

  ~attack()

  string getName();

  unsigned short int getPower();

  unsigned short int getType();

  unsigned short int getPP();

  void usePP();

  void resetPP();

};

#endif
