//This is a header file for the Mode class

#ifndef MODE_H
#define MODE_H

#include <iostream>
#include <fstream>
#include "Grid.h"
#include <stdio.h>
#include <unistd.h>

using namespace std;

class Mode{

public:

  Mode(); //default constructor

  string gridToStr(Grid* g);

  void print(Grid* g); //should be the same for all modes

  void printToFile(Grid* g, string filename);

  void enter();

};

#endif
