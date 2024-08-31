#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream> 
#include "ArgumentManager.h"
using namespace std;
#include "graph.h"

int main(int argc, char *argv[]) {
  ArgumentManager am(argc, argv); 
  string input = am.get("input");
  string output = am.get("output");

  // string input = "input2.txt";
  // string output = "output2.txt";

  ifstream ifs(input);  
  ofstream ofs(output);
  int num;
  ifs >> num;
  Graph graph(num);
  int x, y;
  while(ifs >> x >> y){
    graph.Edge(x, y);
  }
   bool cycle = graph.hasCycle();
   ofs << (cycle ? "True" : "False") << endl; 
  return 0;
}