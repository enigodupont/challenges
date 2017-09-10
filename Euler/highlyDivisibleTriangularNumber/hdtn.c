#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int numDivisors(unsigned long num){

  int numDiv = 2;
  int sqrtNum = sqrt(num);
  for(int i = 2; i <= sqrtNum; i++){

    if(num % i == 0) numDiv += 2;

  }

  if(sqrtNum * sqrtNum == num){
    numDiv--;
  }

  return numDiv;

}

int main(){

  unsigned long runningSum = 0;

  for(int curNum = 1; true; curNum++){

     runningSum += curNum;
     int numDiv = numDivisors(runningSum);
     printf("Testing %d, triangle number of %lu, number of divisors is %d\n",curNum,runningSum,numDiv);
     if(numDiv > 500){
      printf("%lu is the first triangle number to have over 500 divisors!\n",runningSum);
      return 1;
    }
  }

  return 0;
}
