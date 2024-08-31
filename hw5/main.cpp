#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream> 
#include "ArgumentManager.h"
using namespace std;
#include "avl.h"

int main(int argc, char *argv[]) {
  ArgumentManager am(argc, argv);
  AVL avl; 
  string input = am.get("input");
  string output = am.get("output");

  // string input = "input2.txt";
  // string output = "output2.txt";

  ifstream ifs(input);  
  ofstream ofs(output);
  string inputline, command, newStr;
  int num; 
  while(getline(ifs, inputline)){
    if(inputline.length() == 0){
      return 0; 
  }
    inputline.erase(remove(inputline.begin(), inputline.end(), '\n'),
      inputline.end());
    inputline.erase(remove(inputline.begin(), inputline.end(), '\r'),
      inputline.end());
    //cout << inputline << endl; 
    stringstream ss(inputline);
    
    while(ss >> command){
      newStr = command; 
      size_t pos1 = command.find("(");
      size_t pos2 = newStr.find("(");
      size_t pos3 = newStr.find(")"); 
      command = command.substr(0, pos1);
      num = stoi(newStr.substr(pos2 + 1, pos3 - pos2 - 1));
      //cout << command << " "<< num << endl;
      if (command == "Insert"){
        avl.insertNode(num); 
      } else if (command == "Remove"){
        //avl.Print(ofs);
        avl.remove(num);
        //avl.Print(ofs);
      }
    }
    //avl.Print();
  }
  avl.Print(ofs); 

  return 0;
}