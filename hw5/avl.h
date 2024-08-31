#ifndef AVL_H
#define AVL_H
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std; 
#include <queue>

struct Node{
int key;
Node* left;
Node* right;
int height; 
};

class AVL{
private:

Node* root;

int height(Node* node){
  if (node == nullptr){
    return 0;
  }
  return node -> height; 
}

int getBal(Node* node){
 if (node == nullptr)
   return 0; 
 return height(node -> left) - height(node -> right); 
}

Node * rightRot(Node* y){
  Node* x = y -> left;
  Node* z = x -> right;

  x -> right = y;
  y -> left = z;

  y -> height = max(height(y->left), height(y->right)) + 1; 
  x -> height = max(height(x->left), height(x->right)) + 1;

  return x; 
}

Node * leftRot(Node* x){
  Node* y = x -> right;
  Node* z = y -> left;

  y -> left = x;
  x -> right = z;

  x -> height = max(height(x->left), height(x->right)) + 1; 
  y -> height = max(height(y->left), height(y->right)) + 1;

  return y; 
}

Node* insert(Node* node, int key){
  if (node == nullptr){
    return newNode(key);
  }
  if (key < node -> key)
    node -> left = insert(node -> left, key);
  else if (key > node -> key)
    node -> right = insert(node->right, key); 
  else 
    return node; 
  node -> height = 1 + max(height(node->left), height(node -> right));
  int balance = getBal(node);
  //left
  if (balance > 1 && key < node -> left -> key)
    return rightRot(node); 
  if (balance < -1 && key > node ->left->key)
    return leftRot(node);
  if (balance > 1 && key > node->left->key){
    node->left = leftRot(node->left);
    return rightRot(node); 
  }
  if (balance < -1 && key < node->right->key){
    node->right = rightRot(node->right);
    return leftRot(node); 
  }
  return node; 
}

Node* minVal(Node* node){
  Node* cur = node;
  while (cur -> left != nullptr){
    cur = cur -> left; 
  }
  return cur; 
}

Node* deleteNode(Node* root, int key){
  if (root == nullptr)
    return root; 
  if (key < root -> key){
    root -> left = deleteNode(root->left, key);
  } else if (key > root -> key){
    root -> right = deleteNode(root->right, key);
  } else {
     if (root->left == nullptr) {
         Node* temp = root->right;
         delete root;
         return temp;
     } else if (root->right == nullptr) {
         Node* temp = root->left;
         delete root;
         return temp;
     } else {
       Node* temp = minVal(root->right);
       root->key = temp -> key;
       root -> right = deleteNode(root->right, temp->key); 
     }
    //return root; 
  }
  
  if (root == nullptr)
    return root;
  root -> height = 1 + max(height(root -> left), height(root->right));
  int balance = getBal(root); 

  if (balance > 1 && getBal(root->left) >= 0)
    return rightRot(root);

  if (balance > 1 && getBal(root->left) < 0){
    root -> left = leftRot(root-> left);
    return rightRot(root); 
  }

  if (balance < -1 && getBal(root->right) <= 0)
    return leftRot(root);

  if (balance < -1 && getBal(root->right) > 0){
    root -> right = rightRot(root-> left);
    return leftRot(root); 
  }
  return root; 
}

void print(Node* root, ofstream &os){
  if (root == nullptr){
    return; 
  }
  queue<Node*> q;
  q.push(root);
  while(!q.empty()){
    int count = q.size();
    //cout << count << endl; 
    while (count > 0){
      Node* temp = q.front();
      os << temp -> key << " ";
      q.pop(); 

      if (temp -> left != nullptr){
        q.push(temp->left);
      }
      if (temp -> right != nullptr){
        q.push(temp->right); 
      }
      count--; 
    }
    os << endl; 
  }
}

public:
AVL() : root(nullptr){}
Node* newNode(int key){
  Node* node = new Node();
  node -> key = key;
  node -> left = nullptr;
  node -> right = nullptr;
  node -> height = 1;
  return node; 
}
void insertNode(int key){
  root = insert(root, key); 
}
void remove(int key){
  root = deleteNode(root, key);
}
void Print(ofstream &ofs){
  print(root, ofs); 
}
};

#endif