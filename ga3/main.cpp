#include <iostream>
#include "ArgumentManager.h"
#include <fstream>
#include <functional>
#include <string>
using namespace std;
#include "bst.h"

int main(int argc, char *argv[]) {
  ArgumentManager am(argc, argv);
  BST bst;
  string input = am.get("input");
  string output = am.get("output");

  // string input = "input1.txt";
  // string output = "output1.txt";

  ifstream ifs(input);  
  ofstream ofs(output);

string line;
getline(ifs, line);
stringstream ss(line);
  int a;
  while(ss>>a){
    {
      bst._insert(a);
    }
  }
  bst.Tran(ofs);
  return 0;
}