#ifndef HASH_H
#define HASH_H
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std; 

class hash_{
public:
static const int c1_quad = 3;
static const int c2_quad = 5;
void linear(int table[], int x, int tablesize){
  int index = 0;
  for (int i = 0; i < tablesize; i++){
    index = ((x % tablesize) + i) % tablesize; 
    if (table[index] == -1){
      table[index] = x;
      break;
    }
  }
}

void Quad(int table[], int x, int tablesize){
  int index = 0;
  for (int i = 0; i < tablesize; i++){
    index = (x + i * c1_quad + i * i * c2_quad) % tablesize; 
    if (table[index] == -1 ){
      cout << index << " " << x << endl;
      table[index] = x;
      break;
    }
  }
}
void heapify(int array[], int n, int i){
int smallest = i;
int left = 2 * i + 1;
int right = 2 * i + 2;
if(left < n && array[left] < array[smallest]){
    smallest = left;
}
if(right < n && array[right] < array[smallest]){
    smallest = right;
}
if(smallest != i){
    swap(array[i], array[smallest]);
    heapify(array, n, smallest);
}
}

void buildheap(int array[], int size){
  for (int i = size - 2; i >= 0; i--){
    //cout << "here" << endl; 
    heapify(array, size , i);
    }
  }
};
#endif