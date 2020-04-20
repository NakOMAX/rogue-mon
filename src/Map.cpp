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
  eventsInLayer = new unsigned short int[nLayers];
  for (unsigned short int i = 0; i<nLayers; i++)
  {
    eventsInLayer[i]=0;
  }

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

void Map::init(SDL_Renderer * newRenderer, unsigned short int wdimy, unsigned short int wdimx)
{
  // Setting up SDL_Rect for scrolling purposes
  ratio=float(wdimx)/MAP_WIDTH;
  focusRect = new SDL_Rect;
  focusRect->w = MAP_WIDTH;
  focusRect->h = wdimy;
  focusRect->x = 0;
  focusRect->y = MAP_HEIGHT-focusRect->h;

  renderer=newRenderer;

  // Surfaces -> Textures
  texBg = SDL_CreateTextureFromSurface(renderer, surBg);
  texTrainer = SDL_CreateTextureFromSurface(renderer, surTrainer);
  texWild = SDL_CreateTextureFromSurface(renderer, surWild);
  texShop = SDL_CreateTextureFromSurface(renderer, surShop);
  texHeal = SDL_CreateTextureFromSurface(renderer, surHeal);
  setContent();
  replaceIconsOnScroll();
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
  myMap[*allVertices.first].posY = (MAP_HEIGHT*(nLayers-myMap[*allVertices.first].layer+1))/(nLayers+1);
  myMap[*allVertices.first].posX = MAP_WIDTH/2;
  myMap[*allVertices.first].rect->h = 3*ICON_SIZE*ratio;
  myMap[*allVertices.first].rect->w = 3*ICON_SIZE*ratio;
  myMap[*allVertices.first].rect->x = ratio*myMap[*allVertices.first].posX-myMap[*allVertices.first].rect->w/2;

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
    myMap[*iter].posY = (MAP_HEIGHT*(nLayers-myMap[*iter].layer+1))/(nLayers+1);
    myMap[*iter].posX = (MAP_WIDTH*(placedEvents[myMap[*iter].layer] + 1))/(eventsInLayer[myMap[*iter].layer]+1);
    placedEvents[myMap[*iter].layer]++;
    myMap[*iter].rect = new SDL_Rect;
    myMap[*iter].rect->h = ICON_SIZE*ratio;
    myMap[*iter].rect->w = ICON_SIZE*ratio;
    myMap[*iter].rect->x = ratio*myMap[*iter].posX-myMap[*iter].rect->w/2;
  }
}

void Map::replaceIconsOnScroll()
{
  printf("focus rect y %i\n", focusRect->y);
  printf("first posy %i\n", myMap[*allVertices.first].posY);
  printf("ratio %f\n", ratio);
  for (VIterator iter = allVertices.first; iter!=allVertices.second; iter++)
  {
    myMap[*iter].rect->y=(myMap[*iter].posY-focusRect->y)*ratio - myMap[*iter].rect->h;
  }
  printf("first y %i\n", myMap[*allVertices.first].rect->y);
}

void Map::createVerticesBelow(const Vertex & vertexF, unsigned short int layer)
{
  Vertex vertexS;
  unsigned short int randomVertices = rand()%4%3%2+1;
  for (unsigned short int i = 0; i < randomVertices; i++)
  {
    vertexS = add_vertex(myMap);
    myMap[vertexS].layer=layer;
    eventsInLayer[myMap[vertexS].layer]++;
    myMap[vertexS].state=STATE_REACHABLE;
    add_edge(vertexS, vertexF, myMap);
    if (layer!=0)
    createVerticesBelow(vertexS, layer-1);
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
    myMap[*start].rect->h = ICON_SIZE*1.2*ratio;
    myMap[*start].rect->w = ICON_SIZE*1.2*ratio;
    myMap[*start].rect->x = ratio*myMap[*start].posX-myMap[*start].rect->w/2;

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
  myMap[*current].rect->h = ICON_SIZE*ratio;
  myMap[*current].rect->w = ICON_SIZE*ratio;
  myMap[*current].rect->x = ratio*myMap[*current].posX-myMap[*current].rect->w/2;

  PathI next = adjacent_vertices(*current, myMap).first;

  myMap[*next].state = STATE_SELECTED;
  myMap[*next].rect->h = ICON_SIZE*1.2*ratio;
  myMap[*next].rect->w = ICON_SIZE*1.2*ratio;
  myMap[*next].rect->x = ratio*myMap[*next].posX-myMap[*next].rect->w/2;

  smoothScroll(myMap[*current].layer);
  return next;
}

PathI Map::climbFrom(PathI current)
{
  // There is only one option to go upwards. If it changed, change this code
  // to return a vector of PathI and call selectPathI on the desired option.
  myMap[*current].state = STATE_VISITED;
  myMap[*current].rect->h = ICON_SIZE*ratio;
  myMap[*current].rect->w = ICON_SIZE*ratio;
  myMap[*current].rect->x = ratio*myMap[*current].posX-myMap[*current].rect->w/2;

  PathI next = adjacent_vertices(*current, myMap).first;

  myMap[*next].state = STATE_SELECTED;
  myMap[*next].rect->h = ICON_SIZE*1.2*ratio;
  myMap[*next].rect->w = ICON_SIZE*1.2*ratio;
  myMap[*next].rect->x = ratio*myMap[*next].posX-myMap[*next].rect->w/2;

  smoothScroll(myMap[*current].layer);
  return next;
}

void Map::smoothScroll(unsigned short int startL)
{
  for (float i = 0; i<150; i++)
  {
    focusRect->y = (MAP_HEIGHT-focusRect->h)*(1-(startL + i/150)/(nLayers-1));
    replaceIconsOnScroll();
    drawMap();
    SDL_RenderPresent(renderer);
  }
  focusRect->y = (MAP_HEIGHT-focusRect->h)*(1-float(startL + 1)/(nLayers-1));
  replaceIconsOnScroll();
}

void Map::drawMap()
{
  // Background
  SDL_RenderCopy(renderer, texBg, focusRect, NULL);

  // Icons
  for (VIterator iter = allVertices.first; iter!=allVertices.second; iter++)
  {
    SDL_RenderCopy(renderer, myMap[*iter].iconTexture, NULL, myMap[*iter].rect);
  }
}

void Map::highlight(std::vector<VIterator> * options, unsigned short int selected)
{
    auto size = options->size();
    for (unsigned short int i = 0; i<size; i++)
    {
        myMap[*options->at(i)].state = STATE_REACHABLE;
        myMap[*options->at(i)].rect->h = ICON_SIZE*ratio;
        myMap[*options->at(i)].rect->w = ICON_SIZE*ratio;
        myMap[*options->at(i)].rect->x = ratio*myMap[*options->at(i)].posX
        -myMap[*options->at(i)].rect->w/2;
    }
    myMap[*options->at(selected)].state = STATE_SELECTED;
    myMap[*options->at(selected)].rect->h = ICON_SIZE*1.2*ratio;
    myMap[*options->at(selected)].rect->w = ICON_SIZE*1.2*ratio;
    myMap[*options->at(selected)].rect->x = ratio*myMap[*options->at(selected)].posX
    -myMap[*options->at(selected)].rect->w/2;
}
