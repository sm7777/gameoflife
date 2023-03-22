#include "GameOfLife.h"

int GameOfLife::nextState(CellState currentState, int numberOfLiveNeighbors){ 
  return numberOfLiveNeighbors == 3 || currentState == ALIVE && numberOfLiveNeighbors == 2 ? ALIVE : DEAD;
}

std::vector<std::tuple<int, int>> GameOfLife::generateSignalsForACell(std::tuple<int, int> cellPosition){

  std::vector<std::tuple<int, int>> signalVector;

  int iStart = std::get<0>(cellPosition) - 1;
  int iEnd = std::get<0>(cellPosition) + 1;
  int jStart = std::get<1>(cellPosition) - 1;
  int jEnd = std::get<1>(cellPosition) + 1;

  for(int i = iStart; i <= iEnd; i++){
    for(int j = jStart; j <= jEnd; j++){
      if(i == std::get<0>(cellPosition) && j == std::get<1>(cellPosition)){
        continue;
      }
      
      std::tuple<int, int> newSignal = std::make_tuple(i, j); 
      signalVector.push_back(newSignal);
    }
  }

  return signalVector;
}

std::vector<std::tuple<int, int>> GameOfLife::generateSignalsForMultiplePositions(std::vector<std::tuple<int, int>> liveCells){
  
  std::vector<std::tuple<int, int>> signals;
  
  for(int i = 0; i < liveCells.size(); i++){
    std::vector<std::tuple<int, int>> signalsForCurrentPosition = generateSignalsForACell(liveCells[i]);
    signals.insert(signals.end(), signalsForCurrentPosition.begin(), signalsForCurrentPosition.end());
  }

  return signals;
}

std::map<std::tuple<int, int>, int> GameOfLife::countLiveNeighbors(std::vector<std::tuple<int, int>> signals){
  
  std::map<std::tuple<int, int>, int> liveNeighborMap;

  for(int i = 0; i < signals.size(); i++){
    if(liveNeighborMap.find({signals[i]}) == liveNeighborMap.end())
      liveNeighborMap.insert({signals[i], 1});
    else
      liveNeighborMap.at({signals[i]})++;
  }
  
  return liveNeighborMap;
}

std::vector<std::tuple<int, int>> GameOfLife::computeNextGeneration(std::vector<std::tuple<int, int>> liveCells){
  
  std::vector<std::tuple<int, int>> nextGeneration;
  std::vector<std::tuple<int, int>> signals = GameOfLife::generateSignalsForMultiplePositions(liveCells);
  std::map<std::tuple<int, int>, int> liveNeighborMap = GameOfLife::countLiveNeighbors(signals);
  int nextCellState;

  for(int i = 0; i < liveCells.size(); i++){
    if(liveNeighborMap.find({liveCells[i]}) != liveNeighborMap.end()){
      nextCellState = GameOfLife::nextState(ALIVE, liveNeighborMap.at({liveCells[i]}));
    }
    if(nextCellState == ALIVE){
      nextGeneration.push_back(liveCells[i]);
    }
    liveNeighborMap.erase({liveCells[i]});
  }

  for(auto itr = liveNeighborMap.begin(); itr !=liveNeighborMap.end(); itr++){
    nextCellState = GameOfLife::nextState(DEAD, itr->second);
    if(nextCellState == ALIVE){
      nextGeneration.push_back(itr->first);
    }
  }

  return nextGeneration;  
}


std::tuple<std::tuple<int, int>, std::tuple<int, int>> GameOfLife::getBounds(std::vector<std::tuple<int, int>> liveCells){


  std::vector<int> xValuesMax;
  std::vector<int> yValuesMax;
  std::vector<int> xValuesMin;
  std::vector<int> yValuesMin;
  std::tuple<std::tuple<int, int>, std::tuple<int, int>> bounds;

  if(liveCells.size() == 0){
    bounds = std::make_tuple(std::make_tuple(0,0),std::make_tuple(100,100));
  }
  else{

    for(int i = 0; i<liveCells.size(); i++){
      xValuesMax.push_back(std::get<0>(liveCells[i]));
      yValuesMax.push_back(std::get<1>(liveCells[i]));
      xValuesMin.push_back(std::get<0>(liveCells[i]));
      yValuesMin.push_back(std::get<1>(liveCells[i]));
    }

      std::make_heap(xValuesMax.begin(), xValuesMax.end());
      std::make_heap(yValuesMax.begin(), yValuesMax.end());
      int xMaxBoundary = xValuesMax.front() + 10;
      int yMaxBoundary = yValuesMax.front() + 10;
      std::make_heap(xValuesMin.begin(), xValuesMin.end(), std::greater<int>{});
      std::make_heap(yValuesMin.begin(), yValuesMin.end(), std::greater<int>{});
      int xMinBoundary = xValuesMin.front() - 10;
      int yMinBoundary = yValuesMin.front() - 10;

      bounds = std::make_tuple(std::make_tuple(xMinBoundary,yMinBoundary),std::make_tuple(xMaxBoundary,yMaxBoundary));
  }

  return bounds;
}