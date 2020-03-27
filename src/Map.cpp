#include "Map.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SDL_image.h"
#include <string>

SDL_Surface * loadImage(const std::string & filename)
{
  SDL_Surface * surface;
  surface = IMG_Load(filename.c_str());
  if (surface==NULL)
  {
    std::string modFilename;
    modFilename = "../" + filename;
    surface = IMG_Load(modFilename.c_str());
    if (surface==NULL)
    {
      modFilename = "../" + modFilename;
      surface = IMG_Load(modFilename.c_str());
      if (surface==NULL)
      {
        printf("Error: %s\n", SDL_GetError());
      }
    }
  }
  return surface;
}

Map::Map(unsigned short int totalLayers, int seed)
{
  // Initialization of variables
  if (seed == 1) { srand(time(NULL)); }
  else { srand(seed); }
  nLayers=totalLayers;
  myMap = GraphMap();
  eventsInLayer = new short int[nLayers];
  for (unsigned short int i = 0; i<nLayers; i++)
      eventsInLayer[i]=0;

  // SDL2 loading
  std::string filename = "data/map.jpg";
  sur_bg = loadImage(filename);

  // Boss layer
  Vertex vertexF = add_vertex(myMap);
  myMap[vertexF].event=BOSS_EVENT;
  myMap[vertexF].layer=nLayers-1;
  myMap[vertexF].state=STATE_REACHABLE;
  eventsInLayer[nLayers-1]++;

  // Start of the recursive method
  createVerticesBelow(vertexF, nLayers-2);
  setContent();
}

Map::~Map()
{
  delete [] eventsInLayer;
  std::cout<<"Map succesfully destroyed"<<std::endl;
}

void Map::createVerticesBelow(const Vertex & vertexF, unsigned short int layer)
{
    Vertex vertexS;
    unsigned short int randomVertices = rand()%2+1;
    for (unsigned short int i = 0; i < randomVertices; i++)
    {
        vertexS = add_vertex(myMap);
        myMap[vertexS].layer=layer;
        myMap[vertexS].state=STATE_REACHABLE;
        add_edge(vertexS, vertexF, myMap);
        if (layer!=0)
            createVerticesBelow(vertexS, layer-1);
    }
}

void Map::setContent()
{
  auto vPair = vertices(myMap);
  vPair.first++;
  for (VIterator iter = vPair.first; iter!=vPair.second; iter++)
  {
    // For Testing Purposes. Replace when event code is done.
    myMap[*iter].event = rand()%500+1;
  }
}

std::vector<VIterator> * Map::getStarts()
{
    std::vector<VIterator> * v = new std::vector<VIterator>;
    auto vPair = vertices(myMap);
    for (VIterator iter = vPair.first; iter!=vPair.second; iter++)
    {
        if(myMap[*iter].layer==0)
        {
            v->push_back(iter);
        }
    }
    return v;
}

void Map::selectPath(VIterator start)
{
    auto vPair = vertices(myMap);
    for (VIterator iter = vPair.first; iter!=vPair.second; iter++)
    {
        myMap[*iter].state = STATE_UNREACHABLE;
    }
    myMap[*start].state = STATE_SELECTED;
    auto climbIterator = adjacent_vertices(*start, myMap);
    do{
        myMap[*climbIterator.first].state = STATE_REACHABLE;
        climbIterator = adjacent_vertices(*climbIterator.first, myMap);
    }while(myMap[*climbIterator.first].layer != nLayers-1);
    myMap[*climbIterator.first].state = STATE_REACHABLE;
}

PathI Map::climbFrom(VIterator current)
{
    // There is only one option to go upwards. If it changed, change this code
    // to return a vector of PathI and call selectPathI on the desired option.
    myMap[*current].state = STATE_VISITED;
    PathI next = adjacent_vertices(*current, myMap).first;
    myMap[*next].state = STATE_SELECTED;
    return next;
}

PathI Map::climbFrom(PathI current)
{
    // There is only one option to go upwards. If it changed, change this code
    // to return a vector of PathI and call selectPathI on the desired option.
    myMap[*current].state = STATE_VISITED;
    PathI next = adjacent_vertices(*current, myMap).first;
    myMap[*next].state = STATE_SELECTED;
    return next;
}

void Map::setRenderer(SDL_Renderer * renderer)
{
  tex_bg = SDL_CreateTextureFromSurface(renderer, sur_bg);
}

void Map::drawMap(SDL_Renderer * renderer)
{
  SDL_RenderCopy(renderer, tex_bg, NULL, NULL);
}

void Map::highlight(std::vector<VIterator> * options, unsigned short int selected)
{
    auto size = options->size();
    for (unsigned short int i = 0; i<size; i++)
    {
        myMap[*options->at(i)].state = STATE_REACHABLE;
    }
    myMap[*options->at(selected)].state = STATE_SELECTED;
}
