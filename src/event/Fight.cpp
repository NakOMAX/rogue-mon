#include "Player.h"
#include "Pokemon.h"
#include "WildPok.h"
#include "Attack.h"
#include "Item.h"
#include "Fight.h"

#include <string>
#include <iostream>
using namespace std;



Fight :: Fight (Player& newme, WildPok & newopposant)
{
    me = &newme;
    opposant = &newopposant;
}

Fight :: ~Fight () {}

Pokemon* Fight :: choicePok (Pokemon* old)
{   
    int choice;
    do{
        
        cout<< "Quel Pokemon voulez-vous utliser ? " <<endl;
        cin>> choice;
    } while (((choice-1)>=0) && ((choice-1)<me->getNbPokemon()) /*&& (old!= (*(choice-1)))*/);//la derniere condition est bizarre
    return me->getPokemon (choice-1);
}

void Fight :: raid  (Pokemon* Pok)
{
    unsigned short int att;

     cout << "Quelle attaque voulez-vous effectuer ?  1 est " << Pok->getMyAttacks(0).getName(); // étendre avec un pour quand on aura plus d'attques
     cin>>att;

    effectsatt(Pok->getMyAttacks(att-1), Pok);

}

void Fight :: effectsatt (Attack* att, Pokemon* Pok)
{
    opposant->getHp()= opposant->getHp()- (att->getImpact()*(Pok->getAtk())-opposant->getDef());
    Pok->getDef() += att->getGainDefense() ;
    Pok->getAtk() += att->getGainPower() ;// Il faut mettre des set et pas des gets
}

void Fight :: acitem(Pokemon* Pok) // à completer
{
    if (me->getNbItem() = 0) {return;}
    int numit;
    Item thisItem;
     cout<< "Quel objet vous-vous utiliser ?";
     cin>> numit;
    thisItem = me->getItem(numit-1); // surcharger l'oprérateur +
    thisItem.action(Pok);
}

void Fight :: action ()
{
    Pokemon* Pok= new Pokemon;
    char act;
    Pok=me->getPokemon(0);
    if(!me->isDie() && !opposant->wildisdie)//fonction à écrire
    {
        do {
             cout<< "Quelle action voulez-vous effectuer ? x: attaquer; c: item; s: changer de pokemon" <<endl;
             cin>>act;
            }while (act != 'x' || act != 'c' || act != 's');
        switch (act)
            {
                case 'x': raid(Pok); break;

                case 'c': acitem(Pok);break;

                case 's': choicePok(Pok); break;

               // else : break;

            }

    }
    else
    {
        if (me->isDie()){ cout<<"Vous avez perdu";}// bizarre pour l'appelle
        else { cout<<"Vous avez gagné ! Bravo !!!";}
    }

     delete Pok;

}
