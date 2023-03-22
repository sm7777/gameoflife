#include "gtest/gtest.h"
#include "../src/GameOfLife.h"

TEST(GameOfLifeTest, CanaryTest) {
  EXPECT_TRUE(true);
}

TEST(GameOfLifeTest, DeadCellNoNeighborsStaysDead){
  ASSERT_EQ(DEAD, GameOfLife::nextState(DEAD, 0));
}

TEST(GameOfLifeTest, DeadCellOneNeighborStaysDead){
  ASSERT_EQ(DEAD, GameOfLife::nextState(DEAD, 1));
}

TEST(GameOfLifeTest, DeadCellTwoNeighborsStaysDead){
  ASSERT_EQ(DEAD, GameOfLife::nextState(DEAD, 2));
}

TEST(GameOfLifeTest, DeadCellFiveNeighborsStaysDead){
  ASSERT_EQ(DEAD, GameOfLife::nextState(DEAD, 5));
}

TEST(GameOfLifeTest, DeadCellsEightNeighborsStaysDead){
  ASSERT_EQ(DEAD, GameOfLife::nextState(DEAD, 8));
}

TEST(GameOfLifeTest, DeadCellThreeNeighborsComesToLife){
  ASSERT_EQ(ALIVE, GameOfLife::nextState(DEAD, 3));
}

TEST(GameOfLifeTest, LiveCellWithOneLiveNeighborDies){
  ASSERT_EQ(DEAD, GameOfLife::nextState(ALIVE, 1));
}

TEST(GameOfLifeTest, LiveCellWithFourLiveNeighborsDies){
  ASSERT_EQ(DEAD, GameOfLife::nextState(ALIVE, 4));
}

TEST(GameOfLifeTest, LiveCellWithEightLiveNeighborsDies){
  ASSERT_EQ(DEAD, GameOfLife::nextState(ALIVE, 8));
}

TEST(GameOfLifeTest, LiveCellWithTwoLiveNeighborsLives){
  ASSERT_EQ(ALIVE, GameOfLife::nextState(ALIVE, 2));
}

TEST(GameOfLifeTest, LiveCellWithThreeLiveNeighborsLives){
  ASSERT_EQ(ALIVE, GameOfLife::nextState(ALIVE, 3));
}

TEST(GameOfLifeTest, cellAtTwoThreeGeneratesEightSignals){
  std::vector<std::tuple<int,int>> testSignals;
  std::tuple<int,int> signalOne = std::make_tuple(1,2);
  testSignals.push_back(signalOne);
  std::tuple<int,int> signalTwo = std::make_tuple(1,3);
  testSignals.push_back(signalTwo);
  std::tuple<int,int> signalThree = std::make_tuple(1,4);
  testSignals.push_back(signalThree);
  std::tuple<int,int> signalFour = std::make_tuple(2,2);
  testSignals.push_back(signalFour);
  std::tuple<int,int> signalFive = std::make_tuple(2,4);
  testSignals.push_back(signalFive);
  std::tuple<int,int> signalSix = std::make_tuple(3,2);
  testSignals.push_back(signalSix);
  std::tuple<int,int> signalSeven = std::make_tuple(3,3);
  testSignals.push_back(signalSeven);
  std::tuple<int,int> signalEight = std::make_tuple(3,4);
  testSignals.push_back(signalEight);

  std::vector<std::tuple<int,int>> signalsCreated;
  signalsCreated = GameOfLife::generateSignalsForACell(std::make_tuple(2,3));
  
  for(int i = 0; i < 8; i++){
    ASSERT_EQ(testSignals[i], signalsCreated[i]);
  }
}

