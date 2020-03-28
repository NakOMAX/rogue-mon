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
  surBg = loadImage("data/map.jpg");
  surTrainer = loadImage("data/double.png");
  surWild = loadImage("data/simple.png");
  surShop = loadImage("data/store.png");
  surHeal = loadImage("data/rest.png");

  // Boss layer
  Vertex vertexF = add_vertex(myMap);
  myMap[vertexF].layer=nLayers-1;
  myMap[vertexF].state=STATE_REACHABLE;
  eventsInLayer[nLayers-1]++;

  // Start of the recursive method
  createVerticesBelow(vertexF, nLayers-2);
  allVertices = vertices(myMap);
}

Map::~Map()
{
  delete [] eventsInLayer;
  std::cout<<"Map succesfully destroyed"<<std::endl;
}

void Map::init(SDL_Renderer * newRenderer, unsigned short int wdimy)
{
  // Setting up SDL_Rect for scrolling purposes
  focusRect = new SDL_Rect;
  focusRect->w = MAP_WIDTH;
  focusRect->h = wdimy;
  focusRect->x = 0;
  focusRect->y = MAP_HEIGHT-wdimy;

  renderer=newRenderer;

  // Surfaces -> Textures
  texBg = SDL_CreateTextureFromSurface(renderer, surBg);
  texTrainer = SDL_CreateTextureFromSurface(renderer, surTrainer);
  texWild = SDL_CreateTextureFromSurface(renderer, surWild);
  texShop = SDL_CreateTextureFromSurface(renderer, surShop);
  texHeal = SDL_CreateTextureFromSurface(renderer, surHeal);
  setContent();
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
  // Used to represent percentages (0 to 100)
  unsigned short int randomNumber;
  // Used to keep track of treated events per layer
  unsigned short int placedEvents[nLayers]={0};

  // For Testing Purposes. Replace when event code is done.
    // Boss event
  myMap[*allVertices.first].event=BOSS_EVENT;
  myMap[*allVertices.first].iconTexture=texTrainer;
  myMap[*allVertices.first].rect = new SDL_Rect;
  myMap[*allVertices.first].rect->h = 3*ICON_SIZE;
  myMap[*allVertices.first].rect->w = 3*ICON_SIZE;
  myMap[*allVertices.first].posY = (MAP_HEIGHT*(nLayers-myMap[*allVertices.first].layer+1))/(nLayers+1);
  myMap[*allVertices.first].posX = MAP_WIDTH/2;
  //myMap[*allVertices.first].rect->x = myMap[*allVertices.first].posX - 3*ICON_SIZE/2;
  //myMap[*allVertices.first].rect->y = myMap[*allVertices.first].posY - 3*ICON_SIZE/2;

    // Not boss events
  VIterator notFirst = allVertices.first;
  notFirst++;
  for (VIterator iter = notFirst; iter!=allVertices.second; iter++)
  {
    // Setting events
    switch ((nLayers-2-myMap[*iter].layer)%4)
    {
    case 0:
      myMap[*iter].event = HEAL_EVENT;
      myMap[*iter].iconTexture = texHeal;
      break;

    case 1:
      randomNumber = rand()%101;
      if (randomNumber<=50)
      {
        myMap[*iter].event = TRAINER_EVENT;
        myMap[*iter].iconTexture = texTrainer;
        break;
      }
      if (randomNumber<=90)
      {
        myMap[*iter].event = WILD_EVENT;
        myMap[*iter].iconTexture = texWild;
        break;
      }
      myMap[*iter].event = SHOP_EVENT;
      myMap[*iter].iconTexture = texShop;
      break;

    case 2:
      randomNumber = rand()%101;
      if (randomNumber<=10)
      {
        myMap[*iter].event = TRAINER_EVENT;
        myMap[*iter].iconTexture = texTrainer;
        break;
      }
      if (randomNumber<=40)
      {
        myMap[*iter].event = WILD_EVENT;
        myMap[*iter].iconTexture = texWild;
        break;
      }
      if (randomNumber<=70)
      {
        myMap[*iter].event = HEAL_EVENT;
        myMap[*iter].iconTexture = texHeal;
        break;
      }
      myMap[*iter].event = SHOP_EVENT;
      myMap[*iter].iconTexture = texShop;
      break;

    default:
      randomNumber = rand()%101;
      if (randomNumber<=25)
      {
        myMap[*iter].event = TRAINER_EVENT;
        myMap[*iter].iconTexture = texTrainer;
        break;
      }
      myMap[*iter].event = WILD_EVENT;
      myMap[*iter].iconTexture = texWild;
      break;
    }

    // Setting coordinates
    myMap[*iter].posY = MAP_HEIGHT*(float(nLayers-myMap[*iter].layer+1))/(nLayers+1) + rand()%10;
    myMap[*iter].posX = MAP_WIDTH*(float(placedEvents[myMap[*iter].layer] + 1))/(eventsInLayer[myMap[*iter].layer]+1) + rand()%10;
    placedEvents[myMap[*iter].layer]++;
    myMap[*iter].rect = new SDL_Rect;
    myMap[*iter].rect->h = ICON_SIZE;
    myMap[*iter].rect->w = ICON_SIZE;
    //myMap[*iter].rect->x = myMap[*iter].posX - ICON_SIZE/2;
    //myMap[*iter].rect->y = myMap[*iter].posY - ICON_SIZE/2;
  }
}

std::vector<VIterator> * Map::getStarts()
{
    std::vector<VIterator> * v = new std::vector<VIterator>;
    for (VIterator iter = allVertices.first; iter!=allVertices.second; iter++)
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
    for (VIterator iter = allVertices.first; iter!=allVertices.second; iter++)
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
    smoothScroll(myMap[*current].layer);
    return next;
}

PathI Map::climbFrom(PathI current)
{
    // There is only one option to go upwards. If it changed, change this code
    // to return a vector of PathI and call selectPathI on the desired option.
    myMap[*current].state = STATE_VISITED;
    PathI next = adjacent_vertices(*current, myMap).first;
    myMap[*next].state = STATE_SELECTED;
    smoothScroll(myMap[*current].layer);
    return next;
}

void Map::smoothScroll(unsigned short int startL)
{
  for (unsigned short int i = 0; i<800; i++)
  {
    focusRect->y = (MAP_HEIGHT-focusRect->h)*(1-(startL + float(i)/800)/(nLayers-1));
    drawMap();
    SDL_RenderPresent(renderer);
    SDL_Delay(1);
  }
  focusRect->y = (MAP_HEIGHT-focusRect->h)*(1-float(startL + 1)/(nLayers-1));
}

void Map::drawMap()
{
  // Background
  SDL_RenderCopy(renderer, texBg, focusRect, NULL);
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
