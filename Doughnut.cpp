#include "Doughnut.h"

Doughnut::Doughnut(){

}

int Doughnut::numNeighbors(int w, int h, Grid* g){
  // Mode m = Mode();

  int wEdge = g->getWidth() - 1;
  int hEdge = g->getHeight() - 1;

  int numNeighbors = 0;

  if (w == 0 && h == 0){
    //1
    if (g->currentGrid[0][hEdge] == 'X'){
      numNeighbors++;
    }
    //2
    if (g->currentGrid[wEdge][0] == 'X'){
      numNeighbors++;
    }
    //3
    if (g->currentGrid[wEdge][hEdge] == 'X'){
      numNeighbors++;
    }
    //4
    if (g->currentGrid[wEdge][h + 1] == 'X'){
      numNeighbors++;
    }
    //5
    if (g->currentGrid[w + 1][hEdge] == 'X'){
      numNeighbors++;
    }
    //6-8 are captured in classic mode neighbors
  }


  if (w == 0 && h == hEdge){
    //1
    if (g->currentGrid[0][0] == 'X'){
      numNeighbors++;
    }
    //2
    if (g->currentGrid[wEdge][0] == 'X'){
      numNeighbors++;
    }
    //3
    if (g->currentGrid[wEdge][hEdge] == 'X'){
      numNeighbors++;
    }
    //4
    if (g->currentGrid[w + 1][0] == 'X'){
      numNeighbors++;
    }
    //5
    if (g->currentGrid[wEdge][h - 1] == 'X'){
      numNeighbors++;
    }
    // 6-8 in classic mode
  }


  if (w == wEdge && h == 0){
    //1
    if (g->currentGrid[0][0] == 'X'){
      numNeighbors++;
    }
    //2
    if (g->currentGrid[0][hEdge] == 'X'){
      numNeighbors++;
    }
    //3
    if (g->currentGrid[wEdge][hEdge] == 'X'){
      numNeighbors++;
    }
    //4
    if (g->currentGrid[0][h + 1] == 'X'){
      numNeighbors++;
    }
    //5
    if (g->currentGrid[w - 1][hEdge] == 'X'){
      numNeighbors++;
    }
    // 6-8 in classic
  }


  if (w == wEdge && h == hEdge){
    //1
    if (g->currentGrid[0][hEdge] == 'X'){
      numNeighbors++;
    }
    //2
    if (g->currentGrid[wEdge][0] == 'X'){
      numNeighbors++;
    }
    //3
    if (g->currentGrid[0][0] == 'X'){
      numNeighbors++;
    }
    //4
    if (g->currentGrid[0][h - 1] == 'X'){
      numNeighbors++;
    }
    //5
    if (g->currentGrid[w - 1][0] == 'X'){
      numNeighbors++;
    }
    // 6-8 in classic neighbors
  }


  if (w > 0 && w < wEdge && h == 0){
    //1
    if (g->currentGrid[w][hEdge] == 'X'){
      numNeighbors++;
    }
    //2
    if (g->currentGrid[w - 1][hEdge] == 'X'){
      numNeighbors++;
    }
    //3
    if (g->currentGrid[w + 1][hEdge] == 'X'){
      numNeighbors++;
    }
    // 4-8 covered in classic neighbors
  }


  if (w > 0 && w < wEdge && h == hEdge){
    //1
    if (g->currentGrid[w - 1][0] == 'X'){
      numNeighbors++;
    }
    //2
    if (g->currentGrid[w][0] == 'X'){
      numNeighbors++;
    }
    //3
    if (g->currentGrid[w + 1][0] == 'X'){
      numNeighbors++;
    }
    // 4-8 covered in classic neighbors
  }

  if (h > 0 && h < hEdge && w == 0){
    //1
    if (g->currentGrid[wEdge][h - 1] == 'X'){
      numNeighbors++;
    }
    //2
    if (g->currentGrid[wEdge][h] == 'X'){
      numNeighbors++;
    }
    //3
    if (g->currentGrid[wEdge][h + 1] == 'X'){
      numNeighbors++;
    }
    // 4-8 covered classic neighbors
  }

  if (h > 0 && h < hEdge && w == wEdge){
    if (g->currentGrid[0][h - 1] == 'X'){
      numNeighbors++;
    }

    if (g->currentGrid[0][h] == 'X'){
      numNeighbors++;
    }

    if (g->currentGrid[0][h + 1] == 'X'){
      numNeighbors++;
    }
  }

  // Donut Edges Above

  // Classic/Regular Edges Below

  if (w > 0 && h > 0 && g->currentGrid[w - 1][h - 1] == 'X'){
    numNeighbors++;
  }

  if (h > 0 && g->currentGrid[w][h - 1] == 'X'){
    numNeighbors++;
  }

  if (w < wEdge && h > 0 && g->currentGrid[w + 1][h - 1] == 'X'){
    numNeighbors++;
  }

  if (w > 0 && g->currentGrid[w - 1][h] == 'X' ){
    numNeighbors++;
  }

  if (w < wEdge && g->currentGrid[w + 1][h] == 'X' ){
    numNeighbors++;
  }

  if (w > 0 && h < hEdge && g->currentGrid[w - 1][h + 1] == 'X' ){
    numNeighbors++;
  }

  if (h < hEdge && g->currentGrid[w][h + 1] == 'X' ){
    numNeighbors++;
  }

  if (w < wEdge && h < hEdge && g->currentGrid[w + 1][h + 1] == 'X' ){
    numNeighbors++;
  }
  return numNeighbors;
}

char Doughnut::nextState(int w, int h, Grid* g){
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


void Doughnut::nextGen(Grid* g){

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

void Doughnut::playDoughnut(Grid* g, bool enter){
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

void Doughnut::playDoughnut(Grid* g, string filename){

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
