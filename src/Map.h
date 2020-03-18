#ifndef _POKE_MAP_H
#define _POKE_MAP_H


#include <boost/graph/adjacency_list.hpp>

#define MAP_TXT 0
#define MAP_SDL 1

#define BOSS_EVENT 0
#define WILD_EVENT 1
#define TRAINER_EVENT 2
#define HEAL_EVENT 3

#define STATE_VISITED 0
#define STATE_REACHABLE 1
#define STATE_UNREACHABLE 2
#define STATE_SELECTED 3

struct Node{
  //Event * event;
  unsigned short int event;
  /** @brief 0<=layer<totalLayers */
  unsigned short int layer;

  //For SDL purposes
  unsigned short int posX;
  unsigned short int posY;

  // Visited, unreachable, reachable or selected.
  unsigned short int state;
};

typedef boost::adjacency_list<boost::listS, boost::listS,
                              boost::bidirectionalS, Node>
                              GraphMap;
typedef boost::graph_traits<GraphMap>::vertex_descriptor Vertex;
typedef boost::graph_traits<GraphMap>::vertex_iterator VIterator;
typedef boost::graph_traits<GraphMap>::adjacency_iterator Path;

class Map{
public:
  /** @brief Class constructor */
  /** The class constructor randomly generates a map of the desired
  number of layers */
  /** @param layers Number of layers that the map will have. Minimun: 1 */
  Map(unsigned short int totalLayers = 10);

  /** @brief Class destructor. Deallocates memory. */
  ~Map();

  /** @brief Returns initial points where the game can start from */
  /** The vector contains pointers to the first layer vertices */
  std::vector<VIterator> * getStarts();

  /** @brief Selects a path to start*/
  /** Selects a path and sets every unreachable vertex to STATE_UNREACHABLE */
  /** @param start VIterator from the array got in getStarts() */
  void selectPath(VIterator start);

  /** @brief Returns iterator towards next vertex*/
  /** Returns iterator towards next vertex and set state of *current
  to STATE_VISITED*/
  /** @param current VIterator got from getStarts() */
  Path climbFrom(VIterator current);

  /** @brief Returns iterator towards next vertex*/
  /** Returns iterator towards next vertex and set state of *current
  to STATE_VISITED*/
  /** @param current Path got from climbFrom */
  Path climbFrom(Path current);

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
