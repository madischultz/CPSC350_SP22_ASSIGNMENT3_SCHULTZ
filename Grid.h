//This is the header file for the Grid class

#ifndef GRID_H
#define GRID_H

#include "FileProcessor.h"

#include <iostream>
#include <string>

using namespace std;

class Grid{
public:
  Grid();

  Grid(int w, int h);

  void populateGrid(float f); //randomly generate grid

  void populateGrid(string userMap); //populates grid with user's input

  void nextGen(); //populates the next Gen grid into array

  bool isEmpty();

  bool isStable();

  int getWidth();

  int getHeight();

  ~Grid();

  char** currentGrid;

  char** newGrid;

  int genNum;

private:
  int height;

  int width;

};

#endif
