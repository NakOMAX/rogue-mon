#ifndef _POKE_GM_H
#define _POKE_GM_H

//#include "Player.h"
#include "Map.h"
#include "SDL.h"

class GameManager {
public:
  GameManager();
  ~GameManager();

  /** @brief Initialize data */
  /** @param cheatCode Code to start the run with advantage */
  /** @param numberOfLayers Length of the run */
  void init(unsigned short int cheatCode = 0, unsigned short int numberOfLayers = 10);

  /** @brief Runs the game in graphic mode */
  /** Opens a new window and runs the game. It uses SDL2. */
  /** @param dimx Screen width, in pixels */
  /** @param dimx Screen height, in pixels */
  void graph_run(unsigned short int dimx=800, unsigned short int dimy=800);
private:
  //Player * player;
  Map * map;
  SDL_Window * window;
  SDL_Event e;
  SDL_Surface * surface;
  SDL_Renderer * renderer;

};

#endif
