#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(unsigned long num){

  char buf[10];
  snprintf(buf,10,"%lu",num);

  int len = strlen(buf);

  for(int i = 0; i < len; i++){
    if(buf[i] != buf[len - i - 1]){
      return false;
    }
  }
  return true;

}


int main(){
 
  unsigned long maxPal = 0;

  for(int num1 = 999; num1 >= 100; num1--){
    for(int num2 = 999; num2 >= 100; num2--){
     
      unsigned long prod = num1 * num2;

      if(isPalindrome(prod) && prod > maxPal){
        maxPal = prod;
     }
    }
  }

  
  printf("Max Palindrome is %lu\n",maxPal);

  return 0;
}
