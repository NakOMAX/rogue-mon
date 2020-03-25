#include "GameManager.h"
#include "curses.h.in"

GameManager::~GameManager()
{
  //delete player;
  delete map;
}

void GameManager::init(unsigned short int cheatCode, unsigned short int numberOfLayers) {
  //player=new Player(cheatCode);
  map=new Map(numberOfLayers);
}

void GameManager::text_run(){
  initscr();
  printw("Hello world");
  refresh();
  getch();
  endwin();
}
