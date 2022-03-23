#include "FileProcessor.h"

FileProcessor::FileProcessor(){

}

string FileProcessor::fileToString(){
  string readFile;

  string fileContents = "";

  string line;

  int lineCt = 0;

  cout << "What is the name of the file you would like to read from?" << endl;
  cin >> readFile;

  ifstream inFile;

  inFile.open(readFile);

  if (!inFile){
    cout << "file not found" << endl;
    exit(1);
  }

  while(getline(inFile, line)){

    if (lineCt == 0){
      stringstream ss(line);
      ss >> height;
    }

    else if (lineCt == 1){
      stringstream ss(line);
      ss >> width;
    }

    else if (lineCt > 1){

      line.erase(line.length()-1);

      fileContents += line;

    }
    lineCt++;
  }

  inFile.close();

  return fileContents;
}


int FileProcessor::getWidth(){
  return width;
}

int FileProcessor::getHeight(){
  return height;
}