TEST(GameOfLifeTest, cellAtThreeThreeGeneratesEightSignals){
  std::vector<std::tuple<int,int>> testSignals;
  std::tuple<int,int> signalOne = std::make_tuple(2,2);
  testSignals.push_back(signalOne);
  std::tuple<int,int> signalTwo = std::make_tuple(2,3);
  testSignals.push_back(signalTwo);
  std::tuple<int,int> signalThree = std::make_tuple(2,4);
  testSignals.push_back(signalThree);
  std::tuple<int,int> signalFour = std::make_tuple(3,2);
  testSignals.push_back(signalFour);
  std::tuple<int,int> signalFive = std::make_tuple(3,4);
  testSignals.push_back(signalFive);
  std::tuple<int,int> signalSix = std::make_tuple(4,2);
  testSignals.push_back(signalSix);
  std::tuple<int,int> signalSeven = std::make_tuple(4,3);
  testSignals.push_back(signalSeven);
  std::tuple<int,int> signalEight = std::make_tuple(4,4);
  testSignals.push_back(signalEight);

  std::vector<std::tuple<int,int>> signalsCreated;
  signalsCreated = GameOfLife::generateSignalsForACell(std::make_tuple(3,3));
  
  for(int i = 0; i < 8; i++){
    ASSERT_EQ(testSignals[i], signalsCreated[i]);
  }
}

TEST(GameOfLifeTest, cellAtTwoFourGeneratesEightSignals){
  std::vector<std::tuple<int,int>> testSignals;
  std::tuple<int,int> signalOne = std::make_tuple(1,3);
  testSignals.push_back(signalOne);
  std::tuple<int,int> signalTwo = std::make_tuple(1,4);
  testSignals.push_back(signalTwo);
  std::tuple<int,int> signalThree = std::make_tuple(1,5);
  testSignals.push_back(signalThree);
  std::tuple<int,int> signalFour = std::make_tuple(2,3);
  testSignals.push_back(signalFour);
  std::tuple<int,int> signalFive = std::make_tuple(2,5);
  testSignals.push_back(signalFive);
  std::tuple<int,int> signalSix = std::make_tuple(3,3);
  testSignals.push_back(signalSix);
  std::tuple<int,int> signalSeven = std::make_tuple(3,4);
  testSignals.push_back(signalSeven);
  std::tuple<int,int> signalEight = std::make_tuple(3,5);
  testSignals.push_back(signalEight);

  std::vector<std::tuple<int,int>> signalsCreated;
  signalsCreated = GameOfLife::generateSignalsForACell(std::make_tuple(2,4));
  
  for(int i = 0; i < 8; i++){
    ASSERT_EQ(testSignals[i], signalsCreated[i]);
  }
}

TEST(GameOfLifeTest, cellAtZeroZeroGeneratesEightSignals){
  std::vector<std::tuple<int,int>> testSignals;
  std::tuple<int,int> signalOne = std::make_tuple(-1,-1);
  testSignals.push_back(signalOne);
  std::tuple<int,int> signalTwo = std::make_tuple(-1,0);
  testSignals.push_back(signalTwo);
  std::tuple<int,int> signalThree = std::make_tuple(-1,1);
  testSignals.push_back(signalThree);
  std::tuple<int,int> signalFour = std::make_tuple(0,-1);
  testSignals.push_back(signalFour);
  std::tuple<int,int> signalFive = std::make_tuple(0,1);
  testSignals.push_back(signalFive);
  std::tuple<int,int> signalSix = std::make_tuple(1,-1);
  testSignals.push_back(signalSix);
  std::tuple<int,int> signalSeven = std::make_tuple(1,0);
  testSignals.push_back(signalSeven);
  std::tuple<int,int> signalEight = std::make_tuple(1,1);
  testSignals.push_back(signalEight);

  std::vector<std::tuple<int,int>> signalsCreated;
  signalsCreated = GameOfLife::generateSignalsForACell(std::make_tuple(0,0));
  
  for(int i = 0; i < 8; i++){
    ASSERT_EQ(testSignals[i], signalsCreated[i]);
  }
}

TEST(GameOfLifeTest, noPositionReturnsEmptyListInMultiplePositionFunction){
  std::vector<std::tuple<int,int>> multiSignalTestInput;
  std::vector<std::tuple<int,int>> multiSignalTestOutput = GameOfLife::generateSignalsForMultiplePositions(multiSignalTestInput);
  ASSERT_EQ(0, multiSignalTestOutput.size());
}

