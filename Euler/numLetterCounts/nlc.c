#include <stdio.h>
#include <string.h>
int main(){

  char* single[] = {"zero\0","one\0","two\0","three\0","four\0","five\0","six\0","seven\0","eight\0","nine\0"}; 
  char* tenSpec[] = {"ten\0","eleven\0","twelve\0","thirteen\0","fourteen\0","fifteen\0","sixteen\0","seventeen\0","eighteen\0","nineteen\0"};
  char* tens[] = {"twenty\0","thirty\0","forty\0","fifty\0","sixty\0","seventy\0","eighty\0","ninety\0"};
  char* hundred = "hundred\0";
  char* thousand = "thousand\0";

  unsigned long runningCount = 0;
  for(int curNum = 1; curNum <= 1000; curNum++){
    
    char buf[1024];
    memset(buf,'\0',1024);
    int i = curNum;
    while(i != 0){

      if(i < 10){
        strcat(buf,single[i]);
        i -= i;
      }else if(i < 20){
        strcat(buf,tenSpec[i-10]);
        i -= i;
      }else if(i < 100){
        int flatTen = i - (i % 10);
        int num2index = (flatTen/10) - 2;
        strcat(buf,tens[num2index]);
        i -= flatTen;
      }else if(i < 1000){
        int flatHundred = i - (i % 100);
        int numHundreds = i / 100;
        strcat(buf, single[numHundreds]);
        strcat(buf, hundred);
        if(i - flatHundred > 0){
          strcat(buf,"and");
        }
        i -= flatHundred;
      }else if(i < 10000){
        int flatThousand = i - (i % 1000);
        int numThousands = i / 1000;
        strcat(buf, single[numThousands]);
        strcat(buf, thousand);
        i -= flatThousand;
      }else{
        fprintf(stderr,"Bad Number\n");
        return -1;
      }

    }
    runningCount += strlen(buf);
    printf("Number was %d, in char %s, sum of char is %lu\n",curNum,buf,strlen(buf));
  }
  printf("Sum of characters of 1 - 1000 is %lu\n",runningCount);
  return 0;
}
