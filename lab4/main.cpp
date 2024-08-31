#include <iostream>
using namespace std;
#include <sstream>
#include <string> 
#include "ArgumentManager.h"
#include "list.h"
#include <algorithm>
#include <fstream>

struct door{
  bool isOpen;
  bool isLocked;

  door() : isOpen(false), isLocked(false) {} 
};

bool isvalid(string s){
  if (s.find('(') == 0){
    return false;
  } else if (s.find(')') == - 1){
    return false;
  } else {
    return true; 
  }
}

int main(int argc, char * argv[]) {
  ArgumentManager am(argc, argv);
  string input = am.get("input");
  string output = am.get("output");

  // string input = "input1.txt";
  // string output = "output1.txt"; 
  
  ifstream ifs(input);
  ofstream ofs(output);

  list h;
  string inputline;

  while (getline(ifs, inputline)){
      if (isvalid(inputline)){
        string inst = inputline.substr(0, inputline.find('('));
        int prio = stoi(inputline.substr(inputline.find('(') + 1, inputline.find(')') - inputline.find('(') - 1));
        h.insertatPos(prio, inst);
      }
  }
  h.print(ofs);
  door Door;
  Door.isLocked = false;
  Door.isOpen = false;
  
  while(!h.Isempty()){
    string pro = h.gethead(); 
    if (pro.find("unlock") == 0){
        Door.isLocked = false;
    } else if (!Door.isLocked){
      if (pro.find("lock") ==0){
        Door.isLocked = true;
      } else if (pro.find("open") ==0){
      Door.isOpen = true; 
    } else if (pro.find("close") ==0){
      Door.isOpen = false; 
    }
  }
  h.deletehead();
  cout << "for instruction: " << pro << endl;
  cout << "closed: " << Door.isOpen << endl;
  cout << "locked: " << Door.isLocked << endl;
  } 
  if (Door.isOpen){
     cout << "the door is open" << endl;
     ofs << "the door is open";
  
  } else {
    cout << "the door is closed" << endl;
    ofs << "the door is closed"; 
  }
  return 0;
}