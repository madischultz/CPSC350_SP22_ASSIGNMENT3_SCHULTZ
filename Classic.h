//This is the header file for the Classic class

#ifndef CLASSIC_H
#define CLASSIC_H

#include "Mode.h"
#include "Grid.h"

class Classic{

public:

  Classic();

  int numNeighbors(int w, int h, Grid* g);

  char nextState(int w, int h, Grid* g);

  void nextGen(Grid* g);

  void playClassic(Grid* g, bool enter);

  void playClassic(Grid* g, string filename);

};

#endif
