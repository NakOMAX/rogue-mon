#include "Map.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Map::Map(unsigned short int totalLayers)
{
  // Initialization of variables
  nLayers=totalLayers;
  myMap = GraphMap();
  eventsInLayer = new short int[nLayers];
  for (unsigned short int i = 0; i<nLayers; i++)
      eventsInLayer[i]=0;

  // Boss layer
  Vertex vertexF = add_vertex(myMap);
  myMap[vertexF].event=BOSS_EVENT;
  myMap[vertexF].layer=nLayers-1;
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
        add_edge(vertexS, vertexF, myMap);
        if (layer!=0)
            createVerticesBelow(vertexS, layer-1);
    }
}

void Map::setContent()
{
  auto vPair = vertices(myMap);
  vPair.first++;
  for (auto iter = vPair.first; iter!=vPair.second; iter++)
  {
    // For Testing Purposes. Replace when event code is done.
    myMap[*iter].event = rand()%500+1;
  }
}

void Map::drawMap(short int mode)
{
    switch(mode)
    {
        default:
            auto vPair = vertices(myMap);
            vPair.first++;
            for (auto iter = vPair.first; iter!=vPair.second; iter++)
            {
                std::cout << "Vertex with value " << myMap[*iter].event;
                std::cout << " is in layer " << myMap[*iter].layer << " and its upper step is ";
                std::cout << myMap[*(adjacent_vertices(*iter, myMap).first)].event <<std::endl;
            }
    }
}
