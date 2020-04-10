#include "Player.h"
#include "WildPok.h"
#include "Attack.h"

#include <string>

Fight :: Fight (const Player& newme, const WildPok & newopposant)
{
    me = &newme;
    opposant = &newopposant;
}

Fight :: ~Fight ()

Pokemon* Fight :: choice ()
{
    unsigned short int choice;
    std :: cout<< "Quel Pokemon voulez-vous utliser ? " <<endl;
    cin>> choice;

    retrun me.getPokemon (choice); //besoin d'un rappel pour le me. tu pourras me le dire dans un message quand tu le verras :)


}

void Fight :: raid  ()
{
    Pokemon* attacker;
    unsigned short int att;
    attacker=choice();
    std :: cout << "Quelle attaque voulez-vous effectuer ?  1 est " << me.myattacks[1]; // étendre avec un pour quand on aura plus d'attques
    std :: cin>>att;

    effects(attacker.myattacks[att-1]);

}

void Fight effects (const Attack& att)
{
    opposant.Hp= opposant.Hp- (att.impact*attacker.atk-opposant.def);
    attacker.def += att.gainatk;
    attacker.atk += att.gaindef;
}