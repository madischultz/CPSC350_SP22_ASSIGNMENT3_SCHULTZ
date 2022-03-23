//This is a header file for the Mirror class

#ifndef MIRROR_H
#define MIRROR_H

#include "Mode.h"
#include "Grid.h"

class Mirror{
public:
  Mirror();

  int numNeighbors(int w, int h, Grid* g);

  char nextState(int w, int h, Grid* g);

  void nextGen(Grid *g);

  void playMirror(Grid *g, bool enter);

  void playMirror(Grid *g, string filename);
};

#endif
