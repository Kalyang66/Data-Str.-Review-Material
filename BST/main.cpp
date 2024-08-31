#include<iostream>
#include<queue>
using namespace std;

struct node{
  int value;
  node *left;
  node *right;
  node(){
    value = -999;
    left = nullptr;
    right = nullptr;
  }
  node(int v){
    value = v;
    left = nullptr;
    right = nullptr;
  }
};

node *recursiveInsert(node *root, int value){
  if(root == nullptr){
    node *newNode = new node(value);
    return newNode;
  }
  else if(value < root->value){
    root->left = recursiveInsert(root->left, value);
  }
  else if(value > root->value){
    root->right = recursiveInsert(root->right, value);
  }
  return root;
}

node *iterativeInsert(node *root, int value){
  node *newNode = new node(value);
  if(root == nullptr){
    return newNode;
  }
  node *cur = root;
  bool flag = false;
  while(!flag){
    if(value < cur->value){
      if(cur->left == nullptr){
        cur->left = newNode;
        flag = true;
      }
      else{
        cur = cur->left;
      }
    }
    else if(value > cur->value){
      if(cur->right == nullptr){
        cur->right = newNode;
        flag = true;
      }
      else{
        cur = cur->right;
      }
    }
    else{
      flag = true;
    }
  }
  return root;
}

void inorder(node *root){
  if(root == nullptr){
    return;
  }
  inorder(root->left);
  cout << root->value << " ";
  inorder(root->right);
}

void reverseorder(node *root){
  if(root == nullptr){
    return;
  }
  reverseorder(root->right);
  cout << root->value << " ";
  reverseorder(root->left);
}

void preorder(node *root){
  if(root == nullptr){
    return;
  }
  cout << root->value << " ";
  preorder(root->left);
  preorder(root->right);
}

void postorder(node *root){
  if(root == nullptr){
    return;
  }
  postorder(root->left);
  postorder(root->right);
  cout << root->value << " ";
}

void levelorder(node *root){
  if(root == nullptr){
    cout << "BST is empty" << endl;
    return;
  }
  queue<node*> q;
  q.push(root); // just one node or whole tree???
  while(!q.empty()){
    int levelSize = q.size();
    for(int i = 0; i < levelSize; i++){
      node *cu = q.front();
      q.pop();
      cout << cu->value << " ";
      if(cu->left != nullptr)        
      q.push(cu->left);
      if(cu->right != nullptr)
      q.push(cu->right);
    }
    cout << endl;
  }
}

int main(){

  return 0;
}