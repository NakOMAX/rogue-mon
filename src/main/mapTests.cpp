#include "../Map.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

int main(void)
{
  Map pokemonMap(4);
  pokemonMap.drawMap();


  std::vector<VIterator> * vector = pokemonMap.getStarts();
  pokemonMap.highlight(vector, 0);
  pokemonMap.drawMap();


  pokemonMap.selectPath(vector->at(0));
  pokemonMap.drawMap();


  PathI current = pokemonMap.climbFrom(vector->at(0));
  pokemonMap.drawMap();


  current = pokemonMap.climbFrom(current);
  pokemonMap.drawMap();


  return 0;
}
