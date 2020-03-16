#ifndef POKE_MAP_H
#define POKE_MAP_H


#include <boost/graph/adjacency_list.hpp>

#define MAP_TXT 0
#define MAP_SDL 1

#define BOSS_EVENT 0
#define WILD_EVENT 1
#define TRAINER_EVENT 2
#define HEAL_EVENT 3

struct Node{
  //Event * event;
  unsigned short int event;
  /** @brief 0<=layer<totalLayers */
  unsigned short int layer;

  //For SDL purposes
  unsigned short int posX;
  unsigned short int posY;

  // Visited, current, unreachable, reachable
  unsigned short int state;
};

typedef boost::adjacency_list<boost::listS, boost::listS,
                              boost::bidirectionalS, Node>
                              GraphMap;
typedef boost::graph_traits<GraphMap>::vertex_descriptor Vertex;

class Map{
public:
  /** @brief Class constructor */
  /** The class constructor randomly generates a map of the desired
  number of layers */
  /** @param layers Number of layers that the map will have. Minimun: 1 */
  Map(unsigned short int totalLayers = 10);

  /** @brief Class destructor. Deallocates memory. */
  ~Map();

  /** @brief paths and numberOfPaths updated to start the run */
  /** paths become an array of size numberOfPaths that stocks the first
  events id, where the run will start */
  /** @param paths array where the ids will be stocked */
  /** @param numberOfPaths size of paths array */
  void getStarts(Node *& starts, unsigned short int & numberOfPaths);

  /** @brief Returns pointer to the event number eventId */
  /** @param eventId Current event Id */
  //Event * getEvent(const Node * n);

  /** @brief Draws the map*/
  /** Draws the map in console mode or in graphic mode with SDL */
  /** @param mode MAP_TXT to txt mode MAP_SDL to graphic mode.
  Default: console mode, single print in the terminal*/
  void drawMap(short int mode=-1);

private:
  // Container that stores the map structure
  GraphMap myMap;

  // Number of events in each layer
  short int * eventsInLayer;

  // Number of layers
  unsigned short int nLayers;

  // Creates one or two vertices in layer linked to vertxF. Recursive method.
  void createVerticesBelow(const Vertex & vertexF, unsigned short int layer);

  // Set the content of the events
  void setContent();

};

#endif
