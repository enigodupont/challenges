#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

unsigned long long dynFactorial(unsigned long long num, vector<unsigned long long> *fs){

  //Base Case
  if(num == 0){
    return 1;
  }

  //Populate current slot if not done.
  if(fs->at(num-1) == 0){
    fs->at(num-1) = dynFactorial(num - 1,fs) * num;
    return fs->at(num-1);
  }else{
    return fs->at(num-1);
  }


}

int main(int argc, char** argv){

  if(argc != 2){
    cerr << "Usage: " << argv[0] << " <number> "<< endl;
    return -1;
  }

  unsigned long long num = strtoul(argv[1],NULL,0);
  vector<unsigned long long> factStorage;
  for(unsigned long long i = 0; i < num; i++){
    factStorage.push_back(0);
  }

  cout << "The factorial of " << num << " is " << dynFactorial(num,&factStorage) << endl;


  return 0;
}
