#include "Map.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

int main(void)
{
  srand(time(NULL));
  Map pokemonMap(7);
  pokemonMap.drawMap();
  int a;
  std::cin>>a;
  return 0;
}
