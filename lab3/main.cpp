#include <iostream>
#include <string>
#include "stack.h"
#include <algorithm>
#include <fstream>
#include <cctype>
#include <sstream>
#include <iomanip>
#include <cmath>
#include "ArgumentManager.h"
using namespace std; 
string reversePrefix(string prefix){
  stringstream ss(prefix);
  string key;
  vector<string> token;
  while (ss >> key){
    token.push_back(key); 
  }
  reverse(token.begin(), token.end()); 
  string post;
  for (const string &t: token){
    post += t + " "; 
  }
  if (!post.empty()){
     post.pop_back();
  }
  return post; 
}

int main(int argc, char *argv[]) {
  ArgumentManager am(argc, argv);
  string input = am.get("input");
  string output = am.get("output");

  // string input = "input2.txt";
  // string output = "output2.txt";

  ifstream ifs(input);  
  ofstream ofs(output);
  string name;
  string nums = ""; 
  Stack calc; 
  double result =0.0; 
  getline(ifs, name); //exp
  getline(ifs, nums);
  name.erase(remove(name.begin(), name.end(), '\n'),
                    name.end());
  name.erase(remove(name.begin(), name.end(), '\r'),
                    name.end());
  name= name.substr(0, name.length()-1); ///
  //cout << name<<"$" << endl;   
  cout << nums << endl;
  //cout << name << endl;
   if(name == "postfix"){
    cout << name << endl; 
    result = calc.PostFix(nums); 
  } else if (name == "prefix"){
      nums = reversePrefix(nums); 
      cout << nums << endl;
      result = calc.prefix(nums); 
  } else if (name == "infix"){
      cout << name << endl; 
      nums = calc.Infix(nums); 
      cout << nums << endl;
      result = calc.PostFix(nums); 
  } 
  ofs << fixed << setprecision(2) << result;
  return 0; 
                
}