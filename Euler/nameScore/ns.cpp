#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <cstring>
#include <locale>

using namespace std;

int stringSum(string s){

  int sum = 0;
  for(int i = 0; i < strlen(s.c_str()); i++){
    sum += toupper(s[i]) - 64;
  }
  return sum;
}

int main(int argc, char** argv){

  if(argc != 2){
    cerr << "Usage: " << argv[0] << " <fileName>" << endl;
    return -1;
  }

  ifstream iFile;
  iFile.open(argv[1]);

  if(!iFile){
    cerr << "Bad File: " << argv[1] << endl;
    return -1;
  }

  string curStr;
  vector<string> strings;
  while(getline(iFile,curStr,',')){
    strings.push_back(curStr.substr(1,strlen(curStr.c_str())-2));
  }
  sort(strings.begin(),strings.end());
  unsigned long totalSum = 0;
  for(int i = 0; i < strings.size(); i++){
    int sSum = stringSum(strings[i]);
    unsigned long curProd =  (i+1) * sSum;
    cout << "Index: " << i+1 << " string " << strings[i] << " sum " << sSum << " product " << curProd << endl;
    totalSum += curProd;
  }
  cout << "Total sum of all name scores is " << totalSum << endl;
  return 0;
}
