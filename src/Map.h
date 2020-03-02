#ifndef POKE_MAP_H
#define POKE_MAP_H

#include "Event.h"
#include <vector>

class Map{
public:
  /** @brief Class constructor */
  /** The class constructor randomly generates a map of the desired number of layers */
  /** @param layers Number of layers that the map will have. Minimun: 1 */
  Map(unsigned short int layers = 10);
  /** @brief Class destructor. Deallocates memory. */
  ~Map();
  /** @brief paths and numberOfPaths updated to start the run */
  /** paths become an array of size numberOfPaths that stocks the first events id, where the run will start */
  /** @param paths array where the ids will be stocked */
  /** @param numberOfPaths size of paths array */
  void getPathStarts(unsigned short int *& paths, unsigned short int & numberOfPaths);
  /** @brief Returns pointer to the event number eventId */
  /** @param eventId Current event Id */
  Event * getEvent(unsigned short int eventId);
  /** @brief Returns the number of the next event */
  /** @param eventId Current event Id */
  void nextEvent(unsigned short int & eventId);
  /** @brief Draws the map*/
  /** Draws the map in console mode or in graphic mode with SDL */
  /** @param mode MAP_TXT to console mode MAP_SDL to graphic mode */
  void drawMap(unsigned short int mode);
protected:
  /** @brief Array where the events are stocked */
  vector<Event *> eventTree;
  /** @brief Vector that stores the upper step of the n-th event.*/
  /** This vector stores the upper step in the path of the n-th event. nextEvent[0] should never be accesed because 0 its the uppest step*/
  vector<unsigned short int> * nextEvent;
  unsigned short int * eventsInLayer;
};

#endif
