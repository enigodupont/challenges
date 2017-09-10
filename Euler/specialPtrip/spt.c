#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPyth( unsigned long a,  unsigned long b,  unsigned long c){

  return ((a*a) + (b*b)) == (c*c); 
}

int main( int argc, char** argv){

  unsigned long limit = 1000;

  for( unsigned long a = 1; a < limit; a++){
    for( unsigned long b = 1; ((a + b) < limit); b++){
      for( unsigned long c = 1; ((a + b + c) <= limit); c++){
        if(isPyth(a,b,c) && ((a + b + c) == limit)){
          printf("The product of an abc that meets the standard is %lu\n",a*b*c);
          return 1;
        }
        printf("%lu + %lu + %lu does not equal 100 or isn't a triple\n",a,b,c);
      }
    }
  }

  return 0;
}
