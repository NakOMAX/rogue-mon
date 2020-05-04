#ifndef _POKE_GM_H
#define _POKE_GM_H

//#include "Player.h"
#include "Map.h"
#include "SDL.h"
#include "Player.h"

class GameManager {
public:
  GameManager();
  ~GameManager();

  /** @brief Initialize data */
  /** Data Initialization and graphic setup */
  /** @param cheatCode Code to start the run with advantage */
  /** @param numberOfLayers Length of the run */
  /** @param dimx Screen width, in pixels */
  /** @param dimx Screen height, in pixels */
  short int init(unsigned short int cheatCode = 0, unsigned short int numberOfLayers = 10
    , unsigned short int dimx=1200, unsigned short int dimy=750);

  /** @brief Runs the game in graphic mode */
  /** Holds game loops in it */
  void run();

private:
  Player * player;
  Map * map;
  SDL_Window * window;
  SDL_Event e;
  SDL_Surface * surface;
  SDL_Renderer * renderer;
  unsigned short int wdimx;
  unsigned short int wdimy;

  unsigned short int nLayers;
};

#endif
