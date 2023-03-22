#include "GameOfLife.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <unistd.h>

void printDeadCell(){
    std::cout << "-";
}
void printLiveCell(){
    std::cout << "*";
}

std::map<std::tuple<int, int>, int> currentLiveCells(std::vector<std::tuple<int, int>> liveCells){
  std::map<std::tuple<int, int>, int> liveCellMap;

  for(int i = 0; i < liveCells.size(); i++){
    liveCellMap.insert({liveCells[i], ALIVE});
  }
  return liveCellMap;
}

std::vector<std::tuple<int, int>> readCoordinatesFromFile(std::string inputFile){

  std::ifstream inFile;
  
  std::vector<std::tuple<int, int>> initialLiveCells;
  
  inFile.open(inputFile);
  
  if(!inFile.is_open())
    std::cout << "File Not Found" << std::endl;
  
  std::string line;
  std::vector<std::string> coordinateVector;
  do{
    getline(inFile, line);
    if(line != "")
      coordinateVector.push_back(line);
  }while(!inFile.eof());

  std::string xString;
  std::string yString;
  bool delimiter = false;

  for(int i = 0; i < coordinateVector.size(); i++){
    for(int j = 0; j < coordinateVector[i].length(); j++){
      if(coordinateVector[i][j] ==  ','){
          delimiter = true;
          continue;
      }
      if(delimiter == false)
        xString = xString + coordinateVector[i][j];
      else
        yString = yString + coordinateVector[i][j];
    }
    delimiter = false;
    int x = std::stoi(xString);
    int y = std::stoi(yString);
    initialLiveCells.push_back(std::make_tuple(x,y));
    xString = "";
    yString = "";
  }

  inFile.close();
  
  return initialLiveCells;
  
}

int main(int argc, char *argv[]){

    std::string coordinateFile(argv[1]);
    std::vector<std::tuple<int, int>> liveCells = readCoordinatesFromFile(coordinateFile);

    while(true){

      std::cout << "\033[2J\033[1;1H";
      std::cout << std::flush;

      std::tuple<std::tuple<int, int>, std::tuple<int, int>> bounds = GameOfLife::getBounds(liveCells);;
      int xmin = std::get<0>(std::get<0>(bounds));
      int xmax = std::get<0>(std::get<1>(bounds));
      int ymin = std::get<1>(std::get<0>(bounds));
      int ymax = std::get<1>(std::get<1>(bounds));

      std::map<std::tuple<int, int>, int> liveCellMap = currentLiveCells(liveCells);

      for(int i = xmin; i <= xmax; i++){
        for(int j = ymin; j <= ymax; j++){
          if(liveCellMap.find({i,j}) != liveCellMap.end()){
            printLiveCell();
          }
          else
            printDeadCell();
        }
        std::cout << std::endl;
      }

      std::vector<std::tuple<int, int>> nextGeneration = GameOfLife::computeNextGeneration(liveCells);
      liveCells.clear();
      liveCellMap.clear();
      liveCells = nextGeneration;
      usleep(500000);
    }      
    
    return 0;
}