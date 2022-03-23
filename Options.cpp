#include "Options.h"

Options::Options(){

  cout << "Welcome to Game of Life" << endl;

  char boardType;
  char gameMode;
  char output;

  cout << "Would you like to use a random configuration or a flat-file? Enter 'R' or 'F'" << endl;
  cin >> boardType;
  boardType = toupper(boardType);

  cout << "What game mode would you like to play? Enter 'C' for classic, 'M' for mirror, and 'D' for doughnut" << endl;
  cin >> gameMode;
  gameMode = toupper(gameMode);

  cout << "Where would you like the generations to output? Enter 'E' to press enter between generations on the console, 'P' to see a pause between generations on the console, or 'F' for a file" << endl;
  cin >> output;
  output = toupper(output);


  if (boardType == 'R'){
    Mode m = Mode();

    int w;
    int h;
    float f;
    cout << "What dimension would you like the board to be? Enter an integer for the width" << endl;
    cin >> w;

    cout << "What dimension would you like the board to be? Enter an integer for the height" << endl;
    cin >> h;

    cout << "Enter a decimal representing the population density for the board" << endl;
    cin >> f;

    if (f > 1 || f < 0){
      cout << "Not a valid density" << endl;
      exit(1);
    }

    Grid* game = new Grid(w,h);

    game->populateGrid(f);

    if (gameMode == 'C'){

      Classic c = Classic();

      if (output == 'P'){

        // m.print(game);

        c.playClassic(game, false);

        game->~Grid();
      }

      else if (output == 'E'){

        c.playClassic(game, true);

        game->~Grid();
      }

      else if (output == 'F'){
        string file;

        cout << "What is the name of the file you would like to print to?" << endl;
        cin >> file;

        c.playClassic(game, file);

        game->~Grid();
      }

      else {
        cout << "Output type not found. Please try again." << endl;
      }
    }

    else if (gameMode == 'D'){

      Doughnut d = Doughnut();

      if (output == 'P'){
        // m.print(game);

        d.playDoughnut(game, false);

        game->~Grid();
      }

      else if (output == 'E'){

        d.playDoughnut(game, true);

        game->~Grid();
      }

      else if (output == 'F'){
        string file;

        cout << "What is the name of the file you would like to print to?" << endl;
        cin >> file;

        d.playDoughnut(game, file);
        game->~Grid();
      }

      else {
        cout << "Output type not found. Please try again." << endl;
      }
    }

    else if (gameMode == 'M'){

      Mirror mir = Mirror();

      if (output == 'P'){

        mir.playMirror(game, false);

        game->~Grid();
      }

      else if (output == 'E'){

        mir.playMirror(game, true);

        game->~Grid();
      }

      else if (output == 'F'){
        string file;

        cout << "What is the name of the file you would like to print to?" << endl;
        cin >> file;

        mir.playMirror(game, file);
        game->~Grid();
      }

      else {
        cout << "Output type not found. Please try again." << endl;
      }
    }

    else {
      cout << "Game mode not found. Please try again." << endl;
    }
  }

  else if (boardType == 'F'){

    Mode m = Mode();

    FileProcessor fp = FileProcessor();

    string fileBoard = fp.fileToString();

    Grid* game = new Grid(fp.getWidth(), fp.getHeight());

    game->populateGrid(fileBoard);

    if (gameMode == 'C'){

      Classic c = Classic();

      if (output == 'P'){

        c.playClassic(game, false);

        game->~Grid();
      }

      else if (output == 'E'){

        c.playClassic(game, true);

        game->~Grid();
      }


      else if (output == 'F'){
        string file;

        cout << "What is the name of the file you would like to print to? " << endl;
        cin >> file;

        c.playClassic(game, file);

        game->~Grid();
      }

      else {
        cout << "Output type not found. Please try again." << endl;
      }
    }

    else if (gameMode == 'D'){

      Doughnut d = Doughnut();

      if (output == 'P'){

        d.playDoughnut(game, false);

        game->~Grid();
      }

      else if (output == 'E'){

        d.playDoughnut(game, true);

        game->~Grid();
      }

      else if (output == 'F'){
        string file;

        cout << "What is the name of the file you would like to print to? " << endl;
        cin >> file;

        d.playDoughnut(game, file);
        game->~Grid();
      }

      else {
        cout << "Output type not found. Please try again." << endl;
      }
    }

    else if (gameMode == 'M'){

      Mirror mir = Mirror();

      if (output == 'P'){

        mir.playMirror(game, false);

        game->~Grid();
      }

      else if (output == 'E'){

        mir.playMirror(game, true);

        game->~Grid();
      }

      else if (output == 'F'){
        string file;

        cout << "What is the name of the file you would like to print to? " << endl;
        cin >> file;

        mir.playMirror(game, file);

        game->~Grid();
      }

      else {
        cout << "Output type not found. Please try again." << endl;
      }
    }

    else {
      cout << "Game mode not found. Please try again." << endl;
    }
  }

  else {
    cout << "Board type not found. Try Again." << endl;
  }
}
