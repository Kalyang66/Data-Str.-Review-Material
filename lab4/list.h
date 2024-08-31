#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#ifndef LIST_H
#define LIST_H

class list{
  private:
    struct node{
      int pri;
      string instr;
      node *next;
      node() : pri(-1), instr(""), next(nullptr) {}
      node(int x, string s): pri(x), instr(s), next(nullptr) {}
      node(int x, string s, node *n): pri(x), instr(s), next(n) {}
    };
  node * head;
public:
  list() : head(nullptr){}
  string gethead(){
     return head -> instr; 
  }
  int getsize();
  bool Isempty(){
    return (head == nullptr); 
  }
  void insertatPos(int pr, string t){
    if (head == nullptr || pr < head -> pri){
      head = new node(pr, t, head); 
      return; 
    } 
    node * prev = nullptr;
    node * cur = head;
    while (cur != nullptr && pr > cur -> pri){
      prev = cur;
      cur = cur -> next; 
    }
    node * temp = new node (pr, t, cur);
    prev -> next = temp; 
  }

  void deletehead(){
    if (head == nullptr){
      return;
    }
    node * temp = head;
    head = head -> next;
    delete temp; 
  }

  void print(ofstream& ofs){
    node * cur = head;
    if (head == nullptr){
      return; 
    }
    while (cur != nullptr){
      cout << cur -> instr << " " << cur -> pri << endl;
      cur = cur -> next; 
    }
  }
};

#endif