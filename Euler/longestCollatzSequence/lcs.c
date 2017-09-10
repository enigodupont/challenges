#include <stdio.h>

int main(){

  unsigned long maxChain = 0;
  unsigned long maxNum = 0;
  for(unsigned long i = 1; i < 1000000; i++){
  
    unsigned long curNum = i;
    unsigned long curChain = 0;
    while(curNum != 1){
  
      if(curNum % 2 == 0){
        curNum = curNum / 2;
        curChain++;
      }else{
        curNum = (curNum * 3) + 1;
        curChain++;
      }
    } 
    printf("Current Chain is %lu for number %lu\n",curChain,i);
    if(curChain > maxChain){
      maxChain = curChain;
      maxNum = i;
    }
  }


  printf("Max Chain is %lu for number %lu\n",maxChain,maxNum);
  return 0;
}
