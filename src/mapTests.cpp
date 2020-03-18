#include "Map.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

int main(void)
{
  srand(0);
  Map pokemonMap(7);
  pokemonMap.drawMap();
  return 0;
}