TEST(GameOfLifeTest, OnePositionReturnsEightInMultiplePositionFunction){
  std::vector<std::tuple<int,int>> multiSignalTestInput;
  std::tuple<int,int> signalOne = std::make_tuple(0,0);
  multiSignalTestInput.push_back(signalOne);
  std::vector<std::tuple<int,int>> multiSignalTestOutput = GameOfLife::generateSignalsForMultiplePositions(multiSignalTestInput);
  ASSERT_EQ(8, multiSignalTestOutput.size());
}

TEST(GameOfLifeTest, TwoPositionsReturnsSixteenInMultiplePositionFunction){
  std::vector<std::tuple<int,int>> multiSignalTestInput;
  std::tuple<int,int> signalOne = std::make_tuple(0,0);
  std::tuple<int,int> signalTwo = std::make_tuple(1,1);
  multiSignalTestInput.push_back(signalOne);
  multiSignalTestInput.push_back(signalTwo);
  std::vector<std::tuple<int,int>> multiSignalTestOutput = GameOfLife::generateSignalsForMultiplePositions(multiSignalTestInput);
  ASSERT_EQ(16, multiSignalTestOutput.size());
}

TEST(GameOfLifeTest, ThreePositionsReturnsTwentyFourInMultiplePositionFunction){
  std::vector<std::tuple<int,int>> multiSignalTestInput;
  std::tuple<int,int> signalOne = std::make_tuple(0,0);
  std::tuple<int,int> signalTwo = std::make_tuple(1,1);
  std::tuple<int,int> signalThree = std::make_tuple(2,2);
  multiSignalTestInput.push_back(signalOne);
  multiSignalTestInput.push_back(signalTwo);
  multiSignalTestInput.push_back(signalThree);
  std::vector<std::tuple<int,int>> multiSignalTestOutput = GameOfLife::generateSignalsForMultiplePositions(multiSignalTestInput);
  ASSERT_EQ(24, multiSignalTestOutput.size());
}

TEST(GameOfLifeTest, givenNoPositionsCountLiveNeighborsReturnsEmptyMap){
  std::vector<std::tuple<int,int>> multipleSignalsTest;
  std::map<std::tuple<int,int>,int> liveNeighborTest;
  liveNeighborTest = GameOfLife::countLiveNeighbors(multipleSignalsTest);
  ASSERT_EQ(0, liveNeighborTest.size());
}

TEST(GameOfLifeTest, givenOnePositionCountLiveNeighborsKeyandValue1){
  std::vector<std::tuple<int,int>> multipleSignalsTest;
  std::tuple<int,int> signalOne = std::make_tuple(1,2);
  multipleSignalsTest.push_back(signalOne);
  std::map<std::tuple<int,int>,int> liveNeighborTest;
  liveNeighborTest = GameOfLife::countLiveNeighbors(multipleSignalsTest);
  ASSERT_EQ(1, liveNeighborTest.at({1,2}));
}

TEST(GameOfLifeTest, givenTwoSamePositionsCountLiveNeighborsValue2){
  std::vector<std::tuple<int,int>> multipleSignalsTest;
  std::tuple<int,int> signalOne = std::make_tuple(1,2);
  std::tuple<int,int> signalTwo = std::make_tuple(1,2);
  multipleSignalsTest.push_back(signalOne);
  multipleSignalsTest.push_back(signalTwo);
  std::map<std::tuple<int,int>,int> liveNeighborTest;
  liveNeighborTest = GameOfLife::countLiveNeighbors(multipleSignalsTest);
  ASSERT_EQ(2, liveNeighborTest.at({1,2}));
}

TEST(GameOfLifeTest, givenThreePositionsTwoSameCountLiveNeighborsMakesTwoKeys){
  std::vector<std::tuple<int,int>> multipleSignalsTest;
  std::tuple<int,int> signalOne = std::make_tuple(1,2);
  std::tuple<int,int> signalTwo = std::make_tuple(3,4);
  multipleSignalsTest.push_back(signalOne);
  multipleSignalsTest.push_back(signalTwo);
  multipleSignalsTest.push_back(signalOne);
  std::map<std::tuple<int,int>,int> liveNeighborTest;
  liveNeighborTest = GameOfLife::countLiveNeighbors(multipleSignalsTest);

  ASSERT_EQ(2, liveNeighborTest.size());
  ASSERT_EQ(2, liveNeighborTest.at({1, 2}));
  ASSERT_EQ(1, liveNeighborTest.at({3, 4}));
}

