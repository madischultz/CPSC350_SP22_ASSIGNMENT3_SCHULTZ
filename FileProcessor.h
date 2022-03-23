//This is the header file for the FileProcessor class

#ifndef FILE_PROCESSOR_H
#define FILE_PROCESSOR_H

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class FileProcessor {

public:
  FileProcessor(); //constructor

  string fileToString(); // to use with populateGrid()

  int getHeight();

  int getWidth();

private:
  string inFile;

  string outFile;

  int height;

  int width;

};

#endif
