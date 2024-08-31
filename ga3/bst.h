#ifndef BST_H
#define BST_H
#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <algorithm>
#include <string>

struct Node{
  int data;
  Node* left;
  Node* right; 

  Node(int val) : data(val), left(nullptr), right(nullptr){}
};

class BST{
 private:
  Node* root;
  Node* insert(Node* root, int val){
    if (root == nullptr){
      return new Node(val);
    }
    if (val < root -> data){
      root -> left = insert(root -> left, val);
    } else if (val > root -> data){
      root -> right = insert(root -> right, val); 
    }
    return root; 
  }

  void perorder(Node* root, string st, ofstream& ofs){
    if (root != nullptr){
      ofs << "[" << st << "]" << " " << root -> data << endl;
      perorder(root->left, st +"l", ofs);
      perorder(root->right, st + "r",ofs);
    }
  }

public:
BST() : root(nullptr){}
void _insert(int val){
  root = insert(root, val);
}
void Tran(ofstream &ofs){
  perorder(root, "x", ofs); 
}
};

#endif