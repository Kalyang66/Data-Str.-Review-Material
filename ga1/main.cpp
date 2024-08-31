#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include "bar.h"
#include "ArgumentManager.h"
using namespace std;


int main(int argc, char *argv[]){
  ArgumentManager am(argc, argv);
  string input = am.get("input");
  string output = am.get("output");

  ifstream ifs(input); 
  ofstream ofs(output);
  string inputline = ""; 
  bar bar1;
  bar guilty;
  
  while(getline(ifs, inputline)) { //credit to sandy pham for input line parsing code
    inputline.erase(remove(inputline.begin(), inputline.end(), '\n'),
                    inputline.end());
    inputline.erase(remove(inputline.begin(), inputline.end(), '\r'),
                    inputline.end());
    if (inputline.empty()) {

      continue;
    }
    if (inputline == "Bar1" || inputline == "Bar2") {
      
      continue;
    }
     
      string decodedid = bar1.decode(inputline);
      
      bar1.insertAtTail(decodedid); 
} 
  bar1.sort();
  string dupe;
  cout<< bar1.count()<<endl;
  int loops = bar1.count();
  for (int i = 0; i < loops; i++)
  {
    dupe = bar1.getFirstDuplicate(bar1);
    cout << "the dupe is" << dupe << endl;
    guilty.insertAtTail(dupe); 
  }
  cout<< "duplicated taken care of"<<endl;
  if(guilty.isempty()==1){
  ofs << "Guilty:" << endl;
  guilty.print(ofs);
  }
  if(bar1.isempty() == 1 && guilty.isempty()==1)
  {
  ofs << '\n'; 
  ofs << "Innocent:" << endl; 
  bar1.print(ofs);
  } else if (bar1.isempty() == 1){
    ofs << "Innocent:" << endl; 
    bar1.print(ofs);
  }
  return 0; 
}