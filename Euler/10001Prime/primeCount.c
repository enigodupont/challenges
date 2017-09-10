#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(unsigned long num){

  if((num > 3) && ((num % 2 == 0) || (num % 3 == 0)) || (num % 5 == 0)){
    return false;
  }


  for(unsigned long i = 3; i < num; i+=2){
    //printf("----Testing %lu for number %lu\n,",i, num);
    if(num % i == 0 ){
      return false;
    }
  }
  return true;

}

int main(int argc, char** argv){

  int primeCount = 1;

  for(unsigned long i = 2; true; i++){
    if(isPrime(i)){
      primeCount++;
      printf("%lu is prime, we have found %d\n",i,primeCount);
    }
    if(primeCount == 10001){
      printf("The 10001'st prime is %lu\n",i);
      return 1;

    }
  }
  return 0;
}
