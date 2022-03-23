#include "Mode.h"

Mode::Mode(){

}


string Mode::gridToStr(Grid* g){
  int count = 0;
  string board = "";
  for (int i = 0; i < g->getWidth(); ++i){

    for (int j = 0; j < g->getHeight(); ++j){
      board.push_back(g->currentGrid[i][j]);
    }
    board.push_back('\n');
    count++;
  }
  return board;
}


void Mode::print(Grid* g){

  string grid = gridToStr(g);

  cout << "generation " << g->genNum++ << endl;

  cout << grid << endl;
}


void Mode::printToFile(Grid* g, string filename){

  string grid = gridToStr(g);

  ofstream outFile;

  outFile.open(filename, std::ios_base::app); //opens in append mode

  outFile << "generation " << g->genNum++ << endl;

  outFile << grid << endl;

  outFile.close();
}

void Mode::enter(){
  while (true){
    char c = getchar();
    if (c == '\n'){
      break;
    }
  }
}
