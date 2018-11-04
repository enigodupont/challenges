#include <stdio.h>
#include <stdlib.h>

typedef struct pathNode pathNode;

void printTriangle(int** tri, int level){
  printf("There are %d levels.\n",level);
  for(int i = level - 1; i >= 0 ; i--){
    for(int x = 0; x <= i; x++){
      printf(" %d",tri[i][x]);
    }
    printf("\n");
  }
}

int main(int argc,char** argv){

  if(argc != 2){
    fprintf(stderr,"Usage: %s <fileName>\n",argv[0]);
    return -1;
  }

  FILE* fp = fopen(argv[1],"r");
  if(fp == NULL){
    fprintf(stderr, "Bad Filename: %s\n",argv[1]);
    return -1;
  }

  int curNum, numCount = 0, **nodeArray = malloc(sizeof(int*)*100), level = 0;
    

  while(fscanf(fp,"%d",&curNum) == 1){
  
    if(nodeArray[level] == NULL){
      nodeArray[level] = malloc(sizeof(int*)*(level+1));
    }

    nodeArray[level][numCount] = curNum;
    numCount++;

    if((level+1) == numCount){
      level++;
      numCount = 0;
    }

  }
  printTriangle(nodeArray,level);

  for(int i = level - 2; i >= 0 ; i--){
    for(int x = 0; x <= i; x++){
      int num1 = nodeArray[i][x] + nodeArray[i+1][x];
      int num2 = nodeArray[i][x] + nodeArray[i+1][x+1];
      printf("Testing level %d, number %d index %d. Sum is between %d or %d.\n",i,nodeArray[i][x],x,num1,num2);
      if(num1 > num2){
        nodeArray[i][x] = num1;
      }else{
        nodeArray[i][x] = num2;
      }     
     printf("We chose %d.\n",nodeArray[i][x]); 
    }
    free(nodeArray[i+1]);
    level--;
    printTriangle(nodeArray,level);
  }
  free(nodeArray);
  fclose(fp);
  return 0;

}
