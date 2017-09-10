#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

   for(int num = 20; true; num+=2){
    bool isDivisible = true;
    for(int div = 1; div != 20; div++){
      if(num % div != 0){
        isDivisible = false;
        break;
      }
    }
    if(isDivisible){
      printf("Smallest positive number that is divisible of 1-20 is %d\n",num);
      return 1;
    }
   }
  
  return 0;
}
