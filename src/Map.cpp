#include "Map.h"
#include "Event.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

#define MAP_TXT 0
#define MAP_SDL 1

Map::Map(unsigned short int layers = 10)
{
  // Initialization of variables
  srand (time(NULL));
  unsigned short int eventsInLayer = new unsigned short int [layers];
  nodeTree = new vector<Node>;
  edgeArray = new vector<Edge>;
  unsigned short int nEvents = 1;
  unsigned short int random;
  unsigned short int i, j, k;

  // Boss layer set-up
  eventsInLayer[0]=1;
  Node currentEvent;
  //currentEvent->event=new Boss;
  currentEvent.content = 0; // test de contenu
  currentEvent.posY = 0;
  nodeTree->push_back(currentEvent);

  Edge currentEdge;

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
      currentEdge.up = &nodeTree->at(j);

      // Initialization of events
      for (k = 0; k < random; k++)
      {
        currentEvent.posY = i;
        //param
        nodeTree->push_back(temp);

        currentEdge.down = &nodeTree->back();
        edgeArray->push_back(currentEdge);

        currentEvent.connects.push_back(&edgeArray->back());
      }

    }
    nEvents+=eventsInLayer[i];
    for (k = eventsInLayer[i]; k > 0; k--) {
      nodeTree->at(nEvents-k).posX = k;
    }
  }
}

Map::~Map()
{
  size=nodeTree->size();
  for (int i = 0; i < size; i++)
  {
    delete nodeTree->at(i);
  }
  delete nodeTree;
  delete eventsInLayer;
}
