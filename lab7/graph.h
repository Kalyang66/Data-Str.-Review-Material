#ifndef GRAPH_H
#define GRAPH_H
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std; 
#include <vector>
#include <unordered_set>

class Graph{
int nodes;
vector<vector<int>> list;

public:
Graph(int x): nodes(x), list(x){}

void Edge(int i, int j){
  list[i].push_back(j);
}

bool cycle(int node, vector<bool>& vist, unordered_set<int>& recStack){
  if(!vist[node]){
    vist[node] = true;
    recStack.insert(node);
  for(int n : list[node]){
    if(!vist[n] && cycle(n, vist, recStack)){
      return true;
    } else if (recStack.find(n) != recStack.end()){
      return true; 
    }
  }
  }
  recStack.erase(node);
  return false; 
}

bool hasCycle(){
  vector<bool> vist(nodes, false);
  unordered_set<int> recStack;
  for (int i =0; i < nodes; i++){
    if (!vist[i] && cycle(i, vist, recStack)){
      return true; 
    }
  }
  return false; 
}

};

#endif