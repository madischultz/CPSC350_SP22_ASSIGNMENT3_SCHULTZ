#include "Mirror.h"

Mirror::Mirror(){

}

int Mirror::numNeighbors(int w, int h, Grid *g){
  int numNeighbors = 0;

  int wEdge = g->getWidth() - 1;
  int hEdge = g->getHeight() - 1;

  if (w == 0 && h == 0 && g->currentGrid[0][0] == 'X'){
    numNeighbors += 3;
  }

  if (w == 0 && h == hEdge && g->currentGrid[0][hEdge] == 'X'){
    numNeighbors += 3;
  }

  if (w == wEdge && h == 0 && g->currentGrid[wEdge][0] == 'X'){
    numNeighbors += 3;
  }

  if (w == wEdge && h == hEdge && g->currentGrid[wEdge][hEdge] == 'X'){
    numNeighbors += 3;
  }

  if (w == 0 || w == wEdge){
    if (h != 0 && h != hEdge){

      if (g->currentGrid[w][h] == 'X'){
        numNeighbors++;
      }
    }

      // if (g->currentGrid[w][h - 1] == 'X'){
      //   numNeighbors += 1;
      // } //REFLECTION (should get counted again in classic)

      // if (g->currentGrid[w][h + 1] == 'X'){
      //   numNeighbors += 1;
      // } //REFLECTION (should get counted again in classic)

  }

  if (h == 0 || h == hEdge){
    if (w != 0 && w != wEdge){
      if (g->currentGrid[w][h] == 'X'){
        numNeighbors++;
      }
    }
  }

  // if (h == 0 || h == hEdge){
  //
  //   if (w != 0 && w != wEdge){
  //
  //     if (g->currentGrid[w][h] == 'X'){
  //       numNeighbors++;
  //     }
  //
  //     // if (g->currentGrid[w - 1][h] == 'X'){
  //     //   numNeighbors++;
  //     // } //REFLECTION (should get counted again in classic)
  //
  //     // if (g->currentGrid[w + 1][h] == 'X'){
  //     //   numNeighbors++;
  //     // } //REFLECTION (should get counted again in classic)
  //   }
  // }

  // REGULAR/CLASSIC NEIGHBORS

  if (w > 0 && h > 0 && g->currentGrid[w - 1][h - 1] == 'X'){
    numNeighbors++;
  }

  if (h > 0 && g->currentGrid[w][h - 1] == 'X'){
    numNeighbors++;
    if (w == 0 || w == wEdge){
      numNeighbors++;
    }
  }

  if (w < wEdge && h > 0 && g->currentGrid[w + 1][h - 1] == 'X'){
    numNeighbors++;
  }

  if (w > 0 && g->currentGrid[w - 1][h] == 'X' ){
    numNeighbors++; //itself
    if (h == 0 || h == hEdge){
      numNeighbors++; //reflection
    }
  }

  if (w < wEdge && g->currentGrid[w + 1][h] == 'X' ){
    numNeighbors++; //itself
    if (h == 0 || h == hEdge){
      numNeighbors++; //reflection
    }
  }

  if (w > 0 && h < hEdge && g->currentGrid[w - 1][h + 1] == 'X' ){
    numNeighbors++;
  }

  if (h < hEdge && g->currentGrid[w][h + 1] == 'X' ){
    numNeighbors++;
    if (w == 0 || w == wEdge){
      numNeighbors++;
    }
  }

  if (w < wEdge && h < hEdge && g->currentGrid[w + 1][h + 1] == 'X' ){
    numNeighbors++;
  }
  // cout << "[" << w << "]" << "[" << h << "] " << numNeighbors << endl;
  return numNeighbors;
}


char Mirror::nextState(int w, int h, Grid* g){

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

void Mirror::nextGen(Grid *g){

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

void Mirror::playMirror(Grid *g, bool enter){
  Mode m = Mode();

  if (enter == true){
    m.print(g);

    while (true){
      m.print(g);

      m.enter();

      nextGen(g); //gets the next generations until they are empty or stable

      if (g->isEmpty()){ //checks to make sure grid isn't empty
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
        cout << "Goodbye" << endl;
      }
    }
  }
}

void Mirror::playMirror(Grid* g, string filename){

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
