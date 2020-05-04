#ifndef _POKE_MAP_H
#define _POKE_MAP_H

#include <boost/graph/adjacency_list.hpp>
#include "SDL.h"
#include "SDL_image.h"
#include "sdlTools.h"
#include "Event.h"
#include "Fight.h"
#include "InheritedEvents.h"

#define BOSS_EVENT 0
#define WILD_EVENT 1
#define TRAINER_EVENT 2
#define HEAL_EVENT 3
#define SHOP_EVENT 4

#define STATE_VISITED 0
#define STATE_REACHABLE 1
#define STATE_UNREACHABLE 2
#define STATE_SELECTED 3

// map.jpg size
#define MAP_HEIGHT 3190
#define MAP_WIDTH 1600

#define ICON_SIZE 160

struct Node{
  //Event * event;
  unsigned short int event;
  /* 0<=layer<totalLayers */
  unsigned short int layer;

  //For SDL purposes. In pixels.
  unsigned short int posX;
  unsigned short int posY;
  SDL_Texture * iconTexture;
  SDL_Rect * rect;

  // Visited, unreachable, reachable or selected.
  unsigned short int state;
};

SDL_Surface * loadImage(const std::string & filename);

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

  /** @brief Initialize events and SDL data */
  /** @param newRenderer SDL_Renderer linked to an open window */
  /** @param wdimy window height in pixels */
  /** @param wdimx window width in pixels */
  void init(SDL_Renderer * newRenderer, unsigned short int wdimy, unsigned short int wdimx);

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

  // Pair storing the first and last vertex
  std::pair<VIterator,VIterator> allVertices;

  // Number of events in each layer
  unsigned short int * eventsInLayer;

  // Number of layers
  unsigned short int nLayers;

  // Creates one or two vertices in layer linked to vertexF. Recursive method.
  void createVerticesBelow(const Vertex & vertexF, unsigned short int layer);

  // Set the content of the events in a procedural way
  void setContent();

  // SDL Rect -> Map scrolling
  SDL_Rect * focusRect;
  SDL_Renderer * renderer;
  // Real Image / Window Size
  float ratio;

  // SDL Images. Each pair represents an image.
  SDL_Surface * surBg;
  SDL_Texture * texBg;

  SDL_Surface * surTrainer;
  SDL_Texture * texTrainer;

  SDL_Surface * surWild;
  SDL_Texture * texWild;

  SDL_Surface * surShop;
  SDL_Texture * texShop;

  SDL_Surface * surHeal;
  SDL_Texture * texHeal;

  // Moves the focus to the next layer smoothly.
  void smoothScroll(unsigned short int startL);

  // Replaces event icons in the screen depending on camera position
  void replaceIconsOnScroll();
};

#endif
