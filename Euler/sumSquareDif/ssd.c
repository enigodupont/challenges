#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

  int limit = 100;
  unsigned long sumLimit = 0;
  unsigned long sqrLimit = 0;
  
  for(int i = 0; i <= limit; i++){

    sumLimit += (i*i);
    sqrLimit += i;
  }
  sqrLimit = sqrLimit * sqrLimit;

  printf("Difference of first %d numbers sum (%lu) and sumSquare (%lu) is %lu\n",limit,sumLimit, sqrLimit,sqrLimit - sumLimit);
  return 0;
}
