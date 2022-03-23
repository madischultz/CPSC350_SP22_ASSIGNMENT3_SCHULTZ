//This is the header file for the Doughnut class

#ifndef DOUGHNUT_H
#define DOUGHNUT_H

#include "Mode.h"
#include "Grid.h"

class Doughnut{
public:
  Doughnut();

  int numNeighbors(int w, int h, Grid* g);

  char nextState(int w, int h, Grid* g);

  void nextGen(Grid* g);

  void playDoughnut(Grid* g, bool enter);

  void playDoughnut(Grid* g, string filename);
};

#endif
