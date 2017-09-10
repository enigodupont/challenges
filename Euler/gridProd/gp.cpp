#include <iostream>
#include <fstream>

using namespace std;

const int GRIDSIZE = 20;

unsigned long processGrid(int grid[GRIDSIZE][GRIDSIZE]){

  unsigned long maxProd = 0;
  int chunkSize = 4;
  
  //Check Right & Left
  for(int i = 0; i < GRIDSIZE - chunkSize; i++){
    unsigned long rightProd = 0;
    unsigned long leftProd = 0;
    for(int x = i; x < i + chunkSize; x++){
      rightProd *= grid[i][x];
      leftProd *= grid[i][GRIDSIZE - x - 1];
    }
    if(rightProd > maxProd) maxProd = rightProd;
    if(leftProd > maxProd) maxProd = leftProd;
  }

 //Check Down & Up
   for(int i = 0; i < GRIDSIZE - chunkSize; i++){
    unsigned long downProd = 0;
    unsigned long upProd = 0;
    for(int x = i; x < i + chunkSize; x++){
      downProd *= grid[x][i];
      upProd *= grid[GRIDSIZE - x - 1][i];
    }
    if(downProd > maxProd) maxProd = downProd;
    if(upProd > maxProd) maxProd = upProd;
  }


  //Check Diagnal
  for(int i = chunkSize - 1; i < GRIDSIZE - chunkSize; i++){
    for(int x = chunkSize - 1; x < GRIDSIZE - chunkSize; x++){
      unsigned long upLeft = grid[i][x] * grid[i-1][x-1] * grid[i-2][x-2] * grid[i-3][x-3];
      unsigned long upRight = grid[i][x] * grid[i-1][x+1] * grid[i-2][x+2] * grid[i-3][x+3];
      unsigned long downLeft = grid[i][x] * grid[i+1][x-1] * grid[i+2][x-2] * grid[i+3][x-3];
      unsigned long downRight = grid[i][x] * grid[i+1][x+1] * grid[i+2][x+2] * grid[i+3][x+3];
     
      if(upLeft > maxProd) maxProd = upLeft;
      if(upRight > maxProd) maxProd = upRight;
      if(downLeft > maxProd) maxProd = downLeft;
      if(downRight > maxProd) maxProd = downRight;
    }
  }

  return maxProd;

}

int main(int argc, char** argv){

  if(argc != 2){
    cerr << "Usage: " << argv[0] << " <file> " << endl;
    return -1;
  }

  ifstream iFile;
  iFile.open(argv[1]);

  if(!iFile){
    cerr << "Error: Couldn't open file." << endl;
    return -1;
  }

  int grid[GRIDSIZE][GRIDSIZE];

  for(int i = 0; i < GRIDSIZE; i++){
    for(int x = 0; x < GRIDSIZE; x++){
      iFile >> grid[i][x];
    }
  }

  unsigned long maxProd = processGrid(grid);

  cout << "Maximum Product is " << maxProd << endl;

  return 0;
}
