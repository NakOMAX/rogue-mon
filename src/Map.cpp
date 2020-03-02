#include "Map.h"
#include "Event.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_TXT 0
#define MAP_SDL 1

Map::Map(unsigned short int layers = 10)
{
  // Initialization of variables
  srand (time(NULL));
  unsigned short int eventsInLayer = new unsigned short int [layers];
  eventTree = new vector<Noeud>;
  unsigned short int nEvents = 1;
  unsigned short int random;
  unsigned short int i, j, k;

  // Boss layer set-up
  eventsInLayer[0]=1;
  Node * currentEvent = new Node;
  currentEvent->event=new Boss;
  /*posX posY setting*/
  currentEvent->nextEvent=0;
  eventTree.push_back(currentEvent);



  // For each layer we create a number of events that depends on the number of events in the upper layer
  for (i = 1; i < layers; i++)
  {
    eventsInLayer[i]=0;

    // Each event in the upper layer has 1 or 2 lower events, randomly
    // j is the index of the current upper event
    for (j = nEvents - eventsInLayer[i-1]; j < nEvents ; j++)
    {
      random=rand()%2 + 1;
      eventsInLayer[i]+=random;

      // Initialization of events
      for (k = 0; k < random; k++)
      {
        //
        //  Place holder:
        //  Code to generate a event depending on the layer we are
        //  WIP
        //
      }

    }
    nEvents+=eventsInLayer[i];
  }
}

Map::~Map()
{
  size=eventTree->size();
  for (int i = 0; i < size; i++)
  {
    delete eventTree.at(i);
  }
  delete eventTree;
  delete eventsInLayer;
}
