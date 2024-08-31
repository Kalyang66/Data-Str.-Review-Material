#ifndef BAR_H
#define BAR_H
#include <string>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
#include <cctype>
#include <unordered_set>
using namespace std; 

struct person
{
string id;
bool guilty = false;
person *next;
};

class bar
{
  private:
  int size = 0; 
  person *head; 
  public:

  bar()
  { 
    head = nullptr; 
    size = 0;
  }
  int returnsize(int s){
    s = size;
    return s; 
  }
  void insertAtTail(string value){
    person * temp = new person;
    temp -> id = value; 
    temp -> next = nullptr;
    if (head == nullptr){
      head = temp; 
      size++; 
      return; 
    } else {
      person * cur = head;
      while (cur -> next != nullptr){
        cur = cur -> next; 
      } 
      cur -> next = temp;
      size++;
    }
  }
void print(ofstream &ofs){
   if (head == nullptr){
     return ; 
   }
  else{
    person * cur = head; 
    while (cur != nullptr){
      ofs << cur -> id ; 
      cur = cur -> next;
      if (cur != nullptr){
        ofs << '\n'; 
      }
    }
  }
}
int isempty(){
  if (head == nullptr){
    return 0;
  } else {
    return 1; 
  }
}
// Erik code: 
string decode(string a) {
  string decoded;
  int start = 0;
  while (start < a.size()) {
    if (a[start] == '(') {
      int end = start + 1;
      int openCount = 1;        
      while (end < a.size()) {
        if (a[end] == '(') {
            openCount++;
        } else if (a[end] == ')') {
            openCount--;
        }
        if (openCount == 0) {
          break;
        }
          end++;
        }
        string inside = a.substr(start + 1, end - start - 1);
        string decodedInside = decode(inside);
        reverse(decodedInside.begin(), decodedInside.end());
        a.replace(start, end - start + 1, decodedInside);
        start = 0;
    } else {
        start++;
      }
    }
    a.erase(std::remove(a.begin(), a.end(), '('), a.end());
    a.erase(std::remove(a.begin(), a.end(), ')'), a.end());
    a.erase(std::remove(a.begin(), a.end(), ' '), a.end());
    return a;
} 
int count()
{
int dupecount=0;  
    // do something
    person *cur = head;
    person *prev = nullptr;
    while(cur->next!=nullptr)
      {
        if( cur->id == cur->next -> id ) {
          dupecount++;
        }
        prev = cur;
        cur = cur->next;
      }
  return dupecount;  
}
string getFirstDuplicate(bar a)
{
    string temp;  
    // do something
    person *cur = head;
    person *prev = nullptr;
    while(cur->next!=nullptr)
      {
        if( cur->id == cur->next -> id ) {
          if (cur == head ){
            temp = cur->id;
            prev = cur -> next -> next;
            head = prev;
            delete cur;
            delete cur -> next; 
            break; 
          }
          cout << "Found duplicate: " << cur->id << endl;
          temp = cur->id;
          prev->next = cur->next->next; 
          delete cur;
          delete cur->next;
          break;
        }
        prev = cur;
        cur = cur->next;
      }
     return temp;
}  
void setStatus(person *n){
  n->guilty = true;
  return;
}
void sort(){ //credit to Eoin Donovan for the sorting code algorithim
if(head == nullptr || head->next == nullptr)
return;
bool isSorted = false;
person *cur;
while(!isSorted){
isSorted = true;
cur = head;
while(cur->next != nullptr){
if(stoi(cur->id) > stoi(cur->next->id)){
string tempData = cur->id;
cur->id = cur->next->id;
cur->next->id = tempData;
isSorted = false;
}
cur = cur->next;
}
}
}

};
#endif