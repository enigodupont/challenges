#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;


enum nextPath {DOWN = 0, RIGHT = 1, DONE = 2};

class curSpot{
  public:
    
    curSpot(int xC, int yC){
      next = DOWN;
      x = xC;
      y = yC;
    }

    nextPath next;
    int x;
    int y;
};
int main(int argc, char** argv){

  int GRIDSIZE = 20;
  if(argc == 2){
   GRIDSIZE = atoi(argv[1]); 
  }

  int numPaths = 0;
  stack<curSpot> pathStack;
  pathStack.push(curSpot(0,0));

  while(!pathStack.empty()){

    curSpot* cur = &(pathStack.top());
    cout << "Current Spot (" << cur->x << "," << cur->y << ")" << endl; 
    if(cur->next == DOWN){
     
      if(cur->y == GRIDSIZE && cur->x == GRIDSIZE){
        numPaths++;
        pathStack.pop();
        continue;
      }else if(cur->y + 1 > GRIDSIZE){
        cur->next = RIGHT;
        continue;
      }else{
        cur->next = RIGHT;
        pathStack.push(curSpot(cur->x,cur->y + 1));
      }

    }else if(cur->next == RIGHT){
      if(cur->y == GRIDSIZE && cur->x == GRIDSIZE){
        numPaths++;
        pathStack.pop();
        continue;
      }else if(cur->x + 1 > GRIDSIZE){
        pathStack.pop();
        continue;
      }else{
        cur->next = DONE;
        pathStack.push(curSpot(cur->x + 1,cur->y));
      }
    }else{
      pathStack.pop();
    }

  }

  cout << "There were " << numPaths << " available!" << endl;

  return 0;
}
