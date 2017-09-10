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

  if(argc != 2){
    fprintf(stderr,"Usage: %s <Number>\n",argv[0]);
    return -1;
  }

  unsigned long num = strtoul(argv[1],NULL,10); 
  printf("Testing %lu for largest prime factor\n",num);

  for(unsigned long i = 2; i < num; i++){
//      printf("Testing %lu,mod - %lu, prime - %d\n",i, num % i,isPrime(i));
    if(((num % i) == 0) && isPrime(i)){
      printf("Prime Factor is %lu\n",i);
    }
  }
  
  return 0;
}
