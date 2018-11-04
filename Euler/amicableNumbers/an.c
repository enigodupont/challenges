#include <stdio.h>
#include <math.h>

int divSum(int n){
  
  int res = 1;

  for( int i = 2; i <= sqrt(n); i++){
    if(n % i == 0){
      if(i == (n/i)){
          res += i;
      }else{
          res += (i + n / i);
      }
    }
  }
  return res;
}

int main(){

  int intBuf[10000] = {-1};
  for(int i = 0; i < 10000; i++){
    int sum = divSum(i);
    printf("Sum of divisors for %d is %d.\n",i,sum);
    intBuf[i] = sum;
  }

  printf("----------------------------------------------------------\n");
  int aSum = 0;
  for(int i = 0; i < 10000; i++){
    for(int x = i + 1; x < 10000 - 1; x++){
      if(i == intBuf[x] && i != x && intBuf[i] == x){
          aSum += i + x;
      }
    }
  }
  printf("Sum of all amicable numbers less than 10000 is %d.\n",aSum);
  return 0;
}
