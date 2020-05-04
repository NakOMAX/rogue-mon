#include "../GameManager.h"

int main (void)
{
  GameManager gm;
  if(gm.init(0 , 10)==0)
    gm.run();
  else
    printf("Could not open the game\n");
  return 0;
}
