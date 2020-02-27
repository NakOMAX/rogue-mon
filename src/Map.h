#ifndef POKE_MAP_H
#define POKE_MAP_H

#include "Event.h"

class Map{
public:
  /** @brief Class constructor */
  /** The class constructor randomly generates a map*/
  Map();
  /** @brief Class destructor */
  ~Map();
  /** @brief Returns pointer to the event number eventId */
  /** @param eventId Current event Id*/
  Event * getEvent(unsigned short int eventId);
  /** @brief Returns the number of the next event */
  /** @param eventId Current event Id*/
  void nextEvent(unsigned short int & eventId);
  /** @brief Draws the map*/
  /** Draws the map in console mode or in graphic mode with SDL*/
  /** @param mode MAP_TXT to console mode MAP_SDL to graphic mode */
  void drawMap(unsigned short int mode);
protected:
  /** @brief Array where the events are stocked */
  Event ** eventTree;
  /** @brief Array that stores the upper step of the n-th event */
  unsigned short int * nextEvent;
};

#endif
