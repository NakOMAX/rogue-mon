#ifndef _POKE_GM_H
#define _POKE_GM_H

//#include "Player.h"
#include "Map.h"

class GameManager {
public:
  GameManager();
  ~GameManager();

  /** @brief Initialize data */
  /** @param cheatCode Code to start the run with advantage */
  /** @param numberOfLayers Length of the run */
  void init(unsigned short int cheatCode = 0, unsigned short int numberOfLayers = 10);

  /** @brief Runs the game in graphic mode */
  void graph_run();

  /** @brief Runs the game in text mode */
  void text_run();
protected:
  //Player * player;
  Map * map;
};

#endif
