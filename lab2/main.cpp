#include "ArgumentManager.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// structure
struct word {
  // int position;
  // string operation;
  string data;
  word *next;
};
// class
class sentence {
private:
  word *head;

public:
  int size;
  // constructor
  sentence() {
    head = nullptr;
    size = 0;
  }
  // destructor
  ~sentence() {
    if (head != nullptr) {
      word *temp = head;
      while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
      }
      // delete temp;
      // temp = head;
    }
  }

  // return length
  int length() { return size; }

  // insert at end
  void insertatend(string s) {
    // create and fill the node
    word *newtemp = new word;
    newtemp->data = s;
    newtemp->next = nullptr;

    // checking if LL is empty
    if (head == 0) {
      head = newtemp;
      size++;

    }
    //
    else {
      word *last = head;
      while (last->next != nullptr) {
        last = last->next;
      }
      last->next = newtemp;
      size++;
    }
  }

  void insert(int pos, string s) {
    // create and fill
    word *temp1 = new word;
    temp1->data = s;
    temp1->next = nullptr;
    // if(pos>=size && head == nullptr){
    //   temp1->next = head;
    //   head = temp1;
    //   size++;
    // }
    if (pos > size && head == nullptr){
      return; 
    }
      
    // checking if empty
      if (head == nullptr || pos == 0) {
      temp1->next = head;
      head = temp1;
      size++;
    } 
    else {
      word *cur = head;
      word *prev = nullptr;
      for (int i = 0; i < pos; i++) {
        prev = cur;
        cur = cur->next;
      }
      prev->next = temp1;
      temp1->next = cur;
      size++;
    }
  }
  void remove(int pos) {
   // cout << "in remove fun" << pos << endl;
    if (pos >= size) {
      //cout << "size:" << size << " " << pos << endl;
      return;
    }
    if (head == nullptr) {
      return;
    }
    if (pos == 0) {
      word *temp1 = head;
      head = temp1->next;
      delete temp1;
      size--;
      //cout << "pos = 0" << endl;
      return;
    }
    word *prev = nullptr;
    word *cur = head;
    //cout << " Before for loop " << endl;
    for (int i = 0; i < pos; i++) {
      prev = cur;
      cur = cur->next;
      //cout << i << " ";
    }
    //cout << "size=" << size << " After for loop " << endl;
    prev->next = cur->next;
    size--;
    delete cur;
    //  return;
  }
  void printTail(string pos, ofstream &ofs) { // prints last node
    if (head == nullptr)
      return;
    word *temp1 = head;
    while (temp1->next != nullptr)
      temp1 = temp1->next;
    ofs << temp1->data << endl;
  }
  void print(int pos,
             ofstream &ofs) { // prints head node and any other tail not tail
    if (head == nullptr) {
      return;
    }
    word *temp1 = nullptr;
    if (pos == 0) {
      temp1 = head;
      ofs << temp1->data << '\n';
      return;
    }
    word *prev = nullptr;
    word *cur = head;
    for (int i = 0; i < pos; i++) {
      if (cur == nullptr) {
        return;
      }
      prev = cur;
      cur = cur->next;
    }
    ofs << cur->data << '\n';
    return;
  }
  void removetail(string ops) {
    if (head == nullptr) {
      return;
    } else if (head->next == nullptr) {
      word *temp = head;
      head = nullptr;
      delete temp;
      return;
    }
    word *cur = head;
    word *prev = nullptr;
    while (cur->next != nullptr) {
      prev = cur;
      cur = cur->next;
    }
    prev->next = nullptr;
    size--;
    delete cur;
    return;
  }
};
int main(int argc, char *argv[]) {
   ArgumentManager am(argc, argv);
   ifstream ifs(am.get("input"));
   ofstream ofs(am.get("output"));
  // ifstream ifs("input3.txt");
  // ofstream ofs("output3.txt"); // testing one file at a time
  sentence s;                  // obj
  string inStr = "";           // getline
  string cmndStr = "";         // cmd
  string indxStr = "";         // index
  string valStr = "";          // word
  int val = 0;
  //
  //cout << "in main" << endl;
  //
  while (getline(ifs, inStr)) {
    //
    //cout << "outer while " << endl;
    //
    inStr.erase(remove(inStr.begin(), inStr.end(), '\n'), inStr.end());
    inStr.erase(remove(inStr.begin(), inStr.end(), '\r'), inStr.end());
    if (inStr.empty()) {
      continue;
    }
    stringstream ss(inStr);
    //
    while (ss >> cmndStr) {
      //
      //cout << "In while" << endl;
      //
      if (cmndStr == "Insert") { //
        ss >> indxStr;
        if (indxStr != "Head" && indxStr != "Tail") {
          val = stoi(indxStr);
        }
        ss >> valStr;
        if (indxStr != "Head" && indxStr != "Tail") {
          s.insert(val, valStr);
        } else if (indxStr == "Head") {
          val = 0;
          s.insert(val, valStr);
        } else if (indxStr == "Tail") {
          s.insertatend(valStr);
        }
        // test
        // cout << cmndStr << " " << indxStr << " " << valStr << endl; //
      }
      //
      else if (cmndStr == "Remove") {
        ss >> indxStr;
        //cout << "in remove" << endl;
        if (indxStr != "Head" && indxStr != "Tail") {
          val = stoi(indxStr);
          s.remove(val);
          //cout << "done removing " << endl;
        } else if (indxStr == "Head") {
          val = 0;
          s.remove(val);
        } else if (indxStr == "Tail") {
          s.removetail(cmndStr);
        }
        //cout << cmndStr << " " << indxStr << endl; //
      }
      //
      else if (cmndStr == "Print") {
        ss >> indxStr;
        indxStr.erase(remove(indxStr.begin(), indxStr.end(), '['),
                      indxStr.end());
        indxStr.erase(remove(indxStr.begin(), indxStr.end(), ']'),
                      indxStr.end());
        // string str = "";
        if (indxStr != "Head" && indxStr != "Tail") {
          val = stoi(indxStr);
          s.print(val, ofs);
        } else if (indxStr == "Head") {
          val = 0;
          s.print(val, ofs);
          // ofs << str << endl;
        } else if (indxStr == "Tail") {
         // cout << "callint TailPrint" << endl;
          s.printTail(indxStr, ofs);
        }
        //cout << cmndStr << " " << indxStr << endl; //
      }
    }
  }
  return 0;
}