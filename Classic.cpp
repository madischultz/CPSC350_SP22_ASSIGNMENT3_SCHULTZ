#include "Classic.h"

Classic::Classic(){

}

int Classic::numNeighbors(int w, int h, Grid* g){

  int numNeighbors = 0;

  if (w > 0 && h > 0 && g->currentGrid[w - 1][h - 1] == 'X'){
    numNeighbors++;
  }

  if (h > 0 && g->currentGrid[w][h - 1] == 'X'){
    numNeighbors++;
  }

  if (w < (g->getWidth() - 1) && h > 0 && g->currentGrid[w + 1][h - 1] == 'X'){
    numNeighbors++;
  }
  if (w > 0 && g->currentGrid[w - 1][h] == 'X' ){
    numNeighbors++;
  }
  if (w < g->getWidth() - 1 && g->currentGrid[w + 1][h] == 'X' ){
    numNeighbors++;
  }
  if (w > 0 && h < g->getHeight() - 1 && g->currentGrid[w - 1][h + 1] == 'X' ){
    numNeighbors++;
  }
  if (h < g->getHeight() - 1 && g->currentGrid[w][h + 1] == 'X' ){
    numNeighbors++;
  }
  if (w < g->getWidth() - 1 && h < g->getHeight() - 1 && g->currentGrid[w + 1][h + 1] == 'X' ){
    numNeighbors++;
  }
  return numNeighbors;
}

char Classic::nextState(int w, int h, Grid* g){
  // Mode m = Mode();

  int num = numNeighbors(w, h, g);

  if (num <= 1){
    return '-';
  }

  else if (num == 2){
    return g->currentGrid[w][h];
  }

  else if (num == 3){
    return 'X';
  }

  else if (num >= 4){
    return '-';
  }
}


void Classic::nextGen(Grid* g){

  int width = g->getWidth();
  int height = g->getHeight();

  for (int i = 0; i < width; ++i){
    for (int j = 0; j < height; ++j){
      g->newGrid[i][j] = nextState(i,j,g);
    }
  }

  if (g->isStable()){
    cout << "Goodbye" << endl;
  }

  for (int i = 0; i < width; ++i){ //assigning the next generation (new Grid) to current
    for (int j = 0; j < height; ++j){
      g->currentGrid[i][j] = g->newGrid[i][j];
    }
  }
}


void Classic::playClassic(Grid* g, bool enter){
  Mode m = Mode();

  if (enter == true){
    m.print(g);

    while (true){
      m.print(g);

      m.enter();

      nextGen(g); //gets the next generations until they are empty or stable

      if (g->isEmpty()){
        cout << "Goodbye" << endl;
      }
    }
  }

  else {
    m.print(g);

    while (true){
      m.print(g);

      sleep(1.5); //brief pause

      nextGen(g); //gets the next generations until they are empty or stable

      if (g->isEmpty()){ //checks to make sure grid isn't empty
        cout << "Goodbye" << endl;;
      }
    }
  }
}

void Classic::playClassic(Grid* g, string filename){

  Mode m = Mode();

  m.printToFile(g, filename);

  while (true){
    m.printToFile(g, filename);

    nextGen(g); //gets the next generations until they are empty or stable

    if (g->isEmpty()){ //checks to make sure grid isn't empty
      cout << "Goodbye" << endl;
    }
  }
}
