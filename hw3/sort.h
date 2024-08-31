#ifndef SORT_H
#define SORT_H
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std; 
struct node {
  int num;
  node * next;
  node * prev; 
};
class list{
private:
 node * head;
 int size;
public:
 list(){ head = nullptr; 
  size = 0; }
 void insertatTail(int n){
   node * temp = new node;
   temp -> num = n;
   temp -> next = nullptr;
   temp -> prev = nullptr; 
   if (head == nullptr){
     head = temp;
     size++;
     return;
   } else {
     node * cur = head;
     while (cur -> next != nullptr){
       cur = cur -> next;
     }
     cur -> next = temp;
     temp -> prev = cur;
     size++; 
   }
 }
 void print(ofstream& ofs){
   if (head == nullptr){
     return;
   } else{
     node * cur = head;
     ofs << "["; 
     while (cur != nullptr){
       ofs << cur -> num;
       cur = cur -> next; 
       if (cur != nullptr){
         ofs << ','; 
       }
     }
      ofs << "]" << endl; 
   }
 }

   void selectionsort(ofstream & c){
     if (head == nullptr || head -> next == nullptr){
       return; 
     }
     bool first = true; 
     node * cur = head;
     while (cur != nullptr){
       node * min = cur;
       node * temp = cur -> next;
       while (temp != nullptr){
         if (temp -> num < min -> num){
           min = temp;
         }
         temp = temp -> next; 
       } 
       if (min != cur){
         if (cur -> prev != nullptr){
           cur -> prev -> next = min;
         } else{
           head = min; 
         }
         if (min -> prev != nullptr){
           min -> prev -> next = cur; 
         } else {
           head = cur; 
         }
         node * tempPre = cur -> prev;
         cur -> prev = min -> prev;
         min -> prev = tempPre;

         node * tempNext = cur -> prev;
         cur -> next = min -> next;
         min -> next = tempNext; 
       }
       if (!first){
         print(c);
       } else {
         first = false; 
       }
       cur = cur -> next; 
     }
   }

void insertionsort(ofstream & os){
    if (head == nullptr || head -> next == nullptr){
      return; 
    }
  // dummy node 
    node * sort = new node;
    sort -> num = head -> num; 
    sort -> next = nullptr;
    sort -> prev = nullptr;
  
    node * p = head -> next;
    p -> next = head -> next -> next;
    head -> next = nullptr;
    head -> prev = nullptr;
    p -> prev = nullptr;
    
    while (p != nullptr){
      node * cur = p -> next;
      // cout << p -> num << endl;
      //cout << sort -> num << endl;
      if (p -> num < sort -> num){
        //cout << p -> num << endl; 
        p -> next = sort;
        sort -> prev = p;
        p -> prev = nullptr;
        sort = p; 
      } else {
        node * temp = sort;
        while(temp -> next != nullptr && temp -> next -> num < p -> num){
          temp = temp -> next; 
        }
        p -> next = temp -> next;
        if (temp -> next != nullptr){
          temp -> next -> prev = p; 
        }
        temp -> next = p;
        p -> prev = temp;
      } 
      print2(sort, cur, os);
      p = cur; 
    }
    head = sort; 
  }

  void print2(node * sorted, node * unsorted, ofstream& ofs){
    ofs << "[";
    while (sorted != nullptr){
     ofs << sorted -> num;
     sorted = sorted -> next;
      if ( sorted != nullptr || unsorted != nullptr){
      ofs << ',';
    }
    }
    while (unsorted != nullptr){
      ofs << unsorted -> num;
      unsorted = unsorted -> next;
      if (unsorted != nullptr){
        ofs << ","; 
      }
    }
    ofs << "]" << endl; 
  }
};
#endif