TEST(GameOfLifeTest, computeNextGenReturnsBlockGivenBlock){
  std::vector<std::tuple<int, int>> blockCellPositions;
  std::tuple<int, int> signalOne = std::make_tuple(1,1);
  std::tuple<int, int> signalTwo = std::make_tuple(1,2);
  std::tuple<int, int> signalThree = std::make_tuple(2,1);
  std::tuple<int, int> signalFour = std::make_tuple(2,2);
  blockCellPositions.push_back(signalOne);
  blockCellPositions.push_back(signalTwo);
  blockCellPositions.push_back(signalThree);
  blockCellPositions.push_back(signalFour);
  std::vector<std::tuple<int, int>> returnCells;
  returnCells = GameOfLife::computeNextGeneration(blockCellPositions);
  
  for(int i = 0; i < blockCellPositions.size(); i++){
    ASSERT_EQ(blockCellPositions[i], returnCells[i]);
  }
}

TEST(GameOfLifeTest, computeNextGenReturnsBeeHiveGivenBeeHive){
  std::vector<std::tuple<int, int>> BeeHiveCellPositions;
  std::tuple<int, int> signalOne = std::make_tuple(1,1);
  std::tuple<int, int> signalTwo = std::make_tuple(1,2);
  std::tuple<int, int> signalThree = std::make_tuple(2,0);
  std::tuple<int, int> signalFour = std::make_tuple(2,3);
  std::tuple<int, int> signalFive = std::make_tuple(3,1);
  std::tuple<int, int> signalSix = std::make_tuple(3,2);
  BeeHiveCellPositions.push_back(signalOne);
  BeeHiveCellPositions.push_back(signalTwo);
  BeeHiveCellPositions.push_back(signalThree);
  BeeHiveCellPositions.push_back(signalFour);
  BeeHiveCellPositions.push_back(signalFive);
  BeeHiveCellPositions.push_back(signalSix);
  std::vector<std::tuple<int, int>> returnCells;
  returnCells = GameOfLife::computeNextGeneration(BeeHiveCellPositions);
  
  for(int i = 0; i < BeeHiveCellPositions.size(); i++){
    ASSERT_EQ(BeeHiveCellPositions[i], returnCells[i]);
  }

}

TEST(GameOfLifeTest, computeNextGenReturnsVertGivenHor){
  std::vector<std::tuple<int, int>> HorizontalCellPositions;
  std::tuple<int, int> signalOne = std::make_tuple(1,1);
  std::tuple<int, int> signalTwo = std::make_tuple(1,2);
  std::tuple<int, int> signalThree = std::make_tuple(1,3);
  HorizontalCellPositions.push_back(signalOne);
  HorizontalCellPositions.push_back(signalTwo);
  HorizontalCellPositions.push_back(signalThree);
  std::vector<std::tuple<int, int>> returnCells;
  returnCells = GameOfLife::computeNextGeneration(HorizontalCellPositions);
  std::tuple<int, int> expectedCellOne = std::make_tuple(1,2);
  std::tuple<int, int> expectedCellTwo = std::make_tuple(0,2);
  std::tuple<int, int> expectedCellThree = std::make_tuple(2,2);

  ASSERT_EQ(expectedCellOne, returnCells[0]);
  ASSERT_EQ(expectedCellTwo, returnCells[1]);
  ASSERT_EQ(expectedCellThree, returnCells[2]);
  
}

