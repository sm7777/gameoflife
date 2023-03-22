#pragma once
#include <vector>
#include <tuple>
#include <map>
#include <queue>

enum CellState{DEAD, ALIVE};

class GameOfLife{
public:
  static int nextState(CellState currentState, int numberOfLiveNeighbors);
  static std::vector<std::tuple<int, int>> generateSignalsForACell(std::tuple<int, int> cellPosition);
  static std::vector<std::tuple<int, int>> generateSignalsForMultiplePositions(std::vector<std::tuple<int, int>> liveCells);
  static std::map<std::tuple<int, int>, int> countLiveNeighbors(std::vector<std::tuple<int, int>> signals);
  static std::vector<std::tuple<int, int>> computeNextGeneration(std::vector<std::tuple<int, int>> liveCells);
  static std::tuple<std::tuple<int, int>, std::tuple<int, int>> getBounds(std::vector<std::tuple<int, int>> liveCells);
};