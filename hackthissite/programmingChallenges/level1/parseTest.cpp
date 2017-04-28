#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string findClosestWord(string word, vector<string>* wordBank);

int main(int argc, char** argv){

  if(argc < 3 ){
    cerr <<  "Usage: " << argv[0] << " <textFile> <words to crack>\n";
    return -1;
  }
  

  vector<string> wordBank;
  ifstream inFile;
  inFile.open(argv[1]);

  if(!inFile){
    cerr << "Could not open " << argv[1] << endl;
    return -1;
  }

  //Read in the bank.
  string curLine;
  while( inFile >> curLine){
    wordBank.push_back(curLine);
  }


  //Compare each extra word to the list
  for(int i = 2; i < argc; i++){
    cout << findClosestWord(argv[i], &wordBank) << ",";
  }

  cout << endl;

  inFile.close();
  return 0;
}

string findClosestWord(string word, vector<string>* wordBank){

  string result = "Not Found";
  vector<string> filterSize;
  for(int i = 0; i < wordBank->size(); ++i){
    if(wordBank->at(i).size() == word.size()){
      filterSize.push_back(wordBank->at(i));
    }
  }

  //Return the only word if one match.
  if(filterSize.size() == 1){

    result = filterSize.at(0);
    return result;
  }

  vector<string> filterChar;
  for(int i = 0; i < filterSize.size(); i++){
    bool toAdd = true;
    for(int x = 0; x < filterSize.at(i).size(); x++){
      if(word.find(filterSize.at(i)[x]) == string::npos){
        toAdd = false;
      }
    }

    if(toAdd){
      filterChar.push_back(filterSize.at(i));
    }
  }

  if(filterChar.size() >= 1){
    result = filterChar.at(0);
  }

  return result;

}