TEST(GameOfLifeTest, computeNextGenReturnsHorGivenVert){
  std::vector<std::tuple<int, int>> VerticalCellPositions;
  std::tuple<int, int> signalOne = std::make_tuple(1,1);
  std::tuple<int, int> signalTwo = std::make_tuple(2,1);
  std::tuple<int, int> signalThree = std::make_tuple(3,1);
  VerticalCellPositions.push_back(signalOne);
  VerticalCellPositions.push_back(signalTwo);
  VerticalCellPositions.push_back(signalThree);
  std::vector<std::tuple<int, int>> returnCells;
  returnCells = GameOfLife::computeNextGeneration(VerticalCellPositions);
  std::tuple<int, int> expectedCellOne = std::make_tuple(2,1);
  std::tuple<int, int> expectedCellTwo = std::make_tuple(2,0);
  std::tuple<int, int> expectedCellThree = std::make_tuple(2,2);

  ASSERT_EQ(expectedCellOne, returnCells[0]);
  ASSERT_EQ(expectedCellTwo, returnCells[1]);
  ASSERT_EQ(expectedCellThree, returnCells[2]);
  
}

TEST(GameOfLifeTest, computeNextGenReturnsNewGlider){
  std::vector<std::tuple<int, int>> GliderCellPositions;
  std::tuple<int, int> signalOne = std::make_tuple(1,2);
  std::tuple<int, int> signalTwo = std::make_tuple(2,3);
  std::tuple<int, int> signalThree = std::make_tuple(3,1);
  std::tuple<int, int> signalFour = std::make_tuple(3,2);
  std::tuple<int, int> signalFive = std::make_tuple(3,3);
  GliderCellPositions.push_back(signalOne);
  GliderCellPositions.push_back(signalTwo);
  GliderCellPositions.push_back(signalThree);
  GliderCellPositions.push_back(signalFour);
  GliderCellPositions.push_back(signalFive);
  std::vector<std::tuple<int, int>> returnCells;
  returnCells = GameOfLife::computeNextGeneration(GliderCellPositions);
  std::tuple<int, int> expectedCellOne = std::make_tuple(2,3);
  std::tuple<int, int> expectedCellTwo = std::make_tuple(3,2);
  std::tuple<int, int> expectedCellThree = std::make_tuple(3,3);
  std::tuple<int, int> expectedCellFour = std::make_tuple(2,1);
  std::tuple<int, int> expectedCellFive = std::make_tuple(4,2);

  ASSERT_EQ(expectedCellOne, returnCells[0]);
  ASSERT_EQ(expectedCellTwo, returnCells[1]);
  ASSERT_EQ(expectedCellThree, returnCells[2]);
  ASSERT_EQ(expectedCellFour, returnCells[3]);
  ASSERT_EQ(expectedCellFive, returnCells[4]);
  
}

TEST(GameOfLifeTest, inputLGetBlockyShape){
  std::vector<std::tuple<int, int>> LPositions;
  std::tuple<int, int> signalOne = std::make_tuple(1,1);
  std::tuple<int, int> signalTwo = std::make_tuple(2,1);
  std::tuple<int, int> signalThree = std::make_tuple(3,1);
  std::tuple<int, int> signalFour = std::make_tuple(4,1);
  std::tuple<int, int> signalFive = std::make_tuple(4,2);
  std::tuple<int, int> signalSix = std::make_tuple(4,3);
  std::tuple<int, int> signalSeven = std::make_tuple(4,4);
  LPositions.push_back(signalOne);
  LPositions.push_back(signalTwo);
  LPositions.push_back(signalThree);
  LPositions.push_back(signalFour);
  LPositions.push_back(signalFive);
  LPositions.push_back(signalSix);
  LPositions.push_back(signalSeven);
  std::vector<std::tuple<int, int>> returnCells;
  returnCells = GameOfLife::computeNextGeneration(LPositions);
  ASSERT_EQ(11, returnCells.size());

}


TEST(GameOfLifeTest, getsBoundsReturnsZeroZeroHundrendHundredWithEmptyList){
  std::vector<std::tuple<int, int>> TestliveCells;
  std::tuple<std::tuple<int, int>, std::tuple<int, int>> Testbounds = GameOfLife::getBounds(TestliveCells);
  std::tuple<int, int> expectedMin = std::make_tuple(0, 0);
  std::tuple<int, int> expectedMax = std::make_tuple(100, 100);

  ASSERT_EQ(expectedMin, std::get<0>(Testbounds));
  ASSERT_EQ(expectedMax, std::get<1>(Testbounds));
}

