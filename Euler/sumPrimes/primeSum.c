#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(unsigned long num){

  if(num < 2) return false;
  if( num == 2 || num == 3 || num == 5) return true;

  if(((num % 2 == 0) || (num % 3 == 0)) || (num % 5 == 0)){
    return false;
  }


  unsigned long sqrtNum = sqrt(num) + 1L;

  for(unsigned long i = 6L; i <= sqrtNum; i += 6){
    if( (num % (i-1) == 0) || (num % (i+1) == 0)){
      return false;
    }
  }
  return true;
}

int main(int argc, char** argv){

  unsigned long primeSum = 0;
  unsigned long primeCount = 0;
  unsigned long limit = 2000000;

  for(unsigned long i = 2; i < limit; i++){
    if(isPrime(i)){
      primeCount++;
      primeSum += i;
      printf("Prime Found, Number: %lu, Count: %lu, Sum: %lu\n",i,primeCount,primeSum);
    }
  }
  printf("The sum of %lu primes is %lu\n",limit, primeSum);
  return 0;
}
