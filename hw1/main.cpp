#include <fstream>
#include <iostream>
using namespace std;
#include "ArgumentManager.h"
#include <string>
#include <vector>
void bubblesort(vector <int> &vect, int size){
  if (size == 1)
    return;
  for (int i = 0;  i < size - 1; i++){
      if (vect[i] < vect[i + 1]){
        swap(vect[i], vect[i + 1]);
    }
    }
  bubblesort(vect, size - 1);
}
int main(int argc, char* argv[]) {
  ArgumentManager am(argc, argv);
  ifstream ifs(am.get("input"));
  ofstream ofs(am.get("output"));
  vector <int> vect; 
  char nums;
  while(ifs >> nums){
    vect.push_back(nums - '0');
  }
  
  int n = vect.size(); 
  ifs.close();
  bubblesort(vect, n);
  for (int i : vect){
  ofs << i << "";
  }
  ofs.close(); 
  return 0;
}