#ifndef _POKE_MAP_H
#define _POKE_MAP_H

#include <boost/graph/adjacency_list.hpp>
#include "SDL.h"
#include "SDL_image.h"

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
  /* 0<=layer<totalLayers */
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
typedef boost::graph_traits<GraphMap>::adjacency_iterator PathI;

class Map{
public:
  /** @brief Class constructor */
  /** The class constructor randomly generates a map of the desired
  number of layers. SDL_image needs to be initialised before creating objects */
  /** @param layers Number of layers that the map will have. Minimun: 1 */
  Map(unsigned short int totalLayers = 10, int seed = 1);

  /** @brief Class destructor. Deallocates memory. */
  ~Map();

  /** @brief Returns initial points where the game can start from */
  /** The vector contains pointers to the first layer vertices */
  std::vector<VIterator> * getStarts();

  /** @brief Selects a PathI to start*/
  /** Selects a PathI and sets every unreachable vertex to STATE_UNREACHABLE */
  /** @param start VIterator from the array got in getStarts() */
  void selectPath(VIterator start);

  /** @brief Returns iterator towards next vertex*/
  /** Returns iterator towards next vertex and set state of *current
  to STATE_VISITED*/
  /** @param current VIterator got from getStarts() */
  PathI climbFrom(VIterator current);

  /** @brief Returns iterator towards next vertex*/
  /** Returns iterator towards next vertex and set state of *current
  to STATE_VISITED*/
  /** @param current PathI got from climbFrom */
  PathI climbFrom(PathI current);

  /** @brief Transforms surfaces into textures for SDL */
  /** @param newRenderer SDL_Renderer linked to an open window */
  /** @param wdimy window height in pixels */
  void setRenderer(SDL_Renderer * newRenderer, unsigned short int wdimy);

  /** @brief Draws the map*/
  /** Draws the map in graphic mode. */
  void drawMap();

  /** @brief Runs the event for the current vertex*/
  void runEvent(PathI current);

  /** @brief Runs the event for the current vertex*/
  void runEvent(VIterator current);

  /** @brief Highlights one vertex at a time while in map screen */
  /** @param selected VIterator got from getStarts */
  void highlight(std::vector<VIterator> * options, unsigned short int selected);

private:
  // Container that stores the map structure
  GraphMap myMap;

  // Number of events in each layer
  short int * eventsInLayer;

  // Number of layers
  unsigned short int nLayers;

  // Creates one or two vertices in layer linked to vertexF. Recursive method.
  void createVerticesBelow(const Vertex & vertexF, unsigned short int layer);

  // Set the content of the events in a procedural way
  void setContent();

  // SDL Rect -> Map scrolling
  SDL_Rect * focusRect;
  SDL_Renderer * renderer;

  // SDL Images. Each pair represents an image.
  SDL_Surface * sur_bg;
  SDL_Texture * tex_bg;

  // Moves the focus to the next layer smoothly.
  void smoothScroll(unsigned short int startL);
};

#endif
