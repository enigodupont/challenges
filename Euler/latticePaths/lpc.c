#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv){
  int GRIDSIZE = 20;
  if(argc == 2){
    GRIDSIZE = atoi(argv[1]);
  }

  unsigned long paths = 1;
  for(int i = 0; i < GRIDSIZE; i++){
    paths *= (2*GRIDSIZE - i);
    paths /= i + 1;
  }
  printf("The number of paths for a %dx%d square is %lu\n",GRIDSIZE,GRIDSIZE,paths);
}
