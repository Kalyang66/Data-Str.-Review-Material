#include <iostream>
#include <string>
#include <map>
#include <fstream>

#include "ArgumentManager.h"

using namespace std;

int main(int argc, char *argv[]){
  ArgumentManager am(argc, argv);

  string input = am.get("input");
  string output = am.get("output");

  ifstream fin(input);
  ofstream fout(output);


  int num;
  string word;

  fin >> num;


  map<string, int> mapping;

  for(int i = 0; i < num; i++){
    fin >> word;

    if(mapping[word] == -1){
      mapping[word] = 1;
    }
    else{
      mapping[word]++;
    }

  }

  for (auto word: mapping){
    fout << word.first << ": " << word.second << endl;
  }

  return 0;
}