#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream> 
#include "ArgumentManager.h"
using namespace std;
#include "hash.h"
void print(int arr[], int size, ofstream &of){
  int count = 0; 
  for(int i = 0; i < size; i++){
    of << arr[i]; 
    count++;
    if (count != size){
      of << ","; 
    }
  }
  of << endl;
}
void print2(int arr[], int size, ofstream &of){
  int count = 0; 
  for(int i = 0; i < size; i++){
    of << arr[i];
    count++;
    if (count != size){
      of << ","; 
    }
  }
}

int main(int argc, char *argv[]) {
  ArgumentManager am(argc, argv);
  hash_ myHash;
  string input = am.get("input");
  string output = am.get("output");

  // string input = "input3.txt";
  // string output = "output3.txt";

  ifstream ifs(input);  
  ofstream ofs(output);
  string num, name, nums; 
  
  while (getline(ifs, num)){
    getline(ifs, name);
    getline(ifs, nums);
    nums.erase(remove(nums.begin(), nums.end(), '\n'),
      nums.end());
    nums.erase(remove(nums.begin(), nums.end(), '\r'),
      nums.end());
    nums.erase(remove(nums.begin(), nums.end(), ' '),
      nums.end());
    stringstream ss(nums); 
    // cout << num << endl;
    // cout << name << endl;
    // cout << nums << endl;
    int numElm = stoi(num); 
    int arr[numElm];
    int arra[numElm]; 
    int curNum;
    int z, x, k;
    int s = numElm;
    z = nums.size(); 
    k = 0; 
    for (int i = 0; i < s - 1; i++) {
      x = stoi(nums.substr(0, nums.find(',')));
      arr[i] = x;
      nums = nums.substr(nums.find(',') + 1);
    }
    arr[s - 1] = stoi(nums);
   
    // for (int i = 0; i < z; i++){
    //   x = 0; 
    //   while (i < z && nums[i] != ','){
    //     x = x * 10 + (nums[i] - '0');
    //     i++; 
    //   }
    //   arr[k] = x;
    //   k++;
    // }
    for (int i = 0; i < s; i++){
      arra[i] = -1; 
    }
   //print(arr, s);
    for (int i = 0; i < s; i++){
      if (name == "Linear probing"){
         curNum = arr[i]; 
         myHash.linear(arra, curNum, s); 
       } else if (name == "Quadratic probing"){
         curNum = arr[i]; 
         //cout << curNum << endl; 
         myHash.Quad(arra, curNum, s); 
       } 
    }
    print(arra, s, ofs);
    myHash.buildheap(arra, s);
    print2(arra, s, ofs); 
  }
  return 0;
}