TEST(GameOfLifeTest, getsBoundsReturnsCorrectBoundsForOnePoint){
  std::vector<std::tuple<int, int>> TestliveCells;
  std::tuple<int, int> testPoint = std::make_tuple(0, 0);
  TestliveCells.push_back(testPoint);
  std::tuple<std::tuple<int, int>, std::tuple<int, int>> Testbounds = GameOfLife::getBounds(TestliveCells);
  std::tuple<int, int> expectedMin = std::make_tuple(-10, -10);
  std::tuple<int, int> expectedMax = std::make_tuple(10, 10);

  ASSERT_EQ(expectedMin, std::get<0>(Testbounds));
  ASSERT_EQ(expectedMax, std::get<1>(Testbounds));
}

TEST(GameOfLifeTest, getsBoundsReturnsCorrectBoundsForTwoPoints){
  std::vector<std::tuple<int, int>> TestliveCells;
  std::tuple<int, int> testPointOne = std::make_tuple(14, 7);
  std::tuple<int, int> testPointTwo = std::make_tuple(11, 32);
  TestliveCells.push_back(testPointOne);
  TestliveCells.push_back(testPointTwo);

  std::tuple<std::tuple<int, int>, std::tuple<int, int>> Testbounds = GameOfLife::getBounds(TestliveCells);
  std::tuple<int, int> expectedMin = std::make_tuple(1, -3);
  std::tuple<int, int> expectedMax = std::make_tuple(24, 42);

  ASSERT_EQ(expectedMin, std::get<0>(Testbounds));
  ASSERT_EQ(expectedMax, std::get<1>(Testbounds));
}

TEST(GameOfLifeTest, getsBoundsReturnsCorrectBoundsForThreePoints){
  std::vector<std::tuple<int, int>> TestliveCells;
  std::tuple<int, int> testPointOne = std::make_tuple(-150, 50);
  std::tuple<int, int> testPointTwo = std::make_tuple(25, 1000);
  std::tuple<int, int> testPointThree = std::make_tuple(0, 5);
  TestliveCells.push_back(testPointOne);
  TestliveCells.push_back(testPointTwo);
  TestliveCells.push_back(testPointThree);
  std::tuple<std::tuple<int, int>, std::tuple<int, int>> Testbounds = GameOfLife::getBounds(TestliveCells);
  std::tuple<int, int> expectedMin = std::make_tuple(-160, -5);
  std::tuple<int, int> expectedMax = std::make_tuple(35, 1010);

  ASSERT_EQ(expectedMin, std::get<0>(Testbounds));
  ASSERT_EQ(expectedMax, std::get<1>(Testbounds));
}

TEST(GameOfLifeTest, getsBoundsReturnsCorrectBoundsForFourPoints){
  std::vector<std::tuple<int, int>> TestliveCells;
  std::tuple<int, int> testPointOne = std::make_tuple(-10789, 10230);
  std::tuple<int, int> testPointTwo = std::make_tuple(1, -1);
  std::tuple<int, int> testPointThree = std::make_tuple(-492931, 232992);
  std::tuple<int, int> testPointFour = std::make_tuple(-100, 56);
  TestliveCells.push_back(testPointOne);
  TestliveCells.push_back(testPointTwo);
  TestliveCells.push_back(testPointThree);
  TestliveCells.push_back(testPointFour);
  std::tuple<std::tuple<int, int>, std::tuple<int, int>> Testbounds = GameOfLife::getBounds(TestliveCells);
  std::tuple<int, int> expectedMin = std::make_tuple(-492941, -11);
  std::tuple<int, int> expectedMax = std::make_tuple(11, 233002);

  ASSERT_EQ(expectedMin, std::get<0>(Testbounds));
  ASSERT_EQ(expectedMax, std::get<1>(Testbounds));
}
