#include "Map.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Map::Map(unsigned short int totalLayers)
{
  // Initialization of variables
  myMap = GraphMap();
  eventsInLayer = new short int[totalLayers];
  for (unsigned short int i = 0; i<totalLayers; i++)
      eventsInLayer[i]=0;

  // Boss layer
  Vertex vertexF = add_vertex(myMap);
  myMap[vertexF].event=BOSS_EVENT;
  myMap[vertexF].layer=totalLayers-1;
  eventsInLayer[totalLayers-1]++;

  // Start of the recursive method
  createVerticesBelow(vertexF, totalLayers-2);
}

Map::~Map()
{
  delete [] eventsInLayer;
  std::cout<<"Map succesfully destroyed"<<std::endl;
}

void Map::createVerticesBelow(Vertex vertexF, unsigned short int layer)
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

void Map::drawMap(short int mode)
{
    switch(mode)
    {
        default:
            auto vPair = vertices(myMap);
            int i = 0;
            for (auto iter = vPair.first; iter!=vPair.second; iter++)
            {
                std::cout<< "Vertex n" << i++<< " is in layer "<< myMap[*iter].layer
                <<std::endl;
            }
    }
}

int main(void)
{
    Map pokemonMap(5);
    pokemonMap.drawMap();
    return 0;
}
