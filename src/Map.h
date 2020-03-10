#ifndef POKE_MAP_H
#define POKE_MAP_H

#include "Event.h"
#include <vector>
using namespace std;

struct Node{
  //Event * event;
  unsigned short int content;
  unsigned short int posX;
  unsigned short int posY;

  unsigned short int nextEvent;

  unsigned short int state; // visited, current, unreachable, reachable
  vector<Edge *> connects;
};

struct Edge {
  Node * up;
  Node * down;
};

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
  vector<Node>* nodeTree;
  /** @brief Array where edges are stocked */
  vector<Edge>* edgeArray;
  /** @brief Number of events in each layer*/
  unsigned short int * eventsInLayer;
};

#endif
