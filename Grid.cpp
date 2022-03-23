#include "Grid.h"

Grid::Grid(){

}

Grid::Grid(int w, int h){

  width = w;
  height = h;

  currentGrid = new char*[width];

  for (int i = 0; i < width; ++i){
    currentGrid[i] = new char[height];
  }

  newGrid = new char*[width];

  for (int j = 0; j < width; ++j){
    newGrid[j] = new char[height];
  }
}

void Grid::populateGrid(float f){
  genNum = 0;

  int size = width * height;
  int numPop = size * f; //uses density to calc how many sqaures to make alive

  int numEmpty = size - numPop; // calc how many should be empty

  int countPop = 0; // keep track of how many are alive
  int countEmpty = 0; // keep track of how many are empty

  srand(time(0));//makes sure new random value is chosen after each execution of the code

  for (int i = 0; i < width; ++i){

    for (int j = 0; j < height; ++j){

      int picker = rand() % 100;

      if (picker <= 50 && countEmpty < numEmpty){ //make sure count doesn't exceed actual
        currentGrid[i][j] = '-';
        countEmpty++;
      }

      else if (picker <= 0 && countEmpty == numEmpty){ //make sure count doesn't exceed actual
        currentGrid[i][j] = 'X';
        countPop++;
      }

      else if (picker > 1 && countPop < numPop){ //make sure count doesn't exceed actual
        currentGrid[i][j] = 'X';
        countPop++;
      }

      else if (picker > 1 && countPop == numPop){ //make sure count doesn't exceed actual
        currentGrid[i][j] = '-';
        countEmpty++;
      }
    }
  }
}

void Grid::populateGrid(string userMap){

  genNum = 0;

  int curr = 0;

  for (int i = 0; i < width; ++i){

    for (int j = 0; j < height; ++j){ //iterating through all squares of array

      currentGrid[i][j] = userMap[curr]; //allocating character to grid then incrementing

      curr++; // increment
    }
  }
}


bool Grid::isEmpty(){
  int count = 0;
  for (int i = 0; i <width; ++i){
    for (int j = 0; j < height; ++j){
      if (currentGrid[i][j] == 'X'){
        count += 1; //checking if any squares are alive
      }
    }
  }
  if (count > 0){
    return false;
  }

  else {
    cout << "World is empty. Press enter to exit." << endl;
    char c = getchar();
    if (c == '\n'){ //checking if user pressed enter
      exit(1);
    }
    return true; //if wrong key is pushed, but grid is still empty
  }
}

bool Grid::isStable(){
  int count = 0;
  for (int i = 0; i <width; ++i){
    for (int j = 0; j < height; ++j){
      if (currentGrid[i][j] != newGrid[i][j]){
        count += 1; // checking that new gen is different
      }
    }
  }
  if (count > 0){
    return false;
  }

  else {
    cout << "World is stable. Press enter to exit game" << endl;
    char c = getchar();
    if (c == '\n'){
      exit(1);
    }
    return true; // if wrong key is pushed, but grid is still stable
  }
}

int Grid::getWidth(){
  return width;
}

int Grid::getHeight(){
  return height;
}

Grid::~Grid(){
  delete currentGrid;
  delete newGrid;
}
