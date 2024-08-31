#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream> 
#include "ArgumentManager.h"
#include "sort.h"
using namespace std;
int main(int argc, char *argv[]) {
  ArgumentManager am(argc, argv);
  string input = am.get("input");
  string output = am.get("output");

  // string input = "input3.txt";
  // string output = "output3.txt";

  ifstream ifs(input);  
  ofstream ofs(output);
  string nums, name;
  getline(ifs, nums);
  getline(ifs, name); 
  if (name == "" || nums == "" || nums == "Insertion" || nums == "Selection") {    
    ofs << "Input is invalid.";  
  } 
  name.erase(remove(name.begin(), name.end(), '\n'),
                    name.end());
  name.erase(remove(name.begin(), name.end(), '\r'), name.end()); 
  // cout << name << endl;
  // cout << nums << endl; 
  stringstream ss(nums);
  list s;
  while (ss >> nums){
    // cout << nums << endl; 
    s.insertatTail(stoi(nums)); 
  }
  if (name == "Insertion"){
      s.insertionsort(ofs); 
  } else if (name == "Selection"){
     s.selectionsort(ofs); 
  }
  ofs.close(); 
  return 0;
}